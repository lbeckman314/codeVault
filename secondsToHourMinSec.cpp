//Program 2:

//Write a program that prompts a user to enter a number of seconds. The program then prints the amount of time in hours, minutes, and seconds (for example 9630 seconds has the output 2:40:30).



//PURPOSE ------ This program converts number of seconds to digital houtput hr:min:sec.

/*
*NAME: liam beckman
*ASSIGNMENT: 2 magic square
*DATE: mon 26 september 2016
*SOURCES: none 
*/

#include <iostream>

using namespace std;
int main()
{
	int secs=0;
	int mins=0;
	int hrs=0;
	cout << "Enter yer seconds!" << endl;
	cin >> secs;

	while (secs>=60)
	{
		mins=secs/60;
		secs-=60*mins;
		while (mins>=60)
		{
			hrs = mins/60;
			mins -= 60*hrs;
		}
	}

	cout << hrs <<":"<< mins <<":"<< secs << endl;
	return 0;
}

