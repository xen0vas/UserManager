
#UserManager

> UserManager is a Linux tool which helps Linux users to manage user accounts and groups. The tools has a friendly good looking
> dashboard and does the following 

- add,edit,delete user accounts and groups
- add users to groups
- search users
- remove users from groups 
- set UID's and GID's
- set users passwords 
- set working directories
- passwords aging
- set account expiration
- enable or disable user accounts
- view how much storage space users have allocate (disk quotas)
- set working shells

###UserManager dashboard
------------------------

![usermanager_dash](https://cloud.githubusercontent.com/assets/12726776/19657636/b21ed7de-9a2d-11e6-95db-92baa468b2dc.PNG)


###User properties
------------------

![user_properties](https://cloud.githubusercontent.com/assets/12726776/19657721/0139518c-9a2e-11e6-922f-27656a68bed4.PNG)


###Group Properties
-------------------

![group_properties](https://cloud.githubusercontent.com/assets/12726776/19677653/f6e47b88-9aa2-11e6-8cbf-0271dfee6291.PNG)


###User Groups
---------

![groups](https://cloud.githubusercontent.com/assets/12726776/19677661/ff30ea24-9aa2-11e6-8e16-1f9f001186d7.PNG)


###Add Groups
-------------

![add_groups](https://cloud.githubusercontent.com/assets/12726776/19677652/f4d972e4-9aa2-11e6-9fe5-09f6cd91864a.PNG)


###User Passwords 
-----------------

![passwords](https://cloud.githubusercontent.com/assets/12726776/19658010/f81755c6-9a2e-11e6-97bd-60a91c1285b3.PNG)


---------------


- you can find the executable under the folder /Debug/usermanager.app/Content/M\$

- download the executable and put it in /opt/usermanager

- use the following command to create a symbolic link

`ln -s /opt/usermanarer /usr/bin/usermanager\`

- open a terminal and run

`usermanager &`

enjoy ;-)

