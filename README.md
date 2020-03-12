


# UserManager

UserManager has been developed in C/C++ and Qt framework. The application has been designed to provide assistance to Linux administrators in order to manage users and groups accounts. This tool has a friendly dashboard while performing the following functionality

* add,edit,delete user accounts and groups
* add users to groups
* search users
* remove users from groups 
* set UIDs and GIDs
* set users passwords 
* set working directories
* passwords aging
* set account expiration
* enable or disable user accounts
* show disk usage
* set working shells

------------------

### TO-DO 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Upgrade to qt5 

2. Implement a password generator

3. Implement password security strength checks

4. Notify about weak passwords and empty password accounts

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### Installation Info 

* This application has been tested in 64bit Linux Debian and Ubuntu distributions.  


### Succesfully tested in the following architectures
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


- Linux 5.3.0-kali2-amd64 #1 SMP Debian 5.3.9-3kali1 (2019-11-20) x86_64 GNU/Linux

- Linux 4.15.0-29-generic #31-Ubuntu SMP Tue Jul 17 15:39:52 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### Developers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  - Xenofon Vassilakopoulos (xvas)

  - Fotis Tsifountidis (fts)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------

### Installation prerequisites ( optional )

* apt install libcanberra-gtk-module libcanberra-gtk3-module

### Installation 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

git clone https://github.com/xvass/UserManager.git
cd UserManager
chmod +x install_and_run.sh
./install_and_run.sh

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### Important Info : 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- If the application doesn't run, use the following fix export QT X11 NO MITSHM=1 or QT X11 NO MITSHM=1 UserManager. QT X11 NO MITSHM stops Qt form using the MIT-SHM X11 extension. This is a known bug in Qt applications   

More info here: 
https://en.wikipedia.org/wiki/MIT-SHM
http://www.iwillfolo.com/quick-fix-one-kdes-common-xorg-errors-x-error-baddrawable/

- The application by design was developed to run only from root user. Dont run the application with non root users.  

- in case of consistency and performance please consider changing the following kernel parameters

vm.mmap_min_addr=65536
vm.swappiness = 10
vm.swappiness=10
vm.dirty_ratio=60
vm.dirty_background_ratio = 2
vm.dirty_background_ratio=2
vm.dirty_bytes = 0
vm.dirty_writeback_centisecs = 500
vm.dirty_expire_centisecs = 3000
vm.dirty_background_bytes = 0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### UserManager Main View
------------------------

![main](https://user-images.githubusercontent.com/12726776/30857766-aa6a1c96-a2c5-11e7-8210-9666b0949e24.PNG)

### User Properties
------------------

![user_properties](https://cloud.githubusercontent.com/assets/12726776/19657721/0139518c-9a2e-11e6-922f-27656a68bed4.PNG)

### Disk Quota
--------------

![loading](https://user-images.githubusercontent.com/12726776/30857814-d3fcc20c-a2c5-11e7-993b-6ec3f8aad7fd.PNG) 

### Group Properties
-------------------

![group_properties](https://user-images.githubusercontent.com/12726776/30582746-840576ba-9d2d-11e7-95cb-9c3cbeb957de.PNG)


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

### Groups
-----------

![groups](https://user-images.githubusercontent.com/12726776/30519031-68528cbc-9b95-11e7-93c6-32f382ec7783.PNG)

### Set Password 
----------------

![setpassword](https://user-images.githubusercontent.com/12726776/30519036-8d2a8ce2-9b95-11e7-8fb8-890db6880149.PNG)

### Group Privileges
--------------------

![groups](https://user-images.githubusercontent.com/12726776/30855524-f5ba60d2-a2bd-11e7-96ee-9a07814cdd11.PNG)

