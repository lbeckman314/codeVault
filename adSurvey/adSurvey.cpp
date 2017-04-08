//-------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program determines both the longest word and frequencies of different english words.
// AUTHOR ---------- liam beckman
// DATE ------------ 25 october 2016 tuesday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 5 english words (due october 27th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//--------------------------------------------------------------------------------------------------------------


/*
CS 133U
Assignment #5
Advertising Survey



Assignment:  

A certain advertising company has commissioned a study to determine if a recent advertising campaign is effective for certain age groups. Researchers have created a data file (results.txt) that contains the results attained by the study. The first column is the subject’s name (you may assume there is no whitespace in any name) and the second column indicates if the subject has seen the advertisement in question (Y or y  means yes, N or n means no). The third column specifies the subject's age and the last column (the 'score') specifies how favorably the subject views the product being advertised (from 0 to 100 with a score of 100 being most favorable).  A example of the file results.txt is attached as part of this assignment.  You should download this file to a convenient place on your hard drive. Please note that the file is a sample only. Your program should work on any data file that is formatted in a similar way.

Your assignment is to prompt the user to enter the full pathname to the data file on disk.  If the file does not exist in the specified location, your program should exit with a suitable error message.

The first thing your program should do is output to the screen a copy of the data read in from the disk file.  This is known as “echoing” the input data.

Your program should then calculate and display the the following results:
Average score for subjects under 18 who have not seen the ad.
Average score for subjects under 18 who have seen the ad.
Average score for subjects 18 and over who have not seen the ad.
Average score for subjects 18 and over who have seen the ad.
Display your results to two places of decimals, and write your program to automatically list your four calculated averages one to a line, along with a suitable label for each result.

Finally, your program should calculate and display to two places of decimals the overall average score for all of the subjects surveyed. (Note: Mathematically, this is NOT the average of the four averages you calculated previously).

Deliverables:

Please upload your program source code (.cpp file) as usual.  Be sure to comment your code as required, and to acknowledge any sources of help you may have received.  Your header comments should include the identification of the assignment and your name(s).  It should also include a comment indicating any sources of help you may have received. If there were none, the line should read:

// Sources: None.

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
	string name;
	char seenAd;
	double age;
	double score;
	double scoreSum[7];
	double totalScoreSum;
	double scoreCount[7];
	double totalScoreCount;
	double scoreAverage[7];
	double totalScoreAverage;

	ifstream survey;
	//string surveyPath;

	//cout << "Please enter the path of the survey file" << endl;
	//cin >> surveyPath;
	
	survey.open("/home/liam/Documents/compSci1/compSci1/week5/results.txt");

	if (!survey)
	{
		cout << "ERROR IN FILE INPUT! <BEEP BOOP!>" << endl;
		return 1;
	}

	//cout << "hh" << endl;
	int n = 0;
	if (survey.is_open())
	{
	while (!survey.eof())
	{
		survey >> name >> seenAd >> age >> score;
		cout << name << " " << seenAd << " " << age << " " << score << endl;
		//getline(survey, name);
		
		if (age < 18 && tolower(seenAd) == 'n')
		{
			scoreSum[0] += score;
			scoreCount[0] += 1;
			cout << "SCORE " << score << endl;
			cout << "scoreSum[0]: " << scoreSum[0] << endl;
			cout << "scoreCount[0]: "<< scoreCount[0] << endl;
			cout << "age < 18 && seenAd = N " << name << " " << seenAd << " " << age << " " << score << endl<< endl;
		}
		else if (age < 18 && tolower(seenAd) == 'y')
		{
			scoreSum[1] += score;
			scoreCount[1] += 1;
			cout << "SCORE " << score << endl;
			cout << "scoreSum[1]: " << scoreSum[1] << endl;
			cout << "scoreCount[1]: "<< scoreCount[1] << endl;
			cout << "age < 18 && seenAd = Y " << name << " " << seenAd << " " << age << " " << score << endl<< endl;
		}
		else if (age >= 18 && tolower(seenAd) == 'n')
		{
			scoreSum[2] += score;
			scoreCount[2] += 1;
			cout << "SCORE " << score << endl;
			cout << "scoreSum[2]: " << scoreSum[2] << endl;
			cout << "scoreCount[2]: "<< scoreCount[2] << endl;
			cout << "age > 18 && seenAd = N " << name << " " << seenAd << " " << age << " " << score << endl<< endl;
		}
		else if (age >= 18 && tolower(seenAd) == 'y')
		{
			scoreSum[3] += score;
			scoreCount[3] += 1;
			cout << "SCORE " << score << endl;
			cout << "scoreSum[3]: " << scoreSum[3] << endl;
			cout << "scoreCount[3]: "<< scoreCount[3] << endl;
			cout << "age > 18 && seenAd = Y " << name << " " << seenAd << " " << age << " " << score << endl<< endl;
		}
		
	//n++;
	}
	}
	for (int n = 0; n < 4; n++)
	{
		scoreAverage[n] = scoreSum[n] / scoreCount[n];
		totalScoreSum += scoreSum[n];
		totalScoreCount += scoreCount[n]; 
		//cout << "totalScoreSum " << totalScoreSum << endl;
		//cout << "totalScoreCount " << totalScoreCount << endl;
		//cout << "totalScoreSum " << totalScoreSum << endl;
	}
	

	totalScoreAverage = totalScoreSum / totalScoreCount;

	cout << fixed << showpoint << setprecision(2);
	cout << "The average score for subjects under 18 who have not seen the ad is " << scoreAverage[0] << endl; 
	cout << "The average score for subjects under 18 who have seen the ad is " << scoreAverage[1] << endl; 
	cout << "The average score for subjects 18 and over who have not seen the ad is " << scoreAverage[2] << endl; 
	cout << "The average score for subjects 18 and over who have seen the ad is " << scoreAverage[3] << endl; 

	cout << "The average score for all subjects is " << totalScoreAverage << endl; 

	return 0;
} 