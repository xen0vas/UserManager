#ifndef SPC_H
#define SPC_H

#include <QtGui/QtGui>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstddef> 
#include <algorithm> 
#include <iostream>
#include <iterator> 
#include <stdlib.h>
#include <string.h>
#include <paths.h>
#include <grp.h>


static int   orig_ngroups = -1;
static gid_t orig_gid = -1;
static uid_t orig_uid = -1;
static gid_t orig_groups[NGROUPS_MAX];

class Spc : public QObject
{
	Q_OBJECT

public: 
	Spc();
	~Spc();	
	void spc_drop_privilleges(int permanent); 
	void spc_sanitize(std::string &stringValue);
	int clearenv(void);
    int clenv(void);
    char * canonicalize_path(QByteArray di);
	void spc_restore_privileges(void); 

};
#endif

