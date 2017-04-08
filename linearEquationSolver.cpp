//-------------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program solves two linear equations of the form ax + by = c, returning values for x and y.
// AUTHOR ---------- liam beckman
// DATE ------------ 12 october 2016 wednesday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 assignment 3 simultaneous equation solver 
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//--------------------------------------------------------------------------------------------------------------------


#include <iostream>
using namespace std;

int main()
{
  int a1, b1, c1;         //declare values for first linear equation
  int a2, b2, c2;         //declare values for second linear equation

  cout << "Please enter a1, b1, c1 (separated by spaces): ";
  cin >> a1 >> b1 >> c1;   //user intializes values of first linear equation

  cout << "Please enter a2, b2, c2 (separated by spaces): ";
  cin >> a2 >> b2 >> c2;  //user intializes values of first linear equation

  cout << "The solution of the equations: " << endl;
  cout << a1 << "x" << " + " << b1 << "y" << " = " << c1 << endl;
  cout << a2 << "x" << " + " << b2 << "y" << " = " << c2 << endl;

  //we use Cramer's Rule to calculate the values of x and y:
  // x = ( c1 * b2 - c2 * b1 ) / ( a1 * b2 - a2 * b1 )
  // y = ( a1 * c2 - a2 * c1 ) / ( a1 * b2 - a2 * b1 )

    double xNumer = (c1*b2-c2*b1);  //calculate the x numerator in cramer's rule
    double xDenom = (a1*b2-a2*b1);  //calculate the x denominator in cramer's rule
    double x = xNumer/xDenom;       //finally calculate x

    double yNumer = (a1*c2-a2*c1);  //calculate the y numerator in cramer's rule
    double yDenom = (a1*b2-a2*b1);  //calculate the y denominator in cramer's rule
    double y = yNumer/yDenom;       //finally calculate y


    if (xDenom != 0 && yDenom != 0) //if lines are NOT parallel
    {
      cout << "is x = " << x << " and y = " << y << endl;
    }

    else if (xDenom == 0 && yDenom == 0 && xNumer != 0 && yNumer != 0)  //if the lines ARE parallel
    {
      cout << "Golly mister~~ Your lines are parallel!" << endl;
      cout << "There is no solution for these particular linear equations" << endl;
    }

    else if (xDenom == 0 && yDenom == 0 && xNumer == 0 && yNumer == 0) //if lines are the same
    {
      cout << "Golly mister~~ Your lines are the same!" << endl;
      cout << "There are infinte solutions for these particular linear equations" << endl;
    }
    cout << "Thank you for using liam's simultaneous equation solver." << endl;


  return 0;
}

