#!/bin/sh

HOST=`uname -n`

email_user() {
 echo "Your password on $HOST will be expired in $DAYS_UNTIL_PASS_EXPIRE days" | mail -s "Password Expiration" $USER 

}

## Today's date (expressed in epoch format)
today=`/usr/bin/perl -e 'printf("%d\n", (time/60/60/24))'`
echo $today
for line in `cat /etc/shadow`
do
  USER=`echo $line | awk -F: '{print $1}'`
  DAY_LAST_PASS_CHANGE=`echo $line | awk -F: '{print $3}'`
  DAYS_PASS_VALID=`echo $line | awk -F: '{print $5}'`
  DAYS_SINCE_LAST_PASS_CHANGE=`expr $today - $DAY_LAST_PASS_CHANGE`
  DAYS_UNTIL_PASS_EXPIRE=`expr $DAYS_PASS_VALID - $DAYS_SINCE_LAST_PASS_CHANGE`

echo $USER
#echo $DAYS_UNTIL_PASS_EXPIRE
echo $DAYS_PASS_VALID
#echo $DAYS_SINCE_LAST_PASS_CHANGE
echo $DAYS_UNTIL_PASS_EXPIRE


    if [ $DAYS_UNTIL_PASS_EXPIRE -lt "8" ] && [ $DAYS_UNTIL_PASS_EXPIRE -gt "-1" ]; then
       email_user $DAYS_UNTIL_PASS_EXPIRE
    fi

done
