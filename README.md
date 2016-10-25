
###UserManager

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


- you can find the executable under the folder /Debug/usermanager.app/Content/M\$

- download the executable and put it in /opt/usermanager

- use the following command to create a symbolic link

`ln -s /opt/usermanarer /usr/bin/usermanager\`

- open a terminal and run

`usermanager &`

enjoy ;-)
