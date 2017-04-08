//PURPOSE ------ This programs determines whethere a user's 4x4 matrix is a magic square!

//**************************************************************************************************************************
//NAME: liam beckman
//ASSIGNMENT: 2 magic square
//DATE: tues 27 september 2016
//SOURCES: http://stackoverflow.com/questions/8196796/how-can-i-check-whether-multiple-variables-are-equal-to-the-same-value 
//**************************************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;		// <-this will be the first row of our square to test
	int e, f, g, h;		// <-second row of our square 	
	int i, j, k, l;		// <-third row of our square 
	int m, n, o, p;		// <-fourth row of our square 

	int sumHor1, sumHor2, sumHor3, sumHor4; 	//SUM of HORIZONTAL rows
	int sumVer1, sumVer2, sumVer3, sumVer4; 	//SUM of VERTICAL columns
	int sumDia1, sumDia2;						//SUM of DIAGANOLS

	cout << "Welcome to liam's Magic Square Checker! Pleasd enter your magic square (4x4):" << endl;

	cin >> a >> b >> c >> d;	//user populates the square with their values.
	cin >> e >> f >> g >> h;
	cin >> i >> j >> k >> l;
	cin >> m >> n >> o >> p;

	sumHor1 = a+b+c+d; 			//calculate SUM of HORIZONTAL rows
	sumHor2 = e+f+g+h;
	sumHor3 = i+j+k+l;
	sumHor4 = m+n+o+p;
	
	sumVer1 = a+e+i+m;			//calculate SUM of VERTICAL columns
	sumVer2 = b+f+j+n;
	sumVer3 = c+g+k+o;
	sumVer4 = d+h+l+p;
	
	sumDia1 = a+f+k+p;			//calculate SUM of DIAGANOLS
	sumDia2 = d+g+j+m;


	if (sumHor1==sumHor2 && sumHor2==sumHor3 && sumHor3==sumHor4 && sumHor4==sumVer1 && sumVer1==sumVer2 && sumVer2==sumVer3 && sumVer3==sumVer4 && sumVer4==sumDia1 && sumDia1==sumDia2)		//TEST FOR MAGICICITY OF SQUARE
	{
		cout << "This was a magic square! Thank you!" << endl;	//SUCCESS
	}
	else
	{
		cout << "This was not a magic square! Thank you!" << endl;	
	}

	return 0;
}