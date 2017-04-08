//Liam's Off the Cuff Good Enuff Crystal Ball
//PURPOSE ------ This programs takes user input and outputs a projected horoscope.

/*
*NAME: liam beckman
*ASSIGNMENT: 1 horoscope
*DATE: mon 26 september 2016
*SOURCES: none
*/

#include <iostream>
#include <string>

using namespace std;
int main()
{
	string name;    //declare string variables
	string subject;

	cout << "Welcome to Liam's Crystal Ball!" << endl;
	
	cout << "What is your name, please? ";
	
	cin  >> name;		//user inputs name                           
	
	cout << "Hello " << name << ". My name is Liam." << endl;
	
	cout << "What subject are you studying? ";
	
	cin  >> subject;
	
	cout << "Well " << name << ", Liam's crystal ball says " 
         << "you will do very well in " << subject 
         << " this term. ";
	
	cout << "Good luck!" << endl;

	return 0;	//return exit status
}
