//Program 4:

//A permutation of three objects, a, b, and c, is any arrangement of these objects in a row. For example, some of the permutations of these objects are abc, bca, and cab. There are six total permutations of three objects. Suppose that these objects are strings. Write a program that prompts the user to enter three strings. The program then outputs all six permutations of these strings. Please output one permutation per line and print spaces between the objects (strings) on each line.


	
//PURPOSE ------ This programs outputs the permutations of three user-inputted strings.
/*
*NAME: liam beckman
*ASSIGNMENT: 2 magic square
*DATE: mon 26 september 2016
*SOURCES: none 
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string string1, string2, string3;

	cout << "enter your strings: ";
	cin >> string1 >> string2 >> string3;

	cout << string1 << " " << string2 << " " << string3 << endl;
	cout << string1 << " " << string3 << " " << string2 << endl;
	cout << string2 << " " << string1 << " " << string3 << endl;
	cout << string2 << " " << string3 << " " << string1 << endl;
	cout << string3 << " " << string1 << " " << string2 << endl;
	cout << string3 << " " << string2 << " " << string1 << endl;

	return 0;
}
