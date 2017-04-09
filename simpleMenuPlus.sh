#!/bin/bash

#------------------------------------------------------------------------------------------------------
# PURPOSE ------------ This program provides a menu interface for common *NIX activities
# DATE --------------- 26 november 2016 saturday
# AUTHOR ------------- liam beckman
# SOURCES ------------ none
# ASSIGNMENT --------- cs140u assignment 6 (due 27 november 2016 sunday)
# WRITTEN WITH ------- Sublime Text 3 Build 3126
# COMPILED WITH ------ GNU bash, version 4.3.46(1)-release (x86_64-pc-linux-gnu)        
#-------------------------------------------------------------------------------------------------------

response = "a"  #initialize the response variable to a non-"j" value so that the until loop will run 
clear   #clean the screen
until [ "$response" = "j" ]     # j or J is the key to exit the program
        do
            echo "WHAT IS THY COMMAND?"     #MENU SYSTEM
            echo "  a. compose email "
            echo "  b. print users currently logged in "
            echo "  c. print current date and time "
            echo "  d. print current calendar "
            echo "  e. print name of working directory "
            echo "  f. print contents of working directory "
            echo "  g. determine the IP of a given web address "
            echo "  h. print your fortune "
            echo "  i. print a file to the screen "
            echo "  j. exit program "
            echo
            echo
            echo -n "USER RESPONSE: "       #prompt user for their response
            read response                   #read user's response

#---------------------------------------------------------------------------#

            case $response in
                a|A)    #You entered a. compose email
                    clear
                    echo -n "enter subject of message: "
                    read emailSubject
                    echo -n "enter recipient address of message: "
                    read emailAddress
                    echo -n "enter file path of attached file: "
                    read emailAttached
                    mail -s "$emailSubject" "$emailAddress" < "$emailAttached"
                    clear
                    echo "MESSAGE HAS SENT!"
                    echo
                    ;;

#---------------------------------------------------------------------------#

                b|B)    #You entered b. print users currently logged in
                    clear
                    who | more    #output users information    
                    echo
                    ;;

#---------------------------------------------------------------------------#

                c|C)    #You entered c. print current date and time
                    clear
                    date    #output current date        
                    echo
                    ;;

#---------------------------------------------------------------------------#

                d|D)    #You entered d. print current calendar
                    clear                    
                    cal     #output this month's calendar 
                    echo
                    ;;

#---------------------------------------------------------------------------#

                e|E)    #You entered e. print name of working directory
                    clear
                    pwd     #output working directory
                    echo
                    ;;

#---------------------------------------------------------------------------#

                f|F)    #You entered f. print contents of working directory
                    clear
                    ls | more   #output contents of working directory through more program (q to exit)
                    echo
                    ;;

#---------------------------------------------------------------------------#

                g|G)    #You entered g. determine the IP of a given web address
                    clear
                    echo -n "enter web address: "   #prompt user to enter their chosen web address
                    read webAddress
                    host "$webAddress"          #output IP of given web address
                    echo
                    dig +short "$webAddress"    #Domain Information Groper (short flag), more info on DNS
                    echo
                    ;;

#---------------------------------------------------------------------------#

                h|H)    #You entered h. print your fortune
                    clear
                    fortune     #output fortune message
                    echo
                    ;;

#---------------------------------------------------------------------------#

                i|I)    #You entered i. print a file to the screen
                    clear
                    echo -n "enter name of file: "  #prompt user to enter name (or path) of file
                    read fileName
                    if [ -f "$fileName" ]       #if the file is a normal file...
                        then
                            more "$fileName"    #...output file through more program (q to exit)
                    else                        #else, if the file is NOT a normal file...
                        echo "I am unable to find your file. Please reenter filename"
                    fi
                    echo
                    ;;

#---------------------------------------------------------------------------#

                j|J)    #You entered j. exit program
                    clear
                    echo
                    ;;

#---------------------------------------------------------------------------#

                *)      #if no letter between a and j was entered...
                    clear
                    echo "Please enter a letter from a to j"
                    echo
                    ;;
            esac    #end case

        done    #end do
