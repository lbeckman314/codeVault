#!/bin/bash 

# https://www.w3schools.com/code/tryit.asp?filename=FDL5ESUIWVXO
#------------------------------------------------------------------------------------------------------
# PURPOSE --------- This program outputs the repeating section of rational numbers!
# AUTHOR ---------- liam beckman
# DATE ------------ 13 march 2017 monday
# SOURCES --------- none
# WRITTEN WITH ---- Sublime Text 3 Build 3126
# COMPILED WITH --- gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 on Ubuntu 16.04 xenial        
#               --- g++ Lab6.cpp  -lgmpxx -lgmp -o Lab6; ./Lab6
#-------------------------------------------------------------------------------------------------------


#if [ -d "$liber8" ]; then
#    mkdir liber8;
#fi


    
#----------------------------------------------------#
# SEARCH FOR "PURPOSE" AND "DATE"
#----------------------------------------------------#

#change ",," to "\t" for tab seperation
#awk '/PURPOSE/ { ORS = ",,"; print FILENAME; print $0 } /DATE/ { print $0; printf "(www.github.com/lbeckman314/codeVault/blob/master/"FILENAME")" " (raw.githubusercontent.com/lbeckman314/codeVault/blob/master/"FILENAME")"; printf "\n" }' *.cpp > liber8/index.txt 
#ls | grep ".txt" | awk '{ ORS = ",,"; print $0; print null; print null; printf "(www.github.com/lbeckman314/codeVault/master/"$NF")" " (raw.githubusercontent.com/lbeckman314/codeVault/blob/master/"$NF")"; printf "\n" }' >> liber8/index.txt

#rm index.txt

cd ..

for file in *
    do
        if [ -f "$file" ] && [ "$file" != LICENSE ]
            then
            #if grep -c 'PURPOSE' "$file" > /dev/null
            #   then
                awk '/PURPOSE/ { ORS = ",,"; print FILENAME; print $0 } /DATE/ { print $0; printf "(www.github.com/lbeckman314/codeVault/blob/master/"FILENAME")" " (raw.githubusercontent.com/lbeckman314/codeVault/master/"FILENAME")"; printf "\n\n" }' "$file" >> liber8/index.txt
            #else
            #    echo '"$file",,,,,,' >> liber8/index.txt
           #fi
        elif [ -d "$file" ] && [ "$file" != liber8 ] && [ "$file" != .git ]
            then
                cd "$file"
                echo "$file" >> ../liber8/index.txt
                #echo -n ├── >> ../liber8/index.txt
                ls | grep ".txt" | awk '{ printf "├── "$0""; }' >> ../liber8/index.txt
                ls | grep ".sublime-build" | awk '{ printf "├── "$0""; }' >> ../liber8/index.txt
                #tree -o ../liber8.index.txt
                for fileABC in *
                    do
                        #if grep -c 'PURPOSE' "$fileABC" > 0 
                            #then
                                #echo -n └──
                                awk '/PURPOSE/ { ORS = ",,"; printf "└── '$fileABC',,"; print $0 } /DATE/ { print $0; printf "(www.github.com/lbeckman314/codeVault/blob/master/"FILENAME")" " (raw.githubusercontent.com/lbeckman314/codeVault/master/"FILENAME")"; printf "\n" }' "$fileABC" >> ../liber8/index.txt
                        #else
                            #echo '"$fileABC",,,,,,' >> ../liber8/index.txt
                        #fi
                    done
                echo >> ../liber8/index.txt
                cd ..
        fi
    #ls | grep ".sublime-build" | awk '{ ORS = ",,"; print $0; print null; print null; printf "(www.github.com/lbeckman314/codeVault/master/"$NF")" " (raw.githubusercontent.com/lbeckman314/codeVault/master/"$NF")"; printf "\n" }' >> liber8/index.txt
    done #> result.txt



#----------------------------------------------------#
# REMOVE EXTRANEOUS CHARACTERS
#----------------------------------------------------#


sed -i 's:#::g' liber8/index.txt
sed -i 's://::g' liber8/index.txt
sed -i 's/*//g' liber8/index.txt
sed -i 's/://g' liber8/index.txt
sed -i 's/---//g' liber8/index.txt
sed -i 's/   *//g' liber8/index.txt   #changes three spaces to two spaces 
sed -i 's:PURPOSE::g' liber8/index.txt
sed -i 's:DATE::g' liber8/index.txt


#----------------------------------------------------#
# COMPLETE WEB ADDRESS
#----------------------------------------------------#


sed -i 's/www/https:\/\/www/g' liber8/index.txt #add https:// before www
sed -i 's/raw/https:\/\/raw/g' liber8/index.txt #add https:// before raw

#----------------------------------------------------#
# CHOOSE SEPERATION CHARACTER
#----------------------------------------------------#


##sed -i 's/\t\s/\t/g' liber8/index.txt #tab seperated
#sed -i 's/,,\s/,,/g' liber8/index.txt   #comma seperated


#----------------------------------------------------#
# ADD TEXT FILES
#----------------------------------------------------#


#ls | less | grep ".txt" >> liber8/index.txt
#sort -k 3 liber8/index.txt -o liber8/index.txt    #sort list by filename
#cat liber8/index.txt



#----------------------------------------------------#
# ADD HTML TAGS
#----------------------------------------------------#


# http://stackoverflow.com/questions/1251999/how-can-i-replace-a-newline-n-using-#sed
#sed -i ':a;N;$!ba;s:\n:\n</tr>\n<tr>\n\t<td>:g' liber8/index.txt



#awk '/201/ {printf "%s %s %s\n", $3, $2, $1}' index.txt





sed -i ':a;N;$!ba;s:\n├:├:g' liber8/index.txt
sed -i ':a;N;$!ba;s:\n└:└:g' liber8/index.txt

sed -i ':a;N;$!ba;s/\n\n/~~~/g' liber8/index.txt
sed -i 's/,,/\n/g' liber8/index.txt


sed -i 's/[Mm]on[(day) ]2//g' liber8/index.txt
sed -i 's/[Tt]uesday//g' liber8/index.txt
sed -i 's/[Tt]ues//g' liber8/index.txt
sed -i 's/[Ww]ednesday//g' liber8/index.txt
sed -i 's/[Tt]hursday//g' liber8/index.txt
sed -i 's/[Ff]riday//g' liber8/index.txt
sed -i 's/[Ss]aturday//g' liber8/index.txt
sed -i 's/[Ss]unday//g' liber8/index.txt

sed -i 's/[Jj]anuary/01/g' liber8/index.txt
sed -i 's/[Ff]ebruary/02/g' liber8/index.txt
sed -i 's/[Mm]arch/03/g' liber8/index.txt
sed -i 's/[Aa]pril/04/g' liber8/index.txt
sed -i 's/[Mm]ay/05/g' liber8/index.txt
sed -i 's/[Jj]une/06/g' liber8/index.txt
sed -i 's/[Jj]uly/07/g' liber8/index.txt
sed -i 's/[Aa]ugust/08/g' liber8/index.txt
sed -i 's/[Ss]eptember/09/g' liber8/index.txt
sed -i 's/[Oo]ctober/10/g' liber8/index.txt
sed -i 's/[Nn]ovember/11/g' liber8/index.txt
sed -i 's/[Dd]ecember/12/g' liber8/index.txt


sed -r -i 's#([0-9]{1,2}) ([0-9]{1,2}) ([0-9]{4})#date -d"\2/\1/\3" +"%Y-%m-%d"#e' liber8/index.txt


sed -i ':a;N;$!ba;s/\n/,,/g' liber8/index.txt
sed -i 's/~~~/\n/g' liber8/index.txt
sed -i 's/,,\n/\n/g' liber8/index.txt

cp liber8/index.txt liber8/index.csv
cp liber8/index.txt liber8/index.md

sed -i  ':a;N;$!ba;s:\n\n:\n:g' liber8/index.txt
sed -i  's:^:<tr>\n\t<td>:g' liber8/index.txt
sed -i ':a;N;$!ba;s:\n<tr>:</td>\n<tr>:g' liber8/index.txt
sed -i ':a;N;$!ba;s:\n<tr>\n\t<td>:\n</tr>\n<tr>\n\t<td>:g' liber8/index.txt
sed -i ':a;N;$!ba;s:\n<tr>\n\t<td>$:\n</tr>:g' liber8/index.txt
sed -i  's:├:<br />├:g' liber8/index.txt
sed -i  's:└:<br />└:g' liber8/index.txt


#, or TAB or ,, or whatever ORF is set to


sed -i 's:,,:</td>\n\t<td>:g' liber8/index.txt
sed -i ':a;N;$!ba;s:</td>\n\t<td>$:</td>\n</tr>\n</table>:g' liber8/index.txt


#sed -i 's:<td>\n::g' liber8/index.txt
#sed -i 's:\t</tr>:</tr>:g' liber8/index.txt

#beginning of buffer
#sed -i '1s:^:<tr>\n\t<td>:' liber8/index.txt

#delete last line (hanging <td> tag)
##sed -i '$d' liber8/index.txt
##sed -i -e "\$a</tr>" liber8/index.txt


#----------------------------------------------------#
# ADD SVG ICONS AND FORMAT LOCATION
#----------------------------------------------------#

#githubSVG="$(cat liber8/mark-github.svg)"  #inline SVN
#codeSVG="$(cat liber8/code.svg)"           #inline SVN

#SVG embedded in object tag, means fewer lines in index.html.
#assumes SVGs are located in "/assets" directory
#https://svgontheweb.com/
#githubSVG="\<object type=\"image\/svg+xml\" data=\"\/assets\/mark-github.svg\"\>\<\/object\>"
#codeSVG="\<object type=\"image\/svg+xml\" data=\"\/assets\/code.svg\"\>\<\/object\>"

githubPNG="\<img src=\"\/assets\/mark-github.png\"\ alt=\"github logo\">"
codePNG="\<img src=\"\/assets\/code.png\"\ alt=\"code logo\">"

tr -d '(' < liber8/index.txt > temp.txt && mv temp.txt liber8/index.txt     #delete ( character from github address
tr -d ')' < liber8/index.txt > temp.txt && mv temp.txt liber8/index.txt     #delete ) character from github address

sed -i 's/https:/<a href="https:/g' liber8/index.txt    #add <a href="" to all https:
sed -i 's/.cpp\s/.cpp">github<\/a>/g' liber8/index.txt  #add closing a tag to github  address
sed -i 's/\.sh\s/\.sh">github<\/a>/g' liber8/index.txt  #add closing a tag to github  address
sed -i 's/.py\s/.py">github<\/a>/g' liber8/index.txt  #add closing a tag to github  address
sed -i 's/.md\s/.md">github<\/a>/g' liber8/index.txt  #add closing a tag to github  address


#sed -i 's:.py</td>:.py"></a></td>:g' liber8/index.txt
#sed -i 's:.sh</td>:.sh"></a></td>:g' liber8/index.txt


sed -i 's/github<\/a>/github '"$githubPNG"'<\/a>/g' liber8/index.txt #add githubSVG 

sed -i ':a;N;$!ba;s:.cpp</td>\n</tr>:.cpp"> raw code</a></td>\n</tr>:g' liber8/index.txt   #add raw code label
sed -i ':a;N;$!ba;s:.sh</td>\n</tr>:.sh"> raw code</a></td>\n</tr>:g' liber8/index.txt   #add raw code label
sed -i ':a;N;$!ba;s:.py</td>\n</tr>:.py"> raw code</a></td>\n</tr>:g' liber8/index.txt   #add raw code label
sed -i ':a;N;$!ba;s:.md</td>\n</tr>:.md"> raw code</a></td>\n</tr>:g' liber8/index.txt   #add raw code label

sed -i 's/raw code/<br \/>raw code '"$codePNG"'/g' liber8/index.txt   #add line break and codeSVG to raw code label


#----------------------------------------------------#
# FORMAT MARKDOWN TABLE
#----------------------------------------------------#


sed -i 's:,,: | :g' liber8/index.md
sed -i 's:^:| :' liber8/index.md
sed -i 's/(https:\/\/www.github.com/[github](https:\/\/www.github.com/g' liber8/index.md
sed -i 's/(https:\/\/raw.githubusercontent.com/<br \/>[raw](https:\/\/raw.githubusercontent.com/g' liber8/index.md
#sed -i 's:lbeckman314/*:lbeckman314*):g' liber8/index.md
sed -i 's:├:<br />├:g' liber8/index.md
sed -i 's:└:<br />└:g' liber8/index.md
sed -i 's/*)//g' liber8/index.md


sed -i '1s:^:| name | description | date <br /> y-m-d | location |\n:' liber8/index.md
sed -i '1a|:-----|:------------|:-----|:-------- |' liber8/index.md



echo "$(cat liber8/htmlHeader.html)" | cat - liber8/index.txt > temp && mv temp liber8/index.txt
#bothSVG="\<object type=\"image\/svg+xml\" data=\"\/assets\/both.svg\"\>\<\/object\>"
#bothPNG="\<object type=\"image\/png\" data=\"\/assets\/both.png\"\>\<\/object\>"
sed -i 's:</th>: '"$bothPNG"'</th>:g' liber8/index.txt

echo "$(cat liber8/htmlFooter.html)" >> liber8/index.txt

#sort -k 3 liber8/index.txt -o liber8/index.txt    #sort list by filename


mv liber8/index.txt liber8/index.html
cp liber8/index.html ~/Documents/website/code/index.md
mv liber8/index.md README.md
