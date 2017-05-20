#include "models.h"

/**
 * Constructor κλάσης
 */

Models::Models()
{}

/**
 * Destructor κλάσης
 */
Models::~Models()
{}
/**
 * Δημιουργεί το μοντέλο λίστας των χρηστών το οποίο εμφανίζεται στην κύρια φόρμα της εφαρμογής.
 */
QStandardItemModel *Models::createUsersModel( )
{	
	setpwent();	
	
	struct passwd *users; 
 	struct finfo info;
	QStandardItemModel *model = new QStandardItemModel( 0, 6 );
	model->setHeaderData( 0, Qt::Horizontal, QObject::tr( "UID" ) );
	model->setHeaderData( 1, Qt::Horizontal, QObject::tr( "Login Name" ) );
	model->setHeaderData( 2, Qt::Horizontal, QObject::tr( "Real Name" ) );
	model->setHeaderData( 3, Qt::Horizontal, QObject::tr( "Home Directory" ) );
	model->setHeaderData( 4, Qt::Horizontal, QObject::tr( "Default Shell" ) );
	model->setHeaderData( 5, Qt::Horizontal, QObject::tr( "Disk Usage" ) );
	Users *us ;	
		while (( users = getpwent() ) )
	{
		us->passwd_parse(getpwnam(users->pw_name),&info);
		model->insertRow( 0 );
		QModelIndex UID = model->index( 0, 0 );
		QModelIndex loginName = model->index( 0, 1 );
		QModelIndex realName = model->index( 0, 2 );
		QModelIndex homeDir = model->index( 0, 3 );
		QModelIndex defaultShell = model->index( 0, 4 );
		QModelIndex diskUsage = model->index( 0, 5 );	
		QString userName = QString::fromAscii( users->pw_name );
				
				if (us->isLocked(userName))
					model->setData(UID,QVariant(QImage("/usr/share/apps/UserManager/pics/lock.png")),Qt::DecorationRole);
				else
					model->setData(UID,QVariant(QImage("/usr/share/apps/UserManager/pics/enabled.jpeg")),Qt::DecorationRole);
				
		model->setData( UID, users->pw_uid ) ;
		model->setData( loginName, users->pw_name  );
		model->setData( realName, info.full_name);
		model->setData( homeDir, users->pw_dir );
		model->setData( defaultShell, users->pw_shell );
		model->setData( diskUsage, QVariant( QString( " " ) ) );		
	}
	endpwent();
	return model;
}
/**
 * Δημιουργεί το μοντέλο λίστας των χρηστών στο οποίο εμφανίζεται και η κατανάλωση δίσκου του κάθε χρήστη.
 */
QStandardItemModel *Models::createUsersModelWithSizes( QStringList sizeList )
{


	setpwent();
	struct finfo info;
	struct passwd *users;
	QStandardItemModel *model = new QStandardItemModel( 0, 6 );
	model->setHeaderData( 0, Qt::Horizontal, QObject::tr( "UID" ) );
	model->setHeaderData( 1, Qt::Horizontal, QObject::tr( "Login Name" ) );
	model->setHeaderData( 2, Qt::Horizontal, QObject::tr( "Real Name" ) );
	model->setHeaderData( 3, Qt::Horizontal, QObject::tr( "Home Directory" ) );
	model->setHeaderData( 4, Qt::Horizontal, QObject::tr( "Default Shell" ) );
	model->setHeaderData( 5, Qt::Horizontal, QObject::tr( "Disk Usage" ) );
	int i=0;
	Users *us { new Users()} ;

	while (( users = getpwent() ) )
	{
		us->passwd_parse(getpwnam(users->pw_name),&info);
		model->insertRow( 0 );
		QModelIndex UID = model->index( 0, 0 );
		QModelIndex loginName = model->index( 0, 1 );
		QModelIndex realName = model->index( 0, 2 );
		QModelIndex homeDir = model->index( 0, 3 );
		QModelIndex defaultShell = model->index( 0, 4 );
		QModelIndex diskUsage = model->index( 0, 5 );	
		QString userName = QString::fromAscii( users->pw_name );
				
				if (us->isLocked(userName))
				model->setData(UID,QVariant(QImage("/usr/share/apps/UserManager/pics/lock.png")),Qt::DecorationRole);
				else
				model->setData(UID,QVariant(QImage("/usr/share/apps/UserManager/pics/enabled.jpeg")),Qt::DecorationRole);
				
		model->setData( UID, users->pw_uid ) ;
		model->setData( loginName, users->pw_name );
		model->setData( realName, info.full_name);
		model->setData( homeDir, users->pw_dir );
		model->setData( defaultShell, users->pw_shell );
		model->setData( diskUsage,sizeList[i]);		
		i++;
	}
	endpwent();
	delete us;
	us=nullptr;
	return model;
}

/**
 * Δημιουργεί το μοντέλο λίστας των ομάδων του σύστηματος.
 */
QStandardItemModel *Models::createGroupsModel(  )
{
	struct group *groups;	
	setgrent();
	QStandardItemModel *model = new QStandardItemModel( 0, 2 );
	model->setHeaderData( 0, Qt::Horizontal, QObject::tr( "GID" ) );
	model->setHeaderData( 1, Qt::Horizontal, QObject::tr( "Group Name" ) );
	while (( groups = getgrent() ) )
	{
		model->insertRow( 0 );
		QModelIndex GID = model->index( 0, 0 );
		QModelIndex groupName = model->index( 0, 1 );

		model->setData( GID, groups->gr_gid ) ;
		model->setData( groupName, groups->gr_name );
	}
	endgrent();
	return model;
}


/**
 * Δημιουργεί το μοντέλο του χρήστη που αναζητήθηκε στο σύστημα.
 */
QStandardItemModel *Models::createFoundedGroupModel( struct group *grp )
{
	setgrent();
	QStandardItemModel *model = new QStandardItemModel( 0, 2 );
	model->setHeaderData( 0, Qt::Horizontal, QObject::tr( "GID" ) );
	model->setHeaderData( 1, Qt::Horizontal, QObject::tr( "Group Name" ) );

	model->insertRow( 0 );
	QModelIndex GID = model->index( 0, 0 );
	QModelIndex groupName = model->index( 0, 1 );

	model->setData( GID, grp->gr_gid ) ;
	model->setData( groupName, grp->gr_name );
	
	endgrent();
	return model;
}

/**
 * Δημιουργεί το μοντέλο της ομάδας που αναζητήθηκε στο σύστημα.
 */
QStandardItemModel *Models::createFoundedUserModel( struct passwd *usr )
{
	Users *user;
	QString sizeString;
	QStandardItemModel *model = new QStandardItemModel( 0, 6 );
	model->setHeaderData( 0, Qt::Horizontal, QObject::tr( "UID" ) );
	model->setHeaderData( 1, Qt::Horizontal, QObject::tr( "Login Name" ) );
	model->setHeaderData( 2, Qt::Horizontal, QObject::tr( "Real Name" ) );
	model->setHeaderData( 3, Qt::Horizontal, QObject::tr( "Home Directory" ) );
	model->setHeaderData( 4, Qt::Horizontal, QObject::tr( "Default Shell" ) );
	model->setHeaderData( 5, Qt::Horizontal, QObject::tr( "Disk Usage" ) );
	{
		model->insertRow( 0 );
		QModelIndex UID = model->index( 0, 0 );
		QModelIndex loginName = model->index( 0, 1 );
		QModelIndex realName = model->index( 0, 2 );
		QModelIndex homeDir = model->index( 0, 3 );
		QModelIndex defaultShell = model->index( 0, 4 );
		QModelIndex diskUsage = model->index( 0, 5 );
		model->setData( UID, usr->pw_uid ) ;
		model->setData( loginName, usr->pw_name );
		model->setData( realName, usr->pw_gecos );
		model->setData( homeDir, usr->pw_dir );
		model->setData( defaultShell, usr->pw_shell );
		char *dir = usr->pw_dir;
		string dirString = dir;
		char path[PATH_MAX] = "\0"; //PATH_MAX == 4096 xarakthres megisth diadromh.arxikopoihsh me \0 giati alliws exei skpoupidia kai mperdeyetai h getSize
		for ( size_t i = 0; i < dirString.length(); i++ )//string se char[].to i size_t gia na sygkrinei to size_t pou epistrefei to length(). 
		{
			path[i] = dirString[i];
		}
		if ( path[strlen( path )-1] != '/' )
			strcat( path, "/" );
		//totalSize = 0;//mhdenismos giati merikoi home fakeloi den yparxoun,kai an den mhdenistei krataei to mege8os tou teleytaiou fakelou poy yphrxe kai metrh8hke
		uint64_t size = user->getSize( path );
		if ( size < 1000 && size > 0 ) //if < 1kb
		{
			sizeString.setNum( size ) ;//bytes
			sizeString.append( " B" );
		}
		else
			if ( size < 1000000 && size > 1000 ) //if < 1mb
			{
				uint64_t finalSize = ( size / 1024 );//bytes->kb
				sizeString.setNum( finalSize ) ;
				sizeString.append( " KB" );
			}
			else
				if ( size > 1000000 ) //if > 1mb
				{
					uint64_t finalSize = ( size / 1024 / 1024 );//bytes->mb
					sizeString.setNum( finalSize ) ;
					sizeString.append( " MB" );
				}
				else
					sizeString = "-"; //an totalsize=0 h den yparxei o fakelos
		model->setData( diskUsage, sizeString );
	}
	return model;
}

/**
 * Δημιουργεί το μοντέλο των χρηστών που είναι μέλη σε μια ομάδα.
 */
QStandardItemModel *Models::createMembersModel ( const char *groupName )

{
	char **members;
	setpwent();
	struct passwd * user=NULL;
	struct finfo info;
	struct group *grp = getgrnam ( groupName );
	members = grp->gr_mem;
	Users *us;

	QStandardItemModel *model = new QStandardItemModel ( 0, 3 );
	model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "UID" ) );
	model->setHeaderData ( 1, Qt::Horizontal, QObject::tr ( "Login Name" ) );
	model->setHeaderData ( 2, Qt::Horizontal, QObject::tr ( "Real Name" ) );



	while ( *members )
	{
	
		user = getpwnam ( *members );
		if ( user==NULL ) //an exei meinei akyrh eggrafh enos xrhsth san member sto etc/group enw o xrhsths den yparxei sto etc/passwd
			members++;
		else
		{
			model->insertRow ( 0 );
			QModelIndex UID = model->index ( 0, 0 );
			QModelIndex loginName = model->index ( 0, 1 );
			QModelIndex realName = model->index ( 0, 2 );
			model->setData ( UID, user->pw_uid ) ;
			model->setData ( loginName, * ( members ) );
			us->passwd_parse ( getpwnam ( *members ),&info );
			model->setData ( realName, info.full_name ) ;
			members++;
		}

	}
	user=NULL;
	setpwent();
	while ( ( user=getpwent() ) )
	{
		if ( user->pw_gid==grp->gr_gid )
		{
			model->insertRow ( 0 );
			QModelIndex UID = model->index ( 0, 0 );
			QModelIndex loginName = model->index ( 0, 1 );
			QModelIndex realName = model->index ( 0, 2 );
			model->setData ( UID, user->pw_uid ) ;
			model->setData ( UID,QVariant ( QImage ( "/usr/share/apps/UserManager/pics/p.jpeg" ) ),Qt::DecorationRole );
			model->setData ( loginName, user->pw_name );
			us->passwd_parse ( getpwnam ( user->pw_name ),&info );
			model->setData ( realName, info.full_name ) ;

		}
	}
	endpwent();
	return model;
}

/**
 * Δημιουργεί το μοντέλο των ομάδων στις οποίες είναι μέλος ο χρήστης
 */
QStandardItemModel *Models::UsersInGroupModel ( const char *groupName )
{

//idia me thn createMembersModel alla xwris na emfanizei ton omonymo xrhsth pou epeidh einai kai o idiokthths tou group den mporoume na ton kanoume remove ap to group tou
	char **members=NULL;
	struct passwd * user=NULL;
	QStandardItemModel *model = new QStandardItemModel ( 0,1 );
	model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "*Users IN Group*" ) );
//vhma vhma
//1)pairnw thn domh tou group gia to opoio 8elw na vrw ta member.2)an yparxoun melh tote paw kai sygkrinw to onoma tou member me ayto tou group gia to opoio psaxnw kai an einai idio shmainei oti to member einai kai o idiokthths tous group ara den to vazw sthn lista giati oute na ton vgalw apo to group tou ginetai oute na ton valw (afou einai hdh mesa).3)an den einai o idiokthths paw kai vazw ena ena ta member mesa sto montelo 
	struct group *grp = getgrnam ( groupName );
	members = grp->gr_mem;
	
	if ( *members!=NULL )
	{
	
	
		while ( *members )
		{
			user = getpwnam ( *members );
			if ( user!=NULL )//an yparxei akyrh eggrafh sto passwd
			{
				if ( user->pw_gid==grp->gr_gid ) //elegxos gia na mpei mpei o idiokthths tou group sth lista
					members++;
				else
				{
					model->insertRow ( 0 );
					QModelIndex userName = model->index ( 0, 0 );
	
					model->setData ( userName, * ( members ) );
					members++;
				}
	
			}
			else
			members++;
		}
	}
	return model;
}
/**
 * Δημιουργεί το μοντέλο των ομάδων στις οποίες ΔΕΝ είναι μέλος ο χρήστης
 */
QStandardItemModel *Models::UsersNotInGroupModel ( const char *groupName )
{
	char **members=NULL;
	struct passwd * user=NULL;
	QStandardItemModel *model = new QStandardItemModel ( 0,1 );
	struct group *grp;
	model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "*Users NOT In Group*" ) );
//vhma vhma
//perna ena ena ta member kai meta gia ka8e ena xrhsth tou systhmatos koitaei an einai den einai member me thn [strcmp ( *members, user->pw_name ) != 0]
//an den einai ton vazei sto montelo
//an paei meta to else shmainei oti ta *members==NULL kai ara to group den exei kanena melos mesa.ara me thn getpwent paw kai pairnw enan enan olous tous user apo to systhma kai tous xwnw sto montelo.pali ginetai o elegxos gia na mhn mpei o idiokthths tou group

	grp = getgrnam ( groupName );
	members = grp->gr_mem;
	if ( *members!=NULL )
	{
		setpwent();

		while	( ( user = getpwent() ) )
		{
			bool found=true;
			if ( user->pw_gid==grp->gr_gid ) //elegxos an einai to primary kapoiu xrhsth.an einai den xreiazetai na mpei sth lista me tous nonmembers apla anti na fainetai sto groups fainetai sto 3 pedio ap to passwd.(to pw_gid) pou krataei to primary group tou ka8e user
				goto usersPrimary;
			members = grp->gr_mem;//xanagemizei ta members gia sygkrish me ton epomeno user
			while ( *members )
			{
				if ( strcmp ( *members, user->pw_name ) != 0 )
					found=false;
				else
				{
					found=true;//an vre8hke den einai melos ara break gia na meinei true kai na mhn allaxei se false ap thn epomenh sygkrish
					break;
				}
				members++;
			}
		usersPrimary:
			if ( found==false ) //osoi user den vre8hkan mpainoun sto montelo
			{
				model->insertRow ( 0 );
				QModelIndex userName = model->index ( 0, 0 );
				model->setData ( userName, user->pw_name );
			}


		}
		endpwent();

	}
	else
	{

		setpwent();
		while ( ( user = getpwent() ) )
		{
			if ( user->pw_uid!=grp->gr_gid ) //elegxos an einai to primary kapoiu xrhsth.an einai den xreiazetai na mpei sth lista me tous nonmembers giati einai member kai apla anti na fainetai sto groups fainetai sto 3 pedio ap to passwd.(to pw_gid) pou krataei to primary group tou ka8e user
			{
				model->insertRow ( 0 );
				QModelIndex userName = model->index ( 0, 0 );
				model->setData ( userName, user->pw_name );

			}
			else
				{}
		}
		endpwent();


	}
	return model;
}
/**
 * Δημιουργεί ένα μοντέλο με όλες τις ομάδες του συστήματος και δίπλα 	στην κάθε μια τοποθετεί ένα checkbox,ανάλογα με τον αν ο χρήστης του  ορίσματος είναι μέλος στην εκάστοτε ομάδα ή όχι.
 */
QStandardItemModel *Models::createUserInGroupsModel ( QString username )
{
	struct group *grp=NULL;
	struct passwd *user=NULL;
	QStandardItemModel *model = new QStandardItemModel ( 0, 2 );
	user=getpwnam ( username.toAscii().data() );
	char **members=NULL;
	model->setHeaderData ( 1, Qt::Horizontal, QObject::tr ( "Groups" ) );
	model->setHeaderData ( 0, Qt::Horizontal, QObject::tr ( "" ) );
	setgrent();
	while ( ( grp = getgrent() ) )
	{
		bool found=false;
		QModelIndex checkbox = model->index ( 0, 0 );
		QModelIndex groupname = model->index ( 0, 1 );
				QModelIndex pic = model->index ( 0, 2 );
		if ( ( grp->gr_gid==user->pw_gid ) )
			goto resume;//an vrei to primary group tou na mhn to emfanisei sto montelo giati to emfanizei hdh sto label primary group apo katw

		members = grp->gr_mem;
		if ( *members==NULL )
		{
			model->setData ( checkbox, Qt::Unchecked, Qt::CheckStateRole );
			model->setData ( groupname, grp->gr_name );
			found=true;
		}
		while ( *members )
		{
			QString mem ( *members );
			if ( mem==username )
			{
				
				model->setData ( checkbox, Qt::Checked, Qt::CheckStateRole );
				model->setData ( groupname, grp->gr_name );
				found=true;
				break;
			}
			members++;
		}
		if ( !found )
		{

			model->setData ( checkbox, Qt::Unchecked, Qt::CheckStateRole );
			model->setData ( groupname, grp->gr_name );

		}

		model->insertRow ( 0 );
	resume:
		{}
	}
	endgrent();
	return model;
}

