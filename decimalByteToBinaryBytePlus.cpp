//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This programs converts decimal byte capacity to binary byte capacity.
// AUTHOR ---------- liam beckman
// DATE ------------ 01 october 2016 saturday
// SOURCES --------- http://www.tweakandtrick.com/2013/07/lost-storage-space.html 
//                   http://radtke.eu/xiv-storage-blog/howto/56-binary-and-decimal-capacity-conversion
// ASSIGNMENT ------ cs161 lab 2 program 3 (due october 6th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    double byteHD;          //supposed number of bytes in our hard drive              
    double byteReal;        //actual number of bytes in our hard drive 
    char kmgt;              //stands for KB-MB-GB-TB, will be used to help determine user's input
    cout << "enter your hardware specifications (up to 999 terabytes)!" << endl;     //prompt for user to input byteHD
    cin >> byteHD >> kmgt;  //user inputs the supposed number of bytes here
        
                                                //our kmgt comes to the rescue!
        if(kmgt == 'k' || kmgt == 'K')          //'k' translate to KB, or kilobytes, or 1 x 10^3 bytes
            byteHD *= 1e+03;                    
        else if(kmgt == 'm' || kmgt == 'M')     //'m' translate to MB, or megabytes, or 1 x 10^6 bytes
            byteHD *= 1e+06;                     
        else if(kmgt == 'g' || kmgt == 'G')     //'g' translate to GB, or gigabytes, or 1 x 10^9 bytes
            byteHD *= 1e+09;                    
        else if(kmgt == 't' || kmgt == 'T')     //'p' translate to TB, or terabytes, or 1 x 10^12 bytes
            byteHD *= 1e+12;                    
    
   
    if (byteHD < 1e+06)                                 //if the supposed number of bytes is under 1 megabyte...
        byteReal = byteHD * 1000/1024;                  //...the actual number of bytes is 1000 / 1024 less!
    
    else if (byteHD < 1e+09)                            //if the supposed number of bytes is under 1 gigabyte...
        byteReal = byteHD * pow(1000, 2)/pow(1024, 2);  //...the actual number of bytes is 1000^2 / 1024^2 less!
    
    else if (byteHD < 1e+12)                            //if the supposed number of bytes is under 1 terabyte...
        byteReal = byteHD * pow(1000, 3)/pow(1024, 3);  //...the actual number of bytes is 1000^3 / 1024^3 less!
    
    else if (byteHD < 1e+15)                            //if the supposed number of bytes is under 1 petabyte...
        byteReal = byteHD * pow (1000, 4)/pow(1024, 4); //...the actual number of bytes is 1000^4 / 1024^4 less!
    
    cout << "The actual number of bytes in your system is: " << endl;
    cout << byteReal << " bytes";      //outputs the actual number of bytes!
     
    
                                                //this section translates the actual number of bytes into KB, MB, GB, or TB notation
        if(kmgt == 'k' || kmgt == 'K')          //if the user originally inputed KB...then the actual number of bytes is divided by 1 x 10^3
            byteReal /= 1e+03;                  
        else if(kmgt == 'm' || kmgt == 'M')     //and if the user originally inputed MB...then the actual number of bytes is divided by 1 x 10^6
            byteReal /= 1e06;                   
        else if(kmgt == 'g' || kmgt == 'G')     //and if the user originally inputed GB..then the actual number of bytes is divided by 1 x 10^9
            byteReal /= 1e+09;                  
        else if(kmgt == 't' || kmgt == 'T')     //and f the user originally inputed TB...then the actual number of bytes is divided by 1 x 10^12
            byteReal /= 1e+12;                  

    cout << " (or " << byteReal << " " << kmgt << "B)" << endl;     //outputs the actual number of bytes in KB, MB, GB, or TB notation!

    return 0;
}

