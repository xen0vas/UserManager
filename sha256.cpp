#include "sha256.h"
#include <QMessageBox>
#include <QObject>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

hashingalgorithm *sha256::Create()
{
	return new sha256();
}

/**
*
* The function below creates a random 64bit encoded code
*/

void sha256::into64 ( char *s, long int v, int n )
{
	static unsigned char itoa64[] =  "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 0 ... 63 => ascii - 64
	while ( --n >= 0 )
	{
		//64 bit integer into string conversion
		*s++ = itoa64[v&0x3f];
		v >>= 6;  // right shifting 6 bits
	}
}

/* Encryption and hashing */

char *sha256::encryptpass( QString passwd )
{
	char *seed = makeSalt ( saltLength );
	char *buf = ( char * )calloc ( 512, sizeof(*buf) );
	char *password = passwd.toAscii().data();
	strncpy ( buf,password,strlen(password));


	/*
	 * The glibc2 version of crypt(3) function supports additional encryption
       algorithms.

	   If salt or seed in this case is a character string starting with the characters "$id$"
       followed by a string terminated by "$":

              $id$salt$encrypted

       then instead of using the DES machine, id identifies the encryption
       method used and this then determines how the rest of the password
       string is interpreted.

       The following values of id are supported:

              ID  | Method
              ─────────────────────────────────────────────────────────
              1   | MD5
              2a  | Blowfish (not in mainline glibc; added in some
                  | Linux distributions)
              5   | SHA-256 (since glibc 2.7)
              6   | SHA-512 (since glibc 2.7)

       $6$salt$encrypted is an SHA-512 encoded one.

       The characters in "salt" (seed) and "encrypted" are drawn from the set
       [a-zA-Z0-9./].  In the MD5 and SHA implementations the entire key is
       significant.

       salt or seed in this case  is a two-character string chosen from the set [a-zA-Z0-9./].
       This string is used to perturb the algorithm in one of 4096 different
       ways.

	Security Concerns
	------------------

	   Warning: the key space consists of 2**56 equal 7.2e16 possible
       values.  Exhaustive searches of this key space are possible using
       massively parallel computers.

	   Software, such as crack(1), is  available which will search the portion of this key space that is
       generally used by humans for passwords.  Hence, password selection should, at minimum, avoid common words and names.  The use of a
       passwd(1) program that checks for crackable passwords during the selection process is recommended.

       MD5 algorithm should not be choosed because is vulnerable to colission attacks

	 */

	char *pass = crypt ( buf,seed );

	if ( pass == NULL )
		QMessageBox::critical ( 0,QObject::tr ( "User Manager" ),QObject::tr ( "%1" ).arg ( ENOSYS ) );


	if (buf!=NULL)free(buf);

	return strdup ( pass );
}



/**
* Η παρακάτω συνάρτηση δημιουργεί την κωδικοποίηση ενός password για τον αλγόριθμο SHA-256
* Ουσιαστικά δημιουργεί το seed $5$......$ ,δηλαδή έναν τυχαίο string απο χαρακτήρες ξεκινώντας απο
* το $5$ μέτρώντας 8 χαρακτήρες και τελειώνοντας με $.Το μέγεθος του string είναι 64  bytes
* χρησιμοποιεί τη συνάρτηση into64()
*
*/

char* sha256::makeSalt(int length)
{
		//το salt είναι το αναγνωριστικό του αλγόριθμου SHA-256($5$)
		static char salt[12];
		salt[0] = '$';
		salt[1] = '5';
		salt[2] = '$';
		//παράγει διαφορετικά σετ απο ψευδοτυχαίους αριθμούς κάθε φορά που το πρόγραμμα τρέχει
		//Στη συνέχεια η random επιστρέφει τυχαίους αριθμούς ανάλογα με το σετ που έχει δημιουργηθεί απο τη srandom
		srandom ( ( int ) time ( ( time_t * ) NULL ) );
		into64 ( &salt[3], random(),length );
		into64 ( &salt[length],random(),3 );
		salt[length+3] = '$';
		return salt;
}
