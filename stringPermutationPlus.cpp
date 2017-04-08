//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This programs outputs the permutations of three user-inputted strings.
// AUTHOR ---------- liam beckman
// DATE ------------ 01 october 2016 saturday
// SOURCES --------- http://stackoverflow.com/questions/2037736/finding-size-of-int-array
// ASSIGNMENT ------ cs161 lab 2 program 4 (due october 6th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string string1, string2, string3;		//declaring our strings (i.e. abc def ghi)

	cout << "enter your strings: ";			//prompts user to input their strings
	cin >> string1 >> string2 >> string3;	//strings are inputed

	cout << string1 << " " << string2 << " " << string3 << endl;	//1st permutation: abc def ghi
	cout << string1 << " " << string3 << " " << string2 << endl;	//2nd permutation: abc ghi def
	cout << string2 << " " << string1 << " " << string3 << endl;	//3rd permutation: def abc ghi
	cout << string2 << " " << string3 << " " << string1 << endl;	//4th permutation: def ghi abc
	cout << string3 << " " << string1 << " " << string2 << endl;	//5th permutation: ghi abc def
	cout << string3 << " " << string2 << " " << string1 << endl;	//6th permutation: ghi def abc


	return 0;
}


