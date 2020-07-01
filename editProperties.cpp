#include "editProperties.h"
#include "userproperties.h"
#include "HashingAlgorithm.h"
#include "users.h"
#include "MainWindow.h"
#include "HashingFactory.h"
#include "IHashing.h"
#include <string.h>
#include <linux/limits.h>
#include "spc.h"

using namespace std;

/**
 * Constructor κλάσης με συνδέσεις signals και slots
 */

EditProperties::EditProperties ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	QValidator *validator = new QIntValidator(1, 65535, this);
	uiEdit->setValidator(validator);
	easyList->setVisible ( false );
	max->setEnabled(false);
	expire->setEnabled(false);
	warn->setEnabled(false);
	min->setEnabled(false);
	shellConnect->setAutoCompletion ( true );
	shellConnect->setEditable ( false );
	min->setSpecialValueText ( "never" );
	max->setSpecialValueText ( "never" );
	warn->setSpecialValueText ( "never" );
	expire->setSpecialValueText ( "never" );
	connect ( pass,SIGNAL ( clicked() ),this,SLOT ( openHashingAlgorithm() ) );//set_Pass_info() ) );
	connect ( edit, SIGNAL ( clicked() ), this, SLOT ( ok_to_edit_Button() ) );
	connect ( userGroups, SIGNAL ( clicked ( const QModelIndex& ) ), this, SLOT ( changeMembers ( const QModelIndex& ) ) );
	connect ( easyCheckbox, SIGNAL ( clicked() ), this, SLOT ( easyCheckboxClicked() ) );
	connect ( easyList, SIGNAL ( clicked ( const QModelIndex& ) ), this, SLOT ( easyAddGroups ( const QModelIndex& ) ) );
	connect ( makePrimBtn, SIGNAL ( clicked( ) ), this, SLOT ( setPrimaryGroup( ) ) );
	connect ( alway, SIGNAL ( clicked() ),this, SLOT ( disablechk()));
	connect ( browseBtn, SIGNAL ( clicked() ),this, SLOT ( browse()));
	connect ( requires_Pass, SIGNAL ( clicked() ),this, SLOT ( disablechk()));
	connect ( enforce_Pass, SIGNAL ( clicked() ),this, SLOT ( disablechk()));
	}

/**
 * Destructor
 */

EditProperties::~EditProperties()
{}

void EditProperties::openHashingAlgorithm()
{
HashingAlgorithm *hash = new HashingAlgorithm;
QString username = LoginName->text();
hash->NameLabelHidden->setText(username);
hash->UserNameLabel->setText("<font color='Red'>" + username + "</font>");
hash->show();
if ( hash->exec() ){}
if (hash != nullptr){ delete hash; hash = nullptr;}
}

/**
 * This function saves the username inside a private class variable.
 * Thus, we know anytime for which user the data are processed
 */

void EditProperties::setOldUsername ( QString oldUsername )
{
	oldUsername_ = oldUsername;
}
/**
 * The following function returns the saved name when called
 */
QString EditProperties::getOldUsername()
{
	return oldUsername_;
}
/**
 *This function takes the contents of the file /etc/shells which contains the available system shells
 *and inserts them inside a combobox in order to provide the option of choosing a shell for a User
 */
void EditProperties::comboShell()
{

	ifstream inShells ( "/etc/shells", ios::in );
	try {
		if ( !inShells )
			{
				QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Open file <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
			}
			//char header[30];
			std::string header;
		        inShells.seekg ( 35 );
			while ( inShells >> header )
			{
				//shellConnect->addItems ( QStringList ( QObject::tr ( header ) ) );
				shellConnect->addItems ( QStringList ( QString::fromStdString( header )  ) );
			}

	shellConnect->setDuplicatesEnabled ( false );
	} catch  (const std::ios_base::failure& e)
	{
		QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Open file <i> %1 </i> </qt> " ).arg ( e.what() ) );
	}

}

/**
 *Εκτελεί την αλλαγή των πληροφοριών του χρήστη,
 */

void EditProperties::ok_to_edit_Button()
{

if(checkBoxEdit->isChecked())
		{
			set_account(true);
		}

	if(!checkBoxEdit->isChecked())
		{
			set_account(false);
		}	

	chmod(SH_FILE,0640);
	int status;
	int res;
	struct passwd  pw;
	struct finfo  oldf;
	struct finfo  newf;

	Users user;
	char *cp = (char *)calloc(64, sizeof(char));

	QString nam = LoginName->text();
	QString ui = uiEdit->text();
	QString gid = uiEdit->text();
	QString direc = DirEdit->text();
	QString shellcon  = shellConnect->currentText();

	QByteArray di( direc.toLatin1().data() );
	QByteArray na( nam.toLatin1().data() );
	QByteArray shell( shellcon.toLatin1().data() );


    /*
	*  Security fix: Checkout if the home directory is invalid 
	*  Reference :
	*  FIO02-C. Canonicalize path names originating from tainted sources
    */

	size_t  path_size = (size_t)PATH_MAX+1;
	char *realpath_res = NULL; 
	char *canonical_path = NULL; 
	char *actualpath = NULL; 
	const size_t len = strlen( di.data() );

	if (path_size > 0) {
		canonical_path = (char*)calloc(1,path_size);

		if (canonical_path == NULL) {
   		    
	            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not calculate memory for homedir path </qt> " ) ) ;   
  		}
        else if( (strrchr( di.data(), '/') != di.data() + len) && canonical_path != NULL )
		{
		actualpath = di.data();
		realpath_res = realpath(actualpath, canonical_path);
		}
        else
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Invalid path detected  </qt> " ) ) ;
	}

	if (realpath_res == NULL ) 
	{
	       	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Invalid path  <i>  %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	}
	else
	{ 
            pw.pw_dir = realpath_res;
	}
	
	if ( canonical_path != NULL ) { free(canonical_path); canonical_path = NULL; }

	// end of security fix for homedir - consider refactoring in order to centralize security 


	uid_t userID  = ui.toInt();
	gid_t groupID = gid.toInt();

	QByteArray pass = "x";
	pw.pw_name = na.data();
	pw.pw_passwd = pass.data();
	pw.pw_uid = userID;
	pw.pw_gid = groupID;
	pw.pw_shell = shell.data();

	oldf.pw = &pw;

	QString fname   =  FullNameEdit->text();
	QString office1 =  office1Edit->text() ;
	QString office2 =  office2Edit->text() ;
	QString address =  addressEdit->text() ;
	
	QByteArray name( fname.toLatin1().data()   );
	QByteArray off1( office1.toLatin1().data() );
	QByteArray off2( office2.toLatin1().data() );
	QByteArray addr( address.toLatin1().data() );
	
	newf.username    =  na.data();
	QString emptystr = "";
	res = user.check_gecos_string( na.data() );
	if ( res < 0 )
		newf.username = emptystr.toLatin1().data();

	newf.full_name    =  name.data();
	res = user.check_gecos_string( name.data() );
	if ( res < 0 )
		newf.full_name = emptystr.toLatin1().data();

	newf.office  =  off1.data();
	res = user.check_gecos_string( off1.data() );
	if ( res < 0 )
		newf.office = emptystr.toLatin1().data();

	newf.office_phone =  off2.data();
	res = user.check_gecos_string( off2.data() );
	if ( res < 0 )
		newf.office_phone = emptystr.toLatin1().data();

	newf.home_phone   =  addr.data();
	res = user.check_gecos_string( addr.data() );
	if ( res < 0 )
		newf.home_phone = emptystr.toLatin1().data();

	user.passwd_parse(getpwuid(userID), &oldf);

	if ( !oldf.username ) {
		QMessageBox::information( 0, tr( "User Manager" ), tr( "User does not exist." ) );
		status=-1;
	}

	else
	{
		user.passwd_parse( getpwnam( newf.username ), &oldf );

		if ( ! oldf.username )
		{
			cp = newf.username;
			QMessageBox::information( 0, tr( "User Manager" ), tr( "User does not exist." ) );
			status=-1;
		}
	}
	if ( !user.set_Gecos_Data( &oldf, &newf ) )
	{
		QMessageBox::information( 0, tr( "User Manager" ), tr( "Finger information *NOT* changed." ) );
		
	}
	struct passwd *p;
	p = getpwuid(pw.pw_uid);

	if ( p != NULL ) 
		{
		status = user.save_new_info( &oldf,pw.pw_uid,pw.pw_shell );
	
		if (status != 0)
			 QMessageBox::information( 0, tr( "User Manager" ), tr( "Finger information *NOT* changed. " ) );

		}
	if(status != 1)
	this->deleteLater();
	if ( cp != nullptr) { delete cp; cp = nullptr;}
}
/**
 * Η συνάρτηση ενεργοποιεί και απενεργοποιεί συγκεκριμένα συστατικά της φόρμας
 */

void EditProperties::disablechk()
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
 *  χρησιμοποιεί την set_password και ανάλογα με τον κωδικό επιστροφής (αν είναι 0) εμφανίζει μορφοποιημένη την ημερομηνία και τον χρόνο στο δεύτερο tab της EditProperties.
 */
void EditProperties::set_Pass_info()
{
HashingAlgorithm hash;
QString name = LoginName->text();
int ret = hash.setPassword(name);

if (ret == 0)
{
checkBoxEdit->setCheckState ( Qt::Unchecked );
struct  tm *ltime;
time_t times;
char buff[256];
setlocale ( LC_ALL, "C" );
time ( &times );
ltime = localtime ( &times );
strftime ( buff,256," %A  %d  %B  %Y  %H:%M ",ltime );
datetime->setText ( buff );
}
}

/**
 *Εμφάνιση των πληροφοριών σχετικά με την λήξη των κωδικών των χρηστών στα components της φόρμας.
 */

void EditProperties::acct_shadow ( struct spwd spw )
{
	int maxim = spw.sp_max;    /* Maximum number of days between changes.  */
	if ( maxim == 99999 || spw.sp_max == -1 )
	{
		max->setValue ( 30 );
	}
	else
		max->setValue ( maxim );
	int warning = spw.sp_warn; /* Number of days to warn user to change  the password.  */
	warn->setValue ( warning );
	int minim = spw.sp_min;    /* Minimum number of days between changes.  */

	if ( minim ==  0 )
	{
		min->stepBy ( 1 );
	}
	else
		min->setValue ( minim );
	int expired = spw.sp_inact;/* Number of days the account may be  inactive.  */
	if ( expired == -1 )
	{
		expire->stepBy ( -1 );
		expire->stepBy ( -6 );
	}
	else
		expire->setValue ( expired );
}


/**
 * Η συνάρτηση επιστρέφει τον συνολικό αριθμό ημερών που ο κωδικός είναι σε ισχύ.Αν ξεπεραστεί ο αριθμός των ημερών αυτών τότε ο κωδικός λήγει.Εισάγονται οι τιμές months ,days_value kai years_value και εξάγεται η μορφή ενός αριθμού ημερών 
 */

int  EditProperties::set_shad_expire(QString months,int days_value,int years_value)
{
	struct tm newtime;
	time_t rawtime;
	time(&rawtime);	
	newtime = *localtime( &rawtime );
	newtime.tm_mday= days_value;
	newtime.tm_year= years_value - 1900 ;

	if (months == "january") 
		newtime.tm_mon = 1 - 1;
	else if(months == "February" )
		newtime.tm_mon = 2 - 1;
	else if(months ==  "March" )
		newtime.tm_mon = 3 - 1;
	else if(months ==  "April"	)
		newtime.tm_mon = 4 - 1;
	else if(months ==  "May"   )
		newtime.tm_mon = 5 - 1;
	else if(months ==  "June"	)
		newtime.tm_mon = 6 - 1;
	else if(months ==  "July"	)
		newtime.tm_mon = 7 - 1;
	else if(months ==  "August")
		newtime.tm_mon = 8 - 1;
	else if(months ==  "September")
		newtime.tm_mon = 9 - 1;
	else if(months ==  "October")
		newtime.tm_mon = 10 - 1;
	else if(months ==  "November")
		newtime.tm_mon = 11 - 1;
	else if(months ==  "December")
		newtime.tm_mon = 12 - 1;
	time_t raw;
	raw = mktime(&newtime);
	int exptime = raw / (60 * 60 * 24 );
	//int the_time = exptime;
	return exptime;
}
/**
 * Η συνάρτηση δημιουργεί έναν ενεργό η έναν ανενεργό λογαριασμό.Γενικότερα δημιουργεί μία εγγραφή για το αρχείο shadow.Ανάλογα με τις αλλαγές που θα κάνει ο χρήστης στη φόρμα EditProperties για το πρώτο και δεύτερο tab.οι ενέργειες είναι enable disable account και αλλαγές στα 4 πεδία πυ αφορούν την ηλικίωση του κωδικού . 
 */
void EditProperties::set_account ( bool set )
{
MyLibb setshadow;
struct spwd *spw;
struct spwd sp;
QString name = LoginName->text();
QByteArray thenam  = name.toLatin1();
char *nam = thenam.data();
spw = getspnam(nam);
sp = *spw;
if(!max->isEnabled() && max->value() == 30  && !warn->isEnabled() && !expire->isEnabled())
	{
	sp.sp_max = 99999;
	sp.sp_warn = warn->value();
	sp.sp_inact = expire->value();
	if(!min->isEnabled())
	{
	sp.sp_min = 0;
	min->setValue(1);
	}
	else
	sp.sp_min = min->value();
	}
	else
	{
	sp.sp_max  = max->value();
	sp.sp_warn = warn->value();
	sp.sp_inact = expire->value();
	if(!min->isEnabled())
	sp.sp_min = 0;
	else
	{
	sp.sp_min = min->value();
	min->setValue(1);
	}
	}

if( !alway->isChecked() )
sp.sp_expire = set_shad_expire(months->currentText(),days->value(),years->value());
else
sp.sp_expire = -1;

QByteArray encrypt_pass(spw->sp_pwdp);
char *encrypt = encrypt_pass.data();
string encrypting(encrypt);
char *disable;
string account = "";
QString dis = "!";

if(set == true &&  encrypting != "!" )
{
if(encrypting != "!!" && strncmp(encrypt,"!$",2))
{
disable = dis.toLatin1().data();
string dis_account(disable);
account  = dis_account + encrypting;
QString acc = account.data();
sp.sp_pwdp =  acc.toLatin1().data();
setshadow.setspnam( &sp );
}
}
else
{
if(set == false)
{
char *reverse = sp.sp_pwdp;
//αντιγράφει τα τελευτεία 34 byte του πίνακα και κάνει reverse στα πρώτα 34 byte του πίνακα ,στο τέλος αφήνει τα δύο byte (!!) 
if ( strncmp(reverse,"!!",2) == 0 && strncmp(reverse,"$1$",3) != 0)
static_cast< char * >( memmove(reverse,&reverse[2],36));
else if (strncmp(reverse,"!$",2) == 0)
static_cast< char * >( memmove(reverse,&reverse[1],36));
else if (strncmp(reverse,"!!$",3) == 0)
static_cast< char * >( memmove(reverse,&reverse[2],36));
else if(strncmp(reverse,"!", strlen(reverse)) == 0)
reverse = (char *)"";

//διαγράφει τα τελευταία 2 byte (!!)
strncpy(sp.sp_pwdp,reverse,36);

}

}
setshadow.setspnam( &sp );
}
/**
 * Adding/deleting users to/from groups
 */

void EditProperties::changeMembers ( const QModelIndex &index )
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
	//InputValidation input = new InputValidation();
	QVariant state = index.sibling(row,0).data ( Qt::CheckStateRole );//state=2 an eiani checked,0 an einai unchecked to checkbox tou xrhsth pou path8hke
	if ( state == 0 )
	{
		QString command ="usermod -a -G "  +  index.sibling(row,1).data().toString() + " " + getOldUsername() + "";//index.data().toString() periexei ton neo member kai groupNameEdit->text() to group pou 8a mpei
		cmd=command.toLatin1().data();


        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		done = ( system ( cmd ) );
	}
	else
	{
		Groups group;
		MyLibb set;
		struct group *grs;
		grs=getgrnam ( index.sibling(row,1).data().toString().toLatin1().data() );
		group.remove_member ( grs,getOldUsername().toLatin1().data() );
		if ( grs != NULL)
			done=set.setgrnam ( grs );
	}
	if ( done==0 )
	{
        // Security fix : sanitize env
        //
        //TODO
		system ( "sed -i 's/,,/,/g;s/,$//g' /etc/group" );
		userGroups->setModel ( model.createUserInGroupsModel ( getOldUsername() ) );
		userGroups->setColumnWidth ( 0, 30);
	}

	easyList->clear();
	fillEasyList();
}
}
/**
 * Συνάρτηση η οποία γεμίζει μια λίστα με βασικές ομάδες του συστήματος,στην οποία φαίνονται εύκολα τα δικαιώματα του    επιλεγμένου χρήστη.
  Μέσω αυτής της λίστας μπορούμε να δώσουμε/αφαιρέσουμε στον/από τον χρήστη βασικά δικαιώματα.
 */
void EditProperties::fillEasyList()
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

	cdrom->setIcon(QIcon("/usr/share/apps/UserManager/pics/CD.png"));
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members)) ==0 ) //LoginName->text() to onoma tou xrhsth
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members)) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members)) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members) ) ==0 )
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
		if ( strncmp ( *members,LoginName->text().toLatin1().data(), strlen(*members) ) ==0 )
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

void EditProperties::easyCheckboxClicked()
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
	easyList->setGeometry ( 0, 0, 311, 311 );

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
void EditProperties::easyAddGroups ( const QModelIndex &index )
{

	Models model;
	Groups group;
	MyLibb set;
	char *cmd;

	struct group *grs=NULL;
	int done=-1;
	QVariant state = index.data(Qt::CheckStateRole);//state=2 an einai hdh checked(ara vgainei apo member o user),0 an einai unchecked (ara mpainei san member) to checkbox tou group pou path8hke
	if (state == 2)
	{
	done=0;	
	
	if ( index.data().toString() =="Access external storage devices automatically" )
	{
		QString command="addgroup " + getOldUsername() + " plugdev";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input and env
        //
        //TODO
		system ( cmd );
	}
	else if ( index.data().toString() =="Administer the system" )
	{
		QString command="addgroup " + getOldUsername() + " adm" + " > /dev/null 2>&1";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input and env
        //
        //TODO
		system ( cmd );
	}
	else if ( index.data().toString() =="Connect to the internet using a modem" )
	{
		QString command="addgroup " + getOldUsername() + " dialout" + " > /dev/null 2>&1";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		system ( cmd );
	}

	else if ( index.data().toString() =="Monitor system logs" )
	{
		QString command="addgroup " + getOldUsername() + " syslog";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		system ( cmd );
	}

	else if ( index.data().toString() =="Send/Receive faxes" )
	{
		QString command="addgroup " + getOldUsername() + " fax" + " > /dev/null 2>&1";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		system ( cmd );
	}

	else if ( index.data().toString() =="Use CD-ROM/DVD drives" )
	{
		QString command="addgroup " + getOldUsername() + " cdrom";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		system ( cmd );
	}

	else if ( index.data().toString() =="Use floppy drives" )
	{
		QString command="addgroup " + getOldUsername() + " floppy";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
		system ( cmd );
	}
	else if ( index.data().toString() =="Use scanners" )
	{
		QString command="addgroup " + getOldUsername() + " scanner";
		cmd=command.toLatin1().data();
        // Security fix : change system with execve or execl and sanitize input ane env
        //
        //TODO
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
	//h remove_member(grs,getOldUsername().toLatin1().data()	epistrefei thn domh grs pou phre sto orisma ths vgazontas ap ta members ths grs ton xrhsth ton opoio pernoume apo thn  getOldUsername().toLatin1().data().H epistefomenh domh mpainei san orisma sthn setgrnam gia na mpei h nea domh sto group fle.epistrefei 0 an egine h allagh
	if ( grs != NULL)
	done=set.setgrnam(group.remove_member(grs,getOldUsername().toLatin1().data()));
}
if (done==0)
{	
	system("sed -i 's/,,/,/g;s/,$//g' /etc/group");
	easyList->clear();
	fillEasyList();
	userGroups->setModel ( model.createUserInGroupsModel ( getOldUsername() ) );
	userGroups->setColumnWidth ( 0, 30);
}
}
/**
 * Η συνάρτηση αλλάζει σε έναν λογαριασμό την κύρια ομάδα.
 */
void EditProperties::setPrimaryGroup()
{
	struct group *grp=NULL;
	Users *usr = new Users();
	Models model;
	QString gname="";
	const char *groupname="";
	char *cmd;
	QModelIndexList indexes = userGroups->selectionModel()->selectedIndexes();
	foreach ( QModelIndex index, indexes )
	{	if(index.data().toString()!="")
		{		groupname=index.data().toString().toLatin1().data();
				grp=getgrnam ( groupname );
				gname.append ( grp->gr_name );
				QString command="usermod -g " + gname  + " " + LoginName->text() ;
				cmd=command.toLatin1().data();
				system(cmd);
				userGroups->setModel ( model.createUserInGroupsModel (  LoginName->text() ) );
				userGroups->setColumnWidth ( 0, 30);
				primGroupLabel->setText(usr->getPrimaryGroup(LoginName->text()));
		}
	}
	if (usr != nullptr){ delete usr; usr = nullptr;}
}
/**
 * Περιήγηση στον προσωπικό φάκελο του επιλεγμένου χρήστη. 
 */
void EditProperties::browse()

{
QFileDialog::getOpenFileName(this,
       tr("Browse home folder"),DirEdit->text(), tr("AnyFile"));
}
