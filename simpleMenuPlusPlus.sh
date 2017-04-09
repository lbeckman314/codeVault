#!/bin/bash

#------------------------------------------------------------------------------------------------------
# PURPOSE ------------ This program provides a (new and sexier!) menu interface for common *NIX activities
# DATE --------------- 07 december 2016 wednesday
# AUTHOR ------------- liam beckman
# SOURCES ------------ none
# ASSIGNMENT --------- cs140u assignment 7 (due 07 december 2016 wednesday)
# WRITTEN WITH ------- Sublime Text 3 Build 3126
# COMPILED WITH ------ GNU bash, version 4.3.46(1)-release (x86_64-pc-linux-gnu)        
#-------------------------------------------------------------------------------------------------------

    #FUNCTION DEFINITIONS
#---------------------------------------------------------------------------#

    #You entered 1) print users currently logged in
listUsers()
{
    clear
    who | more    #output users information through more 
    echo
    echo "press any key to continue"
    read -n1      #wait for user to continue
}

#---------------------------------------------------------------------------#

    #You entered 2) print calendar for given month and year
pastOrFutureCalendar()
{
    clear                    
    #month = ""
    #year = ""
    echo -n "enter a month between 1 and 12: "          #enter a month between 1 (January) and 12 (December)
    read month                                          #input month                                      
    #while :
    echo -n "enter year between 1900 and 2100: "        #protect from TIME TRAVELING WEIRDOS using our program! (between 20th -- 22nd centuries)
    read year                                           #input year
    if [ "$year" -ge 1900 ] && [ "$year" -le 2100 ]     #if year >= 1900 AND year <= 2100 
        then
            echo
            cal "$month" "$year"                        #output this month's calendar 
            echo
    else
        echo  
        echo "year out of range"                        #otherwise, year is out of range
        echo
    fi
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 3) print name of working directory
outputDirectory()
{
    clear
    pwd     #output working directory
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 4) change working directory
changeDirectory()
{
    clear
    #directoryName = ""
    echo -n "enter directory: "
    read directoryName              #input directory
    if [ -d "$directoryName" ]      #if directory is indeed a directory file
        then
            cd "$directoryName"     #change to that directory
            pwd
    elif [[ "$directoryName" == "~" ]] || [[ "$directoryName" == "\$HOME" ]]    #if user enters "~" or "$HOME"...
        then
            eval cd $directoryName  #change to ~ or $HOME or HOME or home
            echo "success!"         #small check to make sure this elif is running correctly and not defaulting to else below
            pwd 
    elif [ $# -eq 0 ]               #if the user did not enter any arguments...    
        then
            cd                      #...change to the home directory
            pwd
    else                            #if all else fails...
        cd                          #...change to the home directory
        pwd
    fi
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 5) output files in working directory
listFiles()
{
    clear
    ls -l | more                    #output files in working directory through more
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 6) print current calendar and date
currentDateAndTime()
{
    clear
    cal                             #output current calendar
    date                            #output current date
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 7) print a file to the screen
openVi()
{
    clear
    #fileName = ""
    echo -n "enter name of file: "          #prompt user to enter name (or path) of file
    read fileName
    if [ -f "$fileName" ] && file --mime $fileName | grep -q 'text'     #if the file is a normal file and NOT a binary file...
        then
            echo "OPENING FILE, press any key to continue"
            read
            vi "$fileName"                                                  #...open file in vi
    elif file --mime $fileName | grep -q 'binary\|directory'                #else if, if the file IS a binary file or directory...
        then
            echo "no binary files or directories allowed, buster!"          #return to menu
    else                                                                    #else, if the file does not exist yet...
            echo "CREATING FILE, press any key to continue"
            read
            eval vi $fileName                                               #...create the file and open it in vi
    fi
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 8) compose email
email()
{   
    #SUBJECT OF EMAIL
    clear
    echo -n "enter subject of message: "
    read emailSubject                               #input SUBJECT of message

    
    #RECIPIENT OF EMAIL
    echo -n "enter recipient address of message: "
    read emailAddress                               #input RECIPIENT of message
    if grep -c $emailAddress /etc/passwd > 0
        then
        echo "user found"
    else
        echo "user not found, press any key to return to main menu"
        read
        continue
    fi


    #ATTACHMENT OF EMAIL
    echo -n "enter file path of attached file: "
    read emailAttached                              #input ATTACHMENT of message
    if [ -f $emailAttached ] && file --mime $emailAttached | grep -q 'text'         #if attachment is a regular file and NOT a binary file...
        then
            mail -s "$emailSubject" "$emailAddress" < "$emailAttached"              #mail the message with the file attached
            echo "MESSAGE HAS SENT!"                                                #confirm message has been sent
    elif [ -e $emailAttached ]                      #else if the attachment exits and is NOT a reg. file (i.e. is a directory or binary file)...
        then
            echo "no binary files or directories allowed, buster!"                  #Shut it down!
            echo "press any key to return to main menu"    
    else                                            #else the file was not found 
        echo "file not found"           
    fi
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 9) exit program
exitProgram()
{
    clear
    echo "happy trails!"    #see ya around 'partner!
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #if no number between 1 and 9 was entered...
invalidInput ()
{
    clear
    echo "Please enter a number from 1 to 9"    #I only expect so much... *sigh*
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#


    #MAIN MENU AND FUNCTION CALLS
#---------------------------------------------------------------------------#

response = "1"  #initialize the response variable to a non-"9" value so that the until loop will run 
clear           #clean the screen
until [ "$response" = "9" ]     # 9 is the key to exit the program
        do
            clear
            echo  "welcome to liam's main menu"     #MENU SYSTEM
            echo
            echo "1 -- Display users currently logged in"
            echo "2 -- Display a calendar for a specific month and year (user is asked for a month and year to be displayed)"
            echo "3 -- Display the current directory path"
            echo "4 -- Change directory"
            echo "5 -- Long listing of visible files in the current directory"
            echo "6 -- Display current time and date and calendar"
            echo "7 -- Start the vi editor (user will be asked which file to open if the file does not exist, then create new one)"
            echo "8 -- Email a file to a user (use the emailer program created in assignment 6 but it will need a few error checks)"
            echo "9 -- Quit"
            echo
            echo -n "make your selection: "       #prompt user for their response
            read response                   #read user's response



#---------------------------------------------------------------------------#
            case $response in 
                
                1)      #You entered 1) print users currently logged in
                    listUsers               #call listUsers() function
                    ;;

#---------------------------------------------------------------------------#

                2)      #You entered 2) print calendar for given month and year
                    pastOrFutureCalendar    #call pastOrFutureCalendar() function
                    ;;

#---------------------------------------------------------------------------#

                3)      #You entered 3) print name of working directory
                    outputDirectory         #call outputDirectory() function
                    ;;

#---------------------------------------------------------------------------#


                4)      #You entered 4) change working directory
                    changeDirectory         #call changeDirectory() function
                    ;;

#---------------------------------------------------------------------------#

                5)      #You entered 5) output files in working directory
                    listFiles               #call listFiles() function
                    ;;

#---------------------------------------------------------------------------#

                6)      #You entered 6) print current calendar and date
                    currentDateAndTime      #call currentDateAndTime() function
                    ;;

#---------------------------------------------------------------------------#

                7)      #You entered 7) print a file to the screen
                    openVi                  #call openVi() function
                    ;;

#---------------------------------------------------------------------------#
#
                8)      #You entered 8) compose email
                    email                   #call email() function
                    ;;
#---------------------------------------------------------------------------#

                9)      #You entered j. exit program
                    exitProgram             #call exitProgram() function
                    ;;

#---------------------------------------------------------------------------#

                *)      #if no number between 1 and 9 was entered...
                    invalidInput            #call invalidInput() function
            
            esac    #end case

        done    #end do



