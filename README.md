

# ![UserManager](https://user-images.githubusercontent.com/12726776/80515471-b3028380-898a-11ea-9aac-f1d0e44628b5.gif)   UserManager 


![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-yellow)    ![license](https://img.shields.io/github/license/xvass/UserManager)   ![openissues](https://img.shields.io/github/issues/xvass/UserManager) ![closedissues](https://img.shields.io/github/issues-closed-raw/xvass/UserManager) ![forks](https://img.shields.io/github/forks/xvass/UserManager) ![stars](https://img.shields.io/github/stars/xvass/UserManager) ![version](https://img.shields.io/badge/version-1.0.75-brightgreen) ![last_commit](https://img.shields.io/github/last-commit/xvass/UserManager)


| Branch |  Linux Build  |
|--------|:----------------:|
| master | [![Build Status](https://travis-ci.com/xvass/UserManager.svg?branch=master)](https://travis-ci.com/xvass/UserManager) |


### General Information 

----------------------

UserManager has been developed in C/C++ and Qt framework. The application has been designed to provide assistance to Linux administrators in order to manage users and groups. This tool has a friendly dashboard and offers the following functionality 

* add,edit,delete user accounts and groups
* add users to groups
* search users
* search groups
* remove users from groups 
* set primary groups 
* add members to groups 
* remove members from groups 
* add individual groups 
* show and edit user information 
* set UIDs and GIDs
* set users passwords 
* set working directories
* passwords aging
* set account expiration
* enable or disable user accounts
* show disk usage
* set working shells

TODO :

* implement password generator 
* provide application usage from limited users in order to be able to change their passwords (same like passwd)
* implement password strength checks
* implement password suggestions 
* send an email to the users in case their passwords are about to be expired 

------------------


### Installation Info 

* This application has been tested in 64bit Linux Debian and Ubuntu distributions.  


### Succesfully tested in the following architectures
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- Linux 5.3.0-kali2-amd64 #1 SMP Debian 5.3.9-3kali1 (2019-11-20) x86_64 GNU/Linux

- Linux 4.15.0-29-generic #31-Ubuntu SMP Tue Jul 17 15:39:52 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------

### Installation prerequisites ( optional )

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### Installation 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git clone https://github.com/xvass/UserManager.git
cd UserManager
chmod +x install_and_run.sh
./install_and_run.sh
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

