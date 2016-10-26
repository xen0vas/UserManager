
#UserManager

UserManager is a Linux tool which helps Linux users to manage user accounts and groups. The tools has a friendly good looking dashboard and does the following 

- add,edit,delete user accounts and groups
- add users to groups
- search users
- remove users from groups 
- set UIDs and GIDs
- set users passwords 
- set working directories
- passwords aging
- set account expiration
- enable or disable user accounts
- show disk usage
- set working shells

###UserManager dashboard
------------------------

![usermanager_dash](https://cloud.githubusercontent.com/assets/12726776/19657636/b21ed7de-9a2d-11e6-95db-92baa468b2dc.PNG)


###User Properties
------------------

![user_properties](https://cloud.githubusercontent.com/assets/12726776/19657721/0139518c-9a2e-11e6-922f-27656a68bed4.PNG)


###Group Properties
-------------------

![group_properties](https://cloud.githubusercontent.com/assets/12726776/19677653/f6e47b88-9aa2-11e6-8cbf-0271dfee6291.PNG)


###User Groups
--------------

![groups](https://cloud.githubusercontent.com/assets/12726776/19677661/ff30ea24-9aa2-11e6-8e16-1f9f001186d7.PNG)


###Add Groups
-------------

![add_groups](https://cloud.githubusercontent.com/assets/12726776/19677652/f4d972e4-9aa2-11e6-9fe5-09f6cd91864a.PNG)

###Password Manager
-------------------

![password_manager](https://cloud.githubusercontent.com/assets/12726776/19719422/7be2f682-9b72-11e6-86fe-5dfa13fcba3e.PNG)

------------------

###How to Install
-----------------

- download the contents from git repo ( e.g. put them in /opt directory)

- go to the folder you downloaded the app (e.g. /opt/usermanager)

> `cd /opt/usermanager`

- run qmake

> `qmake`

- Makefile will be created 

- in order for the program to be succesfully compiled at newer Linux distributions add `-std=c++0x` directive when compile with `g++`. Thats because newer Linux dists use the new C++ standard. Just change the following Line in Makefile 

> `CXXFLAGS      = -std=c++0x -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)`

- if you have problems using qmake do the following additional step 

    1. install qt-sdk on your system. On debian do the following

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	sudo apt-get update

	sudo apt-get install qt-sdk
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- If there is a makefile find it in the current directory and delete it

> `find . -name Makefile -exec rm '{}' \;` 

- compile the program again

> `cd /opt/usermanager/`

> `qmake`

- After creating the Makefile add `-lcrypt` at the end of the following line as shown below 

> `LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread -lcrypt`

- run make

> `make`

then do the following to run the program 

> ` ./usermanager`

or you can create a symbolic link 

> `ln -s /opt/usermanager/usermanager /usr/bin/usermanager`

and run usermanager from any path on your system 

>  `usermanager`

enjoy ;-)

------------------------


