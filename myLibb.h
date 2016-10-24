#ifndef MYLIBB_H
#define MYLIBB_H

#include <QtGui/QtGui>
#include "pwd.h"
#include "shadow.h"
#include "grp.h"
/**
Δομή στην οποία αποθηκεύονται βασικές πληροφορίες ενός λογαριασμού.Χρησιμοποιείται στην επεξεργασία στοιχείων των χρηστών, 
*/
struct finfo
{  
    char *username;
    char *full_name;
    char *office;
    char *office_phone;
    char *home_phone;
    struct passwd *pw;
};

/**
Η κλάση περιέχει συναρτήσεις οι οποίες μας επιτρέπουν να επεξεργαστούμε εγγραφές στα αρχεία
/etc/passwd /etc/group /etc/shadow και μια συνάρτηση ελέγχου η οποία ελέγχει αν είναι εφικτό το άνοιγμα αρχείων.
*/
class MyLibb : public QObject
{	
	Q_OBJECT
public:
	MyLibb();
	~MyLibb();
	int setspnam(struct spwd *sh);
	int setgrnam(struct group *gr);
	int setpwnam(struct passwd *pwd);
	int setgrnam_r(struct group *grs, char *grp);
	int setpwnam_r(struct passwd *pwd,char *name);
	FILE *fopen_wrapper(const char *filename,const char *mode);
};
#endif

