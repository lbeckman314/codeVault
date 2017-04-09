#!/bin/bash

#------------------------------------------------------------------------------------------------------
# PURPOSE ------------ this program will respond when a given user is logged in (otherwise it will sleep)
# DATE --------------- 30 november 2016
# AUTHOR ------------- liam beckman
# SOURCES ------------ none
# WRITTEN WITH ------- Sublime Text 3 Build 3126
# COMPILED WITH ------ gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 on Ubuntu 16.04 xenial        
# EXECUTE COMMAND ---- ./uon.sh
#-------------------------------------------------------------------------------------------------------
      
until who | grep "$1" > /dev/null #until the user (frist argument) is logged into the system
      do sleep 30   #sleep for 30 seconds
      done
echo "$1 is logged on." exit 0