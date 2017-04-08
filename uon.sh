#!/bin/bash

# liam beckman
# 30 november 2016

#uon.sh: this program will respond when a given user is logged in (otherwise it will sleep)
      
until who | grep "$1" > /dev/null #until the user (frist argument) is logged into the system
      do sleep 30   #sleep for 30 seconds
      done
echo "$1 is logged on." exit 0