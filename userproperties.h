#ifndef USERPROPERTIES_H
#define USERPROPERTIES_H
//
#include "ui_UserProperties.h"
#include <pwd.h>
#include <grp.h>
#include "users.h"

using namespace std;


/**
* This class used in order to process UserProperties form data.
* Αποτελεί κλάση ορίου-διεπαφής καθώς επικοινωνεί με τη φόρμα-χρήστη και κληρονομεί τις ιδιότητες και τα χαρακτηριστικά της.
* Περιέχει συναρτήσεις που σκοπό έχουν να λαμβάνουν και να επιστρέφουν δεδομένα που χειρίζεται η φόρμα.
* Επίσης χειρίζεται *συναρτήσεις κρυπτογράφησης και δημιουργίας κωδικών
*/

class UserProperties : public QDialog , public Ui::UserProperties
{
Q_OBJECT
public:
	UserProperties( QWidget *parent = 0 );
	~UserProperties();
	void combotext();
	int setPasswdUID();

private:
	QString oldUsername_;
	QString passhash;
	int insertIntoPasswdFile(QString nam,QString uid,QString gid,QString directory,QString gec, QString shellcon );
	int insertIntoGroupFile(QString nam,QString gid);
	struct spwd setShadowStruct(int max, int warn,int inact, int min,string inact_user,char *name,char *password_hash,int current_days);
	int insertIntoShadowFile(QString logname,QString encrypted_pass);
    void addGroup(QString label, char* group);
    // use execve in order to execute external programs
    void addGroup_execve(QString label, char* group);
    void usermod_execve(QString index, QString label);

public slots:
	void openHashingAlgorithm();
	void fillEasyList();		
	void easyCheckboxClicked();
	void addUserBase();
	void setFormContents();
	void easyAddGroups(const QModelIndex &index);
	void changeMembers(const QModelIndex &index );
	void setPrimaryGroup();	


};
#endif
