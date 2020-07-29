#include "MainWindow.h"
#include <iostream>
#include "myLibb.h"
#include "spc.h"

/**
 * Constructor κλάσης/φόρμας
 */

GroupProperties::GroupProperties ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	setModal ( true );
	QValidator *validator = new QIntValidator(1, 65535, this);
	GIDEdit->setValidator(validator);	
	connect ( addBtn, SIGNAL ( clicked( ) ), this, SLOT ( addMembers( ) ) );
	connect ( removeBtn, SIGNAL ( clicked( ) ), this, SLOT ( removeMembers( ) ) );
	connect ( groupNameEdit, SIGNAL ( textEdited ( const QString & ) ), this, SLOT ( checkGroupname ( const QString & ) ) );
	connect ( GIDEdit, SIGNAL ( textEdited ( const QString & ) ), this, SLOT ( checkGID ( const QString & ) ) );
	connect ( okBtn, SIGNAL ( clicked() ), this, SLOT ( renameGroup() ) );
	connect ( okBtn, SIGNAL ( clicked() ), this, SLOT ( close() ) );
	connect ( newGroupBtn, SIGNAL ( clicked() ), this, SLOT ( addNewGroup() ) );
}

//****************************************************************************************************
/**
 *Destructor κλάσης/φόρμας
 */
GroupProperties::~GroupProperties()
{}
/**
 * Αποθηκεύει σε μια private μεταβλητή της κλάσης το όνομα της ομάδας που επιλέχθηκε για επεξεργασία.
 */
void GroupProperties::setOldGroupName ( QString oldGroupName )
{
	oldGroupName_ = oldGroupName;
}
/**
 * Συνάρτηση η οποία διαβάζει την μεταβλητή του ονόματος της ομάδας που κρατιέται στην κλάση από την συνάρτηση setOldGroupName.
 */
QString GroupProperties::getOldGroupName()
{
	return oldGroupName_;
}
/**
 * This functions searches the system Groups at /etc/group in order to find the next available free Group ID - GID .
 */
int GroupProperties::groupSearch(gid_t uid_n)
{
	struct group *grp = NULL;
	Settings settings;
	gid_t  tmp_gid;
	gid_t  max = 65535;
	const char  *file = "/etc/group";
	FILE  *fp;
	int i = 0;
	fp = fopen ( file, "r" );
    tmp_gid = atoi ( settings.getconf ( "MINIMUM_GID" ).c_str() );
	setgrent();

	while ( ( grp = getgrent() ) )
	{
		if(grp->gr_gid <= max)
		if ( grp->gr_gid==tmp_gid )
		{
			if(tmp_gid != uid_n && uid_n != 0)
                i++;

			tmp_gid++;
			endgrent();
		}
	}
	fclose ( fp );
	if(tmp_gid>max)
        QMessageBox::information( 0,tr("User Manager " ), tr ("Reached maximum number of groups"));

	return tmp_gid;
}
/**
 * Προσθέτει μέλη σε μια ομάδα. Εκτελείται όταν πατηθεί το κουμπί με τον τίτλο “Add” στην φόρμα των ομάδων.
   Για κάθε επιλεγμένο χρήστη δημιουργείται μια εντολή η οποία με κλήση της system εκτελόντας την εντολή στο κέλυφος.	
 */
void GroupProperties::addMembers( )
{
	Models model;
	QModelIndexList indexes = notMembersList->selectionModel()->selectedIndexes();

	foreach ( QModelIndex index, indexes )
	{


        QString program = "/usr/sbin/addgroup";
        QStringList arguments;

        arguments << index.data().toString() << getOldGroupName() ;

        QProcess *process = new QProcess();
        process->start(program, arguments);

        process->waitForFinished();
        arguments.clear();

	}

		notMembersList->setModel ( model.UsersNotInGroupModel ( getOldGroupName().toLatin1().data() ) );
		membersList->setModel ( model.UsersInGroupModel ( getOldGroupName().toLatin1().data() ) );

}


/**
 * @brief GroupProperties::removeMembers
 * This function removes user members from a Group.
 * The user selects the member and then clicks on 'remove' button in order to remove the member from the group
 * for every user member that needs to be removed the 'remove_member' function is called from myLibb class.
 * After the user member removal, the setgrnam function is called from the class Group which recreates the file /etc/group with the new stracture where
 * the deleted user member is not included. At the end, the third party program 'sed' is called in order to clean any unwanted characters from inside
 * the file /etc/group
 */

void GroupProperties::removeMembers( )
{
	Groups groups;
	Models model;
    MyLibb set;

    size_t len = strlen(getOldGroupName().toLatin1().data());

    char *gname = NULL;

    // bware for overflows
    if ( len == 0 || len > SIZE_MAX / sizeof(char))
        QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Possible overflow due to wrong sting length: %1" ).arg(errno));
    else
    {
    gname = (char*)calloc(len, sizeof(getOldGroupName().toLatin1().data()));

    char *username = NULL;

    char *ptr;

    username = (char*)malloc(sizeof(char));

    if ( username == NULL )
    {
        errno = ENOMEM;
        QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory : %1" ).arg(errno));
    }
    else
    {
    if ( gname != NULL )
    {

    Spc *sec = new Spc();

    memcpy(gname, getOldGroupName().toLatin1().data(), len);

    bool allocate = true;

    struct group *grs;

	grs=getgrnam(gname);

	QModelIndexList indexes = membersList->selectionModel()->selectedIndexes();

    size_t index_len;
	
	foreach ( QModelIndex index, indexes )
    {

       index_len = (size_t)strlen(index.data().toByteArray().data());

       if ( len == 0 || len > SIZE_MAX / sizeof(char) )
       {
           allocate = false ;
           errno = ENOMEM;
           QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Possible overflow due to wrong sting length: %1" ).arg(errno));
           break;
       }
       else
       {

       ptr = (char*)realloc(username,(size_t)index_len*2);

       if ( ptr != NULL )
       {
          memcpy(ptr, index.data().toByteArray().data(), index_len+1);
          username[index_len] = '\0';
          username = ptr ;
          groups.remove_member(grs,username);
          set.setgrnam(grs);
       }
       else if ( ptr == NULL )
       {
             if ( username != NULL )
             {
                  free(username);
                  username = NULL;
             }
             allocate = false ;
             errno = ENOMEM;
             QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory : %1" ).arg(errno));
             break;
       }

       }
	}

    if ( allocate != false )
    {
    sec->clenv(); // clear environment

    QProcess process;
    QString program = "sed";
    QString ed = "s/,,/,/g;s/,$//g";
    QString groupfile = "/etc/group";
    QStringList arguments;

    arguments << "-i" << ed << groupfile  ;
    process.start(program, arguments);
    process.waitForStarted();
    process.waitForFinished();
    arguments.clear();

    arguments << "-i" << ed << groupfile  ;
    process.start(program, arguments);
    process.waitForStarted();
    process.waitForFinished();
    arguments.clear();

    notMembersList->setModel ( model.UsersNotInGroupModel ( getOldGroupName().toLatin1().data() ) );
    membersList->setModel ( model.UsersInGroupModel ( getOldGroupName().toLatin1().data() ) );
    }

    if ( sec != NULL ) { delete sec; sec = NULL; }
    if (gname != NULL) { free (gname); gname = NULL;}
    if (username != NULL ) { free(username); username = NULL; }
    }
    else
    {
        errno = ENOMEM;
        QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory - %1" ).arg(errno));
    }
  }
    }
}


/**
 * Η παραπάνω συνάρτηση χρησιμοποιείται για να αλλάξει το όνομα μιας ομάδας.
   Καλεί μέσω της system το εργαλείο groupmod με την παράμετρο -n το οποίο αλλάζει το όνομα της ομάδας. 
 */

bool GroupProperties::renameGroup()
{
//Spc * sec = new Spc();
QRegExp rx ( "[:.'|<>?/*\\+=&*%]" ); // check out this invalid chars

size_t len = strlen(groupNameEdit->text().toLatin1().data());

if ( len == 0 || len > SIZE_MAX / sizeof(char) )
{
    errno = ENOMEM;
    QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory - %1" ).arg(errno));
    return false;
}
else
{

char *groupname = (char*)calloc( 128, len);

    // check if memory allocated succesully to avoid undefined behaviours and potential security issues
    if ( groupname == NULL )
    {
            errno = ENOMEM;
            QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory - %1" ).arg(errno));
            return false;
    }
    else
    {
            int res = 0 ;
            int count = 0;
            int pos = 0;

            memcpy(groupname, groupNameEdit->text().toLatin1().data(), strlen(groupNameEdit->text().toLatin1().data()));

            QString gname = QString::fromUtf8(groupname);

            res = rx.indexIn(gname, pos);

            while ( (res != -1))
            {
                count++;
                pos+= rx.matchedLength();
            }

            if ( pos == -1)
            {
                //sec->clenv(); we dont need to clear the environment since we get the full path of the groupmod program

                QString program = "/usr/sbin/groupmod";
                QStringList arguments;

                arguments << "-n" << gname << getOldGroupName() ;

                QProcess *process = new QProcess();
                process->start(program, arguments);
                process->waitForFinished();
                arguments.clear();

            }

             free(groupname);
             groupname = NULL ;
    }

}
return true;
}

/**
 * Συνάρτηση η οποία σαρώνει το αρχείο των ομάδων και ενημερώνει τον διαχειριστή για πιθανή απόπειρα προσθήκης/μετονομασίας μιας ομάδας,
 * με όνομα όμως το οποίο υπάρχει ήδη  στο σύστημα.
 */

void GroupProperties::checkGroupname ( const QString &text )
{
	okBtn->setEnabled ( true );
	existsLabel->clear();
	struct group *grp;
    	QRegExp rx ( "[:.'|<>?/*\\&;%*]" );

	setgrent();

	while ( ( grp = getgrent() ) )
	{
		if ( ( grp->gr_name == text ))
{
			groupNameEdit->setStyleSheet ( "border: 4px solid red;" );
			existsLabel->setText ( tr ( "*%1 already exists*" ).arg(groupNameEdit->text()) );
			newGroupBtn->setEnabled ( false );
			okBtn->setEnabled ( false );
	break;
}
else{

			groupNameEdit->setStyleSheet ( " " );//den yparxei to onoma
			existsLabel->setText ( "" );
			newGroupBtn->setEnabled ( true );
			okBtn->setEnabled ( true );
}
}
	endgrent();
if ( ( groupNameEdit->text()=="" ))
{
		newGroupBtn->setEnabled ( false );
		okBtn->setEnabled ( false );
		existsLabel->clear();
		groupNameEdit->setStyleSheet ( " " );
}
	else if (text==getOldGroupName())
	{
		newGroupBtn->setEnabled ( false );
		okBtn->setEnabled ( false );	
	}
	else if (text.contains(rx))
	{
		newGroupBtn->setEnabled ( false );
		okBtn->setEnabled ( false );	
	}
	else if (text.contains(" "))
{

		newGroupBtn->setEnabled ( false );
		okBtn->setEnabled ( false );	
}

}
/**
 * Συνάρτηση η οποία σαρώνει το αρχείο των ομάδων και ενημερώνει τον διαχειριστή στην περίπτωση που προσπαθήσει να προσθέσει στο σύστημα ομάδα με GROUP ID το οποίο είναι κατειλημμένο από άλλη ομάδα του συστήματος.

 */
void GroupProperties::checkGID ( const QString &text )

{
	struct group *grp;
	gid_t Gid = text.toInt();
	if ( Gid<65535&&Gid>0 )
	{

		okBtn->setEnabled ( true );
		newGroupBtn->setEnabled ( true );
		setgrent();
		while ( ( grp = getgrent() ) )
		{

			if ( ( grp->gr_gid != Gid ) )  //an den yparxei to gid anamesa sta gid twn group
			{

				GIDEdit->setStyleSheet ( " " );//den yparxei to onoma
				existsLabel->setText ( "" );
				newGroupBtn->setEnabled ( true );
				okBtn->setEnabled ( true );
			}
			else		//to onoma tou group yparxei hdh
			{
				GIDEdit->setStyleSheet ( "border: 4px solid red;" );
				existsLabel->setText ( tr ( "GID *%1 already exists*" ).arg ( GIDEdit->text() ) );
				newGroupBtn->setEnabled ( false );
				okBtn->setEnabled ( false );
				break;
			
			}
			
			}
			endgrent();	
	}
if ( GIDEdit->text() =="" )
{
	GIDEdit->setStyleSheet ( "" );
	existsLabel->setText ( tr ( "" ) );
}

}

/**
 * Προσθήκης νέας ομάδας στο σύστημα.	
   Δημιουργείται η δομή προς εισαγωγή και έπειτα προστίθεται η ομάδα μέσω της putgrent().
 */

int GroupProperties::addNewGroup()
{
    MyLibb *fchk = new MyLibb();
	QByteArray pass = "x";


disconnect ( okBtn, SIGNAL ( clicked() ), this, SLOT ( renameGroup() ) ); //disconnect to signal giati to rename eiani gia edit tou group kai den xreiazetai otan vazoume neo group na ginei kai rename.
if (groupNameEdit->text()==NULL || GIDEdit->text()==NULL)
{
QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "Insert Group Name" ));
   if (fchk != NULL) { delete fchk; fchk = NULL; }
   return 1;
}
else
{
	
	gid_t groupID = GIDEdit->text().toInt();
	struct group grp;
	grp.gr_name = groupNameEdit->text().toLatin1().data() ;
	grp.gr_passwd = pass.data();
	grp.gr_gid = groupID  ;
	grp.gr_mem = NULL;
    FILE *groupbase;

	const char *filename = "/etc/group";
	int result = 0 ;


    groupbase = fchk->fopen_wrapper ( filename, "a+" );

    if ( groupbase!=NULL )
    {

		result = putgrent ( &grp, groupbase );
        fclose ( groupbase );
    }
    else
    {
         QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate create Group - %1" ).arg(errno));
    }

	if ( result==0 )
	{
		Models model;
		
		QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "Group %1 added" ).arg ( groupNameEdit->text() ) );
		newGroupBtn->setVisible(false);
		notMembersList->setModel ( model.UsersNotInGroupModel ( groupNameEdit->text().toLatin1().data()) );
		membersList->setModel ( model.UsersInGroupModel ( groupNameEdit->text().toLatin1().data() ) );

		setOldGroupName ( groupNameEdit->text().toLatin1().data() );//prepei na dhlw8ei oti to oldgroupname einai pleon to onoma tou kainourgiou group pou valame gia na mporesei na leitourghsei h addmembers() kai h removemembers() pou exoun san orisma to onoma tou group.an den dhlw8ei edw to oldgroupname 8a einai keno epeidh otan dhmiourgh8hke h forma to name sto groupNameEdit htan keno
		newGroupBtn->setEnabled ( false );
		addBtn->setEnabled ( true );
		removeBtn->setEnabled ( true );
    }
    if (fchk != NULL) { delete fchk; fchk = NULL; }
	return result;
}
}

