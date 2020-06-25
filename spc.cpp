#include "spc.h"
#include <unistd.h>
#include <QMessageBox>

using std::string; 


Spc::Spc()
{}

Spc::~Spc()
{}

int Spc::clearenv(void)
{
  
  static char *namebuf = NULL;
  static size_t lastlen = 0;
 
  while (environ != NULL && environ[0] != NULL)
  {

    size_t len = strcspn(environ[0], "=");
    
    if (len == 0) {
      QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Problem calculating the size  <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
      return -1;
    }
    
    if (len > lastlen) {
      namebuf = (char*)realloc(namebuf, len+1);
      
      if (namebuf == NULL) {
        QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Cannot rellocate memory <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
      	return -1;
      }
      
      lastlen = len;
    }
    
    memcpy(namebuf, environ[0], len);
    namebuf[len] = '\0';
    
    if (unsetenv(namebuf) == -1) {
        QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Cannot unset the environmental variable <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
      
    	return -1; 
    	}
    }
  
  return 0;	

}


int Spc::clenv(void)
{

char *pathbuf;

size_t n;

n = confstr(_CS_PATH, NULL, 0);

if (clearenv() != 0) {
       QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Clearing the environment failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
       return -1;
} else if (n == 0) {
  	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not allocate memory for path<i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1;
} else if ((pathbuf = (char*)malloc(n)) == NULL) {
 	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not allocate memory for path<i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1;
} else if (confstr(_CS_PATH, pathbuf, n) == 0) {
 	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not get configuration dependent string variables <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1;
} else if (setenv("PATH", pathbuf, 1) == -1) {
	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Setting default environment failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1;
} else if (setenv("IFS", " \t\n", 1) == -1) {
	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Setting IFS failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1; 
}

return 0; 
}	

void Spc::spc_sanitize(std::string &stringValue)
{
stringValue.erase(
    std::remove_if(
        stringValue.begin(), stringValue.end(), [](char const c) {
            return '\\' == c || '"' == c || '#' == c || '\'' == c || '\r' == c || '{' == c || '}' ==c || '[' == c || ']' == c || '&' == c || '+' == c || ';' == c || '<' == c || '>' == c || '-' == c || '/' == c || '*' == c || '%' == c || '\n' == c || '|' == c || '\0' == c || '\x1A' == c;
        }
    ),
    stringValue.end()
    );
}

