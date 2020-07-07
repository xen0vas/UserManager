#include "spc.h"
#include <unistd.h>
#include <QMessageBox>

using std::string; 


Spc::Spc()
{}

Spc::~Spc()
{}


/**
 * A space-separated list of variable=value pairs is returned, with variable names guaranteed not to contain equal signs (=), 
 * and variable=value pairs guaranteed not to contain spaces. Used together with the _CS_PATH request,
 * this completely describes the minimum environment variable settings required to obtain a clean, conforming environment.
 * On systems conforming to the POSIX.1-2008 standard, this should be used to create a sanitized environment
 */
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
        if (namebuf != NULL)
    	return -1; 
    	}
    }

return 0;
}

/**
 * This function used to clear Environmental variables. 
 * The environment is cleared by clearenv(), and then the PATH and IFS variables are set to safe values before system() is invoked
 * Ref:. ENV03-C. Sanitize the environment when invoking external programs
 */
int Spc::clenv(void)
{

char *pathbuf = {} ;

size_t n;

n = confstr(_CS_PATH, NULL, 0);

if (clearenv() != 0) {
    QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Clearing the environment failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    return -1;
} else if (n == 0) {
  	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not allocate memory for path<i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
	return -1;
} else if ((pathbuf = (char*)calloc(128, n)) == NULL) {
 	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not allocate memory for path<i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    free(pathbuf);
    return -1;

    /*
    *  _CS_PATH : This parameter’s value is the recommended default path for
    *  searching for executable files. This is the path that a user has by default just after logging in
    */

} else if (confstr(_CS_PATH, pathbuf, n) == 0) {
 	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not get configuration dependent string variables <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    free(pathbuf);
    return -1;
} else if (setenv("PATH", pathbuf, 1) == -1) {
	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Setting default environment failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    free(pathbuf);
    return -1;
} else if (setenv("IFS", " \t\n", 1) == -1) {
	QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Setting IFS failed <i> %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    free(pathbuf);
	return -1; 
}
free(pathbuf);
return 0; 
}	

char *Spc::canonicalize_path(QByteArray directory)
{
    size_t  path_size = (size_t)PATH_MAX+1;
    char *realpath_res = NULL;
    char *canonical_path = NULL;
    char *actualpath = NULL;
    const size_t len = strlen( directory.data() );

    if (path_size > 0) {
        canonical_path = (char*)calloc(1,path_size);

        if (canonical_path == NULL) {

                QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Could not calculate memory for homedir path </qt> " ) ) ;
        }
        else if( (strrchr( directory.data(), '/') != directory.data() + len) && canonical_path != NULL )
        {
        actualpath = directory.data();
        realpath_res = realpath(actualpath, canonical_path);
        }
        else
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Invalid path detected  </qt> " ) ) ;
    }

    if (realpath_res == NULL )
    {
            QMessageBox::critical ( 0,tr ( "User Manager" ),tr ( "<qt> Invalid path  <i>  %1 </i> </qt> " ).arg ( strerror ( errno ) ) );
    }

    if ( canonical_path != NULL ) { free(canonical_path); canonical_path = NULL; }

    return realpath_res;
}

/**
 * Sanitize sascpicious characters in order to avoid injections. Possible characters that migh cause harm are 
 * *,-,+,|,/,\,*,&,{,},[,],\0,\x1A,\r,\t,\n,<,>,;,#,\",' .These chars need to be trimmed. 
 * The stringValue called be reference and has to be checked 
 */
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

void Spc::spc_drop_privilleges(int permanent)
{
  gid_t newgid = getgid(  ), oldgid = getegid(  );
  uid_t newuid = getuid(  ), olduid = geteuid(  );

  if (!permanent) {
    /* Save information about the privileges that are being dropped so that they
     * can be restored later.
     */
    orig_gid = oldgid;
    orig_uid = olduid;
    orig_ngroups = getgroups(NGROUPS_MAX, orig_groups);
  }

  if (!olduid)
      setgroups(1, &newgid);


   if (newgid != oldgid) {
 #if !defined(linux)
     setegid(newgid);
     if (permanent && setgid(newgid) == -1) abort(  );
 #else
     if (setregid((permanent ? newgid : -1), newgid) =  = -1) abort(  );
 #endif
   }

   if (newuid != olduid) {
 #if !defined(linux)
     seteuid(newuid);
     if (permanent && setuid(newuid) == -1) abort(  );
 #else
     if (setreuid((permanent ? newuid : -1), newuid) =  = -1) abort(  );
 #endif
   }

   if (newuid != olduid) {
   #if !defined(linux)
       seteuid(newuid);
       if (permanent && setuid(newuid) == -1) abort(  );
   #else
       if (setreuid((permanent ? newuid : -1), newuid) =  = -1) abort(  );
   #endif
     }

     /* verify that the changes were successful */
     if (permanent) {
       if (newgid != oldgid && (setegid(oldgid) != -1 || getegid(  ) != newgid))
         abort(  );
       if (newuid != olduid && (seteuid(olduid) != -1 || geteuid(  ) != newuid))
         abort(  );
     } else {
       if (newgid != oldgid && getegid(  ) != newgid) abort(  );
       if (newuid != olduid && geteuid(  ) != newuid) abort(  );
     }
}

void Spc::spc_restore_privileges()
{
    if (geteuid(  ) != orig_uid)
        if (seteuid(orig_uid) == -1 || geteuid(  ) != orig_uid) abort(  );
      if (getegid(  ) != orig_gid)
        if (setegid(orig_gid) == -1 || getegid(  ) != orig_gid) abort(  );
      if (!orig_uid)
        setgroups(orig_ngroups, orig_groups);
}
