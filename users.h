#ifndef USERS_H
#define USERS_H
//
#include "MainWindow.h"
#include "userproperties.h"
#include <dirent.h>
#include <stdint.h>
/**
 *Η κλάση περιέχει βασικές συναρτήσεις ελέγχου χρηστών,διαχωρισμού των πεδίων των λογαριασμών (όνομα,τηλέφωνο,διεύθυνση κτλ),καταμέτρηση χρηστών του συστήματος,έλεγχος κλειδώματος λογαριασμών,μέτρηση του χώρου που καταναλώνουν στον δίσκο,αναζήτηση χρηστών κτλ.
 */
class Users : public QObject
{
	Q_OBJECT
public:
	Users();
	~Users();
	static int check_gecos_string (char *gecos);
	bool set_Gecos_Data(struct finfo *oldfn , struct finfo *newfn );
	int passwd_parse(struct passwd *pw,struct finfo *pinfo);
	int save_new_info(struct finfo *pinfo,uid_t uid,char *shellnew);
	bool isLocked(QString user);
	QString getUsersPrimaryGroup( int UID );
	QString getUsersSecondaryGroups( QString name );
	bool userExists(QString name);
	int  rm_pwUser(QString name);
	struct passwd *searchUser();
	int  countUsers();

public slots:
	uint64_t getSize(char *dirname);
	QString getPrimaryGroup(QString username);
	
private:
	int  rm_shUser(QString name);
	QString passhash;
};
#endif
