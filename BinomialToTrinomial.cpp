//--------------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program takes two user-inputed binomials and returns the product in the form of a trinomial.
// AUTHOR ---------- liam beckman
// DATE ------------ 12 october 2016 wednesday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 3 program 3/4
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//---------------------------------------------------------------------------------------------------------------------


#include  <iostream>
#include <string>
using namespace std;

int main()
{
	double a1, a2, a3;	//declaring the "a" values for both binomials and the trinomial.
	double b1, b2, b3;	//declaring the "b" values for both binomials and the trinomial.
	double c;			//declaring the "c" value for the trinomial.
	char mid;			//This is the "+" or "-" in the user input (i.e. "+" in 2x+5, or "-" in 2x-5) 

	cout << "Enter thy first binomial: ";
		cin >> a1 >> mid >> b1;//, b1;		//user input of their first binomial

	cout << "Enter thy second binomial: ";
		cin >> a2 >> mid >> b2;				//user input of their second binomial

	a3 = a1*a2;			//calculate the "a" value of the trinomial
	b3 = a1*b2 + a2*b1;	//calculate the "b" value of the trinomial
	c = b1*b2;			//calculate the "c" value of the trinomial

	
	//This section is just some formatting for the output of the trinomial...
	//...so that negative values (such as -2) are printed as "-2" instead of "+ -2"
	if (b2>0 && c>0)	
		cout << a3 << "x^2" << " + " << b3 << "x" << " + " << c << endl;

	else if(b2>0 && c<0)
		cout << a3 << "x^2" << " + " << b3 << "x" << " - " << -1 * c << endl;

	else if (b2<0 && c>0)
		cout << a3 << "x^2" << " - " << -1 * b3 << "x" <<" + " << c << endl;

	else if (b2<0 && c<0)
		cout << a3 << "x^2" << " - " << -1 * b3 << "x" <<" - " << -1 * c << endl;

	return 0;
}
