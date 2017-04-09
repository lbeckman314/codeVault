#!/bin/bash

#------------------------------------------------------------------------------------------------------
# PURPOSE ------------ This program installs my favorite programs on a fresh install of ubuntu!
# DATE --------------- 26 march 2017
# AUTHOR ------------- liam beckman
# SOURCES ------------ none
# WRITTEN WITH ------- Sublime Text 3 Build 3126
# COMPILED WITH ------ gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 on Ubuntu 16.04 xenial        
# EXECUTE COMMAND ---- ./itsAlive.sh
# VERSION ------------ 2017-03-26
# MODIFICATIONS ------ updated dropbox daemon command
#-------------------------------------------------------------------------------------------------------

installPrograms()
{
    #-----------------------------------------------#
    # dropbox
    #-----------------------------------------------#

    cd ~ && wget -O - "https://www.dropbox.com/download?plat=lnx.x86_64" | tar xzf -
    (~/.dropbox-dist/dropboxd &)    #launches dropbox daemon in bckground

    #-----------------------------------------------#
    # evince
    #-----------------------------------------------#

    sudo apt-get install evince

    #-----------------------------------------------#
    # firefox
    #-----------------------------------------------#

    sudo apt-get install firefox
    
    #-----------------------------------------------#
    # flatabulous theme
    #-----------------------------------------------#

    #flatabulous
    sudo apt-get install unity-tweak-tool

    wget -q -O - http://archive.getdeb.net/getdeb-archive.key | sudo apt-key add -
    sudo sh -c 'echo "deb http://archive.getdeb.net/ubuntu xenial-getdeb apps" >> /etc/apt/sources.list.d/getdeb.list'
    sudo apt-get update
    sudo apt-get install ubuntu-tweak

    sudo add-apt-repository ppa:noobslab/themes
    sudo apt-get update
    sudo apt-get install flatabulous-theme

    #-----------------------------------------------#
    # gparted
    #-----------------------------------------------#

    sudo apt-get install gparted

    #-----------------------------------------------#
    # libreoffice
    #-----------------------------------------------#

    sudo apt-get install libreoffice

    #-----------------------------------------------#
    # numix circle icons
    #-----------------------------------------------#

    sudo add-apt-repository ppa:numix/ppa
    sudo apt-get update
    sudo apt-get install numix-icon-theme-circle    

    #-----------------------------------------------#
    # owncloud
    #-----------------------------------------------#

    sudo curl https://download.owncloud.org/download/repositories/stable/Ubuntu_16.04/Release.key | sudo apt-key add -
    echo 'deb https://download.owncloud.org/download/repositories/stable/Ubuntu_16.04/ /' | sudo tee /etc/apt/sources.list.d/owncloud.list
    sudo apt-get update
    sudo apt-get install owncloud

    #-----------------------------------------------#
    # plank
    #-----------------------------------------------#

    sudo add-apt-repository ppa:ricotz/docky
    sudo apt-get update
    sudo apt-get install plank

    #-----------------------------------------------#
    # redshift
    #-----------------------------------------------#

    sudo apt-get install redshift redshift-gtk

    #-----------------------------------------------#
    # simple scan
    #-----------------------------------------------#

    sudo apt-get install simple-scan
    
    #-----------------------------------------------#
    # spotify
    #-----------------------------------------------#

    # 1. Add the Spotify repository signing key to be able to verify downloaded packages
    sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys BBEBDCB318AD50EC6865090613B00F1FD2C19886

    # 2. Add the Spotify repository
    echo deb http://repository.spotify.com stable non-free | sudo tee /etc/apt/sources.list.d/spotify.list

    # 3. Update list of available packages
    sudo apt-get update

    # 4. Install Spotify
    sudo apt-get install spotify-client

    #-----------------------------------------------#
    # sublime text 3
    #-----------------------------------------------#

    sudo add-apt-repository ppa:webupd8team/sublime-text-3
    sudo apt-get update
    sudo apt-get install sublime-text-installer

    #-----------------------------------------------#
    # transmission
    #-----------------------------------------------#

    sudo add-apt-repository ppa:transmissionbt/ppa
    sudo apt-get update
    sudo apt-get install transmission-cli transmission-common transmission-daemon

    #-----------------------------------------------#
    # zsh
    #-----------------------------------------------#

    sudo apt-get install zsh
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
    wget -O xt http://git.io/vn6HM && chmod +x xt && ./xt && rm xt  #flatabulous zsh config

}


#---------------------------------------------------------------------------#

listPrograms()
{
    clear
    echo "dropbox"
    echo "evince"
    echo "firefox"
    echo "flatabulous theme"
    echo "gparted"
    echo "libreoffice"
    echo "numix circle icons"
    echo "owncloud"
    echo "plank"
    echo "redshift"
    echo "simple scan"
    echo "spotify"
    echo "sublime text 3"
    echo "transmission"
    echo "zsh"
    echo
    echo "press any key to continue"
    read -n1
}

#---------------------------------------------------------------------------#

    #You entered 9) exit program
quit()
{
    clear
#    echo "happy trails!"    #see ya around 'partner!
#    echo
#    echo "press any key to continue"
#    read -n1
}

#---------------------------------------------------------------------------#

    #if no number between 1 and 9 was entered...
invalidInput ()
{
    clear
    echo "Please enter a number from 1 to 2"    #I only expect so much... *sigh*
    echo
    echo "press any key to continue"
    read -n1
}



#---------------------------------------------------------------------------#
    #MAIN MENU AND FUNCTION CALLS
#---------------------------------------------------------------------------#

response = "1"  #initialize the response variable to a non-"9" value so that the until loop will run 
#clear           #clean the screen
until [ "$response" = "q" ]     # q is the key to exit the program
        do
            clear
            echo " ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ ⚡ "
            echo "---------------------------------"
            echo " ⚡ ⚡ ⚡ ⚡  IT'S ALIVE!!!  ⚡ ⚡ ⚡ ⚡ "                #MENU SYSTEM
            echo "---------------------------------"
            echo " ⚡     post-install script     ⚡ "
            echo "---------------------------------"
            echo
            echo "1 :: Install programs"
            echo "2 :: List programs to be installed"
            echo "q :: Quit"
            echo
            echo -n "user input :: "       #prompt user for their response
            read response                   #read user's response



#---------------------------------------------------------------------------#
            case $response in 
                
                1)      #You entered 1) print users currently logged in
                    installPrograms               #call listUsers() function
                    ;;

#---------------------------------------------------------------------------#

                2)      #You entered 2) print calendar for given month and year
                    listPrograms    #call pastOrFutureCalendar() function
                    ;;

#---------------------------------------------------------------------------#

                q)      #You entered j. exit program
                    quit             #call quit() function
                    ;;

#---------------------------------------------------------------------------#

                *)      #if no number between 1 and 9 was entered...
                    invalidInput            #call invalidInput() function
            
            esac    #end case

        done    #end do