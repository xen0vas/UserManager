#ifndef  INPUTVALIDATION_H_
#define  INPUTVALIDATION_H_

class InputValidation
{

private:
	extern char **environ;
	inputValidation();
	~inputValidation();
	char* SanitizeInput( char *s) const;
	void SanitizeEnv() const;
	int clearenv(void)
	bool exec(char* input);
};


#endif /* INPUTVALIDATION_H_ */
