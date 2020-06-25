#ifndef SPC_H
#define SPC_H

#include <QtGui/QtGui>
#include <stdio.h>
#include <cstddef> 
#include <algorithm> 
#include <iostream>
#include <iterator> 
#include <stdlib.h>
#include <string.h>
#include <paths.h>

//extern char **environ; 

//static char* spc_restricted_environ[ ] = {
//	"IFS= \t\n",
//	"PATH=" _PATH_STDPATH, 
//	0
//};

//static char *spc_preserve_environ[ ] = {
//	"TZ",
//	0
//};


class Spc : public QObject
{
	Q_OBJECT
public: 
	Spc();
	~Spc();	
	//void spc_drop_privilleges(int permanent); 
	void spc_sanitize(std::string &stringValue);
	int clearenv(void);
        int clenv(void);	

};
#endif

