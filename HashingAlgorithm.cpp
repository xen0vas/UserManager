
#include "HashingAlgorithm.h"
#include "MainWindow.h"
#include "HashingFactory.h"
#include "userproperties.h"
#include <memory>

/**
 * Constructor with connections, signals and slots
 */

HashingAlgorithm::HashingAlgorithm ( QWidget * parent ) : QDialog ( parent )
{
	setupUi ( this );
	setModal ( true );
	Sha512rdb->setChecked( true );
	UserNameLabel->setVisible( true );
	NameLabelHidden->setVisible ( false );
	Blowfishrdb->setEnabled( false );
	pass->setEchoMode(QLineEdit::Password);
	pass2->setEchoMode(QLineEdit::Password);
	connect( Save, SIGNAL( clicked() ), this, SLOT( setHashingAlgorithm() ) );
	connect( Sha256rdb, SIGNAL( clicked() ), this, SLOT( getSha256IsChecked() ) );
	connect( Sha512rdb, SIGNAL( clicked() ), this, SLOT( getSha512IsChecked() ) );
	connect( MD5rdb, SIGNAL( clicked() ), this, SLOT( getMd5IsChecked() ) );
	connect( Blowfishrdb, SIGNAL( clicked() ), this, SLOT( getBlowIsChecked() ) );

}

HashingAlgorithm::~HashingAlgorithm()
{}

void HashingAlgorithm::storePassShadow(QString name, QString passhash)
{
    std::unique_ptr<MyLibb> fchk(new MyLibb);
	struct spwd spd;
	MainWindow main;
	int curdays = time ( NULL ) / ( 60 * 60 * 24 );
	spd = *getspnam(name.toLatin1().data());
	spd.sp_lstchg = curdays;
	spd.sp_pwdp = passhash.toLatin1().data();

	fchk->setspnam(&spd);
	main.reloadUsersAndGroups();
}

bool HashingAlgorithm::getBlowIsChecked()
{
	return this->Blowfishrdb->isChecked();

}

bool HashingAlgorithm::getSha256IsChecked()
{
	return this->Sha256rdb->isChecked();
}

bool HashingAlgorithm::getSha512IsChecked()
{
	return this->Sha512rdb->isChecked();
}

bool HashingAlgorithm::getMd5IsChecked()
{
	return this->MD5rdb->isChecked();
}

void HashingAlgorithm::setHashingAlgorithm()
{


	int res = this->setPassword( NameLabelHidden->text() );

	if ( res  == 0 )
	{
		QMessageBox::information( 0,tr ( "User Manager" ),tr ( "Password inserted successfully" ) );
		QWidget::close();
	}

}

/**
 *
 * This function is used to create a user password.
 * A form is used in order to insert a new password.
 * Using IHashing interface, it calls encryptpass function which is implemented in classes sha256, sha512, blowfish
 * and MD5 depending on the selected hashing algorithm.
 * The formated result is encrypted and saved inside the global variable passhash for further processing.
 *
*/
int HashingAlgorithm::setPassword(QString name)
{

   QString passhash;
   QString verify = this->pass2->text();
   QString passwd = this->pass->text();

   bool sha256Checked = this->getSha256IsChecked();
   bool sha512Checked = this->getSha512IsChecked();
   bool md5Checked = this->getMd5IsChecked();
   bool blowfishChecked = this->getBlowIsChecked();

   if ( this->Save && sha256Checked )
   {
		if (this->Save && (this->pass->text().toStdString() == "" || this->pass2->text().toStdString() == "" ))
		{
			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Empty field. Please fill in with the new password" ) );
			return 1;
		}

		if (this->Save && strncmp(passwd.toLatin1().data(), verify.toLatin1().data(), strlen(passwd.toLatin1().data())) != 0)
		{
			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords do not match!" ) );
			return 1;
		}

		/* Choose SHA-256 Algorithm */
		IHashing *psha256 = HashingFactory::Get()->CreateAlgorithm("SHA-256");
		if (psha256)
		{
			passhash = psha256->encryptpass ( passwd );
			this->storePassShadow(name, passhash);
			psha256->Free();
			psha256 = NULL;
		}
	}

   	if ( this->Save && sha512Checked )
   	{
   		if (this->Save && (this->pass->text().toStdString() == "" || this->pass2->text().toStdString() == "" ))
   		{
   			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Empty field. Please fill in with the new password" ) );
   			return 1;
   		}

   		if (this->Save && strncmp(passwd.toLatin1().data(), verify.toLatin1().data(), strlen(passwd.toLatin1().data())) != 0)
   		{
   			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords do not match!" ) );
   			return 1;
   		}

		/* Choose SHA-512 Algorithm */
		IHashing *psha512 = HashingFactory::Get()->CreateAlgorithm("SHA-512");
		if (psha512)
		{
			passhash = psha512->encryptpass ( passwd );
			this->storePassShadow(name, passhash);
			psha512->Free();
			psha512 = NULL;
		}
	}

   	if ( this->Save && blowfishChecked )
   	   	{
   	   		if (this->Save && (this->pass->text().toStdString() == "" || this->pass2->text().toStdString() == "" ))
   	   		{
   	   			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Empty field. Please fill in with the new password" ) );
   	   			return 1;
   	   		}

   	   		if (this->Save && strncmp(passwd.toLatin1().data(), verify.toLatin1().data(), strlen(passwd.toLatin1().data())) != 0)
   	   		{
   	   			QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords do not match!" ) );
   	   			return 1;
   	   		}

   			/* Choose blowfish Algorithm */
   			IHashing *pblow = HashingFactory::Get()->CreateAlgorithm("blowfish");
   			if (pblow)
   			{
   				passhash = pblow->encryptpass ( passwd );
   				this->storePassShadow(name, passhash);
   				pblow->Free();
   				pblow = NULL;
   			}
   		}

   	if ( this->Save && md5Checked )
   	{
   		if (this->Save && (this->pass->text().toStdString() == "" || this->pass2->text().toStdString() == "" ))
   		{
   		   	QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Empty field. Please fill in with the new password" ) );
   		   	return 1;
   		}

   		if (this->Save && strncmp(passwd.toLatin1().data(), verify.toLatin1().data(), strlen(passwd.toLatin1().data())) != 0)
   		{
   		   	QMessageBox::warning( 0,tr ( "User Manager" ),tr ( "Passwords do not match!" ) );
   		   	return 1;
   		}

		/* Choose MD5 Algorithm */
		IHashing *pmd5 = HashingFactory::Get()->CreateAlgorithm("MD5");
		if (pmd5)
		{
			passhash = pmd5->encryptpass ( passwd );
			this->storePassShadow(name, passhash);
			pmd5->Free();
			pmd5 = NULL;
		}

   	}
		return 0;
}


