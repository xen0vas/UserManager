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

    Spc *spc = new Spc();

    spc->clenv();

	foreach ( QModelIndex index, indexes )
	{

        // TO-DO : find program from PATH but first use spc->clenv() to clear the environmental variables
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

    delete spc;

}

/**
 * Αφαιρεί μέλη από μια ομάδα.Εκτελείται όταν πατηθεί το κουμπί με τον τίτλο “Remove” στην φόρμα των ομάδων.
    Για κάθε ένα χρήστη που είναι προς απομάκρυνση καλείται η remove_member από την κλάση MyLibb η οποία αφαιρεί τον χρήστη από την ομάδα
    και έπειτα καλείται η setgrnam από την κλάση Groups η οποία βάζει μέσα στο /etc/group την νέα δομή της ομάδας χωρίς τον χρήστη που
    αφαιρέθηκε 
    Στο τέλος εκτελείται ο sed για να καθαρίσει πιθανά υπολείμματα κομμάτων από το /etc/group
 */

void GroupProperties::removeMembers( )
{
	Groups groups;
	Models model;
	struct group *grs = NULL;
	MyLibb set;

    char *gname = (char*)calloc(1, sizeof(getOldGroupName().toLatin1().data()));

    memcpy(gname, getOldGroupName().toLatin1().data(), strlen(getOldGroupName().toLatin1().data()));

	char *username;
	grs=getgrnam(gname);

    QModelIndexList indexes = membersList->selectionModel()->selectedIndexes();
	foreach ( QModelIndex index, indexes )
	{
	username=index.data().toByteArray().data();
	groups.remove_member(grs,username);
	set.setgrnam(grs);
	}

    //Spc *spc = new Spc();
    //spc->clenv();

    QString program = "/usr/bin/sed ";
    QString ed = "s/,,/,/g;s/,$//g"; //replaces two commas with one
    QString groupfile = "/etc/group";

    QStringList arguments;

    arguments << "-i" << ed << groupfile  ;

    QProcess process;
    process.start(program, arguments);
    process.waitForStarted();
    process.waitForFinished();

    arguments.clear();

	notMembersList->setModel ( model.UsersNotInGroupModel ( getOldGroupName().toLatin1().data() ) );
	membersList->setModel ( model.UsersInGroupModel ( getOldGroupName().toLatin1().data() ) );

    if (gname != NULL) { free (gname); gname = NULL;}
    //if ( spc != NULL ) delete spc;

}
/**
 * Η παραπάνω συνάρτηση χρησιμοποιείται για να αλλάξει το όνομα μιας ομάδας.
   Καλεί μέσω της system το εργαλείο groupmod με την παράμετρο -n το οποίο αλλάζει το όνομα της ομάδας. 
 */

bool GroupProperties::renameGroup()
{
Spc * sec = new Spc();
QRegExp rx ( "[:.'|<>?/*\\+=&*%]" );
int res = 0 ;
int pos = 0;
int count = 0;

char *groupname = (char*)calloc( 1, sizeof(groupNameEdit->text().toLatin1().data()) );

    // check if memory allocated succesully to avoid undefined behaviours and potential security issues
    if ( groupname == NULL )
    {
            QMessageBox::critical( 0,tr ( "User Manager" ),tr ( "Could not allocate memory - %1" ).arg(errno));
            return -1;
    }
    else
    {
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
                sec->clenv();

                QString program = "/usr/sbin/groupmod";
                QStringList arguments;

                arguments << "-n" << gname << getOldGroupName() ;

                QProcess *process = new QProcess();
                process->start(program, arguments);
                process->waitForFinished();
                arguments.clear();
            }
    }
delete sec;

if (groupname != NULL) { free(groupname); groupname = NULL ; }

return true;
this->~GroupProperties();
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
    QRegExp rx ( "[:.'|<>?/*\\&;%*]" );//ayta den ta 8eloume sto editbox

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
	MyLibb *fchk = NULL;
	QByteArray pass = "x";


disconnect ( okBtn, SIGNAL ( clicked() ), this, SLOT ( renameGroup() ) ); //disconnect to signal giati to rename eiani gia edit tou group kai den xreiazetai otan vazoume neo group na ginei kai rename.
if (groupNameEdit->text()==NULL || GIDEdit->text()==NULL)
{
QMessageBox::information ( 0,tr ( "User Manager" ),tr ( "Insert Group Name" ));
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
	return result;
}
}

