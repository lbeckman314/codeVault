#!/bin/bash

#----------------------------------------------------------------------------------------------------------
# AUTHOR ---------- liam beckman
# DATE ------------ 30 november 2016 wednesday
# PURPOSE --------- This program provides a menu interface for common *NIX activities
# SOURCES --------- none
# ASSIGNMENT ------ cs140u lab 7 (due 30 november 2016 wednesday)
# COMPILED WITH --- GNU bash, version 4.3.46(1)-release (x86_64-pc-linux-gnu)
#-----------------------------------------------------------------------------------------------------------


answer = "a"
clear
until [ "$answer" = "q" ]           # until response equals 999
    do                              #complete the following...
        echo -e "\n COMMAND MENU\n"     # menu interface to simple commands
        echo " 1. system's date and time"
        echo " 2. logged in users"
        echo " 3. current working directory"
        echo " 4. print yer fortune"
        echo " 5. whatever ya got in yer working directory"
        echo -e " q. QUIT PROGRAM\n"
        
        read answer
        case "$answer" in
            1)
                clear
                date
                echo
                cal
                ;;
            2)
                clear
                who | more
                ;;
            3)
                clear
                pwd
                ;;
            4)
                clear
                fortune
                ;;
            5)
                clear
                ls | more
                ;;
            q)  clear
                echo "Happy trails 'partner!"
                ;;
            * )
                destination = "the sun"
                clear
                #confirm = "n"
                echo -n "Nuclear launch code accepted. CONFIRM LAUNCH (y/n):" 
                read confirm
                if [ $confirm  = "y" ]
                    then 
                        echo -n "enter destination: "
                        read destination
                        echo "Launching in 3... 2... 1..."
                        echo "Happy thoughts and good juju launched at" $destination 
                else
                    echo "global war narrowly averted. *phew*"
                fi
                ;;
        esac                #end case
    done                    #end do loop