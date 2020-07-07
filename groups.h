#ifndef GROUPS_H
#define GROUPS_H
#include "pathfile.h"
#include <QtGui/QtGui>
#include <spc.h>

/**
Η Κλάση αυτή περιέχει συναρτήσεις οι οποίες ενεργούν πάνω στις ομάδες ενός συστήματος.
Μερικές από τις ενέργειες αυτές είναι η διαγραφή μελών απο ομάδες,η διαγραφή ομάδων από το σύστημα,η προσθήκη ενός νέου χρήστη σε προεπιλεγμένες ομάδες κ.ο.κ. 
*/
class Groups: public QObject
{
	Q_OBJECT
public:
	Groups();
	~Groups();

	static struct group *remove_member(struct group *in,char *uname);
	QString getPrimaryUsers(int gid);
	int deleteGroup(QString gname);
	bool isPrimary(int gid);
	static int rm_grMember(QString log);
	struct group *searchGroup();
	int default_groups(QString newmem);

private:
	int setgrnam(struct group *gr);
    Spc *spc;

	
};
#endif
