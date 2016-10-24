#ifndef MODELS_H
#define MODELS_H
#include "editProperties.h"
#include "groups.h"

using std::string;
/**
 * Στην κλάση αυτή δημιουργούνται οι λίστες των δεδομένων που ζητούνται κάθε φορά ανάλογα με την ενέργεια που έχει επιλέξει να εκτελέσει ο χρήστης. Η φιλοσοφία είναι ίδια σε όλες τις συναρτήσεις της κλάσης. Αρχικά παίρνουμε τα δεδομένα τα οποία θέλουμε να εμφανιστούν σε ένα component,πχ σε  μια λίστα. Αυτά τα φορτώνουμε σε ένα αντικείμενο της κλάσης QstandardItemModel, η οποία προσφέρεται από τις βιβλιοθήκες της QT. Σε αυτό το αντικείμενο/μοντέλο αποθηκεύουμε όλα τα δεδομένα που θέλουμε να εμφανίσουμε. Μπορούμε να καθορίσουμε τον αριθμό των στηλών,των γραμμών,το χρώμα στο κείμενο,να βάλουμε επικεφαλίδες στις στήλες και γενικά να προσδιορίσουμε ποια θα είναι η οπτική αναπαράσταση των δεδομένων.
 */


class Models : public QStandardItemModel
{
public:
	Models();
	~Models();
	QStandardItemModel *createUsersModel();
	QStandardItemModel *createUsersModelWithSizes( QStringList sizeList );
	QStandardItemModel *createGroupsModel( );
	QStandardItemModel *createFoundedUserModel( struct passwd *userFound );
	QStandardItemModel *createMembersModel( const char *groupName );
	QStandardItemModel *createFoundedGroupModel( struct group *grp );
	QStandardItemModel *UsersInGroupModel( const char *groupName );
	QStandardItemModel *UsersNotInGroupModel( const char *groupName );
	QStandardItemModel *createUserInGroupsModel(QString username );
};
#endif
