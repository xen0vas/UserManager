#!/bin/sh
#
#
HOST=`uname -n`

email_user() {
 echo "Your password on $HOST will be expired in $DAYS_UNTIL_PASS_EXPIRE days!" | mail -s "Password Expiration" $USER 

}

## Today's date (expressed in epoch format)
today=`/usr/bin/perl -e 'printf("%d\n", (time/60/60/24))'`

for line in `cat /etc/shadow | egrep -v "sscop|root|NP|LK"`
do
  USER=`echo $line | awk -F: '{print $1}'`
  DAY_LAST_PASS_CHANGE=`echo $line | awk -F: '{print $3}'`
  DAYS_PASS_VALID=`echo $line | awk -F: '{print $5}'`
  DAYS_SINCE_LAST_PASS_CHANGE=`expr $today - $DAY_LAST_PASS_CHANGE`
  DAYS_UNTIL_PASS_EXPIRE=`expr $DAYS_PASS_VALID - $DAYS_SINCE_LAST_PASS_CHANGE`


    if [ $DAYS_UNTIL_PASS_EXPIRE -lt "8" ]; then


          email_user $DAYS_UNTIL_PASS_EXPIRE
    fi

done