//Program 1:

//Write a program that prompts a user to enter five test scores and then prints the average test score.




//PURPOSE ------ This programs determines the average of five user-inputed test scores.

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
	//scores = float[5]
	/*for (i=1,i<=5,i++)
	{
		cout << "Enter score number " << i << ": ";
		cin >> float[i];
	}
	*/
	float score1, score2, score3, score4, score5;

	cout << "Enter thy scores young padawan." << endl;

	cin >> score1 >> score2 >> score3 >> score4 >> score5;
	float scoreAvg = (score1+score2+score3+score4+score5)/5;
	//float scoreAvg = scores.sum/scores.length;
	cout << scoreAvg << endl;
	return 0;
}
