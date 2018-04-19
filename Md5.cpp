#include "Md5.h"
#include <QMessageBox>
#include <unistd.h>
#include <crypt.h>


IHashing *Md5::Create()
{
	return new Md5();
}

void Md5::Free()
{
	delete this;
}

/* Hashing */

char *Md5::encryptpass( QString passwd) const
{
	HashEncode *hEnc = new HashEncode();
	static char seed[12];
	seed[0] = '$';
	seed[1] = '1';
	seed[2] = '$';
	/*
	* it produces different sets with pseudorandom numbers everytime the programm runs 
	* To continue, the srandom function returns random numbers in relation with the set of numbers being created from srandom
  	*/
	srandom ( ( int ) time ( ( time_t * ) NULL ) );
	hEnc->into64 ( &seed[3], random(),saltLength );
	hEnc->into64 ( &seed[saltLength],random(),3 );
	seed[saltLength+3] = '$';

	if (hEnc != nullptr )
		{delete hEnc;
		hEnc = nullptr;}

	char *buf = ( char * )calloc ( 512, sizeof(*buf) );
	char *password = passwd.toAscii().data();
	strncpy ( buf,password,strlen(password));

	/*
	 * The crypt_r function does the same thing as crypt, 
	 * but takes an extra parameter which includes space for its result (among other things),
	 * so it can be reentrant. data->initialized must be cleared to zero before the first time crypt_r is called
	 */
	struct crypt_data data;
	data.initialized = 0;

	char *pass = crypt_r ( buf,seed, &data);

	if ( pass == NULL )
		QMessageBox::critical ( 0,QObject::tr ( "User Manager" ),QObject::tr ( "%1" ).arg ( ENOSYS ) );
	if (buf!=NULL)free(buf);
	return strdup ( pass );
}




