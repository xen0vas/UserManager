#include "myLibb.h"
#include <stdio.h>
#include "pathfile.h"
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "userproperties.h"
#define _POSIX_SOURCE 1


/**
 * Constructor κλάσης
*/
MyLibb::MyLibb()
{}
/**
 * Destructor κλάσης
 */
MyLibb::~MyLibb()
{}
/**
 * Συνάρτηση ελέγχου πρόσβασης σε αρχεία.Δίνουμε σαν ορίσματα το path του αρχείου και τον τρόπο με τον οποίο θέλουμε να το ανοίξουμε (read write κτλ) και σε περίπτωση που είναι εφικτή η πρόσβαση στο συγκεκριμένο αρχείο μας επιστρέφει έναν δείκτη στο αρχείο.Σε διαφορετική περίπτωση μας εμφανίζει ανάλογο μήνυμα.
 */
FILE *MyLibb::fopen_wrapper(const char *filename,const char *mode)//elegxos prosvasis sto arxeio. An oxi epistrefei sfalma
{
	
    FILE *f;
    f = fopen(filename,mode);
    if (f == NULL) 
	{
	QMessageBox::critical(0,tr("User Manager"),tr("<qt> could not Open DataBase file <i> %1 </i> </qt>").arg(filename));
    	
	}
    return f;
}
/**
*
*Η συνάρτηση διαγράφει εγγραφές μέσα στο αρχείο passwd.Είναι ίδια με την setpwnam με τη μόνη διαφορά ότι 
*χρησιμοποιεί το όρισμα name το οποίο ειναι string χαρακτήρων και περιέχει το όνομα του λογαριασμου του χρήστη.
*Η κενή δομή περνάει μια κενή εγγραφή στο αρχείο .
*/
int MyLibb::setpwnam_r (struct passwd *pwd,char *name)
{ 
   FILE *fp = NULL, *pwf = NULL;
   int x, ret;
   int fd;
   bool found;
   int namelen;

   int buflen = 512;
   char *linebuf = (char*)calloc(buflen,sizeof(char));
   if (!linebuf) return -1;

//σε περίπτωση που το προσωρινό αρχείο υπάρχει και δεν έχει διαγραφεί για λόγους όπως να έχει διακοπεί η διεργασία πριν διαγραφεί το αρχείο ,τοτε η παρακάτω επανάληψη χρησιμοποιειται για να διαγράψει προσωρινα αρχεία και να δημιουργήσει καινούρια 
   for (x = 0; x < 3; x++) {
      if (x > 0)
	{
		unlink(PTMP_FILE);
	 	sleep(1);
	}
        fd = open(PTMPTMP_FILE, O_WRONLY|O_CREAT|O_EXCL, 0644);//-rw-r--r-- owner ->rw group->r other->r
        if (!fd)
	{
           return -1;
        }
       ret = link(PTMPTMP_FILE, PTMP_FILE);
       unlink(PTMPTMP_FILE);
       if (ret == -1)
           close (fd);
        else
           break;
    }

    if (ret == -1) return -1;

    fp =  fopen_wrapper(PTMP_FILE, "w+");
    pwf = fopen_wrapper(PASSWD_FILE, "r");
    namelen = strlen(name);

    found = false;
//διαβάζεται γραμμή προς γραμμή το προσωρινο αρχείο PASSWD_FILE που βρίσκεται στον κατάλογο /tmp/. 
    while (fgets(linebuf, buflen, pwf) != NULL) {

	int res = strncmp(linebuf,name, namelen); 	
        if ((found == false) && (res == 0) ) 
	  {
            putpwent(pwd, fp);
            found = true;
            continue;
          }
//προσθέτει εγγραφές χαρακτήρων στο αρχείο έως ότου φθάσει στον χαρακτήρα null \0 
        fputs(linebuf, fp);
    }

    fclose(fp);
    close(fd);
    fclose(pwf);

    if (!found) {
        errno = EIDRM; 
	QMessageBox::critical( 0,tr( "User Manager" ),tr( " %1  ").arg(strerror(errno)));
	free(linebuf);
	return -1;
    }	
     
    unlink(PASSWD_FILE".bak");
    
    link(PASSWD_FILE, PASSWD_FILE".bak");
    
    rename(PTMP_FILE, PASSWD_FILE) ;
    
    unlink(PTMP_FILE);
    
    if (linebuf != NULL) free(linebuf);
    
    return 0;
}

/**
*Η συνάρτηση διαγράφει εγγραφές μέσα στο αρχείο group.Είναι ίδια με την setpwnam με τη μόνη διαφορά ότι 
*χρησιμοποιεί το όρισμα name το οποίο ειναι string χαρακτήρων με το όνομα του λογαριασμου του χρήστη.
*Η κενή δομή περνάει μια κενή εγγραφή στο αρχείο .
 */
int MyLibb::setgrnam_r(struct group *grs,char *grp)
{
FILE *fp = NULL, *pwf = NULL;
int x, ret;
int fd;
bool found;
int namelen;
int buflen = 1024;
char *linebuf = (char*)calloc(buflen, sizeof(char));
if (!linebuf) return -1;

//σε περίπτωση που το προσωρινό αρχείο υπάρχει και δεν έχει διαγραφεί για λόγους όπως να έχει διακοπεί η διεργασία πριν διαγραφεί το αρχείο ,τοτε η παρακάτω επανάληψη χρησιμοποιειται για να διαγράψει προσωρινα αρχεία και να δημιουργήσει καινούρια 
for (x = 0; x < 3; x++) {
     if (x > 0)
     {
	unlink(GTMP_FILE);
 	sleep(1);
     }
     fd = open(GTMPTMP_FILE, O_WRONLY|O_CREAT|O_EXCL, 0644);//-rw-r--r-- owner ->rw group->r other->r
     if (!fd)
     {
        return -1;
     }
     ret = link(GTMPTMP_FILE, GTMP_FILE);
     unlink(GTMPTMP_FILE);
     if (ret == -1)
        close (fd);
     else
           break;
     }
    if (ret == -1) return -1;
   
 if(chown(GTMP_FILE,(uid_t) 0,(gid_t) 0 ) > 0 ) 
	{
	errno = EPERM;
	QMessageBox::information(0,tr("User Manager"),tr( "%1" ).arg(strerror(errno)));
	return -1;
	}
fp =  fopen_wrapper(GTMP_FILE, "w+");
pwf = fopen_wrapper(GR_FILE, "r");

namelen = strlen(grp);
found = false;

//διαβάζεται γραμμή προς γραμμή το προσωρινο αρχείο GR_FILE που βρίσκεται στον κατάλογο /tmp/. 
while (fgets(linebuf, buflen, pwf) != NULL) 
{

int res = strncmp(linebuf, grp, namelen); 	
        if ((found == false)&& (res == 0) )  
        {
            putgrent(grs, fp);
            found = true;
            continue;
        }
//προσθέτει εγγραφές χαρακτήρων στο αρχείο έως ότου φθάσει στον χαρακτήρα null \0 
fputs(linebuf, fp);
}
fclose(fp);
close(fd);
fclose (pwf);
if (!found) 
{
        errno = EIDRM; 
	QMessageBox::critical( 0,tr( "User Manager" ),QString( "%1").arg(strerror(errno)));
	return -1;
}	

unlink(GR_FILE".bak");
link(GR_FILE, GR_FILE".bak");

rename(GTMP_FILE, GR_FILE) ;

if (linebuf != NULL) free(linebuf);
unlink(GTMP_FILE);

return 0;
}
/**
 * Η συνάρτηση διαβάζει το αρχείο γραμμή πρός γραμμη εώς ότου να βρεθεί η εγγραφή η οποία είναι δείκτης σε δομή 
 * και μόλις βρέθει εισάγει στη σωστή γραμμή την εγγραφή με το τροποποιημένο πεδίο μέσα στο αρχείο /etc/shadow
 * αντικαθιστώντας την παλαιά εγγραφή.
 */
int MyLibb::setspnam(struct spwd *sh)
{
FILE *fp = NULL, *swf = NULL;
int x, ret;
int fd;
bool found;
int namelen;
int buflen = 256;
char *linebuf = (char*)calloc(buflen, sizeof(char));

if (!linebuf) return -1;

//σε περίπτωση που το προσωρινό αρχείο υπάρχει και δεν έχει διαγραφεί για λόγους όπως να έχει διακοπεί η διεργασία πριν διαγραφεί το αρχείο ,τοτε η παρακάτω επανάληψη χρησιμοποιειται για να διαγράψει προσωρινα αρχεία και να δημιουργήσει καινούρια 
for (x = 0; x < 3; x++) {
     if (x > 0)
     {
	unlink(STMP_FILE);
 	sleep(1);
     }
     fd = open(STMPTMP_FILE, O_WRONLY|O_CREAT|O_EXCL, 0644);//-rw-r--r-- owner ->rw group->r other->r
     if (!fd)
     {

        return -1;
     }
     ret = link(STMPTMP_FILE, STMP_FILE);
     unlink(STMPTMP_FILE);
     if (ret == -1)
        close (fd);
     else
           break;
     }
    if (ret == -1) return -1;

fp =  fopen_wrapper(STMP_FILE, "w+");
swf = fopen_wrapper(SH_FILE, "r");

namelen = strlen(sh->sp_namp);
found = false;
//διαβάζεται γραμμή προς γραμμή το προσωρινο αρχείο SH_FILE που βρίσκεται στον κατάλογο /tmp/. 
while (fgets(linebuf, buflen, swf) != NULL) 
{
	
int res = strncmp(linebuf, sh->sp_namp, namelen); 	
        if ((found == false) && (res == 0) ) 
        {
            putspent(sh, fp);
            found = true;
            continue;
        }
//προσθέτει εγγραφές χαρακτήρων στο αρχείο έως ότου φθάσει στον χαρακτήρα null \0 
fputs(linebuf, fp);
}
if(fclose(fp)) fp = NULL;
if(close(fd)) fd = -1;
if(fclose (swf)) swf = NULL;
if (!found) 
{
        errno = EIDRM; 
	QMessageBox::critical( 0,tr( "User Manager" ),tr( "%1").arg(strerror(errno)));
	return -1;
}	
unlink(SH_FILE".bak");
link(SH_FILE, SH_FILE".bak");
rename(STMP_FILE, SH_FILE) ;

if (linebuf != NULL) free(linebuf);
unlink(STMP_FILE);

return 0;
}
/**
 * Η συνάρτηση διαβάζει το αρχείο γραμμή πρός γραμμη εώς ότου να βρεθεί η εγγραφή η οποία είναι δείκτης σε δομή 
 * και μόλις βρέθει εισάγει στη σωστή γραμμή την εγγραφή με το τροποποιημένο πεδίο μέσα στο αρχείο /etc/group              * αντικαθιστώντας την παλαιά εγγραφή.
 */
int MyLibb::setgrnam(struct group *gr)
{
FILE *fp = NULL, *pwf = NULL;
int x, ret;
int fd;
bool found;

int namelen;
int buflen = 256;
char *linebuf = (char*)calloc(buflen, sizeof(char));

if (!linebuf) return -1;
//σε περίπτωση που το προσωρινό αρχείο υπάρχει και δεν έχει διαγραφεί για λόγους όπως να έχει διακοπεί η διεργασία πριν διαγραφεί το αρχείο ,τοτε η παρακάτω επανάληψη χρησιμοποιειται για να διαγράψει προσωρινα αρχεία και να δημιουργήσει καινούρια 
for (x = 0; x < 3; x++) {
     if (x > 0)
     {
	unlink(GTMP_FILE);
 	sleep(1);
     }
     fd = open(GTMPTMP_FILE, O_WRONLY|O_CREAT|O_EXCL, 0644);//-rw-r--r-- owner ->rw group->r other->r
     if (!fd)
     {
        return -1;
     }
     ret = link(GTMPTMP_FILE, GTMP_FILE);
     unlink(GTMPTMP_FILE);
     if (ret == -1)
        close (fd);
     else
           break;
     }
    if (ret == -1) return -1;

fp =  fopen_wrapper(GTMP_FILE, "w+");
pwf = fopen_wrapper(GR_FILE, "r");

namelen = strlen(gr->gr_name);
found = false;
//διαβάζεται γραμμή προς γραμμή το προσωρινο αρχείο GR_FILE που βρίσκεται στον κατάλογο /tmp/. 
while (fgets(linebuf, buflen, pwf) != NULL) 
{


int res = strncmp(linebuf, gr->gr_name, namelen); 	
        if ((found == false) && (res == 0) )
        {
            putgrent(gr, fp);
            found = true;
            continue;
        }
//προσθέτει εγγραφές χαρακτήρων στο αρχείο έως ότου φθάσει στον χαρακτήρα null \0 
fputs(linebuf, fp);

}

fclose(fp);
close(fd);
fclose(pwf);

if (!found) 
{
        errno = EIDRM; 
	QMessageBox::critical( 0,tr( "User Manager" ),tr( "%1").arg(strerror(errno)));
	if (linebuf!=NULL) free(linebuf);
	return -1;
}
	
unlink(GR_FILE".bak");

link(GR_FILE, GR_FILE".bak");

rename(GTMP_FILE, GR_FILE) ;

if (linebuf != NULL) free(linebuf);
unlink(GTMP_FILE);

return 0;
} 
/**
 * Η συνάρτηση διαβάζει το αρχείο γραμμή πρός γραμμη εώς ότου να βρεθεί η εγγραφή η οποία είναι δείκτης σε δομή 
 * και μόλις βρέθει εισάγει στη σωστή γραμμή την εγγραφή με το τροποποιημένο πεδίο μέσα στο αρχείο passwd αντικαθιστώντας την παλαιά εγγραφή.
 */
int MyLibb::setpwnam (struct passwd *pwd)
{
 
   FILE *fp = NULL, *pwf = NULL;
   int x, ret;
   int fd;
   bool found;
   int namelen;
   int buflen = 256;
   char *linebuf = (char*)calloc(buflen, sizeof(char));
   if (!linebuf) return -1;

   //σε περίπτωση που το προσωρινό αρχείο υπάρχει και δεν έχει διαγραφεί για λόγους όπως να έχει διακοπεί η διεργασία πριν διαγραφεί το αρχείο ,τοτε η παρακάτω επανάληψη χρησιμοποιειται για να διαγράψει προσωρινα αρχεία και να δημιουργήσει καινούρια 
   for (x = 0; x < 3; x++) {
      if (x > 0)
	{
		unlink(PTMP_FILE);
	 	sleep(1);
	}
        fd = open(PTMPTMP_FILE, O_WRONLY|O_CREAT|O_EXCL, 0644); //-rw-r--r-- owner ->rw group->r other->r
        if (!fd) {
           return -1;
        }
       ret = link(PTMPTMP_FILE, PTMP_FILE);
       unlink(PTMPTMP_FILE);
       if (ret == -1)
           close (fd);
        else
           break;
    }
    if (ret == -1) return -1;

    fp =  fopen_wrapper(PTMP_FILE, "w+");
    pwf = fopen_wrapper(PASSWD_FILE, "r");

    namelen = strlen(pwd->pw_name);
     
    found = false;
     
    //διαβάζεται γραμμή προς γραμμή το προσωρινο αρχείο PASSWD_FILE που βρίσκεται στον κατάλογο /tmp/. 
    while (fgets(linebuf, buflen, pwf) != NULL)
    {
        	int res = strncmp(linebuf,pwd->pw_name, namelen);	
        	if ((found == false) && (res == 0) )
	 	{
            		putpwent(pwd, fp);
            		found = true;
            		continue;
          	}
    //προσθέτει εγγραφές χαρακτήρων στο αρχείο έως ότου φθάσει στον χαρακτήρα null \0 
    fputs(linebuf, fp);
    }

    fclose(fp);
    close(fd);
    fclose (pwf);

    if (!found) {
        errno = EIDRM; 
        QMessageBox::critical( 0,tr( "User Manager" ),tr( " %1  ").arg(strerror(errno)));
		if (linebuf != NULL) free(linebuf);
		return -1;
    }	
     
    unlink(PASSWD_FILE".bak");
    
    link(PASSWD_FILE, PASSWD_FILE".bak");
    
    rename(PTMP_FILE, PASSWD_FILE) ;

    if (linebuf != NULL) free(linebuf);
    unlink(PTMP_FILE);
    return 0;
}




