#include "userproperties.h"
#include "editProperties.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include "HashingFactory.h"
#include "IHashing.h"
#include "HashingAlgorithm.h"
#include "spc.h"
#include <string.h>

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
	passBtn->setEnabled(false);
	shellConnect->setAutoCompletion ( true );
	tabWidget->setTabEnabled(2,false);
	expire->setSpecialValueText("never");
	expire->stepBy(-1);
	warn->setSpecialValueText ( "never" );
	warn->stepBy(-1);
	ok->setVisible(false);
	connect ( add, SIGNAL ( clicked() ), this, SLOT ( addUserBase() ) );
	connect ( passBtn ,SIGNAL ( clicked() ),this,SLOT ( openHashingAlgorithm() ) );
	connect( userGroups, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( changeMembers(const QModelIndex& )));
	connect( easyCheckbox, SIGNAL( clicked() ), this, SLOT( easyCheckboxClicked() ) );
	connect( easyList, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( easyAddGroups(const QModelIndex& )));
	connect ( requires_Pass, SIGNAL ( clicked() ),this, SLOT ( setFormContents()));
	connect ( enforce_Pass, SIGNAL ( clicked() ),this, SLOT  ( setFormContents()));
	connect ( alway, SIGNAL ( clicked() ),this, SLOT ( setFormContents()));
	connect ( makePrimBtn, SIGNAL ( clicked( ) ), this, SLOT ( setPrimaryGroup( ) ) );
}	
/**
* UserProperties Class destractor 
*/
UserProperties::~UserProperties()
{}

/**
 * Execute the Widget that will be used to check the hashing algorithm used when generating the password 
 */
void UserProperties::openHashingAlgorithm()
{
HashingAlgorithm *hash = new HashingAlgorithm;
QString username = NameLabel->text();
hash->NameLabelHidden->setText(username);
hash->UserNameLabel->setText("<font color='Red'>" + username + "</font>");
hash->show();
if ( hash->exec() ){}
delete hash;

}

/**
*Συνάρτηση που θέτει σε εμφανή ή μη εμφανή τα συστατικά της φόρμας σε διαφορετικές περιπτώσεις
*/
void UserProperties::setFormContents()
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
	std::string header;
        inShells.seekg ( 35 );
	while ( inShells >> header )
	{
		shellConnect->addItems ( QStringList ( QString::fromStdString( header )  ) );
        }
	
	shellConnect->setItemText (0, "/bin/bash" );
	shellConnect->setDuplicatesEnabled ( false );

}
/**
 *
 * This function searches the /etc/passwd file in order to find the next available uid in order to be assigned to
 * the new user. The initial uid value taken from the configuration provided by the user through the Settings class
 *
 */
int UserProperties::setPasswdUID()
{
    struct passwd pwd ;
    struct passwd *result ;

    size_t pwdlen;

    pwdlen = sysconf(_SC_GETPW_R_SIZE_MAX);
        if (pwdlen == (size_t)-1)
            pwdlen = 16384;

    char *pwdBuffer = (char*)malloc(pwdlen);
    memset( pwdBuffer, 0, sizeof(char) );

	Settings settings;
    int uid;
    int  max = 65535;
	const char  *file = "/etc/passwd";
	FILE  *fp;

	fp = fopen ( file, "r" );

    uid = atoi(settings.getconf("MINIMUM_UID").c_str());
    int actual_uid = uid;

	if ( !fp ) { return 0; }

    for ( int i=uid ; i < max; ++i )
    {
        if(getpwuid_r ( (uid_t)i, &pwd, pwdBuffer, pwdlen, &result ) == 0)
        {
            if (result == NULL)
                break;
            else
                actual_uid++;
        }
    }

    fclose(fp);

    free(pwdBuffer);

return actual_uid;
}
/**
*Η συνάρτηση εισάγει στο αρχείο /etc/passwd μια ολοκληρωμένη εγγραφή με όλα τα πεδία της δομής passwd 
*Ο νέος χρήστης  εισάγεται στο σύστημα με όλες τις πληροφορίες στα πεδία της δομής χωρισμένα με ανω κατω τελεια
* 
*/
int UserProperties::insertIntoPasswdFile ( QString nam,QString uid,QString gid,QString directory,QString gec, QString shellcon )
{
	MyLibb *fchk = new MyLibb();
	int done = 0 ;
	QString pass = "x";
	QByteArray name ( nam.toLatin1().data() );
	QByteArray gecos ( gec.toLatin1().data() );
	QByteArray dir ( directory.toLatin1().data() );
	QByteArray shell ( shellcon.toLatin1().data() );
	uid_t userID  = uid.toInt();
	gid_t groupID = gid.toInt();
	struct passwd  us;
	
	us.pw_name   =  name.data();
	us.pw_passwd =  pass.toLatin1().data();
	us.pw_uid    =  userID;
	us.pw_gid    =  groupID;
	us.pw_gecos  =  gecos.data();
	us.pw_dir    =  dir.data();
	us.pw_shell  =  shell.data();
	
	const char *filename  = PASSWD_FILE;
	
	FILE *fp;
	fp = fopen ( filename, "a+" );
	if ( fp != NULL )
	{
		done = putpwent ( &us , fp );
		fclose ( fp );
	}
	delete fchk;
	fchk = nullptr;
	return done;

}
/**
*Συνάρτηση που εισάγει group στο αρχείο /etc/group 
*/
int UserProperties::insertIntoGroupFile ( QString nam,QString gid )
{
	MyLibb *fchk = new MyLibb();
	int def;
	QString pass = "x";
	Groups *groupie {new Groups()};
	QByteArray name ( nam.toLatin1().data() );
	gid_t groupID = gid.toInt();
	struct group grp;
	grp.gr_name = name.data() ;
	grp.gr_passwd = pass.toLatin1().data();
	grp.gr_gid = groupID  ;
	grp.gr_mem = NULL;
	FILE *groupbase;

	const char *filename1 = GROUP_FILE;
	int res = 0;
	groupbase = fchk->fopen_wrapper ( filename1, "a+" );
	if ( groupbase!=NULL )
	{
		res = putgrent ( &grp, groupbase );
		fclose ( groupbase );
	}
	def = groupie->default_groups ( nam );
	if ( def== -1 ) res = -1;

	delete fchk;
	fchk = nullptr ;
	delete groupie;
	groupie = nullptr;
	return res;
}
/**
*Η συνάρτηση δίνει τιμές στα πεδία του του shadow struct που αφορούν τις επισημάνσεις για το χρόνο λειτουργίας του *κρυπτογραφημένου password ,καθώς έπίσης εισάγει στη δομή και τον κρυπτογραφημένο κωδικό με το όνομα του χρήστη.Επιστρέφει έναν δείκτη σε δομή struct spwd.
*
*/
struct spwd  UserProperties::setShadowStruct(int max, int warn,int inact, int min,string inact_user,char * name,char * password_hash,int current_days)
{
struct spwd sp;
sp.sp_namp = name;
sp.sp_pwdp = password_hash;
sp.sp_lstchg = current_days;

EditProperties *edit {new EditProperties()};
			
            if( !requires_Pass->isChecked())
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

            if(!alway->isChecked()) //this is where the password expires..
				sp.sp_expire = edit->set_shad_expire(months->currentText(),days->value(),years->value());
			else
			{
				sp.sp_expire = -1;
				expire->setValue(0);
			}
				sp.sp_flag = -1;
delete edit ;
edit = nullptr;
return sp;

}
/**
*Η συνάρτηση εισάγει στο αρχείο shadow τις τιμές όλων τών πεδίων του shadow struct.Το πεδίο του password συμπληρώνεται ανάλογα με το αν είναι ενεργός λογαριασμός ή όχι (έλεγχος απο τη φόρμα).Χρησιμποιει την συνάρτηση set_posix () για την εισαγωγή στα πεδία του shadow struct
*/
int UserProperties::insertIntoShadowFile ( QString logname,QString encrypted_pass )
{
	int ret = 0;
	struct spwd spw;
	int curdays = time ( NULL ) / ( 60 * 60 * 24 );
	
	QByteArray name ( logname.toLatin1().data() );
		
	QString mini = min->cleanText();
	string minim = mini.toLatin1().data();
	
	QString maxi = max->cleanText();
	string maximum = maxi.toLatin1().data();
		
	QString inaction = expire->cleanText();
	string inactuser = inaction.toLatin1().data();
	
	QString warning = warn->cleanText();
	string warn_pass = warning.toLatin1().data();
	
	char *encrypt = encrypted_pass.toLatin1().data();

	if( !checkBox->isChecked() && encrypted_pass != "" )
		{		
		spw = setShadowStruct(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),encrypted_pass.toLatin1().data(),curdays );
		}			
	else if ( checkBox->isChecked() && encrypted_pass == "" )
		{
		spw = setShadowStruct(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),(char *)"!",0 );
		}
	else if ( !checkBox->isChecked() && encrypted_pass == "" )
		{
		spw = setShadowStruct(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),(char *)"",0 );
		
		}
	else if(checkBox->isChecked() && encrypted_pass != "" )
	{
		char *disable;
		string encrypting(encrypt);	
		QString dis = "!";
		disable = dis.toLatin1().data();
		string dis_account(disable);
		string account = "";
		account  = dis_account +  encrypting;
		QString acc = account.data();
		spw = setShadowStruct(atoi ( maximum.c_str() ),atoi(warn_pass.c_str()),atoi ( inactuser.c_str() ),atoi ( minim.c_str() ),inactuser,name.data(),acc.toLatin1().data(),curdays);
		}

	setspent();
	FILE *shadowbase;
	const char *sh_file = SHADOW_FILE;
	
	MyLibb *fchk { new MyLibb};
	shadowbase = fchk->fopen_wrapper ( sh_file, "a+" );
	if ( shadowbase!=NULL )
	{
		//insert shadow struct into shadow file
		ret = putspent ( &spw, shadowbase );
		fclose ( shadowbase );
	}
	//shadow file change privileges
	chmod(SHADOW_FILE,0640);
	struct group *grp;
	grp = getgrnam("shadow");
	chown (SHADOW_FILE , (uid_t)0 ,(gid_t)grp->gr_gid);
	endspent();

	delete fchk ;
	fchk = nullptr;
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
	
	int pass_done = 0;
	int pid;
	int pid1;
	int pid2;
	int group_done = 0 ;
	int shadow_done = 0 ;
	QString nam = NameLabel->text();
	QString uid = uidEdit->text();

    struct passwd pwd ;
    struct passwd *result ;

    size_t pwdlen;

    pwdlen = sysconf(_SC_GETPW_R_SIZE_MAX);
        if (pwdlen == (size_t)-1)
            pwdlen = 16384;

    char *pwdBuffer = (char*)malloc(pwdlen);
    memset( pwdBuffer, 0, sizeof(char) );

	gid_t ui = uid.toInt();
    int free_gid  = grp.groupSearch(ui);
	QString gid =  gid.number(free_gid);
	QString gec = "";

    QRegExp rx;
    rx.setPattern( "[%+{}#\\[^:;\\.*?\"<>|\\]*$]+");

    QRegExpValidator *v = new QRegExpValidator(rx,0);
    HomeDirEdit->setValidator(v);

    if (HomeDirEdit->text().contains(rx))
        QMessageBox::information ( 0,tr ( "User Manager" ),tr ( " Home Directory contains invalid characters " ));
    else{

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
        if(getpwuid_r ( (uid_t)userID, &pwd, pwdBuffer, pwdlen, &result ) == 0)
        {
            if (result == NULL)
            {
			pass_done = insertIntoPasswdFile ( nam,uid,gid,directory,gec,shellcon );
			group_done = insertIntoGroupFile ( nam,gid );
			shadow_done = insertIntoShadowFile ( nam,passhash );	
            }
            else
            {
            QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "UID %1 already exists " ).arg(uid) );
            userExists=true;
            }
        }
        else
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "Could not read /etc/passwd - %1" ).arg(errno) );

		if ( ( pass_done == 0 ) && ( group_done == 0 ) && ( shadow_done == 0 ) )
        {
            Spc *spc = new Spc();

            int n_index = HomeDirEdit->text().length()+1;

            char cli_sanitized_path[n_index] ;

            strncpy( cli_sanitized_path, directory.toUtf8().data(), (size_t) n_index);

            if (n_index > 0)
                cli_sanitized_path[n_index - 1] = '\0';


            mkdir ( cli_sanitized_path,X_OK );
            chmod ( cli_sanitized_path,0700 );
            chown ( cli_sanitized_path, ( uid_t ) userID, ( gid_t ) groupID );

            spc->clenv();  // Security : clear the environment

            // read the environment



            char *const arr[] =  { "cp", "-l", "-p", "/etc/skel/.bash_logout", cli_sanitized_path, NULL };


			pid  = fork();
			if ( pid == 0 ) //parent process
			{
                // clear environment resotinrg the system default

                // Security fix: change execl with execv or implement QProcess - Critical
                if (execv("/bin/cp", arr ) == -1)
				{
                    QMessageBox::information ( this,tr ( "User Manager" ),tr ("copy %1 failed" ).arg ( cli_sanitized_path ) );
				}
					
                //int status;
                //waitpid(pid,&status,0);
			}

			pid1 = fork();
			if ( pid1 == 0 ) //child process 1
			{
                spc->clenv(); // clear environment restoring the system default

                // Security fix: change execl with execv or implement QProcess - Critical
                if (execl("/bin/cp", "-i", "-p", "/etc/skel/.bashrc", cli_sanitized_path ,(char*)0) == -1)
				{

                    QMessageBox::information ( this,tr ( "User Manager" ),tr ("copy %1 failed" ).arg ( cli_sanitized_path ) );
				}
			
				int status1;
				waitpid(pid1,&status1,0);
			}
	
			pid2 = fork();
			if ( pid2 == 0 ) // child process 2
			{
                // Security fix: change execl with execv or implement QProcess - Critical
                if (execl("/bin/cp", "-i", "-p", "/etc/skel/.profile", cli_sanitized_path, (char*)0) == -1 )
				{

                    QMessageBox::information ( this,tr ( "User Manager" ),tr ("copy %1 failed" ).arg ( cli_sanitized_path ) );
				}
				
				int status2;
				waitpid(pid2,&status2,0);
			}
			
            // deletes the previous passwd backup file
			unlink(PASSWD_FILE".bak");

            //creates a new passwd backup file
			link ( PASSWD_FILE, PASSWD_FILE".bak" );

            //deletes the previous group backup file
			unlink ( GROUP_FILE".bak" );

            //creates a new group backup file
			link ( GROUP_FILE,GROUP_FILE".bak" );

            // deletes the previous shadow backup file
			unlink ( SHADOW_FILE".bak" );

            // creates a new shadow backup file
			link ( SHADOW_FILE,SHADOW_FILE".bak" );

			
			QMessageBox::information ( this,tr ( "User Manager" ),tr ( " User %1 Inserted succesfully!!" ).arg ( nam ) );
			passBtn->setEnabled(true);


            delete spc;
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
	Users *usr{ new Users()};
	Models *model{ new Models()};
	add->setVisible(false);
	closeBtn->setVisible(false);
	ok->setVisible(true);
	tabWidget->setTabEnabled(2,true);
	primGroupLabel->setText ( usr->getPrimaryGroup ( nam ) );
	userGroups->setModel(model->createUserInGroupsModel(nam));
	userGroups->setColumnWidth ( 0, 30);
	fillEasyList();
	delete usr ;
	usr  = nullptr;
	delete model ;
	model = nullptr;

}

  }

}

/**
 * Adding/deleting users to/from groups
 */

void UserProperties::changeMembers ( const QModelIndex &index )
{
	int col=index.column();
	Spc *spc = new Spc();
	int row=index.row();
	QString test = index.sibling(row,1).data().toString();

    if(col==0 && test!="")
	{
	Models model;
	int done=1;
	int row=index.row();
	QVariant state = index.sibling(row,0).data ( Qt::CheckStateRole ); 
	if ( state == 0 )
	{
		QString fromindex = index.sibling(row,1).data().toString();

        std::string from_index = fromindex.toUtf8().constData();

		spc->spc_sanitize(from_index); 
		QString sanitized_index = QString::fromStdString(from_index);

		QString fromLabel = NameLabel->text(); 
		std::string from_Label = fromLabel.toUtf8().constData();

		spc->spc_sanitize(from_Label);
		QString sanitized_NameLabel = QString::fromStdString(from_Label);



          //usermod_execve(fromindex, fromLabel);

          char* cli_sanitized_index = sanitized_index.toLatin1().data();
          char* cli_sanitized_label = sanitized_NameLabel.toLatin1().data();

          QProcess process;
          QString program = "/usr/sbin/usermod";
          QStringList arguments;

          arguments << "-a" << "-G" << cli_sanitized_index << cli_sanitized_label ;

          process.start(program, arguments);
          process.waitForStarted();
          process.waitForFinished();

          arguments.clear();

	}
	else
	{
		Groups group;
		MyLibb set;
		struct group *grs;
		grs=getgrnam ( index.sibling(row,1).data().toString().toLatin1().data() );
		group.remove_member ( grs,NameLabel->text().toLatin1().data() );
		done=set.setgrnam ( grs );
	}
	if ( done==0 )
	{
		/*
		* Security fix :  
	 	* 	The environment is cleared by clearenv(), and then the PATH and IFS
	 	* 	variables are set to safe values before system() is invoked.
	 	* Reference : ENV03-C. Sanitize the environment when invoking external programs 
	 	*/
		spc->clenv(); 
		system ( "sed -i 's/,,/,/g;s/,$//g' /etc/group" );
		userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
		userGroups->setColumnWidth ( 0, 30);
	}

	easyList->clear();
	fillEasyList();
	delete spc;
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
		if ( strncmp ( *members, NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 ) //LoginName->text() to onoma tou xrhsth
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
		if ( strncmp ( *members, NameLabel->text().toLatin1().data(), strlen(*members)) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,NameLabel->text().toLatin1().data(),strlen(*members)) ==0 )
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

void UserProperties::usermod_execve(QString index, QString label)
{
    pid_t pid;
    int status;

    Spc *spc = new Spc();

    std::string from_Label = label.toUtf8().constData();
    std::string from_index = index.toUtf8().constData();

    spc->spc_sanitize(from_Label);
    spc->spc_sanitize(from_index);

    QString sanitized_NameLabel = QString::fromStdString(from_Label);
    QString sanitized_index = QString::fromStdString(from_index);

    QString arg = " -a -G " + sanitized_index + " " + sanitized_NameLabel + "";
    std::string arguments = arg.toUtf8().constData();
    int n_index = arguments.length()+1;

    char argv[n_index];

    strncpy( argv, arguments.c_str(), (size_t) n_index);

    if (n_index > 0)
        argv[n_index - 1] = '\0';

    char *const args[3] = {(char*)"/usr/sbin/usermod " ,argv ,NULL};

    pid = fork();

    if (pid == -1){
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> can't fork, error occured <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    }
    else if (pid == 0)
    {
        if (execv("/usr/sbin/usermod ", args) == -1)
        {
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Cannot run usermod  <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
        }
    }
   else
    {
        if (waitpid(pid, &status, 0) > 0)
           {
                 if (WIFEXITED(status) && WEXITSTATUS(status)) {
                   if (WEXITSTATUS(status) == 127) {
                    //     execv failed
                       QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> execv failed  <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
                    }
                }
            }
            else {
               // waitpid() failed
               QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> waitpid() failed  <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
            }
   }
}


/**
 * @brief UserProperties::addGroup adds a new group into /etc/group
 * @param label
 * @param group
 *
 */

void UserProperties::addGroup(QString label, char* group)
{
    Spc *spc = new Spc();
    QString fromLabel = label;
    std::string from_Label = fromLabel.toUtf8().constData();

    spc->spc_sanitize(from_Label);
    QString sanitized_NameLabel = QString::fromStdString(from_Label);
    char* cli_sanitized_label = sanitized_NameLabel.toLatin1().data();

    QProcess process;
    QString program = "/usr/sbin/addgroup";
    QStringList arguments;

    arguments << "-a" <<  "-G" << cli_sanitized_label << group ;

    process.start(program, arguments);
    process.waitForStarted();
    process.waitForFinished();

    arguments.clear();

    delete spc;

}
/**
 * Adding or removing a user from groups from the list of the basic groups
 */
void UserProperties::easyAddGroups ( const QModelIndex &index )
{

	Models model;
	Groups group;
	MyLibb set;
	struct group *grs = {};
	int done=-1;
    // check the state if it is checked means that the user will be removed from the list
    QVariant state = index.data(Qt::CheckStateRole);
	if (state == 2)
	{
	done=0;	

	
	if ( index.data().toString() =="Access external storage devices automatically" )
	{		
        addGroup(NameLabel->text(), (char*)" plugdev");
    }
	else if ( index.data().toString() =="Administer the system" )
	{
        addGroup(NameLabel->text(), (char*)" adm");
	}
	else if ( index.data().toString() =="Connect to the internet using a modem" )
	{
        addGroup(NameLabel->text(), (char*)" dialout");

	}

	else if ( index.data().toString() =="Monitor system logs" )
	{
         addGroup(NameLabel->text(), (char*)" syslog");
	}

	else if ( index.data().toString() =="Send/Receive faxes" )
	{

         addGroup(NameLabel->text(), (char*)" fax");
	}

	else if ( index.data().toString() =="Use CD-ROM/DVD drives" )
	{

         addGroup(NameLabel->text(), (char*)" cdrom");

	}

	else if ( index.data().toString() =="Use floppy drives" )
	{

         addGroup(NameLabel->text(), (char*)" floppy");

	}
	else if ( index.data().toString() =="Use scanners" )
	{

         addGroup(NameLabel->text(), (char*)" Use scanners");
	}
}
	else
{
	if ( index.data().toString() =="Access external storage devices automatically" )
	grs=getgrnam("plugdev");
	if ( index.data().toString() =="Administer the system" )
	grs=getgrnam("adm");
	if ( index.data().toString() =="Connect to the internet" )
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
	
	done=set.setgrnam(group.remove_member(grs,NameLabel->text().toLatin1().data()));
}
if (done==0)
{	
	/*
	 * Security fix :  
	 * 	The environment is cleared by clearenv(), and then the PATH and IFS
	 * 	variables are set to safe values before system() is invoked.
	 * Reference : ENV03-C. Sanitize the environment when invoking external programs
	 */
    Spc *spc = new Spc();

    spc->clenv(); // clear the environment
	system("sed -i 's/,,/,/g;s/,$//g' /etc/group");

	easyList->clear();
	fillEasyList();
	userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
	userGroups->setColumnWidth ( 0, 30);
	delete spc; 
}
}

/**
 * This function changes the primary group
 */
void UserProperties::setPrimaryGroup()
{
	struct group *grp;

	Users *usr { new Users };
	Models model;
	QString gname="";
	const char *groupname="";

	QModelIndex index=userGroups->selectionModel()->currentIndex();
	if ( index.data().toString() !="" )
	{
		groupname=index.data().toString().toLatin1().data();
		grp=getgrnam ( groupname );
		gname.append ( grp->gr_name );

        QProcess process;
        QString program = "/usr/sbin/usermod";
        QStringList arguments;

        arguments << "-g" << gname << NameLabel->text() ;

        process.start(program, arguments);
        process.waitForStarted();
        process.waitForFinished();

        arguments.clear();

		userGroups->setModel ( model.createUserInGroupsModel ( NameLabel->text() ) );
		userGroups->setColumnWidth ( 0, 30 );
		primGroupLabel->setText ( usr->getPrimaryGroup ( NameLabel->text() ) );
	
	}
	delete usr;
	usr = nullptr ;
	}



