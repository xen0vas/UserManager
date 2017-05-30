#ifndef USERPROPERTIES_H
#define USERPROPERTIES_H
//
#include "ui_UserProperties.h"
#include <pwd.h>
#include <grp.h>
#include "users.h"

using namespace std;


/**
*Χρησιμοποιείται για να επεξεργάζεται δεδομένα της φόρμας UserProperties.Αποτελεί κλάση ορίου-διεπαφής καθώς επικοινωνεί με τη φόρμα-χρήστη και κληρονομεί τις *ιδιότητες και τα χαρακτηριστικά της.Περιέχει συναρτήσεις που σκοπό έχουν να λαμβάνουν και να επιστρέφουν δεδομένα που χειρίζεται η φόρμα.Επίσης χειρίζεται *συναρτήσεις κρυπτογράφησης και δημιουργίας κωδικών
*/

class UserProperties : public QDialog , public Ui::UserProperties
{
Q_OBJECT
public:
	UserProperties( QWidget *parent = 0 );
	~UserProperties();
	char *encryptPasswd(QString passwd);
	void combotext();
	int passwd_study();
	int insert_passwd(QString nam,QString uid,QString gid,QString directory,QString gec, QString shellcon );
	int insert_group(QString nam,QString gid);
	struct spwd set_possix(int max, int warn,int inact, int min,string inact_user,char *name,char *password_hash,int current_days);
	char *makeSalt(int length);
	void into64(char *s, long int v, int n);
	void set_shad_acc(struct spwd spw);
	int insert_shadow(QString logname,QString encrypted_pass);

private:
	QString oldUsername_;
	QString passhash;	

public slots:
	void fillEasyList();		
	void easyCheckboxClicked();
	void addUserBase();
	void setPassword();
	void disCheck();
	void easyAddGroups(const QModelIndex &index);
	void changeMembers(const QModelIndex &index );
	void setPrimaryGroup();	


};
#endif
