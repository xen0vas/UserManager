#!/bin/bash
# generate a run script which performing the build process of UserManager application

mkdir -p /usr/share/apps/UserManager/other/
if [ ! -f /usr/share/apps/UserManager/other/usermanager.conf ]; then
	cp -r ./other/usermanager.conf /usr/share/apps/UserManager/other/
fi

DIRECTORY=`pwd | cut -d/ -f4`

if [ "$DIRECTORY" != "UserManager" ]; then 
	echo " this isnt the UserManager Directory " 
	exit 0
fi
make clean 
rm -rf Makefile > /dev/null 2>&1
qmake -project
qmake -o Makefile UserManager.pro 
echo "QMAKE_CXXFLAGS += -std=c++11" >> UserManager.pro
echo "CONFIG += qt debug" >> UserManager.pro
echo "QMAKE_LIBS += -lcrypt" >> UserManager.pro
echo "# installation" >> UserManager.pro
echo "installfiles.files += usermanager" >> UserManager.pro
echo "installfiles.path += /usr/bin/" >> UserManager.pro  
echo "INSTALLS += installfiles" >> UserManager.pro
make
make install
#UserManager 



