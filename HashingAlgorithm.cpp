
#include "HashingAlgorithm.h"
#include "MainWindow.h"
#include "HashingFactory.h"
#include "userproperties.h"

/**
 * Constructor with connections, signals and slots
 */

HashingAlgorithm::HashingAlgorithm ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	setModal ( true );
	MD5rdb->setChecked( true );
	usrEdit->setVisible( false );
	connect( Save, SIGNAL( clicked() ), this, SLOT( setHashingAlgorithm() ) );
	connect( Sha256rdb, SIGNAL( clicked() ), this, SLOT( getSha256IsChecked() ) );

}

HashingAlgorithm::~HashingAlgorithm()
{}

void HashingAlgorithm::setPassAging(QString name, QString passhash)
{
	MyLibb *fchk = new MyLibb;
	struct spwd spd;
	MainWindow main;
	int curdays = time ( NULL ) / ( 60 * 60 * 24 );
	spd = *getspnam(name.toAscii().data());
	spd.sp_lstchg = curdays;
	spd.sp_pwdp = passhash.toAscii().data();

	fchk->setspnam(&spd);
	main.reloadUsersAndGroups();
	if (fchk != nullptr) { delete fchk; fchk = nullptr;}
}

bool HashingAlgorithm::getSha256IsChecked()
{

	return this->Sha256rdb->isChecked();
}

void HashingAlgorithm::setHashingAlgorithm()
{
	QString name = this->usrEdit->text();
	int res = this->setPassword(name);
	if ( res  == 0 )
	{
		QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Password inserted successfully" ) );
	}
}

/**
 *
 * This function is used to create a user password.
 * A form is used in order to insert a new password.
 * Using IHashing interface, it calls encryptpass function which is implemented in classes sha256, sha512 and MD5 depending in the selected hashing algorithm.
 * The formated result is encrypted and saved inside the global variable passhash for further processing.
 *
*/
int HashingAlgorithm::setPassword(QString name)
{

	QString passhash;
	QString verify = this->pass2->text();
	QString passwd = this->pass->text();

	bool sha256Checked = this->getSha256IsChecked();
	if ( this->Save && sha256Checked )
	{


		if (this->Save && (this->pass->text().toStdString() == "" || this->pass2->text().toStdString() == "" ))
		{
			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Empty field. Please fill in with the new password" ) );
			return 1;
		}

		if (this->Save && strncmp(passwd.toAscii().data(), verify.toAscii().data(), strlen(passwd.toAscii().data())) != 0)
		{
			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords do not match!" ) );
			return 1;
		}

		/*SHA-256 Algorithm */
		IHashing *psha256 = HashingFactory::Get()->CreateAlgorithm("SHA-256");
		if (psha256)
		{
			passhash = psha256->encryptpass ( passwd );
			this->setPassAging(name, passhash);
		if (psha256)
			psha256->Free();
		psha256 = NULL;
		}

	}
	else
	{
		QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "sha256 not checked" ) );
	}
		/* SHA-512 Algorithm
		IHashing *psha512 = HashingFactory::Get()->CreateAlgorithm("SHA-512");
		if (psha512)
			passhash = psha512->encryptpass ( passwd );

		if (psha512)
			psha512->Free();
		psha512 = NULL;
		*/

		/* MD5 Algorithm
		IHashing *pmd5 = HashingFactory::Get()->CreateAlgorithm("MD5");
		if (pmd5)
			passhash = pmd5->encryptpass ( passwd );

		if (pmd5)
			pmd5->Free();
		pmd5 = NULL;
		*/


		return 0;
}


