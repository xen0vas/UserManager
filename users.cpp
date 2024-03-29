#include "users.h"
#include <QtWidgets>
#include "myLibb.h"
#define MAX_FIELD_SIZE          256

using std::string;
/**
 * Constructor κλάσης.
 */
Users::Users()
{}
/**
 * Destructor κλάσης.
 */
Users::~Users()
{}
/**
 * Αναζήτηση ενός χρήστη στο σύστημα.Η συνάρτηση αναζητεί ένα χρήστη στο σύστημα και αν βρεθέι επιστρέφει την δομή του.
 */
struct passwd *Users::searchUser()
{
	bool okBtn;
	char *userToSearch ;

	struct passwd *result = NULL;
	QString userString = QInputDialog::getText( 0, QObject::tr( "Search" ), QObject::tr( "Enter Login Name:(case sensitive)" ), QLineEdit::Normal, QString( "" ), &okBtn );

	if ( okBtn && userString != " " )
	{
		userToSearch = userString.toLatin1().data();
		result = getpwnam( userToSearch );
		if ( result == NULL )
		{
			QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "User %1 not found" ).arg( userString ) );
		}
	}
	return result;
}
/**
 * Ψάχνει να βρει αν υπάρχει ένας συγκεκριμένος χρήστης στο σύστημα.Επιστρέφει true σν βρεθεί διαφορετικά επιστρέφει false.
 */
bool Users::userExists( QString name )
{
	struct passwd *user;
	user = getpwnam( name.toLatin1().data() );
	if ( user != NULL )
	{
		QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "User Exists!! " ) );
		return true;
	}
	else
		return false;
}

/**
 * Searches for the main group of a certain user. It takes the UID as an argument and then searches the
 * group structure to find the user's group using the group id
 *
 */
QString Users::getUsersPrimaryGroup( QString UID )
{
	struct passwd pwd;
	struct passwd *result; 
    struct group *group = {};
    size_t pwdlen;
    QString groupName="";

    QByteArray pwuid = UID.toLatin1();

    size_t size = strlen(pwuid.data());

    char *pwuid_t = (char*)calloc(size, sizeof(char));

    if (pwuid_t != NULL)
    {

    strncpy(pwuid_t, pwuid.data(), strlen(pwuid.data()));

    pwdlen = sysconf(_SC_GETPW_R_SIZE_MAX);
    if (pwdlen == (size_t)-1)
        pwdlen = 16384;

    char *pwdBuffer = (char*)malloc(pwdlen);

	memset( pwdBuffer, 0, sizeof(char) ); 

    setgrent();
    if ((getpwuid_r(atoi(pwuid_t), &pwd, pwdBuffer, pwdlen, &result)) == 0 )
    {
        group = getgrgid( pwd.pw_gid );
    }
    if (group!=NULL)
            groupName = QString::fromUtf8( group->gr_name );
        else
        	QMessageBox::critical( 0, QObject::tr( "User Manager" ), QObject::tr( "No group entry for user %1 in /etc/group" ).arg(pwd.pw_name) );
    endgrent();
	if ( pwuid_t != NULL ) { free(pwuid_t) ; pwuid_t = NULL; }   
	if ( pwdBuffer != NULL ) { free(pwdBuffer); pwdBuffer = NULL; }
    }
    else
    {
        errno = ENOMEM;
        QMessageBox::critical( 0, QObject::tr( "User Manager" ), QObject::tr("Bad memory allocation : %1 ").arg(errno));
    }
	return groupName;
}

/**
 *
 * The following function searches the groups that the user is member taking as a parameter the name of the user
 *
 */

QString Users::getUsersSecondaryGroups( QString name )
{
	struct group *group;
	setgrent();
	QString listGroup;
	QByteArray nameArray = name.toLatin1();
	const char *userChar = nameArray.data();
	
	char **members;
    members = (char**)malloc(sizeof(char*));
    memset(&members, 0, sizeof(members));
	while (( group = getgrent() ) != NULL )
	{
		for ( members = group->gr_mem; *members; members++ )
			if ( strncmp( *members, userChar, strlen(*members) ) == 0 )
			{
				listGroup.append( group->gr_name );
				listGroup.append( "," );
			}
	}
        listGroup.chop(1);
	endgrent();
	free(*members); 
	return listGroup;
}
/**
 * Η συνάρτηση σαρώνει μια μια τις εγγραφές από το /etc/shadow και ψάχνει να βρει αν ένας λογαριασμός είναι κλειδωμένος.
 * Για να θεωρηθεί κλειδωμένος ένας λογαριασμός πρέπει το δεύτερο πεδίο της εγγραφής το οποίο είναι ο κρυπτογραφημένος κωδικός  να έχι ένα ! ή *
 * Επιστρέφει true αν ο λογαριασμός είναι κλειδωμένος και false αν δεν είναι.
 */
bool Users::isLocked( QString user )
{
	
	struct spwd   *sp;
	int sp_size = sizeof(sp->sp_pwdp);
	bool lock = false;
	QByteArray userArray = user.toLatin1();
	const char *userChar = userArray.data();
	setspent();
	
	sp = getspnam( userChar );
	if(sp != NULL)
	{
	if ( strncmp( sp->sp_pwdp, "!",1 ) == 0 || strncmp( sp->sp_pwdp, "*" , sp_size) == 0 )
		lock = true;
	}
	else lock = false;

	endspent();
	
return lock;

}	

/**
 * Η συνάρτηση παρακολουθεί το gecos αν ξεπερνάει το μέγεθος των 256 bytes σε περίπτωση που  το ξεπερνάει εμφανιζεται στην οθόνη το κατάλληλο μήνυμα λάθους
 * Επίσης ελέγχει για τους χαρακτήρες [, : = " \n] και σε περίπτωση που βρεθούν επιστρέφει -1 (κωδικό λάθους)
 */

int Users::check_gecos_string( char *gecos )
{
	int i, c;
	if ( strlen( gecos ) > MAX_FIELD_SIZE )
	{
		QMessageBox::information( 0, tr( "User Manager" ), tr( "field is too long" ) );
		return -1;
	}
	int p = strlen( gecos );
	for ( i = 0; i < p; i++ )
	{
		c = gecos[i];
		if ( c == ',' || c == ':' || c == '=' || c == '"' || c == '\n' )
			return -1;
		if ( iscntrl( c ) )
			return -1;
	}
	return ( 0 );
}

/**
 * Η συνάρτηση χρησιμοποιείται για να συνδεθούν τα δεδομένα της δομής finfo (που αφορά τη δημιουργία gecos)και τής εκάστοτε  δομής passwd για περεταίρω επεξεργασία.Αυτο που γίνεται στη συνάρτηση είναι πως με τη σύνδεση της δομής finfo με την passwd αντιστοιχίζεται το gecos  με τα δεδομένα της passwd του κάθε χρήστη. 
 */
int Users::passwd_parse( struct passwd *pw, struct finfo *pinfo )
{
	char *gecos;
	char *cp;
	if ( pw )
	{
		pinfo->pw = pw;
		pinfo->username = pw->pw_name;
		gecos = strdup( pw->pw_gecos );
		cp = gecos;
		pinfo->full_name = cp;
		cp = strchr( cp, ',' );
		if ( cp )
		{
			*cp = 0, cp++;
		}
		else
		{
			return 2;
		}
		pinfo->office = cp;
		cp = strchr( cp, ',' );
		
		if ( cp )
		{
			*cp = 0, cp++;
		}
		else
		{
			return 3;
		}
		
		pinfo->office_phone = cp;
		cp = strchr( cp, ',' );
		
		if ( cp )
		{
			*cp = 0, cp++;
		}
		else
			return 4;
		pinfo->home_phone = cp;
		return 1;
	}
	return 0;
}
/**
* Η συνάρτηση θέτει τις νέες εγγραφές newfn στις παλιές oldfn της δομής finfo η οποία τροποποιεί τα πεδία 
* της finfo που αφορούν τις πληροφορίες gecos 
*/
bool Users::set_Gecos_Data( struct finfo *oldfn , struct finfo *newfn )
{
	bool changed = false;
	if ( newfn->full_name )
	{
		oldfn->full_name = newfn->full_name;
		changed = true;
	}
	if ( newfn->office )
	{
		oldfn->office = newfn->office;
		changed = true;
	}
	if ( newfn->office_phone )
	{
		oldfn->office_phone = newfn->office_phone;
		changed = true;
	}
	if ( newfn->home_phone )
	{
		oldfn->home_phone = newfn->home_phone;
		changed = true;
	}
	return changed;
}
 /**
 * Διαγραφή ενός χρήστη εισάγοντας έναν NULL pointer στην δομή passwd και χρησιμοποιώντας την 
 setpwnam.σαρώνοντας έναν έναν τους χρήστες στο αρχείο ωστε να βρεθεί η  σωστη εγγραφή που θα πρέπει να διαγραφεί
σε περίπτωση επιτυχούς κλήσης και διαγραφής η συνάρτηση επιστρέφει 0 και σε περίπτωση αποτυχιας -1
 */
int  Users::rm_pwUser(QString name)
{
MyLibb lib;
struct passwd *pw = NULL;
char *nam = name.toLatin1().data();
if(lib.setpwnam_r(pw,nam)<0)
return -1;
else
return 0;
}

/**
 * Η συνάρτηση χρησιμοποιείται για να αποθηκευτούν τα δεδομένα της δομής finfo στο αρχείο passwd.
 */
int Users::save_new_info (struct finfo *pinfo,uid_t uid,char *shellnew)
{	
int len = 128;
QString gec;
QString emptystr = "";
    if (!pinfo->full_name) pinfo->full_name = emptystr.toLatin1().data();
    if (!pinfo->office) pinfo->office = emptystr.toLatin1().data();
    if (!pinfo->office_phone) pinfo->office_phone =  emptystr.toLatin1().data();
    if (!pinfo->home_phone) pinfo->home_phone =  emptystr.toLatin1().data();
    /* create the new gecos string */
    len   =(strlen (pinfo->full_name) + strlen (pinfo->office) + strlen (pinfo->office_phone) + strlen (pinfo->home_phone) + 4);
    char *gecos =(char*)calloc(len, sizeof(char));
    int fname = strlen(pinfo->full_name);

	if (pinfo->full_name == emptystr.toLatin1().data() && pinfo->office == emptystr.toLatin1().data() && pinfo->office_phone == emptystr.toLatin1().data() && pinfo->home_phone == emptystr.toLatin1().data())
	strncpy(gecos, emptystr.toLatin1().data(), fname);

	else
	{

	if(strncmp(pinfo->full_name,emptystr.toLatin1().data(),fname) != 0)
	{
	gec = pinfo->full_name;
	}
	int officesize = sizeof(pinfo->office);
	if(strncmp(pinfo->office ,emptystr.toLatin1().data(), officesize) != 0)
	{
	gec ="" + gec + ",";	
	gec = "" + gec + "" + pinfo->office + "";
	}
	int pinfo_size = sizeof(pinfo->office_phone);
	if(strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) != 0)
	{	
	int pinfo_office = sizeof(pinfo->office);
	if (strncmp(pinfo->office,emptystr.toLatin1().data(), pinfo_office) == 0 )
		gec ="" + gec + ",";
	gec ="" + gec + ",";
	gec = "" + gec + "" + pinfo->office_phone +  "";
	}
	
	int ophone = sizeof(pinfo->office_phone);
	if(strncmp(pinfo->home_phone,emptystr.toLatin1().data(), ophone) != 0)
	{	
	if (strncmp(pinfo->office_phone,emptystr.toLatin1().data(),ophone) == 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size)!= 0 )gec ="" + gec + ",,";
	if (strncmp(pinfo->office_phone,emptystr.toLatin1().data(), ophone) != 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) == 0  )gec ="" + gec + ",";
	if (strncmp(pinfo->full_name,emptystr.toLatin1().data(), fname) == 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) == 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) == 0){gec ="" + gec + ",,,";}
	if (strncmp(pinfo->full_name,emptystr.toLatin1().data(), fname) != 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size)== 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) == 0){gec ="" + gec + ",,,";}
	if (strncmp(pinfo->full_name,emptystr.toLatin1().data(), fname) != 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) != 0 && strncmp(pinfo->office_phone,emptystr.toLatin1().data(),pinfo_size) != 0){gec ="" + gec + ",";}
	gec = "" + gec + "" +  pinfo->home_phone +  "";
	}
	

	}
    sprintf(gecos, "%s",gec.toLatin1().data());

    pinfo->pw->pw_gecos = gecos;
    pinfo->pw->pw_uid   = uid;
    pinfo->pw->pw_shell = shellnew; 
    MyLibb set;
    if(set.setpwnam (pinfo->pw) < 0)
    {
     if(gecos!=NULL) free( gecos );
       return(-1);
    }
    else {
	if(gecos!=NULL) free( gecos );
    }
	return 0;
}
/**
 * This function returns the size of a file.
 * for every regular file it counts the size and then adds the value copy it at the variable totalSize.
 * When the calculation ends the totalSize variable will end up having the total size of the current folder.
 * if There is a folder inside the current folder then the function is used retrospectively.
 * The retrospective behavior happens until there are no folders to calculate the size.
 */
uint64_t Users::getSize( char *dirname )
{
  DIR *dir;
  struct dirent *ent = NULL;
  struct stat st;
  char *path = (char*)calloc(PATH_MAX, sizeof(*path));
  uint64_t totalsize = 0;

  if(!(dir = opendir(dirname)))
  {
	  if (path != nullptr) { free(path); path =nullptr; }
   return totalsize;
  }

  while((ent = readdir(dir)))
  {
    if(!strncmp(ent->d_name, "..", (int)sizeof(ent->d_name)) || !strncmp(ent->d_name, ".",(int)sizeof(ent->d_name)))
    {
    	continue;
    }

    sprintf(path, "%s%s", dirname, ent->d_name);

    if(lstat(path, &st) == -1)
    {
      printf("Couldn't stat %s: %s\n", path, strerror(errno));
       continue;
    }

    if(S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode))
    {
      uint64_t dirsize;
      strncat(path, "/", strlen(path));
      dirsize = getSize(path);
      totalsize += dirsize;
    }
    else if(S_ISREG(st.st_mode))
    {
      totalsize += st.st_size;
    }
  }

  if ( closedir(dir) < 0 ){ printf("Error closing file \n") ; }
  if (path != nullptr) { free(path); path =nullptr; }
  return totalsize;
}
/**
 * Η συνάρτηση μετράει τον αριθμό των χρηστών του συστήματος.Χρησιμοποιείται για να είναι ακριβής το ποσοστό ολοκλήρωσης της
 * progress bar που χρησιμοποιείται στον υπολογισμό του χώρου που καταλαμβάνουν οι χρήστες.
 */
int Users::countUsers( )
{	
	struct passwd *users = NULL;
	int total=0;
	setpwent();
	while (( users = getpwent() ) )
	{
		total++;
	}
	endpwent();

return total;
}
/**
 * Ψάχνει να βρει την κύρια ομάδα ενός χρήστη.Παίρνει την δομή του χρήστη και βλέπει το πεδίο της δομής το οποίο αναφέρει την κύρια ομάδα.Με το GID που υπάρχει στο πεδίο αυτό κάνει αναζήτηση στις ομάδες του συστήματος και η  ομάδα η οποία έχει ίδιο GID θεωρείται κύρια του χρήστη. 
 */
QString Users::getPrimaryGroup(QString username)
{

struct group *group=NULL;
struct passwd *user=NULL;
QString primGroup;
bool found=false;
user=getpwnam(username.toLatin1().data());

setgrent();
while (( group = getgrent() ))
{
if (user->pw_gid==group->gr_gid)
{
primGroup.append(group->gr_name);
found=true;
}
}
if(!found)
primGroup.append("");

endgrent();
return primGroup;

}


