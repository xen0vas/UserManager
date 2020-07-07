#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include "ui_mainwindow.h"
#include "ui_UserProperties.h"
#include "ui_EditProperties.h"
#include "ui_GroupProperties.h"
#include "ui_Settings.h"
#include "ui_About.h"
#include "userproperties.h"
#include "editProperties.h"
#include "groupProperties.h"
#include "Settings.h"
#include "About.h"
#include "users.h"
#include "myLibb.h"
#include "groups.h"
#include "models.h"
#include "pathfile.h"
#include <unistd.h>
/**
 * Η MainWindow είναι η κλάση ορίου-διεπαφής  στην οποία βρίσκεται η αρχική φόρμα που εμφανίζεται στο πρόγραμμα. Σε αυτήν την φόρμα εμφανίζονται και οι βασικές πληροφορίες για τους χρήστες και τις ομάδες του συστήματος. Οι περισσότερες ενέργειες του προγράμματος ξεκινάνε από την MainWindow,ανάμεσα τους και  οι ενέργειες της εισαγωγής,διαγραφής,επεξεργασίας,αναζήτησης χρηστών και ομάδων. Επικοινωνεί με όλες τις κλάσεις του προγράμματος για να είναι εφικτή η δημιουργία αντικειμένων από αυτές. Οι περισσότερες συναρτήσεις της αντιστοιχούν στις ενέργειες που μπορεί να εκτελέσει ο διαχειριστής από την αρχική φόρμα. Για κάθε ενέργεια που ξεκινάει από την  φόρμα,υπάρχει και μια σύνδεση στον constructor της κλάσης που συνδέει το κάθε signal-ενέργεια με την αντίστοιχη slot-υλοποίηση και είναι της μορφής :

connect( addUserBtn,SIGNAL( clicked() ),this,SLOT( addUserBtnClicked() ) );

Στο παραπάνω παράδειγμα αντιστοιχίζεται το 'κλικ' στο κουμπί της εισαγωγής νέου χρήστη με την συνάρτηση  addUserBtnClicked().Έτσι μόλις πατηθεί το κουμπί για την εισαγωγή το πρόγραμμα θα υλοποιήσει τον κώδικα που βρίσκεται μέσα στην addUserBtnClicked().
 */

class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindow( QWidget * parent = 0, Qt::WindowFlags f = 0 );
	~MainWindow();


protected:
	bool eventFilter(QObject* obj , QEvent* e);

public slots:
	void reloadUsersAndGroups();

private:
	
	QStandardItemModel *userModel;
	QStandardItemModel *groupModel;
	QStandardItemModel *foundedUserModel;
	QStandardItemModel *foundedGroupModel;
	QString log;
	QString fnam;
	QString office1 ;
	QString office2 ;
	QString address  ;
	QString dir;
	QString ui;
	QStringList shell;
	struct passwd *users_info;
	struct group *groups_info;
	void  loadUsersAndGroups( );
	void initialize();
    Spc *spc;

private slots:
	void tabChanged( int tab );
	void aboutUserManager();
	void folderSizeCheckBoxClicked();
	void addGroupBtnClicked();
	void setPassMenu();
	void searchUserBtnClicked();
	void addUserBtnClicked();
	void searchGroupBtnClicked();
	void UserDetails();
	void GroupDetails(const QModelIndex &index );
	void beautyTree( QTreeView *tree, int columns );
	void getSelectedUserInfo( const QModelIndex &index );
	void getSelectedGroupInfo( const QModelIndex &index );
	void clearEditBoxes();
	void calculateFolderSize();
	void deleteUser();
	int deleteGroup();
	void EditUser();
	void editGroup();
	void getEditDetails(const QModelIndex&);
	void openSettings();
	void createBackup();

};
#endif






