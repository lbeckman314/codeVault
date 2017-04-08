//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program determines the average of five user-inputed test scores.
// AUTHOR ---------- liam beckman
// DATE ------------ 01 october 2016 saturday
// SOURCES --------- http://stackoverflow.com/questions/2037736/finding-size-of-int-array
// ASSIGNMENT ------ cs161 lab 2 program 1 (due october 6th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>

using namespace std;
int main()
{
	double scores[5] = {};	//this array will hold the user's test scores for the class 
	double total=0;			//total number of points (which will help us in calculating the average score)
	for (int i=0;i<5;i++)	//loop for the input of the class points
	{
            cout << "Enter score number " << i + 1 << " out of 5: ";	//"Enter score number 1 out of 5: "
            cin >> scores[i];											//User inputs scores here
            total += scores[i];											//total number of points increases
	}
	
	double scoreAverage = total/5;		//average class score is simply total number of points divided by class size 
	
	cout << "The average score for your class is: " << scoreAverage << endl;	//output of average

	return 0;

}

