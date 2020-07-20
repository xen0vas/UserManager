#include "groups.h"
#include "myLibb.h"
#include <QMessageBox> 
#include <QInputDialog> 
#include "spc.h"

/**
 Constructor κλάσης 
 */
Groups::Groups( )
{

}
/**
 *Destructor κλάσης
 */
Groups::~Groups( )
{

}


/**
 *Εισάγει κάθε νέο χρήστη σε σε βασικές ομάδες όπως audio (ήχο),video (χρήση βίντεο),cdrom (χρήση cdrom),floppy (χρήση δισκέτας) και plugdev (χρήση αποθηκευτικών μέσων).
 */
int Groups::default_groups(QString newmem)
{
struct group *grs;
setgrent();
QString allmem = "";
while((grs = getgrent()))
{
if (strncmp(grs->gr_name,"video", strlen(grs->gr_name))==0 || strncmp(grs->gr_name ,"cdrom", strlen(grs->gr_name))==0 || strncmp(grs->gr_name,"floppy", strlen(grs->gr_name))==0 || strncmp(grs->gr_name ,"audio", strlen(grs->gr_name))==0 ||  strncmp(grs->gr_name, "plugdev", strlen(grs->gr_name))==0 )
{
QString member =  *grs->gr_mem;
if(*grs->gr_mem == NULL)
*grs->gr_mem = newmem.toLatin1().data();
else
{
allmem = "" + member + ","  + newmem + "";
*grs->gr_mem = allmem.toLatin1().data();
}
MyLibb set;
if(set.setgrnam(grs) < 0)return -1;
allmem = "";
}
}
endgrent();
return 0;
}
/**
 *Αναζήτηση μιας ομάδας στο σύστημα.Ψάχνει στο αρχείο των ομάδων και αν βρεθεί η ομάδα που αναζητούμε 
επιστρέφει την δομή της.Αν όχι εμφανίζει ανάλογο μήνυμα.
 */
struct group *Groups::searchGroup()
{
	bool okBtn;
	char *groupToSearch;
	struct group *result = NULL;
	QString groupString = QInputDialog::getText( 0, QObject::tr( "Search" ), QObject::tr( "Enter Group Name:(case sensitive)" ), QLineEdit::Normal, QString( "" ), &okBtn );

	if ( okBtn && groupString != " " )
	{
		groupToSearch = groupString.toLatin1().data();
		result = getgrnam( groupToSearch );
		if ( result == NULL )
		{
			QMessageBox::information( 0, QObject::tr( "User Manager" ), QObject::tr( "Group %1 not found" ).arg( groupString ) ) ;
		}

	}
	return result;
}
/**
 *Διαγράφει ένα μέλος από μια ομάδα.Παίρνει την δομή της ομάδας με τα μέλη της και αν βρεί τον χρήστη που
θέλουμε να αφαιρέσουμε από την ομάδα (όρισμα uname),αντικαθιστά τη θέση του στα μέλη με ένα κενό.Στην συνέχεια καθαρίζει το αρχείο των ομάδων από πιθανά άχρηστα κόμματα που έμειναν μέσω του κειμενογράφου sed.
Στο τέλος επιστρέφει την δομή χωρίς το μέλος που αφαιρέθηκε.
 */
struct group *Groups::remove_member(struct group *in,char *uname)
{	
	int i;
	
    QString memo = "";

	if (in == NULL) return NULL;

	for (i = 0; in->gr_mem[i]; i++)
    {
			if (!strncmp(in->gr_mem[i], uname, strlen(in->gr_mem[i])))
			{
				in->gr_mem[i] = memo.toLatin1().data();
            }
    }

    usleep(1000);
	return in;
}

/**
 *Διαγραφή ενός χρήστη από όλες τις ομάδες που πιθανόν να ήταν μέλος.Χρησιμοποιείται αφού διαγραφεί κάποιος χρήστης από το σύστημα.
 */

int Groups::rm_grMember(QString log)
{
    struct group *grs = NULL;

	FILE * f;
	MyLibb *set = new MyLibb();
	f = fopen(GR_FILE,"r");
	char *login = log.toLatin1().data();
	setgrent();
	while((grs = fgetgrent(f)))
    {
		remove_member(grs , login);
		if(set->setgrnam(grs)<0)
		{
			return -1;
		}
	}
	endgrent();
	if (set != nullptr){ delete set; set = nullptr;}
	fclose(f);
	return 0;
}
/**
 *Προετοιμασία διαγραφής μια ομάδας από το σύστημα. 
 */
int Groups::deleteGroup(QString gname)
{
	MyLibb set;
	struct group *gr = NULL;
	char * groupname = gname.toLatin1().data();
	if(set.setgrnam_r(gr,groupname)<0)
		{

			return -1;
		}

    return 0;
}
/**
 *Ελέγχει αν υπάρχει χρήστης ο οποίος έχει σαν κύρια ομάδα,την ομάδα με το GROUP ID που παίρνει σαν όρισμα.
 */
bool Groups::isPrimary(int gid)
{
gid_t gidt=gid;

bool found=false;
struct passwd *users;
setpwent();
while (( users = getpwent() ) )
{
	if (users->pw_gid==gidt)
	{
			found=true;
	}
}
endpwent();
return found;

}
/**
 *Δημιουργία ενός string το οποίο περιέχει όλους τους χρήστες οι οποίοι έχουν σαν κύρια ομάδα την ομάδα με το GROUP ID που παίρνει σαν όρισμα.
 */
QString Groups::getPrimaryUsers(int gid) // epistrefei tous xrhstes pou exoun to group san prwteywn
{
gid_t gidt = gid;
QString primOfUsers;
struct passwd *users;
setpwent();
while (( users = getpwent() ) )
{
	if (users->pw_gid==gidt)
	{
		primOfUsers.append(users->pw_name);
		primOfUsers.append(",");
	}
}
endpwent();
primOfUsers.chop(1); // cut out the last comma
return primOfUsers;
}
