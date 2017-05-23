#include "users.h"
#include <QtGui/QtGui>
#include "myLibb.h"
#define MAX_FIELD_SIZE          256
//

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
	char *userToSearch;
	struct passwd *result = NULL;
	QString userString = QInputDialog::getText( 0, QObject::tr( "Search" ), QObject::tr( "Enter Login Name:(case sensitive)" ), QLineEdit::Normal, QString( "" ), &okBtn );

	if ( okBtn && userString != " " )
	{
		userToSearch = userString.toAscii().data();
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
	user = getpwnam( name.toAscii().data() );
	if ( user != NULL )
	{
		QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "User Exists!! " ) );
		return true;
	}
	else
		return false;
}

/**
 * Ψάχνει να βρει την κύρια ομάδα ενός χρήστη.Παίρνει την δομή του χρήστη και βλέπει το πεδίο της δομής το 
  οποίο αναφέρει την κύρια ομάδα.Με το GID που υπάρχει στο πεδίο αυτό κάνει αναζήτηση στις ομάδες του συστήματος και η  ομάδα η οποία έχει ίδιο GID θεωρείται κύρια του χρήστη. 
 */
QString Users::getUsersPrimaryGroup( int UID )
{
	struct passwd *user;
	struct group *group;
	QString groupName="";
        user = getpwuid( UID ); //pernw thn domh passwd aytounou pou exei uid==UID
        group = getgrgid( user->pw_gid ); //pernw thn domh group gia to primary group tou UID (user->pw_gid=default group id tou user)
        if (group!=NULL)
        groupName = QString::fromLocal8Bit( group->gr_name );
	//else
	//QMessageBox::critical( 0, QObject::tr( "User Manager" ), QObject::tr( "No group entry for user %1 in /etc/group" ).arg(user->pw_name) );
	return groupName;
}

/**
 *Ψάχνει να βρει τις ομάδες στις οποίες είναι μέλος ο χρήστης που παίρνει σαν όρισμα.Σαρώνει όλες τις ομάδες του συστήμστος με τα μέλη τους.Αν βρεθεί μέλος που έχει ίδιο όνομα με το όνομα του ορίσματος, το
προσθέτει σε ένα string.Η τελική μορφή αυτού του string θα είναι κάπως έτσι ανάλογα με τις ομάδες στις οποίες είναι μέλος :
audio,cdrom,fax,plugdev κ.ο.κ.
 */
QString Users::getUsersSecondaryGroups( QString name )
{
	struct group *group;
	setgrent();
	QString listGroup;
	QByteArray nameArray = name.toLatin1();
	const char *userChar = nameArray.data();
	char **members;
	while (( group = getgrent() ) != NULL )
	{
		for ( members = group->gr_mem; *members; members++ )
			if ( strcmp( *members, userChar ) == 0 )
			{
				listGroup.append( group->gr_name );
				listGroup.append( " , " );
			}
	}
	listGroup.chop(2);//kovei tous 2 teleytaious xarakthres apo to string pou apo thn append panw einai ena keno kai ena komma
endgrent();
	return listGroup;
}
/**
 * Η συνάρτηση σαρώνει μια μια τις εγγραφές από το /etc/shadow και ψάχνει να βρει αν ένας λογαριασμός είναι κλειδωμένος.Για να θεωρηθεί κλειδωμένος ένας λογαριασμός πρέπει το δεύτερο πεδίο της εγγραφής το οποίο είναι ο κρυπτογραφημένος κωδικός  να έχι ένα ! ή * Επιστρέφει true αν ο λογαριασμός είναι κλειδωμένος και false αν δεν είναι.
 */
bool Users::isLocked( QString user )
{
	
	struct spwd   *sp;
	bool lock = false;
	QByteArray userArray = user.toLatin1();
	const char *userChar = userArray.data();
	setspent();
	
	sp = getspnam( userChar );
	if(sp != NULL)
	{
	if ( strncmp( sp->sp_pwdp, "!",1 ) == 0 || strcmp( sp->sp_pwdp, "*" ) == 0 )  
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
char *nam = name.toAscii().data();
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
    if (!pinfo->full_name) pinfo->full_name = emptystr.toAscii().data();
    if (!pinfo->office) pinfo->office = emptystr.toAscii().data();
    if (!pinfo->office_phone) pinfo->office_phone =  emptystr.toAscii().data();
    if (!pinfo->home_phone) pinfo->home_phone =  emptystr.toAscii().data();
    /* create the new gecos string */
    len   =(strlen (pinfo->full_name) + strlen (pinfo->office) + strlen (pinfo->office_phone) + strlen (pinfo->home_phone) + 4);
    char *gecos =(char*)calloc(len, sizeof(char));
    int fname = sizeof(pinfo->full_name);

	if (pinfo->full_name == emptystr.toAscii().data() && pinfo->office == emptystr.toAscii().data() && pinfo->office_phone == emptystr.toAscii().data() && pinfo->home_phone == emptystr.toAscii().data())
	gecos = emptystr.toAscii().data();

	else
	{

	if(strncmp(pinfo->full_name,emptystr.toAscii().data(),fname) != 0)
	{
	gec = pinfo->full_name;
	}
	int officesize = sizeof(pinfo->office);
	if(strncmp(pinfo->office ,emptystr.toAscii().data(), officesize) != 0)
	{
	gec ="" + gec + ",";	
	gec = "" + gec + "" + pinfo->office + "";
	}
	int pinfo_size = sizeof(pinfo->office_phone);
	if(strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) != 0)
	{	
	int pinfo_office = sizeof(pinfo->office);
	if (strncmp(pinfo->office,emptystr.toAscii().data(), pinfo_office) == 0 )
		gec ="" + gec + ",";
	gec ="" + gec + ",";
	gec = "" + gec + "" + pinfo->office_phone +  "";
	}
	
	int ophone = sizeof(pinfo->office_phone);
	if(strncmp(pinfo->home_phone,emptystr.toAscii().data(), ophone) != 0)
	{	
	if (strncmp(pinfo->office_phone,emptystr.toAscii().data(),ophone) == 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size)!= 0 )gec ="" + gec + ",,";
	if (strncmp(pinfo->office_phone,emptystr.toAscii().data(), ophone) != 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) == 0  )gec ="" + gec + ",";
	if (strncmp(pinfo->full_name,emptystr.toAscii().data(), fname) == 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) == 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) == 0){gec ="" + gec + ",,,";}
	if (strncmp(pinfo->full_name,emptystr.toAscii().data(), fname) != 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size)== 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) == 0){gec ="" + gec + ",,,";}
	if (strncmp(pinfo->full_name,emptystr.toAscii().data(), fname) != 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) != 0 && strncmp(pinfo->office_phone,emptystr.toAscii().data(),pinfo_size) != 0){gec ="" + gec + ",";}
	gec = "" + gec + "" +  pinfo->home_phone +  "";
	}
	

	}
    sprintf(gecos, "%s",gec.toAscii().data());

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
 * Η συνάρτηση ψάχνει να βρεί το μέγεθος των αρχείων ενός φακέλου.Για κάθε ένα κανονικό αρχείου του δωσμενου καταλόγου μετρά το μέγεθός του και το προσθέτεί στην μεταβλητή totalSize η οποία στο τέλος θα έχει το συνολικό μέγεθος όλου του φακέλου.Αν μέσα σε έναν φάκελο υπάρχει και άλλος φάκελος η getSize λειτουργεί αναδρομικά.Καλεί τον εαυτό της και προσθέτει το τελικό μέγεθος στην totalSize πάλι.Αυτή η διαδικασία γίνεται μέχρι να τελειώσουν όλα τα αρχεία και οι φάκελοι μέσα στον φάκελο που παίρνει σαν όρισμα.
 */
uint64_t Users::getSize( char *dirname )
{
  DIR *dir;
  struct dirent *ent;
  struct stat st;
  char path[PATH_MAX];
  uint64_t totalsize = 0;

  if(!(dir = opendir(dirname)))
  {
   return totalsize;
  }

  while((ent = readdir(dir)))
  {
    if(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
       continue;

    sprintf(path, "%s%s", dirname, ent->d_name);//pros8hkh onomatos tou katalogou + to ka8e arxeio to opoio eksetazetai ka8e fora

    if(lstat(path, &st) == -1)
    {
      printf("Couldn't stat %s: %s\n", path, strerror(errno));
       continue;
    }

    if(S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode))
    {
      uint64_t dirsize;
      strcat(path, "/");
      dirsize = getSize(path);
      totalsize += dirsize;
    }
    else if(S_ISREG(st.st_mode))
    {
      totalsize += st.st_size;
    }
  }

  closedir(dir);
  return totalsize;
}
/**
 * Η συνάρτηση μετράει τον αριθμό των χρηστών του συστήματος.Χρησιμοποιείται για να είναι ακριβής το ποσοστό ολοκλήρωσης της  progress bar που χρησιμοποιείται στον υπολογισμό του χώρου που καταλαμβάνουν οι χρήστες. 
 */
int Users::countUsers( )
{	
	struct passwd *users;
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
user=getpwnam(username.toAscii().data());

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


