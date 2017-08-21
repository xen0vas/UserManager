
#include "HashingAlgorithm.h"
#include "MainWindow.h"
#include "HashingFactory.h"

/**
 * Constructor with connections, signals and slots
 */

HashingAlgorithm::HashingAlgorithm ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	setModal ( true );
	MD5rdb->setChecked( true );


}

HashingAlgorithm::~HashingAlgorithm()
{}

/**
 *
 * This function is used to create a user password.
 * A form is used in order to insert a new password.
 * It calls encryptpass function which is implemented in classes sha256, sha512 and MD5 depending in the selected hashing algorithm, using IHashing interface.
 * The formated result is encrypted and saved inside the global variable passhash for further processing.
 *
 */

int HashingAlgorithm::setPassword(QString name)
{
	struct spwd spd;
	MyLibb *fchk {new MyLibb};
	QString passhash;


	bool okBtn;
	QString verify;
	QString passwd = QInputDialog::getText ( 0, QObject::tr ( "Enter Password" ), QObject::tr ( "Please Enter password for '%1'" ).arg ( name ), QLineEdit::Password, QString ( "" ), &okBtn );
	if(passwd != "" )
	verify = QInputDialog::getText ( 0, QObject::tr ( " Verify Password " ), QObject::tr ( "Please Verify password for '%1'" ).arg ( name ), QLineEdit::Password, QString ( "" ), &okBtn );
	if ( okBtn && passwd != "" && strncmp(passwd.toAscii().data(),verify.toAscii().data(), strlen(passwd.toAscii().data())) == 0)
	{
		MainWindow main;
		/*SHA-256 Algorithm */
		IHashing *psha256 = HashingFactory::Get()->CreateAlgorithm("SHA-256");
		if (psha256)
			passhash = psha256->encryptpass ( passwd );

		if (psha256)
			psha256->Free();
		psha256 = NULL;


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

		int curdays = time ( NULL ) / ( 60 * 60 * 24 );
		spd = *getspnam(name.toAscii().data());
		spd.sp_lstchg = curdays;
		spd.sp_pwdp = passhash.toAscii().data();

		fchk->setspnam(&spd);
		main.reloadUsersAndGroups();
		if (fchk != nullptr) { delete fchk; fchk = nullptr;}
		return 0;
	}
	else
	{
		if ( passwd != "" )
		{
			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords are not identical \n. Please try again!" ) );
			passhash = "";
		return 1;
		}
	}
return 1;
}
