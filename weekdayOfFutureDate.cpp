//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This programs transports you into the future (or the past!) up to 5,883,516 years
// AUTHOR ---------- liam beckman
// DATE ------------ 12 october 2016 wednesday
// SOURCES --------- https://www.tutorialspoint.com/cplusplus/cpp_strings.html
// ASSIGNMENT ------ cs161 lab 3 program 1/4
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include  <iostream>
#include <string>
using namespace std;

int main()
{
    string dayPresent[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  //we'll use an array to hold our days of the week

    string dayInput;    //the current day
    string dayFuture;   //the future day
    int advance;        //the number of days to advance
    int n;              //temporary integer used to help calculate dayFuture

    cout << "Enter current day and number of days to advance (i.e. Saturday 3)." << endl;
    cin >> dayInput >> advance;

    //USER INPUTS CURRENT DAY
    if (dayInput == "Sunday" || dayInput == "sunday" )              
        n = 0;
    else if (dayInput == "Monday" || dayInput == "monday" )         //Hold me, love me, hold me, love me
        n = 1;
    else if (dayInput == "Tuesday" || dayInput == "tuesday" )       //I ain't got nothing but love, babe
        n = 2;
    else if (dayInput == "Wednesday" || dayInput == "wednesday" )   //Eight days a week!
        n = 3;
    else if (dayInput == "Thursday" || dayInput == "thursday" )
        n = 4;
    else if (dayInput == "Friday" || dayInput == "friday" )
        n = 5;
    else if (dayInput == "Saturday" || dayInput == "saturday" )
        n = 6;
    else                                                            //We don't recognize "Mooday" 'round these parts.
        cout << "BEEP BOOP -- DOES NOT COMPUTE -- PLEASE REENTER VALUES" << endl;

    dayFuture = dayPresent[(n + advance) % 7];  //calculation of the future day

    cout << dayFuture << endl;                  //out of the future day

    return 0;
}
