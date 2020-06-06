#!/bin/bash

##################################################################################
#
# This script installs UserManager application to Debian and Ubuntu distributions
#
##################################################################################

os=$(uname -a) 
nu=$(pwd | tr '/' ' ' | wc -w)
num=$(($nu + 1))
directory=$(pwd | cut -d/ -f$num)
usr=$(whoami)
found="false"

qt=`dpkg --get-selections | grep qt4-default`
default=`echo $qt | cut -d" " -f1`

IFS=' ' # space set as delimiter
read -ra ADDR <<< "$os"
for i in "${ADDR[@]}"; do # access each element of array
    if [ "$i" = "Debian" -o "$i" = "Ubuntu" -o "$i" = "debian" ];then
	found="true"
    fi
done

if [ "$found" = "false" ]; then 
	echo "this script installs UserManager at Debian and Ubuntu"
	exit 1; 
fi

if [ "$found" = "true" ]; then 
	if [ ! -f /"$usr"/.local/share/applications/UserManager.desktop ]; then
		if [ "$directory" = "UserManager" -o "$directory" = "UserManager-master"  ]; then
			cp ./resources/images/UserManager.gif /$usr/Pictures/UserManager.gif
		fi
	 	touch /"$usr"/.local/share/applications/UserManager.desktop	
		echo "[Desktop Entry]" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Type=Application" >> /"$usr"/.local/share/applications/UserManager.desktop 
		echo "Encoding=UTF-8" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Name=UserManager" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Comment=provides administration support for user management" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Icon=/"$usr"/Pictures/UserManager.gif" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Exec=/usr/bin/UserManager" >> /"$usr"/.local/share/applications/UserManager.desktop
	        echo "Terminal=false" >> /"$usr"/.local/share/applications/UserManager.desktop
		echo "Categories=Tags;Describing;Application" >> /"$usr"/.local/share/applications/UserManager.desktop
	fi
fi

if [ ! -f  /usr/share/apps/UserManager/translations ]; then 
	mkdir -p /usr/share/apps/UserManager/translations/
fi

if [ ! -f /usr/share/apps/UserManager/pics ]; then 
	mkdir -p /usr/share/apps/UserManager/pics/
	iconpt=`pwd`
        yes | cp -rf "$iconpt"/resources/images/* /usr/share/apps/UserManager/pics/
fi

if [ ! -f /usr/share/apps/UserManager/language ]; then 
	if [ "$directory" = "UserManager" ]; then
		pat=`pwd`
		cp "$pat"/language/el.qm /usr/share/apps/UserManager/translations/
	fi
fi

mkdir -p /usr/share/apps/UserManager/other/
if [ ! -f /usr/share/apps/UserManager/other/usermanager.conf ]; then
	cp -r ./other/usermanager.conf /usr/share/apps/UserManager/other/
fi

echo $directory 

if [ "$directory" != "UserManager" -a "$directory" != "UserManager-master" ]; then 
	echo "[!] this isnt the UserManager Directory" 
	exit 0
fi

make clean 2>/dev/null
rm -rf Makefile 2>/dev/null 
#2>&1
qmake -project 2>/dev/null
qmake -o Makefile UserManager.pro  
echo "QMAKE_CXXFLAGS += -std=c++11" >> UserManager.pro
echo "CONFIG += qt debug" >> UserManager.pro
echo "QMAKE_LIBS += -lcrypt" >> UserManager.pro
echo "QT += widgets" >> UserManager.pro
echo "# installation" >> UserManager.pro
echo "installfiles.files += usermanager" >> UserManager.pro
echo "installfiles.path += /usr/bin/" >> UserManager.pro  
echo "INSTALLS += installfiles" >> UserManager.pro
errolog=$(mktemp)
make 1>"$errorlog"
if [[ -s "$errorlog" ]]; then
	echo -ne "Ooops something went wrong. Give it another try!"
	exit 1 
fi
echo -ne '#######			(25%)\r'
sleep 2
make install &>/dev/null

#cd .. && mv UserManager/ /opt
#cd /opt/UserManager
echo -ne '##########			(32%)\r'
sleep 2
chown -R root:root UserManager
chmod -R 700 /opt/UserManager
chmod 700 /usr/bin/UserManager
echo -ne '##############		(33%)\r'
sleep 2
echo -ne '##################		(57%)\r'
sleep 2
echo -ne '######################	(78%)\r'
sleep 2
echo -ne '##########################	(89%)\r'
sleep 2
echo -ne '#############################	(97%)\r'
sleep 2
echo -ne '##############################(100%)\r'
sleep 2
echo -ne '\n'
echo -ne "\nUserManager Installed succesfully! enjoy :) \n\n" 
#./UserManager 



