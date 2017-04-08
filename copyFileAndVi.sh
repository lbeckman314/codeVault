#!/bin/bash
 
# liam beckman
# 30 november 2016

# purpose of the program: To both make a copy of a given file and open it in vi

  

if test $# = 1 # if the number of arguments is equal to one...
     then
          if test -f $1   # ...and if the first argument is a regular file...

               then
                    cp $1 $HOME/keep    #...then copy that file to the keep directory in the user's home drectory, and then open it in vi
                    vi $1
                    else
                    echo " file not found.Try again"
          fi
          else
          echo " You must specify a file name.Try again."
fi
