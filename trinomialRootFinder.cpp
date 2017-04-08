//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program returns the roots of a trinomial.
// AUTHOR ---------- liam beckman
// DATE ------------ 12 october 2016 wednesday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 3 program 4/4
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include  <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	double a, b, c;			//declaring the values of the trinomial

	cout << "Enter your three numbers (separated by spaces): ";
	cin >> a >> b >> c;		//intializing the values of the trinomial

	cout << "Your trinomial is: ";
	cout << a << "x^2" << " + " << b << "x" << " + " << c << endl;

	float disc = b*b - 4*a*c;				//calculating the discriminant
	cout << "Your dicriminant is: " << disc << endl;

	float quad1 = (-b + sqrt(b*b - 4*a*c))/(2*a);	//finding the first root
	float quad2 = (-b - sqrt(b*b - 4*a*c))/(2*a);	//finding the second root


	if (disc > 0)		//if the discrimant is positive, we'll have two roots (quad1 and quad 2)
	{
		cout << "The first root of this trinomial is: " << quad1 << endl;
		cout << "And the second root is: " << quad2 << endl;
	}
	else if (disc == 0)	//if the discriminat is 0, we'll have one root (quad1)
	{
		cout << "The only root of this trinomial is: " << quad1 << endl;
	}
	else				//if the discriminat is negative, we'll have zero roots
	{
		cout << "There are no roots for this trinomial." << endl;
	}


	return 0;
}
