//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program attempts to summon the spirit of fibonnaci.
// AUTHOR ---------- liam beckman
// DATE ------------ 20 october 2016 thursday
// SOURCES --------- http://rabbit.eng.miami.edu/class/een218/getchar.html
//		   --------- http://www.cplusplus.com/reference/cstdio/getchar/
// ASSIGNMENT ------ cs161 lab 4 program 2/2 
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------



#include <iostream>		//
#include <stdio.h>		//getchar()
#include <iomanip>		//setw(), setfill() 
using namespace std;	//


int main()	
{
	int i = 1;	//our first of three placeholder integers that will be used to hold and output the elements of the fibonacci sequence.
	int n = 0;	//our second of three placeholder integers
	int o = 0;	//our final placeholder integer
	//int x = 1;

	cout << "press enter to pay respects to fibanocci" << endl;	//prompt for user to press "enter" to begin output
		cout << "--------" << 1;								//prints our first element in fibonacci sequence
		while (i < 10e4)										//up to 28th element in fibonacci sequence
		{
			getchar();											//pause the output until the user strikes the "enter" key. 
			n = i + o;											//our placeholder integers in action! First iteration: n = 1 + 0
				cout << setw(9) << setfill('-') << n;			//prints our element 
			
			getchar();										
			o = n + i;											//First iteration: o = 1 + 1
				cout << setw(9) << setfill('-') << o;			
			
			getchar();										
			i = o + n;	 										// Fisrt iteration: i = 2 + 1
				cout << setw(9) << setfill('-') << i;			
		}	
}
