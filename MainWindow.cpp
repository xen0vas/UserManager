#include "MainWindow.h"
#define SIZE 256


using namespace std;



/**
 *Constructor της κλάσης/φόρμας.
 */
MainWindow::MainWindow( QWidget * parent, Qt::WFlags f ): QMainWindow( parent, f )
 {	

	Settings set;
	QString selectedLanguage=set.getconf("LANGUAGE").c_str();
	if(selectedLanguage=="Greek")
	{
	QTranslator *translator = new QTranslator();



	if ( QFile::exists( "/usr/share/apps/UserManager/translations/el.qm" ) )
	{
	translator->load("/usr/share/apps/UserManager/translations/el.qm");
	QApplication::installTranslator( translator );
	}
	}
	setupUi( this );
	

	initialize();

}

/**
 *Destructor κλάσης/φόρμας
 */

MainWindow::~MainWindow()
{}
/**
 *Περιορισμός μεγέθους στηλών στα περιεχόμενά τους
 */
void MainWindow::beautyTree( QTreeView *tree, int columns )
{
	tree->sortByColumn( 0, Qt::AscendingOrder );
	for ( int i = 0;i < columns;i++ )
	{
		tree->resizeColumnToContents( i );
	}
}

/**
 *Αρχικοποίηση των components στην κύρια φόρμα - Συνδέσεις signals με slots
 */
void MainWindow::initialize()
{
//***buttons/tabs/mege8h ktl***
searchGroupBtn->setEnabled(false);
addGroupBtn->setEnabled(false);
delGroupBtn->setEnabled(false);
loadUsersAndGroups( );
menuDeleteGroup->setEnabled(false);
menuEditGroup->setEnabled(false);
//***syntomeyseis***
menuQuit->setShortcut( QString( "Ctrl+E" ) );
menuReload->setShortcut( QString( "Ctrl+R" ) );
menuAddUser->setShortcut( QString( "Ctrl+U" ) );
menuAddGroup->setShortcut( QString( "Ctrl+G" ) );
menuConfiguration->setShortcut( QString( "Ctrl+S" ) );
menuLanguage->setShortcut( QString( "Ctrl+L" ) );
menuBackup->setShortcut( QString( "Ctrl+B" ) );
menuAbout_Qt->setShortcut( QString( "Ctrl+Q" ) );
menuAboutUserManager->setShortcut( QString( "Ctrl+A" ) );
menuDiskUsage->setShortcut( QString( "Ctrl+D" ) );
//***Key Events***
userTreeView->installEventFilter (this);
groupTreeView->installEventFilter (this);
//***Connections***
connect( searchUserBtn, SIGNAL( clicked() ), this, SLOT( clearEditBoxes() ) );
connect( searchUserBtn, SIGNAL( clicked() ), this, SLOT( searchUserBtnClicked() ) );
connect( searchGroupBtn, SIGNAL( clicked() ), this, SLOT( searchGroupBtnClicked() ) );
connect( userTreeView, SIGNAL( doubleClicked( const QModelIndex& ) ), this, SLOT( getEditDetails( const QModelIndex& ) ) );
connect( addUserBtn, SIGNAL( clicked() ), this, SLOT( addUserBtnClicked() ) );
connect( reloadBtn, SIGNAL( clicked() ), this, SLOT( reloadUsersAndGroups() ) );
connect( userTreeView, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( getSelectedUserInfo( const QModelIndex& ) ) );
connect( groupTreeView, SIGNAL( doubleClicked( const QModelIndex& ) ), this, SLOT( GroupDetails( const QModelIndex& ) ) );
connect( groupTreeView, SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( getSelectedGroupInfo( const QModelIndex& ) ) );
connect( tabWidget, SIGNAL( currentChanged( int ) ), this, SLOT( tabChanged( int ) ) );
connect( folderSizeCheckBox, SIGNAL( clicked() ), this, SLOT( folderSizeCheckBoxClicked() ) );
connect( delUserBtn, SIGNAL( clicked() ), this, SLOT( deleteUser() ) );
connect( editBtn, SIGNAL( clicked() ), this, SLOT( EditUser() ) );
connect( editGroupBtn, SIGNAL( clicked() ), this, SLOT( editGroup() ) );
connect( addGroupBtn, SIGNAL( clicked() ), this, SLOT( addGroupBtnClicked() ) );
connect( delGroupBtn, SIGNAL( clicked() ), this, SLOT( deleteGroup() ) );
//menu buttons
connect(menuConfiguration, SIGNAL(triggered()), this, SLOT(openSettings()));
connect(menuQuit, SIGNAL(triggered()), this, SLOT(close()));
connect(menuBackup, SIGNAL(triggered()), this, SLOT(createBackup()));
connect(menuReload, SIGNAL(triggered()), this, SLOT(reloadUsersAndGroups()));
connect(menuAddUser, SIGNAL(triggered()), this, SLOT(addUserBtnClicked() ));
connect(menuDeleteUser, SIGNAL(triggered()), this, SLOT(deleteUser()));
connect(menuEditUser, SIGNAL(triggered()), this, SLOT(EditUser() ));
connect(menuAddGroup, SIGNAL(triggered()), this, SLOT(addGroupBtnClicked() ));
connect(menuDeleteGroup, SIGNAL(triggered()), this, SLOT(addUserBtnClicked() ));
connect(menuSetPassword, SIGNAL(triggered()), this, SLOT(set_Pass_Menu() ));
connect(menuEditGroup, SIGNAL(triggered()), this, SLOT(editGroup()));
connect(menuDiskUsage, SIGNAL(triggered()), this, SLOT(calculateFolderSize()));
connect(menuAbout_Qt, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );
connect(menuAboutUserManager, SIGNAL( triggered() ), this, SLOT( aboutUserManager() ) );
}

/**
 * Αλλαγή κωδικού χρήστη από το μενού της κύριας φόρμας (Users->Set Password)
 */

void MainWindow::set_Pass_Menu()
{

EditProperties *edit_for_menu;
QModelIndex index=userTreeView->selectionModel()->currentIndex();
int row=index.row();
QString username=index.sibling ( row, 1 ).data( ).toString();
if (username == "")
QMessageBox::information ( 0, tr ( " UserManager " ),tr ( " Please Select a User to Change Password!!" ) ); 
else
edit_for_menu->set_password(username);
}
/**
 *Προετοιμασία εισαγωγής νέου χρήστη.Έλεγχος αν υπάρχουν όλα τα αρχεία συστήματος (group,passwd,shadow).Εκκινεί με το πάτημα του κουμπιού εισαγωγής νέου χρήστη από την κύρια φόρμα.
 */
void MainWindow::addUserBtnClicked()
{
	
	FILE *passBase;
	FILE *groupBase;
	FILE *shadowBase;	
	UserProperties *userProp = new UserProperties;
	MyLibb *fchk { new MyLibb()};
	shadowBase = fchk->fopen_wrapper(SHADOW_FILE, "r+");
	groupBase  = fchk->fopen_wrapper(GROUP_FILE , "r+");
	passBase   = fchk->fopen_wrapper(PASSWD_FILE, "r+");
	
	if( passBase == NULL || groupBase == NULL || shadowBase == NULL )
	
		QMessageBox::critical(0,tr("User Manager"),tr("<qt>  <i> %1 </i>  </qt> ").arg(strerror(errno)));
	
	else
	{
	bool okBtn;
	QString userString = QInputDialog::getText( 0, QObject::tr( "Add User" ), QObject::tr( "Please Enter User Name:" ), QLineEdit::Normal, QString( "" ), &okBtn );
	if ( userString == "" && okBtn )
	{
		QMessageBox::information( 0, tr( "User Manager" ), tr( "Empty field!! " ) );
	}
	else
	{
	Users user ;
		if ( !user.userExists( userString ) && okBtn )
		{
			userProp->NameLabel->setText( userString );
			userProp->fillEasyList();
			userProp->combotext();
			QString uid;
			uid = uid.setNum(userProp->passwd_study());
			userProp->uidEdit->setText( uid );
			userProp->HomeDirEdit->setText( "" "/home/" + userString + "" );	
			userProp->timeDate->setText("_");
			userProp->setWindowTitle("User Properties - New User");
			userProp->show();
			if ( userProp->exec() ){}
			delete userProp;
			userProp = nullptr;
			delete fchk;
			fchk = nullptr;

		}
	}
	if (userProp != nullptr )
	{
		delete userProp;
		userProp = nullptr;
	}
	if (fchk != nullptr)
		{
		delete fchk;
		fchk = nullptr;
		}


	}

reloadUsersAndGroups();
}
/**
 *Αναζήτηση ενός χρήστη στο σύστημα και εμφάνιση των πληροφοριών του.Καλεί την searchUser από την κλάση Users και με την επιστρεφόμενη δομή του χρήστη(αν βρέθηκε) δημιουργεί το μοντέλο ώστε να εμφανιστούν οι πληροφορίες του χρήστη που αναζητήθηκε στην φόρμα.Εκκινεί με το πάτημα του κουμπιού αναζήτησης χρηστών από την κύρια φόρμα.
 */
void MainWindow::searchUserBtnClicked()
{	
	Models *model = new Models();
	Users *user = new Users;
	struct passwd *foundedUserStruct = user->searchUser();

	if ( foundedUserStruct != NULL )
	{
		foundedUserModel = model->createFoundedUserModel( foundedUserStruct );
		userTreeView->setModel( foundedUserModel );
		beautyTree( userTreeView, 6 );
		folderSizeCheckBox->setVisible(false);

	}
	user->~Users();
	model->~Models();
}
/**
 *Αναζήτηση μιας ομάδας στο σύστημα.Καλεί την searchGroup από την κλάση Groups και με την επιστρεφόμενη δομή της ομάδας(αν βρέθηκε) δημιουργεί το μοντέλο ώστε να εμφανιστούν οι πληροφορίες της ομάδας που  αναζητήθηκε στην φόρμα.Εκκινεί με το πάτημα του κουμπιού αναζήτησης ομάδων από την κύρια φόρμα.
 */
void MainWindow::searchGroupBtnClicked()
{

	Models *model { new Models };
	Groups *group { new Groups };
	struct group *foundedGroupStruct = group->searchGroup();

	if ( foundedGroupStruct != NULL )
	{
		foundedGroupModel = model->createFoundedGroupModel( foundedGroupStruct );
		groupTreeView->setModel( foundedGroupModel );
		beautyTree( groupTreeView, 1 );
	}
	group->~Groups();
	delete model ;
	model = nullptr;

}
/**
 *Φόρτωση των λιστών ομάδων και χρήστων που βρίσκονται στην κύρια φόρμα.
 */
void  MainWindow::loadUsersAndGroups( )
{
		Models *model {new Models()};
        userModel = model->createUsersModel( );
        groupModel = model->createGroupsModel( );
        userTreeView->setModel( userModel );
        beautyTree( userTreeView, 6 );
        groupTreeView->setModel( groupModel );
        beautyTree( groupTreeView, 1 );
        delete model;
        model = nullptr;

}
/**
 *Επαναφόρτωση των λιστών ομάδων και χρήστων της κύριας φόρμας με αλλαγές σε components της φόρμας.
 */
void MainWindow::reloadUsersAndGroups()
{	

	if (folderSizeCheckBox->isChecked())
		folderSizeCheckBox->setChecked(false);
	Models *model {new Models()};
	userModel = model->createUsersModel( );
	groupModel = model->createGroupsModel( );
	userTreeView->setModel( userModel );
	beautyTree( userTreeView, 6 );
	groupTreeView->setModel( groupModel );
	beautyTree( groupTreeView, 1 );
	clearEditBoxes();
	if (tabWidget->currentIndex()==0)
	folderSizeCheckBox->setVisible(true);
	delete model ;
	model = nullptr;
}
/**
 *Αποθήκευση των στοιχείων του χρήστη που πατήθηκε από την λίστα σε ανάλογες μεταβλητές της κλάσης για επεξεργασία.
 */
void MainWindow::getEditDetails(const QModelIndex &index)
{	
	int row = index.row();
	ui    = index.sibling( row, 0 ).data( Qt::DisplayRole ).toString();
	log   = index.sibling( row, 1 ).data( Qt::DisplayRole ).toString();
	fnam  = index.sibling( row, 2 ).data( Qt::DisplayRole ).toString();
	dir   = index.sibling( row, 3 ).data( Qt::DisplayRole ).toString();
	shell = index.sibling( row, 4 ).data( Qt::DisplayRole ).toStringList();
	struct spwd *sp;
	sp = getspnam(log.toAscii().data());
	if (sp != NULL)
		UserDetails();
	else
	QMessageBox::critical ( 0, tr ( " UserManager " ),tr ( "User '<i><b>%1</b></i>' does not exist in /etc/shadow!" ).arg(log.toAscii().data()) );
}

/**
 *Επεργασία στοιχείων ενός χρήστη όταν επιλεχθεί η ενέργεια της επεξεργασίας από το μενού των χρηστών.
 */
void MainWindow::EditUser()
{
	QModelIndex index=userTreeView->selectionModel()->currentIndex();
	int row=index.row();
	QString username=index.sibling ( row, 1 ).data( ).toString();
	if (username == "")
	QMessageBox::information ( 0, tr ( " UserManager " ),tr ( " Please Select a User for Edit!!" ) ); 
	else
	{
		this->getEditDetails(index);
	}
}
/**
 *Επεργασία στοιχείων μιας ομάδας όταν επιλεχθεί η ενέργεια της επεξεργασίας από το μενού των ομάδων.
 */
void MainWindow::editGroup()
{
	QModelIndex index=groupTreeView->selectionModel()->currentIndex();
	int row=index.row();
	QString groupName=index.sibling ( row, 1 ).data( ).toString();
	if (groupName == "")
	QMessageBox::information ( 0, tr ( " UserManager " ),tr ( " Please Select a group to edit" ) ); 
	else
	GroupDetails(index);
}
/**
 *Διαγραφή ενός χρήστη από το σύστημα όταν πατηθεί το κουμπί της διαγραφής χρηστών από την κύρια φόρμα.
 */
void MainWindow::deleteUser()
{
	MyLibb *fchk = new MyLibb();
	Groups gr;
	int okk = 0;
	int result2 = 0;
	int result = 0;
	FILE *passBase, *groupBase;
	passBase = fchk->fopen_wrapper ( PASSWD_FILE, "r+" );
	QModelIndex index=userTreeView->selectionModel()->currentIndex();
	int row=index.row();
	QString username=index.sibling ( row, 1 ).data( ).toString();
	struct passwd *passs;
	struct group *grr;
	passs = getpwnam(username.toAscii().data());
	
		
	if (passBase!=NULL)
	{
	if(username=="" || !index.isValid())
	{
		QMessageBox::information ( 0, tr ( " UserManager " ),tr ( " Please Select a User to Delete !!" ) );
		delete fchk ;
		fchk = nullptr;
	}
	else
	{
	grr = getgrgid(passs->pw_gid);
	int ok;
	ok = QMessageBox::warning ( 0, tr ( "User Manager" ), tr ( "User ' <i><b>%1</b></i> ' is about to be deleted from User Database.Are You sure you want to delete it? " ).arg ( username ) ,QMessageBox::Ok | QMessageBox::Cancel );
	if ( ok == 1024 )
	{
		Users usr;
		result = usr.rm_pwUser ( username );
		struct spwd *spp;
		spp = getspnam(username.toAscii().data());
				if (spp != NULL)
				{
					QString delshadow = "sed 's/" + username + ".*$//' /etc/shadow  > /tmp/.shad";//remove to user apo to shadow file
					QString delemptylines = "sed '/^$/D' /tmp/.shad > /tmp/.sh ";//afairei tin keni grammi pou dimiourgeitai 
					char *cmd = delshadow.toAscii().data();
					system(cmd);
					char *lines = delemptylines.toAscii().data();
					system(lines);
					unlink(SH_FILE".bak");
					link(SH_FILE, SH_FILE".bak");
					unlink(SH_FILE);
					unlink("/tmp/.shad");
					link("/tmp/.sh",SH_FILE);
					unlink("/tmp/.sh");
		
					//meta ti diagrafi to arxeio paramenei me dikaiomata root yia user kai root yia group.
					//kanonika tha prepei na einai group shadow.kai permissions forbitten yia allous, read kai write yia ton owner, kai read yia 
					//group .Prepei na allaksoun loipon ta permissions.
					chmod(SH_FILE,0640);
					struct group *grp;					
					grp = getgrnam("shadow");					
					chown ( SH_FILE, (uid_t)0 ,(gid_t)grp->gr_gid);
					}				
					char * logg  = username.toAscii().data();
					string  logdata(logg);
					string  path = "/home/" + logdata + "/.profile"; 
					string  pathways = "/home/" + logdata + "";
					const char * paths = path.c_str();
					QString pathway = path.data();
					//home directory tou xristi pou epilegetai.
					QString pathdir = pathways.data();

					//char *pat = pathways.c_str();
					chmod(paths,0700);
					chown ( paths, (uid_t)0 ,(gid_t)0 );
					
					FILE *pFile;
					pFile = fopen(paths ,"r+");
					
					if(pFile == NULL)//periptosi pou den vrethei to home directory !!
					{
						errno = ENOENT;
						QMessageBox::critical(0,tr("Error - User Manager"),tr("stat call on file '%1' failed.\n\n Error: '%2'" ).arg(pathdir).arg(strerror(errno)));
					}
					
					else
					{
					//diagrafi tou home directory tou xristi pou epilegetai.
					QString deldir = "rm -rf " + pathdir;
					char *rmdir = deldir.toAscii().data();
					system(rmdir);
					}
					if ( result == -1 )
						QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " User '%1' cannot be deleted from User 'Database' " ).arg ( username ) );
					if ( result != -1 )
					{
						QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " User '%1' deleted from Database " ).arg ( username ) );
						reloadUsersAndGroups();
											
						okk = QMessageBox::information(0,tr ("User Manager " ), tr ( " You are Using Private Groups.\n\n do you want to delete the User's Private Group '%1' ?").arg( grr->gr_name ),tr ( " &Delete  "),tr( "Do &Not Delete "));
					
						result2 = gr.rm_grMember( username );
					
						if (okk == 0 )
						{			
								
							groupBase  = fchk->fopen_wrapper ( GROUP_FILE,  "r+" );
							result  = gr.deleteGroup ( username );
							
							if ( result == -1 && result2 == -1 )
							QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " Group '%1' cannot be deleted from 'database' " ).arg ( username ) );
							if ( result != -1 && result2 != -1)
							QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " Group '%1' deleted from Database " ).arg ( username ) );
							reloadUsersAndGroups();
						}						
					
					}
			}
		}
	}
			if (fchk != nullptr)
			{
				delete fchk;
				fchk = nullptr;
			}


}
/**
 *Διαγραφή μιας ομάδας από το σύστημα όταν πατηθεί το κουμπί της διαγραφής ομάδων από την κύρια φόρμα.
 */
int  MainWindow::deleteGroup()
{
	MyLibb *fchk {new MyLibb()};
	FILE  *groupBase;
	Groups gr;
	int result;
	groupBase  = fchk->fopen_wrapper ( GROUP_FILE,  "r+" );
	QModelIndex index=groupTreeView->selectionModel()->currentIndex();
	int row=index.row();
	int gid=index.sibling ( row, 0 ).data( ).toInt();
	QString groupname=index.sibling ( row, 1 ).data( ).toString();
	if( groupname=="" || !index.isValid() || groupBase==NULL || index.row() == 0 || index.column() == 0 )
	{
	QMessageBox::information ( 0, tr ( " UserManager " ),tr ( " Please Select a Group to Delete !!" ) );
	}
	else if ( gr.isPrimary ( gid ) )
	{
		QString primUsersOfGroup ( gr.getPrimaryUsers ( gid ) );
		QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "Group %1 is the primary group of user(s) '%2' " ).arg ( groupname ).arg ( primUsersOfGroup ) ) ;
	}
	else
	{
		QModelIndex index = groupTreeView->selectionModel()->currentIndex ( );
		groupname=index.data().toString();
		int ok;
		ok = QMessageBox::warning ( 0, tr ( "User Manager" ), tr ( "Group '%1' is about to be deleted from Group Database.Are You sure you want to delete it? " ).arg ( groupname ) ,QMessageBox::Ok | QMessageBox::Cancel );
				if ( ok == 1024 )
				{
					result = gr.deleteGroup ( groupname );
					if ( result == -1 )
						QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " Group '%1' cannot be deleted from 'database' " ).arg ( groupname ) );
					if ( result != -1 )
					{
						QMessageBox::information ( 0, tr ( " User Manager " ), tr ( " Group '%1' deleted from Database " ).arg ( groupname ) );
						reloadUsersAndGroups();
						delete fchk;
						fchk = nullptr;
						return 0;
					}
				}	
	}
	if (fchk != nullptr)
	{
		delete fchk;
		fchk = nullptr;
	}
return 1;
}

/**
 *Εμφάνιση των στοιχείων του χρήστη που πατήθηκε από την λίστα στα editboxes στο κάτω μέρος της κύριας φόρμας.
 */

void MainWindow::getSelectedUserInfo( const QModelIndex &index )
{
	Users user;
	int row = index.row();
	UIDEdit->setText( index.sibling( row, 0 ).data( Qt::DisplayRole ).toString() );//0=UID column
	loginNameEdit->setText( index.sibling( row, 1 ).data( Qt::DisplayRole ).toString() );//1=loginname column
	realNameEdit->setText( index.sibling( row, 2 ).data( Qt::DisplayRole ).toString() );//2=realname column
	priGroupEdit->setText( user.getUsersPrimaryGroup( index.sibling( row, 0 ).data( Qt::DisplayRole ).toInt() ) );//getPrimaryGroup pernei UID apo 1h sthlh
	secGroupEdit->setText( user.getUsersSecondaryGroups( index.sibling( row, 1 ).data( Qt::DisplayRole ).toString() ) );//secondary groups
	
	if(user.isLocked(index.sibling( row, 1 ).data( Qt::DisplayRole ).toString()))//Enable & Disable
	{	
		statusEdit->setText(tr("Disabled"));
	}	
	else 
	{
		statusEdit->setText(tr("Enabled"));	
	}

}
/**
 *Εμφάνιση των στοιχείων της ομάδας που επιλέχθηκε από την λίστα των ομάδων στην κύρια φόρμα.
 */
void MainWindow::getSelectedGroupInfo( const QModelIndex &index )
{
	Models *model {new Models()};
	int row = index.row();
	QString  groupnameString = index.sibling( row, 1 ).data( Qt::DisplayRole ).toString();
	QByteArray groupnameArray = groupnameString.toLatin1();
	const char *groupName = groupnameArray.data();
	membersTree->setModel( model->createMembersModel( groupName ) );
	beautyTree( membersTree, 2 );
	delete 	model;
	model = nullptr;

}
/**
 *Καθαρισμός των editboxes
 */
void MainWindow::clearEditBoxes()
{
	UIDEdit->clear();
	loginNameEdit->clear();
	realNameEdit->clear();
	priGroupEdit->clear();
	secGroupEdit->clear();
}

/**
 *Δημιουργία event όταν πατηθούν τα enter,up,down από το πληκτρολόγιο,για ευκολότερη πλοήγηση στους χρήστες και τις ομάδες.
 */
bool MainWindow::eventFilter ( QObject* obj , QEvent* e )
{
	bool filtered = false;
if (obj==userTreeView || obj==groupTreeView)
{
	if ( tabWidget->currentIndex() ==0 )
	{
		if ( e->type () == QEvent::KeyRelease )
		{
			QModelIndex index=userTreeView->selectionModel()->currentIndex();
			QKeyEvent* k = ( QKeyEvent* ) e;

			if ( k->key () == Qt::Key_Up )
			{
				getSelectedUserInfo ( index );

				filtered = true;
			}
			if ( k->key () == Qt::Key_Down )
			{
				getSelectedUserInfo ( index );
				filtered = true;
			}
			if ( k->key() == Qt::Key_Return )
			{
				UserDetails();
				filtered = true;
			}      			
		}
	}
	if ( tabWidget->currentIndex() ==1 )
	{
		if ( e->type () == QEvent::KeyRelease )
		{
			QKeyEvent* k = ( QKeyEvent* ) e;
			QModelIndex index=groupTreeView->selectionModel()->currentIndex();
			if ( k->key () == Qt::Key_Up )
			{
				getSelectedGroupInfo ( index );

				filtered = true;
			}
			if ( k->key () == Qt::Key_Down )
			{
				getSelectedGroupInfo ( index );
				filtered = true;
			}
			if ( k->key() == Qt::Key_Return )
			{
				GroupDetails ( index );
				filtered = true;
			}

		}
	}
}
	

return filtered;
}

/**
 *Ρυθμίσεις εμφάνισης components της κύριας φόρμας,ανάλογα με το ποιο tab είναι ενεργοποιημένο (χρηστών ή ομάδων)
 */
void MainWindow::tabChanged( int tab )
{	
	     if ( tab == 0 )//tab xrhstwn energo
        {        
                searchUserBtn->setEnabled(true);
                searchGroupBtn->setEnabled(false);        
                addUserBtn->setEnabled(true);
                addGroupBtn->setEnabled(false);        
                delUserBtn->setEnabled(true);
                delGroupBtn->setEnabled(false);
                editBtn->setEnabled(true);
                //menu buttons
                menuDeleteGroup->setEnabled(false);
                menuEditGroup->setEnabled(false);
                menuDeleteUser->setEnabled(true);
                menuAddGroup->setEnabled(true);
                menuAddUser->setEnabled(true);
                menuEditUser->setEnabled(true);
                menuSetPassword->setEnabled(true);
                editGroupBtn->setEnabled(false);
                menuDiskUsage->setEnabled(true);

        }

	if( tab == 1 )//tab omadwn energo
	{
		searchUserBtn->setEnabled(false);
		searchGroupBtn->setEnabled(true);
		addUserBtn->setEnabled(false);
		addGroupBtn->setEnabled(true);	
		delUserBtn->setEnabled(false);
		delGroupBtn->setEnabled(true);
		editBtn->setEnabled(false);
		//menu buttons
		menuDeleteGroup->setEnabled(true);
		menuDeleteUser->setEnabled(false);
		menuAddGroup->setEnabled(true);
		menuAddUser->setEnabled(true);
		menuEditUser->setEnabled(false);
		menuSetPassword->setEnabled(false);
		menuEditGroup->setEnabled(true);
		editGroupBtn->setEnabled(true);
		menuDiskUsage->setEnabled(false);

        }

	
}

/**
 *Παρουσίαση πληροφοριών σε νέο παράθυρο για τον χρήστη που επιλέχθηκε,στο οποίο μπορούμε να τις επεξεργαστούμε 
 */

void MainWindow::UserDetails()
{
	Users *use{ new Users } ;
	struct finfo inf;
	struct spwd *sp;
	Models *model {new Models()};
	struct passwd p;
	sp = getspnam ( log.toAscii().data() );
	EditProperties *props { new EditProperties() };
	if (sp != nullptr)
		props->acct_shadow ( *sp );
	props->uiEdit->setText ( ui );
	props->LoginName->setText ( log );
	props->setOldUsername ( log );
	p.pw_name = log.toAscii().data();

	if(props->uiEdit->text() != "" || props->LoginName->text() != "")
	{
		p.pw_name = log.toAscii().data();
		if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 2)
		{
			office1 = inf.office;
			props->office1Edit->setText( office1 );
		}
		p.pw_name = log.toAscii().data();
		if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 2)
		{
			if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 3)
			{
				office2 = inf.office_phone;
				props->office2Edit->setText( office2 );
			}
		}
		p.pw_name = log.toAscii().data();
			
		if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 2)
		{
			if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 3)
			{
				if(( use->passwd_parse( getpwnam( p.pw_name ), &inf ) ) != 4)
				{
			
				address = inf.home_phone;
				props->addressEdit->setText( address );
				}		
			}
		}
	struct spwd *spw ;
	struct  tm *ltime;
	time_t time;
	time_t exp_time;
	char buff[256], day_buffer[256],month_buffer[256],year_buffer[256];
	char *login = log.toAscii().data();
	spw = getspnam ( login );
	*sp = *spw;
	props->userGroups->setModel(model->createUserInGroupsModel(props->getOldUsername()));
	props->userGroups->setColumnWidth ( 0, 30);
	setlocale (LC_ALL, "C");
	if ( sp->sp_expire != -1 )
	{
	exp_time = spw->sp_expire*3600*24;
	ltime = localtime(&exp_time);
	strftime(day_buffer,256,"%d ",ltime);
	strftime(month_buffer,256,"%B",ltime);
	strftime(year_buffer,256,"%Y ",ltime);
	int day = atoi(day_buffer);
	int year = atoi(year_buffer);
	props->days->setValue(day);
	string  mon(month_buffer);
	const QString mont = mon.data(); 

	//emfanizei sto deftero tab stin edit properties tous mines kataxorimenous sto combobox
	if (mont == "january") 
		props->months->setCurrentIndex(0);
	else if(mont == "February" )
		props->months->setCurrentIndex(1);
	else if(mont ==  "March" )
		props->months->setCurrentIndex(2);
	else if(mont ==  "April"	)
		props->months->setCurrentIndex(3);
	else if(mont ==  "May"   )
		props->months->setCurrentIndex(4);
	else if(mont ==  "June"	)
		props->months->setCurrentIndex(5);
	else if(mont ==  "July"	)
		props->months->setCurrentIndex(6);
	else if(mont ==  "August")
		props->months->setCurrentIndex(7);
	else if(mont ==  "September")
		props->months->setCurrentIndex(8);
	else if(mont ==  "October")
		props->months->setCurrentIndex(9);
	else if(mont ==  "November")
		props->months->setCurrentIndex(10);
	else if(mont ==  "December")
		props->months->setCurrentIndex(11);
	
	props->years->setValue(year);
	props->alway->setChecked(false);
	props->months->setEnabled(true);
	props->days->setEnabled(true);
	props->years->setEnabled(true);
	}
	else 
	{
	props->alway->setChecked(true);
	props->months->setEnabled(false);
	props->days->setEnabled(false);
	props->years->setEnabled(false);
	}
	if ( spw->sp_lstchg != 0 )
	{
	time=spw->sp_lstchg*3600*24;
	ltime = localtime(&time);
	strftime(buff,256," %A  %d  %B  %Y  ",ltime);// %H:%M
	props->datetime->setText( buff );
	}
	else
	{
	QString bbuf = " ";
	props->datetime->setText( bbuf );
	}
	props->FullNameEdit->setText( fnam  );
	props->DirEdit->setText( dir  );
	props->shellConnect->addItems( shell );
	if(statusEdit->text() == "Disabled")
	props->checkBoxEdit->setCheckState(Qt::Checked);
	props->primGroupLabel->setText(use->getPrimaryGroup(props->getOldUsername()));
	props->comboShell();
	props->setModal(true);
	props->setWindowTitle("User Properties - " +props->LoginName->text()+"");
	if ( props->exec() ){}
		reloadUsersAndGroups();

	}

	if (model != nullptr)
	{delete model; model = nullptr;}

	if (use != nullptr)
	{delete use; use = nullptr;}

}

/**
 *Εκκίνηση μέτρησης του χώρου που καταλαμβάνουν οι χρήστες στο σύστημα ή επαναφόρτωση των λιστών χρηστών/ομάδων(αν είχε ήδη πατηθεί το checkbox)
 */
void MainWindow::folderSizeCheckBoxClicked()
{
	if ( !folderSizeCheckBox->isChecked() )
	{
		reloadUsersAndGroups();
		menuDiskUsage->setEnabled(true);
	}
	else
	{	
		calculateFolderSize();
	}
}

/**
 *Υπολογισμός μέτρησης του χώρου που καταλαμβάνουν οι χρήστες στο σύστημα.
 */
void MainWindow::calculateFolderSize()
{
	QProgressDialog progressBar(tr("Calculating sizes..."),tr("Abort"), 0, 100, this);
	setCursor(Qt::WaitCursor);
     	progressBar.setWindowModality(Qt::WindowModal);	
	qApp->processEvents();
	Users *usr {new Users()};
	struct passwd *user = new passwd();
	int i = 0;
 	float cnt=1,totalUsers=0,progress=0;// parolo pou einai int kanonika an ta dhlwsw san int den leitourgei h progressbar swsta
	QString sizeString;
	QStringList sizeList;
	uint64_t totalSize = 0;//unsigned long int
	Models *model {new Models()};
	totalUsers=usr->countUsers();
	setpwent();
   	while (( user = getpwent() ) )
	{

		
		char *dir = user->pw_dir;
		string dirString = dir;
		char path[PATH_MAX] = "\0"; //PATH_MAX == 4096 xarakthres megisth diadromh.arxikopoihsh me \0 giati alliws exei skpoupidia kai mperdeyetai h getSize
		for ( i = 0; i < (int)dirString.length(); i++ )//string se char[]
		{
			path[i] = dirString[i];
		}
		if ( path[strlen( path )-1] != '/' )
			strcat( path, "/" );
		totalSize = 0;//mhdenismos giati merikoi home fakeloi den yparxoun,kai an den mhdenistei krataei to mege8os tou teleytaiou fakelou poy yphrxe kai metrh8hke
		totalSize += usr->getSize( path );
		if ( totalSize < 1000 && totalSize>0) //if < 1kb
		{
			sizeString.setNum( totalSize ) ;//bytes
			sizeString.append( " B" );
		}
		else if ( totalSize < 1000000 && totalSize>1000) //if < 1mb
		{
			uint64_t finalSize = ( totalSize / 1024 );//bytes->kb
			sizeString.setNum( finalSize ) ;
			sizeString.append( " KB" );
		}
		else if ( totalSize > 1000000 ) //if > 1mb
		{
			uint64_t finalSize = ( totalSize / 1024 / 1024 );//bytes->mb
			sizeString.setNum( finalSize ) ;
			sizeString.append( " MB" );
		}
		else 
		sizeString="-"; //an totalsize=0 h den yparxei o fakelos 
		
		sizeList.append( sizeString );
		progress=(cnt/totalUsers)*100;

		//progressBar->setTextVisible(true);
		progressBar.setValue(int(progress));
		//qApp->processEvents();
		cnt++;
		if (progressBar.wasCanceled())
		{
		folderSizeCheckBox->setChecked(false);
             	goto canceled;
		}
	}
endpwent();
	progressBar.deleteLater();
	userModel = model->createUsersModelWithSizes( sizeList );
	userTreeView->setModel( userModel );
	beautyTree( userTreeView, 6 );
	unsetCursor();
folderSizeCheckBox->setChecked(true);
menuDiskUsage->setEnabled(false);
canceled:
{}
delete user;
delete usr;
delete model;
}
/**
 *Εμφάνιση νέου παραθύρου στο οποίο μπορούμε να επεξεργαστούμε τα δεδομένα των ομάδων του συστήματος.
 */
void MainWindow::GroupDetails( const QModelIndex &index )
{
	Models *model {new Models};
	int row = index.row();
	QString  groupnameString = index.sibling( row, 1 ).data( Qt::DisplayRole ).toString();
	QByteArray groupnameArray = groupnameString.toLatin1();
	const char *groupName = groupnameArray.data();
	GroupProperties *grProps = new GroupProperties;
	
	grProps->membersList->setModel( model->UsersInGroupModel( groupName ) );
	grProps->notMembersList->setModel( model->UsersNotInGroupModel( groupName ) );
	grProps->GIDLabel->setText( index.sibling( row, 0 ).data( Qt::DisplayRole ).toString() );
	grProps->groupNameEdit->setText( index.sibling( row, 1 ).data( Qt::DisplayRole ).toString() );
	grProps->GIDEdit->setVisible(false);
	grProps->newGroupBtn->setVisible(false);
	grProps->setOldGroupName(grProps->groupNameEdit->text());
	grProps->setWindowTitle("Group Properties - " + grProps->groupNameEdit->text()+"");
	grProps->show();
if ( grProps->exec() ){}
			reloadUsersAndGroups();
			delete grProps;
			delete model;

}

/**
 *Εκκίνηση ενέργειας εισαγωγής νέας ομάδας όταν πατηθεί το κουμπί εισαγωγής ομάδων από την κύρια φόρμα.
 */

void MainWindow::addGroupBtnClicked()
{
GroupProperties *newGroup = new GroupProperties;
QString gid;
newGroup->GIDEdit->setText(gid.setNum(newGroup->groupStudy(0))); //epomeno eley8ero GID
newGroup->setWindowTitle("Add Group");
newGroup->GIDEdit->setVisible(true);
newGroup->addBtn->setEnabled(false);
newGroup->removeBtn->setEnabled(false);

newGroup->show();
if ( newGroup->exec() ){}
			reloadUsersAndGroups();
			delete newGroup;

}
/**
 *Άνοιγμα της φόρμα ρυθμίσεων της εφαρμογής όταν επιλεχθεί από το μενού.
 */
void MainWindow::openSettings()
{
Settings *settings = new Settings;
settings->show();
if ( settings->exec() ){}
delete settings;
}
/**
 *Δημιουργία αντιγράφου των etc/passwd /etx/group κσι /etc/shadow όταν επιλεχθεί από το
 μενού.Χρησιμοποιείται το εργαλείο tar και δημιοουργείται ένα αρχείο με το όνομα backup το οποίο ακολουθείται από την ημερομηνία και τα δευτερόλεπτα που έγινε το αντίγραφο.
 */
void MainWindow::createBackup()
{
int ret = QMessageBox::information( this,tr ( "User Manager" ),tr ( "This will create a backup file containing /etc/passwd,/etc/group and /etc/shadow files, in the /tmp directory." ) ,QMessageBox::Ok | QMessageBox::Cancel);

if (ret==1024)//1024 epistrefei an path8ei to ok
{
if ((system("tar -cvvf /tmp/backup$(date +'%Y%m%d%S').tar /etc/passwd  /etc/group  /etc/shadow") && system("sudo chmod 600 /tmp/backup$(date +'%Y%m%d%S').tar"))==0)//me allagh dikaiwmatwn gia na einai prosvasimo mono ston root
QMessageBox::information(0,tr ( "User Manager" ),tr ( "Backup Created" ) );
else 
QMessageBox::information(0,tr ( "User Manager" ),tr ( "Error:Backup not created" ) );
}
}
/**
 *Εμφανίζει την φόρμα με τις πληροφορίες της εφαρμογής.
 */
void MainWindow::aboutUserManager()
{
About *about = new About;
about->show();
if ( about->exec() ){}
delete about;
}

