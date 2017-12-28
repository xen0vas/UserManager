#include "InputValidation.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>


InputValidation::InputValidation()
{}

InputValidation::~InputValidation()
{}

int InputValidation::clearenv(void)
{
  static char *namebuf = NULL;
  static size_t lastlen = 0;

  while (environ != NULL && environ[0] != NULL) {
    size_t len = strcspn(environ[0], "=");
    if (len == 0) {
      /* Handle empty variable name (corrupted environ[]) */
    }
    if (len > lastlen) {
      namebuf = realloc(namebuf, len+1);
      if (namebuf == NULL) {
        /* Handle error */
      }
      lastlen = len;
    }
    memcpy(namebuf, environ[0], len);
    namebuf[len] = '\0';
    if (unsetenv(namebuf) == -1) {
      /* Handle error */
    }
  }
  return 0;
}

void InputValidation::SanitizeEnv() const
{
	char *pathbuf;
	size_t n;

	if (clearenv() != 0) {
	  /* Handle error */
	}

	n = confstr(_CS_PATH, NULL, 0);
	if (n == 0) {
	  /* Handle error */
	}

	if ((pathbuf = malloc(n)) == NULL) {
	  /* Handle error */
	}

	if (confstr(_CS_PATH, pathbuf, n) == 0) {
	  /* Handle error */
	}

	if (setenv("PATH", pathbuf, 1) == -1) {
	  /* Handle error */
	}

	if (setenv("IFS", " \t\n", 1) == -1) {
	  /* Handle error */
	}
}

char* InputValidation::SanitizeInput(char *s) const
{
	static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
	                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	                         "1234567890_-.@";

	char *cp = s; /* Cursor into string */
	const char *end = s + strlen( user_data);
	for (cp += strspn(cp, ok_chars); cp != end; cp += strspn(cp, ok_chars)) {
	  *cp = '_';
	}

	return *cp;
}

bool InputValidation::exec(char* exe, char* input){

  pid_t pid;
  int status;
  pid_t ret;
  char *const args[3] = {exe, input, NULL};
  char **env;


  /* ... Sanitize arguments ... */


  pid = fork();
  if (pid == -1) {
    /* Handle error */
  } else if (pid != 0) {
    while ((ret = waitpid(pid, &status, 0)) == -1) {
      if (errno != EINTR) {
        /* Handle error */
        break;
      }
    }
    if ((ret != -1) &&
      (!WIFEXITED(status) || !WEXITSTATUS(status)) ) {
      /* Report unexpected child status */
    }
  } else {
    /* ... Initialize env as a sanitized copy of environ ... */


    if (execve("/usr/bin/"+ exe, args, env) == -1) {
      /* Handle error */
      _Exit(127);
    }
  }
}


