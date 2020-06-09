#!/bin/bash

##################################################################################
#
# This script installs UserManager application to Debian and Ubuntu distributions
#
##################################################################################

MAGENTA='\033[95m'
RED='\033[0;31m'
GREEN='\e[92m'
NC='\033[0m' # No Color
BLUE='\e[96m'
YELLOW='\e[33m'

echo -ne "\n"
echo -ne "$YELLOW"
echo  '  / / / /_______  _____/  |/  /___ _____  ____ _____ ____  ____ '
echo  ' / / / / ___/ _ \/ ___/ /|_/ / __ `/ __ \/ __ `/ __ `/ _ \/ ___/'
echo  '/ /_/ (__  )  __/ /  / /  / / /_/ / / / / /_/ / /_/ /  __/ /    '
echo  '\____/____/\___/_/  /_/  /_/\__,_/_/ /_/\__,_/\__, /\___/_/     '
echo  '                                             /____/             '
echo
echo  'UserManager - Linux accounts manager'
echo  'Version 1.0.74'
echo -ne "$NC"

os=$(uname -a)
nu=$(pwd | tr '/' ' ' | wc -w)
num=$(($nu + 1))
directory=$(pwd | cut -d/ -f$num)
usr=$(whoami)
found="false"

qt5=`dpkg-query -W -f='${Status} ${Version}\n' qt5*`
if [[ ! `echo $qt5 | grep "install ok"` ]]; then echo "Qt5 is not installed. Exiting.."; exit 1; fi

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

echo -ne "\n$GREEN[!] $directory installation..please wait..$NC\n\n" 

if [ "$directory" != "UserManager" -a "$directory" != "UserManager-master" ]; then 
	echo "$RED[!] this isnt the UserManager Directory$NC" 
	exit 0
fi

make clean > make_clean.log
rm -rf Makefile 2>/dev/null
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

make > make_.log 2>&1

terminated=`cat make_.log | grep "compilation\ terminated"`
if [ "$terminated" == "compilation terminated." ]; then 
	echo -ne "\n$RED[x] Ooops! Installetion failed.. PLease try again!$NC\n"
	echo -ne "\n$RED[!] Please check at make_.log file for more information.$NC\n\n"
	exit 1
fi


make install > make_install.log 2>&1 &
pid=$!

for ((k = 0; k <= 10 ; k++))
do
    if [[ ! `kill -0 $pid 2>/dev/null` ]]; then
    echo -ne "$MAGENTA[ "
    for ((i = 0 ; i <= k; i++)); do echo -n "###"; done
    for ((j = i ; j <= 10 ; j++)); do echo -n "   "; done
    v=$((k * 10))
    echo -ne " ]$NC "
    echo -ne "$YELLOW$v %$NC" $'\r'
    sleep 0.5
    fi
done
echo

chown -R root:root UserManager
chmod -R 700 /opt/UserManager
chmod 700 /usr/bin/UserManager
echo -ne "\n\n$YELLOW[!] UserManager Installed succesfully! enjoy :)$NC\n\n" 

