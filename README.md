
# UserManager

UserManager has been developed in c/c++ and Qt framework which helps Linux administrators to manage user accounts and groups. This tool has a friendly dashboard performing the following 

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

------------------


### Devs
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  - Xenofon Vassilakopoulos (kseno)
  - Fotis Tsifountidis (fts)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------

#### hashing algorithms 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The application uses crypt() to encrypt the Linux password which supports the following algorithms: 
- MD5 
- SHA-512
- SHA-256
- Blowfish ( it has been implemented but is currently disabled by the Application because bcrypt it is not included in glibc. If you want to enable it you must import a patch to include crypt_blowfish in libc.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

#### Important Info : 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

the application is currently on a stable version. I have succesfully tested it in Linux ubuntu and Debian systems.    
if you find any bugs please give me a feedback.

If the application doesn't run, use the following fix     
- export QT X11 NO MITSHM=1 or QT X11 NO MITSHM=1 UserManager.     
QT X11 NO MITSHM stops Qt form using the MIT-SHM X11 extension.    
This is a known bug in Qt applications   
More info here: 
https://en.wikipedia.org/wiki/MIT-SHM
http://www.iwillfolo.com/quick-fix-one-kdes-common-xorg-errors-x-error-baddrawable/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### UserManager main view
------------------------

![usermanager_dash](https://cloud.githubusercontent.com/assets/12726776/19657636/b21ed7de-9a2d-11e6-95db-92baa468b2dc.PNG)


### User Properties
------------------

![user_properties](https://cloud.githubusercontent.com/assets/12726776/19657721/0139518c-9a2e-11e6-922f-27656a68bed4.PNG)


### Group Properties
-------------------

![group_properties](https://cloud.githubusercontent.com/assets/12726776/19677653/f6e47b88-9aa2-11e6-8cbf-0271dfee6291.PNG)


### User Groups
--------------

![groups](https://cloud.githubusercontent.com/assets/12726776/19677661/ff30ea24-9aa2-11e6-8e16-1f9f001186d7.PNG)


### Add Groups
-------------

![add_groups](https://cloud.githubusercontent.com/assets/12726776/19677652/f4d972e4-9aa2-11e6-9fe5-09f6cd91864a.PNG)

### Password Manager
-------------------

![password_manager](https://cloud.githubusercontent.com/assets/12726776/19719422/7be2f682-9b72-11e6-86fe-5dfa13fcba3e.PNG)

------------------

### How to Install
-----------------

- download the contents from git repo ( e.g. put them in `/opt` directory)

- go to the folder you downloaded the app (e.g. `/opt/usermanager`)

> `cd /opt/usermanager`

- Prepare the build using `qmake` utility

> `qmake -project UserManager`

> `qmake`

- `Makefile` will be created 

- in order for the program to be succesfully compiled at newer Linux distributions add `-std=c++0x` directive when compile with `g++`. Thats because newer Linux dists use the new C++ standard. Just change the following Line in `Makefile` 

> `CXXFLAGS      = -std=c++0x -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)`

- if you have problems using qmake utility do the following

	1. install `qt-sdk` on your system. On debian do the following

		> `sudo apt-get update`
		
		> `sudo apt-get install qt-sdk`

	2. If there is an older `makefile` find it in the current directory and delete it

		> `find . -name Makefile -exec rm '{}' \;` 

		- then again prepare the build using `qmake` utility

		> `cd /opt/usermanager/`

		> `qmake -project UserManager`

		> `qmake`
		
		- `Makefile` will be created 

- Also add `-lcrypt` inside the Makefile at the end of the following line as shown below 

> `LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread -lcrypt`

- Build with `make` utility and compile

> `make`

- run the program 

> ` ./usermanager`

- alternatively you can create a symbolic link 

> `ln -s /opt/usermanager/usermanager /usr/bin/usermanager`

- run usermanager from any path on your system using the following command

>  `usermanager`

- Instead of creating a symbolic link , use `make install`. Add the following lines in `usermanager.pro` which produced from `qmake`

````````````````````````````````````
# installation
installfiles.files += usermanager
installfiles.path += /usr/bin/
INSTALLS += installfiles 
````````````````````````````````````

- use the following command 

> `make install`
 
- run usermanager from any path on your system using the following command

>  `usermanager`

------------------------


