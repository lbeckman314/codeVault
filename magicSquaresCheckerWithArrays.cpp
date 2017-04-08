//-----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This programs determines whether a user's 4x4 matrix is a magic square, arrays included!
// AUTHOR ---------- liam beckman
// DATE ------------ 17 november 2016 thursday
// SOURCES --------- http://stackoverflow.com/questions/2037736/finding-size-of-int-array
//		   --------- https://en.wikipedia.org/wiki/Magic_square
// ASSIGNMENT ------ cs161 lab 8 magic sqaures (due 17 november 2016 thursday)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int row1[4];		// <-this will be the first row of our square to test
int row2[4];		// <-second row of our square 
int row3[4];		// <-fourth row of our square
int row4[4];		// <-fourth row of our square 

int main()
{	
	int sumHor[4];	// <-four sums for each of the four rows 
	int sumVer[4];	// <-four sums for each of the four columns
	int sumDia[2];	// <-two sums for each of the two diagonals

	cout << "Welcome to liam's Magic Square Checker! Please enter your magic square (4x4):" << endl;

	cout << '\n';
	cin >> row1[0] 	>> row1[1] 	>> row1[2] >> row1[3];			//user populates the square with their values.
	cin >> row2[0] 	>> row2[1] 	>> row2[2] >> row2[3];
	cin >> row3[0]	>> row3[1] 	>> row3[2] >> row3[3];
	cin >> row4[0] 	>> row4[1] 	>> row4[2] >> row4[3];

	sumHor[0] = row1[0] + row1[1] + row1[2] + row1[3];			//calculation of horizontal sums (e.g. the row sums)
	sumHor[1] = row2[0] + row2[1] + row2[2] + row2[3];
	sumHor[2] = row3[0] + row3[1] + row3[2] + row3[3];
	sumHor[3] = row4[0] + row4[1] + row4[2] + row4[3];

	sumDia[0] = row1[0] + row2[1] + row3[2] + row4[3];			//calculation of diagonal sums
	sumDia[1] = row1[3] + row2[2] + row3[1] + row4[0];

	for (int n = 0; n < 4; n++)
		sumVer[n] += row1[n] + row2[n] + row3[n] + row4[n];		//calculation of vertical sums (e.g. the column sums)



	cout << '\n';
	if (sumHor[0]==sumHor[1] && sumHor[1]==sumHor[2] && sumHor[2]==sumHor[3] && sumHor[3]==sumVer[0] && 
		sumVer[0]==sumVer[1] && sumVer[1]==sumVer[2] && sumVer[2]==sumVer[3] && sumVer[3]==sumDia[0] && 
		sumDia[0]==sumDia[1])								//TEST FOR MAGICICITY OF SQUARE
		cout << "'Yer a wizard Harry! This is a MAGIC square." << endl;		//if a sqaure is magic
	else
		cout << "'Yer a muggle Dudley! This is NOT a magic square." << endl;	//if a sqaure is not magic



	//FOR DIAGNOSIS OF BUGS AND WEIRD MALADIES
	cout << '\n';
	for (int n = 0; n < 2; n++)
		cout << "sumDia[" << n << "]: " << sumDia[n] << endl;
	//cout << "sumDia[0]: " << sumDia[0] << endl;
	//cout << "sumDia[1]: " << sumDia[1] << endl;
	
	cout << '\n';
	for (int n = 0; n < 4; n++)
		cout << "sumHor[" << n << "]: " << sumHor[n] << endl; 
	//cout << "sumHor[0]: " << sumHor[0] << endl;
	//cout << "sumHor[1]: " << sumHor[1] << endl;
	//cout << "sumHor[2]: " << sumHor[2] << endl;
	//cout << "sumHor[3]: " << sumHor[3] << endl;

	cout << '\n';
	for (int n = 0; n < 4; n++)
		cout << "sumVer[" << n << "]: " << sumVer[n] << endl;
	//cout << "sumVer[0]: " << sumVer[0] << endl;
	//cout << "sumVer[1]: " << sumVer[1] << endl;
	//cout << "sumVer[2]: " << sumVer[2] << endl;
	//cout << "sumVer[3]: " << sumVer[3] << endl;
	

	return 0;
}

/*
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  ~ ~ ~ ~ ~ ~ ~ Poetry of the Day! ~ ~ ~ ~ ~ ~ ~ 
  		   D O U B L E   F E A T U R E
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Today's Poems:
"The Squares" & "Magic"
both written by the comedian Bo Burnham
for his book of poetry, "Egghead"

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

The Squares

The Squares lived happily,
in their square houses,
in their square yards,
in their square town.

One day, a family of Circles
moved in from the west.

“Get out of here, roundies!” shouted one of the Squares.
“Why?” asked one of the Circles.
“Because this is a metaphor for racism!”

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Magic

Read this to yourself. Read it silently.
Don't move your lips. Don't make a sound.
Listen to yourself. Listen without hearing anything.
What a wonderfully weird thing, huh?

NOW MAKE THIS PART LOUD!
SCREAM IT IN YOUR MIND!
DROWN EVERYTHING OUT.
Now, hear a whisper. A tiny whisper.

Now, read this next line in your best crotchety-
old man voice:
"Hello there, sonny. Does your town have a post office?"
Awesome! Who was that? Whose voice was that?
It sure wasn't yours!

How do you do that?
How?!
It must've been magic.

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

*/