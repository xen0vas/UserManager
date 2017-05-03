#include "userproperties.h"
#include "editProperties.h"
#include <sys/stat.h>
#include <sys/wait.h>


using namespace std;


/**
*Constructor κλάσης με αρχικοποιήσεις σε components της φόρμας
*/

UserProperties::UserProperties ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	setModal ( true );
	QValidator *validator = new QIntValidator(1, 65535, this);
	uidEdit->setValidator(validator);
	easyList->setVisible(false);
	
	
	// long int sp_lstchg;	/* Ονομα λογαριασμού του χρήστη */

	min->setMaximum(99999);// long int sp_min;  /* Μικρότερος αριθμός ημερών στον οποίο γίνεται αλλαγή κωδικού */  
	min->setMinimum(0);
	min->setSuffix(" days");
	min->setValue(1);	

	max->setMaximum(99999);//long int sp_max;   /* Μεγαλύτερος αριθμός ημερών στον οποίο γίνεται αλλαγή κωδικού  */
	max->setMinimum(1);
	max->setValue(30);
	max->setSuffix(" days");
	
	warn->setMaximum(99999);//long int sp_warn; /* Αριθμός ημερών για προειδοποίηση του χρήστη να αλλάξει τον κωδικό του*/
	warn->setMinimum(0);
	warn->setValue(8);
	warn->setSuffix(" days");
	warn->setPrefix("After ");

	expire->setMaximum(99999); //long int sp_inact;  /* Αριθμός ημερών που ο λογαριασμός μπορεί να είναι ανενεργός */
	expire->setMinimum(-1);
	expire->setSuffix(" days");
	
	//long int sp_expire;	/* αριθμός ημερών που ο κωδικός πρόκειται να  λήξει.*/
	max->setEnabled(false);
	expire->setEnabled(false);
	warn->setEnabled(false);
	min->setEnabled(false);
	
	days->setEnabled(false);
	months->setEnabled(false);
	years->setEnabled(false);
	alway->setCheckState(Qt::Checked);
	
	shellConnect->setAutoCompletion ( true );
	tabWidget->setTabEnabled(2,false);
	expire->setSpecialValueText("never");
	expire->stepBy(-1);
	warn->setSpecialValueText ( "never" );
	warn->stepBy(-1);
	connect ( add, SIGNAL ( clicked() ), this, SLOT ( addUserBase() ) );
	connect ( passBtn ,SIGNAL ( clicked() ),this,SLOT ( setPassword() ) );
	connect( userGroups, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( changeMembers(const QModelIndex&  ) ) );
	connect( easyCheckbox, SIGNAL( clicked() ), this, SLOT( easyCheckboxClicked() ) );
	connect( easyList, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( easyAddGroups(const QModelIndex&  ) ) );
	connect ( requires_Pass, SIGNAL ( clicked() ),this, SLOT ( disCheck()));
	connect ( enforce_Pass, SIGNAL ( clicked() ),this, SLOT  ( disCheck()));
	connect ( alway, SIGNAL ( clicked() ),this, SLOT ( disCheck()));
	connect ( makePrimBtn, SIGNAL ( clicked( ) ), this, SLOT ( setPrimaryGroup( ) ) );
}	
/**
*Destructor κλάσης
*/
UserProperties::~UserProperties()
{}
/**
*Συνάρτηση που θέτει σε εμφανή ή μη εμφανή τα συστατικά της φόρμας σε διαφορετικές περιπτώσεις
*/
void UserProperties::disCheck()
{
if(enforce_Pass->isChecked())
	{
	min->setEnabled(true);
	}
	else
	{
	min->setEnabled(false);
	}
if(requires_Pass->isChecked())
	{
	max->setEnabled(true);
	expire->setEnabled(true);
	warn->setEnabled(true);
	}
	else
	{
	max->setEnabled(false);
	expire->setEnabled(false);
	warn->setEnabled(false);
	}
if(!alway->isChecked())
	{
	months->setEnabled(true);
	days->setEnabled(true);
	years->setEnabled(true);
	}
	else
	{
	months->setEnabled(false);
	days->setEnabled(false);
	years->setEnabled(false);	
	}
}
/**
*Η συνάρτηση ψάχνει το αρχείο /etc/shells το οποίο περιέχει τα διαθέσιμα κελύφη που υπάρχουν στο σύστημα
και τα εμφανίζει σε ένα combobox στην φόρμα δίνοντας την ευκαιρία στον διαχειριστή να διαλέγει ποιο κέλυφος θα έχει σαν προεπιλεγμένο ο κάθε χρήστης.
*/
void UserProperties::combotext()
{
	ifstream inShells ( "/etc/shells", ios::in );
	if ( !inShells )
	{
		QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Open file <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	}
	char header[30];
	inShells.seekg ( 35 );
	while ( inShells >> header )
	{
		shellConnect->addItems ( QStringList ( QObject::tr ( header ) ) );
	}
	
	shellConnect->setItemText (0, "/bin/bash" );
	shellConnect->setDuplicatesEnabled ( false );



}
/**
 * Συνάρτηση σάρωσης του αρχείου των χρηστών του συστήματος,για να βρεθεί από την εφαρμογή το αμέσως επόμενο ελεύθερο USER ID που είναι διαθέσιμο στο σύστημα.Χρησιμοποιείται ώστε να μπορεί ο διαχειριστής να διατηρεί οργανωμένη την σειρά με την οποία προσθέτει χρήστες,δίνοντας σε κάθε νέο χρήστη το αμέσως επόμενο USER ID,από τον τελευταίο χρήστη που έχει προστεθεί στο σύστημα.
 */
int UserProperties::passwd_study()
{
	
	struct passwd   *pw;
	bool found=false;
	Settings settings;
	uid_t uid;
	uid_t  max = 65535;
	const char  *file = "/etc/passwd";
	FILE  *fp;
	fp = fopen ( file, "r" );
	uid = atoi(settings.getconf("MINIMUM_UID").c_str());//atoi to metatrepei se int kai c_str() metatrepei to epistrefomeno string se char*
	if ( !fp ) { return 0; }
	setpwent();
	while ( ( pw = getpwuid ( uid ) ) && found==false && uid<max)
	{
		if(pw==NULL)
		found=true;
		else
		uid++;
	}
	setpwent();
return uid;
}
/**
*Η συνάρτηση εισάγει στο αρχείο /etc/passwd μια ολοκληρωμένη εγγραφή με όλα τα πεδία της δομής passwd 
*Ο νέος χρήστης  εισάγεται στο σύστημα με όλες τις πληροφορίες στα πεδία της δομής χωρισμένα με ανω κατω τελεια
* 
*/
int UserProperties::insert_passwd ( QString nam,QString uid,QString gid,QString directory,QString gec, QString shellcon )
{
	MyLibb *fchk;
	int done;
	QString pass = "x";
	QByteArray name ( nam.toAscii().data() );
	QByteArray gecos ( gec.toAscii().data() );
	QByteArray dir ( directory.toAscii().data() );
	QByteArray shell ( shellcon.toAscii().data() );
	uid_t userID  = uid.toInt();
	gid_t groupID = gid.toInt();
	struct passwd  us;
	
	us.pw_name   =  name.data();
	us.pw_passwd =  pass.toAscii().data();
	us.pw_uid    =  userID;
	us.pw_gid    =  groupID;
	us.pw_gecos  =  gecos.data();
	us.pw_dir    =  dir.data();
	us.pw_shell  =  shell.data();
	const char *filename  = PASSWD_FILE;
	
	FILE *fp;
	fp = fchk->fopen_wrapper ( filename, "a+" );
	if ( fp != NULL )
	{
		done = putpwent ( &us , fp );
		fclose ( fp );
	}
	return done;

}
/**
*Συνάρτηση που εισάγει group στο αρχείο /etc/group 
*/
int UserProperties::insert_group ( QString nam,QString gid )
{
	MyLibb *fchk;
	int def;
	QString pass = "x";
	Groups *groupie;
	QByteArray name ( nam.toAscii().data() );
	gid_t groupID = gid.toInt();
	struct group grp;
	grp.gr_name = name.data() ;
	grp.gr_passwd = pass.toAscii().data();
	grp.gr_gid = groupID  ;
	grp.gr_mem = NULL;
	FILE *groupbase;

	const char *filename1 = GROUP_FILE;
	int res;
	groupbase = fchk->fopen_wrapper ( filename1, "a+" );
	if ( groupbase!=NULL )
	{
		res = putgrent ( &grp, groupbase );
		fclose ( groupbase );
	}
	def = groupie->default_groups ( nam );
	if ( def== -1 ) res = -1;


	return res;
}
/**
*Η συνάρτηση δίνει τιμές στα πεδία του του shadow struct που αφορούν τις επισημάνσεις για το χρόνο λειτουργίας του *κρυπτογραφημένου password ,καθώς έπίσης εισάγει στη δομή και τον κρυπτογραφημένο κωδικό με το όνομα του χρήστη.Επιστρέφει έναν δείκτη σε δομή struct spwd.
*
*/
struct spwd  UserProperties::set_possix(int max, int warn,int inact, int min,string inact_user,char * name,char * password_hash,int current_days)
{
struct spwd sp;
sp.sp_namp = name;
sp.sp_pwdp = password_hash;
sp.sp_lstchg = current_days;

EditProperties *edit;
			
			if( !requires_Pass->isChecked())//προκαθορισμένες τιμές σε περίπτωση που δεν υπάρχει password
			{	
				sp.sp_max  = 99999; 
				sp.sp_min  = 0;
				sp.sp_warn =	7;
				sp.sp_inact =  -1;
			}
			else if (requires_Pass->isChecked())
			{
				sp.sp_max   =  max;
				sp.sp_warn =   warn;
			if (inact_user == "never")
				sp.sp_inact = -1;
			else
				sp.sp_inact = inact;
			if(enforce_Pass->isChecked())
				sp.sp_min   = min;
			else 
				sp.sp_min = 0;
			}

			if(!alway->isChecked())//πότε λήγει ο κωδικός
				sp.sp_expire = edit->set_shad_expire(months->currentText(),days->value(),years->value());
			else
			{
				sp.sp_expire = -1;
				expire->setValue(0);
			}
				sp.sp_flag = -1;
	
return sp;

}
/**
*Η συνάρτηση εισάγει στο αρχείο shadow τις τιμές όλων τών πεδίων του shadow struct.Το πεδίο του password συμπληρώνεται ανάλογα με το αν είναι ενεργός λογαριασμός ή όχι (έλεγχος απο τη φόρμα).Χρησιμποιει την συνάρτηση set_posix () για την εισαγωγή στα πεδία του shadow struct
*/
int UserProperties::insert_shadow ( QString logname,QString encrypted_pass )
{
	int ret = 0;
	struct spwd spw;
	int curdays = time ( NULL ) / ( 60 * 60 * 24 );
	
	QByteArray name ( logname.toAscii().data() );
		
	QString mini = min->cleanText();
	string minim = mini.toAscii().data();
	
	QString maxi = max->cleanText();
	string maximum = maxi.toAscii().data();
		
	QString inaction = expire->cleanText();
	string inactuser = inaction.toAscii().data();
	
	QString warning = warn->cleanText();
	string warn_pass = warning.toAscii().data();
	
	char *encrypt = encrypted_pass.toAscii().data();

	if( !checkBox->isChecked() && encrypted_pass != "" )
		{		
		spw = set_possix(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),encrypted_pass.toAscii().data(),curdays );		
		}			
	else if ( checkBox->isChecked() && encrypted_pass == "" )
		{
		spw = set_possix(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),(char *)"!",0 );
		}
	else if ( !checkBox->isChecked() && encrypted_pass == "" )
		{
		spw = set_possix(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),(char *)"",0 );
		
		}
	else if(checkBox->isChecked() && encrypted_pass != "" )
	{
		char *disable;
		string encrypting(encrypt);	
		QString dis = "!";
		disable = dis.toAscii().data();
		string dis_account(disable);
		string account = "";
		account  = dis_account +  encrypting;
		QString acc = account.data();
		spw = set_possix(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),acc.toAscii().data(),curdays);
		}

	setspent();
	FILE *shadowbase;
	const char *sh_file = SHADOW_FILE;
	
	MyLibb *fchk;
	shadowbase = fchk->fopen_wrapper ( sh_file, "a+" );
	if ( shadowbase!=NULL )
	{
		//εισαγωγή της δομής στο αρχείο shadow 
		ret = putspent ( &spw, shadowbase );
		fclose ( shadowbase );
	}
	//δικαιώματα αρχείου 6->
	//chmod(SHADOW_FILE,0640);
	//struct group *grp;					
	//grp = getgrnam("shadow");					
	//chown (SHADOW_FILE , (uid_t)0 ,(gid_t)grp->gr_gid);
	//endspent();	
	return ret;	
}

/**
 Η παρακάτω συνάρτηση εισάγει έναν νέο χρήστη στο σύστημα.Πιό αναλυτικά ,γίνεται η εισαγωγή στα αρχεία /etc/passwd *,/etc/shadow και /etc/goup.Δημιουργεί το Home Directory του χρήστη και προσθέτει τα ειδικά αρχεία .profile , .bash_logout *και .bashrc μέσα απο το /etc/skelμεσα στο καινούριο home του νέου χρήστη.

	$HOME/.profile		περιέχει εντολές που το σύστημα εκτελέι όταν ο χρήστης κάνει login.Προβάλει μεταβλητές περιβάλλοντος που 			καθορίζουν στο σύστημα συγκεκριμένες ενεργειες στο προφίλ του χρήστη οπως π.χ. ποιο ειναι το path για 				τις ρυθμίσεις συστήματος για το συγκεκριμένο shell δηλαδή το /etc/ 
	
	$HOME/.bashrc 		προσδιορίζει τη συμπεριφορά των αλληλοεξαρτώμενων shells και το πώς συνδέονται μεταξύ τους με το bash shell.
	
	$HOME/.logout_bash	Οταν γίνει έξοδος απο το φλοιο bash εκτελούνται οι διαταγες που βρίσκονται σε αυτό το 	
				αρχείο αποσυνδεση απο  το φλοιό και έξοδο απο το σύστημα  

Επίσης η συνάρτηση ελεγχει αν υπάρχει ο χρήστης ηδη στο σύστημα και ανάλογα εμφανίζει μύνημα λάθους.
*/

void UserProperties::addUserBase() 
{
	GroupProperties grp;
	
	int pass_done;
	int pid;
	int pid1;
	int pid2;
	int group_done;
	int shadow_done;
	QString nam = NameLabel->text();
	QString uid = uidEdit->text();
	struct passwd *u;
	gid_t ui = uid.toInt();
	int free_gid  = grp.groupStudy(ui);
	QString gid =  gid.number(free_gid);
	QString gec = "";

	if (FullNameEdit->text() == "" && office1Edit->text() == "" && office2Edit->text() == "" && addressEdit->text() == "")
	gec = "";
	else
	{
	if(FullNameEdit->text() != "")
	{
	gec = FullNameEdit->text();
	}
	
	if(office1Edit->text() != "")
	{
	gec ="" + gec + ",";	
	gec = "" + gec + "" + office1Edit->text()+ "";
	}
	
	if(office2Edit->text() != "")
	{	
	if (office1Edit->text()=="" ) gec ="" + gec + ",";
	gec ="" + gec + ",";
	gec = "" + gec + "" + office2Edit->text() +  "";
	}
	
	if(addressEdit->text() != "")
	{
	if (office2Edit->text() == "" &&  office1Edit->text() != "" ) gec ="" + gec + ",,";
	if (office1Edit->text() == "" && office2Edit->text() != "" ) gec ="" + gec + ",";	
	if (FullNameEdit->text() == "" && office1Edit->text() == "" && office2Edit->text()== ""){gec ="" + gec + ",,,";}
	if (FullNameEdit->text() != "" && office1Edit->text() == "" && office2Edit->text() == ""){gec ="" + gec + ",,,";} 
	if (FullNameEdit->text() != "" && office1Edit->text() != "" && office2Edit->text() != ""){gec ="" + gec + ",";} 
	gec = "" + gec + "" +  addressEdit->text()  +  "";

	}
	
	}
	QString directory = HomeDirEdit->text();
	QString shellcon  = shellConnect->currentText();
	uid_t userID  = uid.toInt();
	gid_t groupID = gid.toInt();
	bool userExists=false;
	if ( uidEdit->text() == "" || HomeDirEdit->text() == "" )
		QMessageBox::information ( 0,tr ( "User Manager" ),tr ( " Empty fields " ) );
	else
	{
		
		u = getpwuid ( userID );
		if ( u == NULL )
		{
			pass_done = insert_passwd ( nam,uid,gid,directory,gec,shellcon );
			group_done = insert_group ( nam,gid );
			shadow_done = insert_shadow ( nam,passhash );
			
		}
		else
		{
		QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "UID %1 already exists " ).arg(uid) );
		userExists=true;
		}
		if ( ( pass_done == 0 ) && ( group_done == 0 ) && ( shadow_done == 0 ) )
		{
			QByteArray dir ( directory.toAscii().data() );
			const char *path = dir.data();
			mkdir ( path,X_OK );
			chmod ( path,0700 );
			chown ( path, ( uid_t ) userID, ( gid_t ) groupID );

			pid  = fork();
			if ( pid != 0 ) //parent process
			{
				execl ( "/bin/cp", "/bin/cp", "/etc/skel/.bash_logout",path, ( char* ) 0 );
				int status;
				waitpid(pid,&status,0);
			}
			pid1 = fork();
			if ( pid1 == 0 ) //child process 1
			{
				execl ( "/bin/cp", "/bin/cp", "/etc/skel/.bashrc",path,NULL );
				int status1;
				waitpid(pid1,&status1,0);
			}
			pid2 = fork();
			if ( pid2 == 0 ) // child process 2
			{
				execl ( "/bin/cp", "/bin/cp", "/etc/skel/.profile",path,NULL );
				int status2;
				waitpid(pid2,&status2,0);
			}
			//dimiourgei back up arxeio gia to passwd
			unlink(PASSWD_FILE".bak");

			link ( PASSWD_FILE, PASSWD_FILE".bak" );
			//dimiourgei back up arxeio gia to group
			unlink ( GROUP_FILE".bak" );

			link ( GROUP_FILE,GROUP_FILE".bak" );
			//dimiourgei back up arxeio gia to shadow
			unlink ( SHADOW_FILE".bak" );

			link ( SHADOW_FILE,SHADOW_FILE".bak" );
			//dimiourgei back up arxeio gia to shadow
			
	
			QMessageBox::information ( this,tr ( "User Manager" ),tr ( " User %1 Inserted succesfully!!" ).arg ( nam ) );
			passBtn->setEnabled(false);
			}
		else
		QMessageBox::information ( 0,tr ( "User Manager" ),tr ( " User %1 Not Inserted" ).arg ( nam ) );
	}


	if ( group_done != 0 )
	{
		errno = EACCES;
		QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "Group Base: %1 " ).arg ( errno ) );
	}

if ( ok && !userExists)
{
	Users *usr;
	Models *model;
	add->setVisible(false);
	closeBtn->setVisible(false);
	tabWidget->setTabEnabled(2,true);
	primGroupLabel->setText ( usr->getPrimaryGroup ( nam ) );
	userGroups->setModel(model->createUserInGroupsModel(nam));
	userGroups->setColumnWidth ( 0, 30);
	fillEasyList();

}

	
}

/****************************************************************************/
/*               	 MD5 CRYPTOGRAPHY				    */
/****************************************************************************/


/**
*συνάρτηση δημιουργεί έναν τυχαίο 64bit κρυπτογραφημένο κωδικό 
*/
void UserProperties::into64 ( char *s, long int v, int n )
{

	static unsigned char itoa64[] =         // 0 ... 63 => ascii - 64
	    "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	while ( --n >= 0 )
	{
		//μετατροπή ενός ακεραίου 64 bit σε string 
		*s++ = itoa64[v&0x3f];
		v >>= 6;  // μετακίνηση 6 bit 
	}
}
/**
* Η συνάρτηση δημιουργεί τον κρυπτογραφημένο md5 κωδικό χρησιμοποιώντας την crypt(3) και την make_md5_salt 
*/
char *UserProperties::md5_passwd ( QString passwd )
{
	char *buf;
	int saltLength = 8;
	char *seed;
	seed = make_md5_salt ( saltLength );
	buf = ( char * ) malloc ( 30 );
	char *p = passwd.toAscii().data();
	strcpy ( buf,p );
	char *passs;
	//Η συνάρτηση crypt() σύμφωνα με τη βιβλιοθήκη glibc2 έχει το εξής χαρακτηριστικό.Εάν το seed είναι ένα string το οποίο ξεκινάει απο 
  	//τρείς χαρακτήρες $1$ ακολουθώντας 8 χαρακτήρες και τελειώνοντας με $ τότε αντί να χρησιμοποιείσει τον αλγόριθμο κρυπτογράφησης DES χρησιμοποιεί τον
	//αλγόριθμο κρυπτογράφησης MD5.Το αποτέλεσμα είναι να επιστραφεί ο κρυπτογραφημένος κωδικός $1$<string>$ 34 bytes ακολουθώντας ένα 22 bytes string με //χαρακτήρες επιλεγμένους απο το set  [a-zA-Z0-9./]  
	passs = crypt ( buf,seed );

	if ( passs == NULL )
		QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "%1" ).arg ( ENOSYS ) );

	free(buf);
	return strdup ( passs );
}
/**
* Η παρακάτω συνάρτηση δημιουργεί την κωδικοποίηση ενός password για τον αλγόριθμο MD5
* Ουσιαστικά δημιουργεί το seed $1$......$ ,δηλαδή έναν τυχαίο string απο χαρακτήρες ξεκινώντας απο
* το $1$ μέτρώντας 8 χαρακτήρες και τελειώνοντας με $.Το μέγεθος του string είναι 34  bytes
*χρησιμοποιεί τη συνάρτηση into64()
*/
char *UserProperties::make_md5_salt ( int length )
{
	//το salt είναι το αναγνωριστικό του αλγόριθμου md5($1$)
	static char salt[12];
	salt[0] = '$';
	salt[1] = '1';
	salt[2] = '$';
	//παράγει διαφορετικά σετ απο ψευδοτυχαίους αριθμούς κάθε φορά που το πρόγραμμα τρέχει
	//Στη συνέχεια η random επιστρέφει τυχαίους αριθμούς ανάλογα με το σετ που έχει δημιουργηθεί απο τη srandom
	srandom ( ( int ) time ( ( time_t * ) NULL ) );
	//χησιμοποιούμε την παρακάτω συνάρτηση δύο φορές για τη δημιουργία 128 bit hash value όπως ορίζεται απο τον md5 αλγόριθμο για το πρώτο salt πρίν δοθεί στην crypt για την παραγωγή του MD5 κωδικού. 
	into64 ( &salt[3], random(),length );
	into64 ( &salt[length],random(),3 );
	salt[length+3] = '$';
	return salt;

}
/**
*Η σνάρτηση χρησιμοποιεί το γραφικό περιβάλλον της φόρμας για να δεχτει τον κωδικό απο τον χρήστη και να κάνει την πιστοποίηση verify.Επίσης χρησιμοποιεί τη συναρτήση  md5_passwd .o κρυπτογραφημένος κωδικός αποθηκεύεται στην passhash για περεταίρω επεξεργασία
*/
void UserProperties::setPassword()
{
	bool okBtn;
	QString name = NameLabel->text();
	QString verify;
	QString passwd = QInputDialog::getText ( 0, QObject::tr ( "Enter Password" ), QObject::tr ( "Please Enter password for '%1'" ).arg ( name ), QLineEdit::Password, QString ( "" ), &okBtn );
	if(passwd != "" )
	verify = QInputDialog::getText ( 0, QObject::tr ( " Verify Password " ), QObject::tr ( "Please Verify password for '%1'" ).arg ( name ), QLineEdit::Password, QString ( "" ), &okBtn );
	if ( okBtn && passwd != "" && strcmp(passwd.toAscii().data(),verify.toAscii().data()) == 0)
	{
		checkBox->setCheckState ( Qt::Unchecked );
		/*  MD5 Algorthm */
		passhash = md5_passwd ( passwd );
		struct  tm *ltime;
		time_t times;
		char buff[256];
		setlocale ( LC_ALL, "C" );
		time ( &times );
		ltime = localtime ( &times );
		strftime ( buff,256," %A  %d  %B  %Y  %H:%M ",ltime );
		timeDate->setText ( buff );
	}
	else 
		{
		if ( passwd != "" )
		QMessageBox::warning ( 0,tr ( "User Manager" ),tr ( "Passwords are not identical \n. Please try again!" ) );
		passhash = "";
		}
}
/**
 * Προσθήκη/αφαίρεση χρηστών σε/από ομάδες
 */

void UserProperties::changeMembers ( const QModelIndex &index )
{
	int col=index.column();
	int row=index.row();
	QString test = index.sibling(row,1).data().toString();
	if(col==0 && test!="")
	{
	Models model;
	char *cmd;
	int done=1;
	int row=index.row();
	QVariant state = index.sibling(row,0).data ( Qt::CheckStateRole );//state=2 an eiani checked,0 an einai unchecked to checkbox tou xrhsth pou path8hke
	if ( state == 0 )
	{
		QString command="usermod -a -G "  +  index.sibling(row,1).data().toString() + " " + NameLabel->text() + "";//index.data().toString() periexei ton neo member kai groupNameEdit->text() to group pou 8a mpei
		cmd=command.toAscii().data();
		done = ( system ( cmd ) );
	}
	else
	{
		Groups group;
		MyLibb set;
		struct group *grs;
		grs=getgrnam ( index.sibling(row,1).data().toString().toAscii().data() );
		group.remove_member ( grs,NameLabel->text().toAscii().data() );
		done=set.setgrnam ( grs );
	}
	if ( done==0 )
	{
		system ( "sed -i 's/,,/,/g;s/,$//g' /etc/group" );
		userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
		userGroups->setColumnWidth ( 0, 30);
	}

	easyList->clear();
	fillEasyList();
}
}
/**
 * Συνάρτηση η οποία γεμίζει μια λίστα με βασικές ομάδες του συστήματος,στην οποία φαίνονται εύκολα τα δικαιώματα του επιλεγμένου χρήστη.
  Μέσω αυτής της λίστας μπορούμε να δώσουμε/αφαιρέσουμε στον/από τον χρήστη βασικά δικαιώματα.
 */
void UserProperties::fillEasyList()
{
	bool bstorage=false,badmin=false,bfax=false,binternet=false,bfloppy=false,bcdrom=false,blog=false,bscanner=false;
	QListWidgetItem* header = new QListWidgetItem ( tr ( "	Privileges" ) );
	QListWidgetItem* storage = new QListWidgetItem ( tr ( "Access external storage devices automatically" ) );
	QListWidgetItem* admin = new QListWidgetItem ( tr ( "Administer the system" ) );
	QListWidgetItem* internet = new QListWidgetItem ( tr ( "Connect to the internet using a modem" ) );
	QListWidgetItem* logs = new QListWidgetItem ( tr ( "Monitor system logs" ) );
	QListWidgetItem* fax = new QListWidgetItem ( tr ( "Send/Receive faxes" ) );
	QListWidgetItem* cdrom = new QListWidgetItem ( tr ( "Use CD-ROM/DVD drives" ) );
	QListWidgetItem* floppy = new QListWidgetItem ( tr ( "Use floppy drives" ) );
	QListWidgetItem* scanner = new QListWidgetItem ( tr ( "Use scanners" ) );
	easyList->addItem ( header );
	
	cdrom->setIcon(QIcon("/usr/share/apps/UserManager/pics/cd.png"));
	floppy->setIcon(QIcon("/usr/share/apps/UserManager/pics/floppy.png"));
	logs->setIcon(QIcon("/usr/share/apps/UserManager/pics/log.png"));
	fax->setIcon(QIcon("/usr/share/apps/UserManager/pics/fax.png"));
	scanner->setIcon(QIcon("/usr/share/apps/UserManager/pics/scanner.png"));
	admin->setIcon(QIcon("/usr/share/apps/UserManager/pics/admin.png"));
	internet->setIcon(QIcon("/usr/share/apps/UserManager/pics/dialout.png"));
	storage->setIcon(QIcon("/usr/share/apps/UserManager/pics/storage.png"));
	
	struct group *grp;
	char **members=NULL;
	grp=getgrnam ( "adm" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( admin );
		admin->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 ) //LoginName->text() to onoma tou xrhsth
		{
			easyList->addItem ( admin );
			admin->setCheckState ( Qt::Checked );
			badmin=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "plugdev" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( storage );
		storage->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( storage );
			storage->setCheckState ( Qt::Checked );
			bstorage=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "dialout" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( internet );
		internet->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( internet );
			internet->setCheckState ( Qt::Checked );
			binternet=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "syslog" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( logs );
		logs->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( logs );
			logs->setCheckState ( Qt::Checked );
			blog=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "fax" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( fax );
		fax->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( fax );
			fax->setCheckState ( Qt::Checked );
			bfax=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "cdrom" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( cdrom );
		cdrom->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( cdrom );
			cdrom->setCheckState ( Qt::Checked );
			bcdrom=true;
			break;
		}
		members++;;
	}
}
	grp=getgrnam ( "floppy" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( floppy );
		floppy->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( floppy );
			floppy->setCheckState ( Qt::Checked );
			bfloppy=true;
			break;
		}
		members++;
	}
}
	grp=getgrnam ( "scanner" );
	if(grp!=NULL)
{
	members=grp->gr_mem;
	if ( *members==NULL )
	{
		easyList->addItem ( scanner );
		scanner->setCheckState ( Qt::Unchecked );
	}
	while ( *members )
	{
		if ( strcmp ( *members,NameLabel->text().toAscii().data() ) ==0 )
		{
			easyList->addItem ( scanner );
			scanner->setCheckState ( Qt::Checked );
			bscanner=true;
			break;
		}
		members++;
	}
}
	if ( !badmin )
	{
		easyList->addItem ( admin );
		admin->setCheckState ( Qt::Unchecked );
	}
	if ( !bstorage )
	{
		easyList->addItem ( storage );
		storage->setCheckState ( Qt::Unchecked );
	}
	if ( !bfax )
	{
		easyList->addItem ( fax );
		fax->setCheckState ( Qt::Unchecked );
	}
	if ( !binternet )
	{
		easyList->addItem ( internet );
		internet->setCheckState ( Qt::Unchecked );
	}
	if ( !bfloppy )
	{
		easyList->addItem ( floppy );
		floppy->setCheckState ( Qt::Unchecked );
	}
	if ( !bcdrom )
	{
		easyList->addItem ( cdrom );
		cdrom->setCheckState ( Qt::Unchecked );
	}
	if ( !blog )
	{
		easyList->addItem ( logs );
		logs->setCheckState ( Qt::Unchecked );
	}
	if ( !bscanner )
	{
		easyList->addItem ( scanner );
		scanner->setCheckState ( Qt::Unchecked );
	}

}

/**
 * Εμφανίζει την παραπάνω λίστα με τις βασικές ομάδες του συστήματος.
 */
void UserProperties::easyCheckboxClicked()
{
easyList->clear();
int x;
if ( easyCheckbox->isChecked() )
{
x=1;
	while ( x<316 )
	{
		userGroups->move ( x,0 );
		x=x+10;
		qApp->processEvents();
	}
	fillEasyList();
	easyList->setVisible ( true );
	easyList->setGeometry ( 0, 0, 311, 331 );

}
else
{
	x=330;
	easyList->setVisible ( false );
	while ( x>-5 )
	{
		userGroups->move ( x,0 );
		x=x-10;
		qApp->processEvents();
	}
}
}
/**
 * Προσθήκη ή αφαίρεση του χρήστη από ομάδες μέσω της λίστας βασικών ομάδων.
 */
void UserProperties::easyAddGroups ( const QModelIndex &index )
{

	Models model;
	Groups group;
	MyLibb set;
	char *cmd;
	struct group *grs;
	int done=-1;
	QVariant state = index.data(Qt::CheckStateRole);//state=2 an einai hdh checked(ara vgainei apo member o user),0 an einai unchecked (ara mpainei san member) to checkbox tou group pou path8hke
	if (state == 2)
	{
	done=0;	
	
	if ( index.data().toString() =="Access external storage devices automatically" )
	{
		QString command="addgroup " + NameLabel->text() + " plugdev";
		cmd=command.toAscii().data();
		system ( cmd );
	}
	else if ( index.data().toString() =="Administer the system" )
	{
		QString command="addgroup " + NameLabel->text() + " adm";
		cmd=command.toAscii().data();
		system ( cmd );
	}
	else if ( index.data().toString() =="Connect to the internet using a modem" )
	{
		QString command="addgroup " + NameLabel->text() + " dialout";
		cmd=command.toAscii().data();
		system ( cmd );
	}

	else if ( index.data().toString() =="Monitor system logs" )
	{
		QString command="addgroup " + NameLabel->text() + " syslog";
		cmd=command.toAscii().data();
		system ( cmd );
	}

	else if ( index.data().toString() =="Send/Receive faxes" )
	{
		QString command="addgroup " + NameLabel->text() + " fax";
		cmd=command.toAscii().data();
		system ( cmd );
	}

	else if ( index.data().toString() =="Use CD-ROM/DVD drives" )
	{
		QString command="addgroup " + NameLabel->text() + " cdrom";
		cmd=command.toAscii().data();
		system ( cmd );
	}

	else if ( index.data().toString() =="Use floppy drives" )
	{
		QString command="addgroup " + NameLabel->text() + " floppy";
		cmd=command.toAscii().data();
		system ( cmd );
	}
	else if ( index.data().toString() =="Use scanners" )
	{
		QString command="addgroup " + NameLabel->text() + " scanner";
		cmd=command.toAscii().data();
		system ( cmd );
	}
}
	else
{
	if ( index.data().toString() =="Access external storage devices automatically" )
	grs=getgrnam("plugdev");
	if ( index.data().toString() =="Administer the system" )
	grs=getgrnam("adm");
	if ( index.data().toString() =="Connect to the internet using a modem" )
	grs=getgrnam("dialout");
	if ( index.data().toString() =="Monitor system logs" )
	grs=getgrnam("syslog");
	if ( index.data().toString() =="Send/Receive faxes" )
	grs=getgrnam("fax");
	if ( index.data().toString() =="Use CD-ROM/DVD drives" )
	grs=getgrnam("cdrom");
	if ( index.data().toString() =="Use floppy drives" )
	grs=getgrnam("floppy");
	if ( index.data().toString() =="Use scanners" )
	grs=getgrnam("scanner");
	//h remove_member(grs,getOldUsername().toAscii().data()	epistrefei thn domh grs pou phre sto orisma ths vgazontas ap ta members ths ton xrhsth ton opoio pernoume apo thn  getOldUsername().toAscii().data().H epistefomenh domh mpainei san orisma sthn setgrnam gia na mpei h nea domh sto group fle.epistrefei 0 an egine h allagh
	done=set.setgrnam(group.remove_member(grs,NameLabel->text().toAscii().data()));
}
if (done==0)
{	
	system("sed -i 's/,,/,/g;s/,$//g' /etc/group");
	easyList->clear();
	fillEasyList();
	userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
	userGroups->setColumnWidth ( 0, 30);
}
}
/**
 * Η συνάρτηση αλλάζει σε έναν λογαριασμό την κύρια ομάδα.
 */
void UserProperties::setPrimaryGroup()
{
	struct group *grp=NULL;
	struct passwd *user=NULL;
	Users *usr;
	Models model;
	QString gname="";
	const char *groupname="";
	char *cmd;
	QModelIndex index=userGroups->selectionModel()->currentIndex();
	if ( index.data().toString() !="" )
	{
		groupname=index.data().toString().toAscii().data();
		grp=getgrnam ( groupname );
		gname.append ( grp->gr_name );
		user=getpwnam ( NameLabel->text().toAscii().data() );
		QString command="usermod -g " + gname  + " " + NameLabel->text() ;
		cmd=command.toAscii().data();
		system ( cmd );
		userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
		userGroups->setColumnWidth ( 0, 30 );
		primGroupLabel->setText ( usr->getPrimaryGroup ( NameLabel->text() ) );
	
	}
	}



