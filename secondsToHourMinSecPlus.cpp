//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program converts number of seconds to digital output hr:min:sec.
// AUTHOR ---------- liam beckman
// DATE ------------ 01 october 2016 saturday
// SOURCES --------- http://stackoverflow.com/questions/2037736/finding-size-of-int-array
// ASSIGNMENT ------ cs161 lab 2 program 2 (due october 6th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>

using namespace std;
int main()
{
	int secs=0;		//seconds
	int mins=0;		//minutes
	int hrs=0;		//hours
	
	cout << "Enter yer seconds ye scurvy dog!" << endl;	//prompts user for the number of seconds
	cin >> secs;	//user inputs their total number of seconds

	while (secs>=60)		//while there are more than 60 seconds overall...
	{
		mins=secs/60;		//...convert seconds into minutes...
		secs-=60*mins;		//...and subtract those seconds from the total. 
		while (mins>=60)	//and while there are more than 60 minutes overall..
		{
			hrs = mins/60;	//... convert minutes to hours...
			mins -= 60*hrs;	//...and subtract those minutes from the total.
		}
	}

	cout << hrs <<":"<< mins <<":"<< secs << endl;	//output hours:minutes:seconds
	
	return 0;
}

