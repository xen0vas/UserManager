#include "sha256.h"
#include <QMessageBox>
#include <unistd.h>
#include <crypt.h>


IHashing *sha256::Create()
{
	return new sha256();
}

void sha256::Free()
{
	delete this;
}

/* Hashing */

char *sha256::encryptpass( QString passwd) const
{
	HashEncode *hEnc = new HashEncode();
	/* 
	* seed is the SHA-256($5$) identifier 
	*/
	static char seed[12];
	seed[0] = '$';
	seed[1] = '5';
	seed[2] = '$';
	
	/* 
	* The srandom() function creates different sets of pseudorandom numbers every time the program runs.  
	* It sets its argument as the seed for a new sequence of pseudo-random integers to be returned by random()
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
	 * The crypt_r function does the same thing as crypt, but takes an extra parameter which includes space for its result (among other things), so it can be reentrant. data->initialized must be cleared to zero before the first time crypt_r is called
	 */
		struct crypt_data data;
		data.initialized = 0;

		char *pass = crypt_r ( buf,seed, &data);

	if ( pass == NULL )
		QMessageBox::critical ( 0,QObject::tr ( "User Manager" ),QObject::tr ( "%1" ).arg ( ENOSYS ) );
	if (buf!=NULL)free(buf);
	return strdup ( pass );
}
