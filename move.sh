#!/bin/bash

cd .. && mv UserManager/ /opt
cd /opt/UserManager
chown -R root:root UserManager
chmod -R 700 /opt/UserManager
