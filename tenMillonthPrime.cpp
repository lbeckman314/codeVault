//------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program outputs the first 10,000,000 primes...
// AUTHOR ---------- liam beckman
// DATE ------------ 17 november 2016 thursday
// SOURCES --------- http://www.cplusplus.com/forum/beginner/14666/
//	       --------- http://primes.utm.edu/lists/small/millions/
// ASSIGNMENT ------ cs161 lab 8 program 2/2 primes PLUS! (due 17th november 2016 thursday)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-------------------------------------------------------------------------------------------------------------


#include <iostream>		//cout	
#include <cmath>		//sqrt(), pow()
#include <iomanip>		//setw(), left
#include <time.h>       // clock_t, clock(), CLOCKS_PER_SEC

using namespace std;


void isPrime ();		//our isPrime() function for the output of the first ten million primes
void outputResults(int numberOfPrimes, int prime);	//function outputs the calculated results


int primeArray[100000001] = {2,3,5,7,11};	//our array to hold the prime numbers. Seeded with the first few primes
int nthPrimeNumber=4;	//declare and initialize our prime counter
int userNumOfPrimes;	//user selected number of primes to calculate


//----------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------//


int main()
{
	cout << "Welcome to fitz's" << endl;
	cout << "	HOT STUFF >> OFF THE CUFF >> GOOD ENUFF >> PRIME CALCULATOR " << endl;
	cout << "\n";
	
	cout << "Latest tests have clocked this program at the following speeds: " << endl;
	cout << "10,000,000 primes in  177.7940 seconds" << endl;
	cout << " 1,000,000 primes in    6.4728 seconds" << endl;
	cout << "   100,000 primes in 	0.3254 seconds" << endl;
	cout << "    10,000 primes in 	0.0162 seconds" << endl;
	cout << "     1,000 primes in 	0.0007 seconds" << endl;
	cout << "       100 primes in 	0.0001 seconds" << endl;
	cout << "        10 primes in 	5.8e-5 seconds" << endl;
	cout << "\n";
    
	cout << "How many primes are you interested in today? (i.e. 10000000)" << endl;
	cout << "User input: ";
	cin >> userNumOfPrimes;
	if (!cin)
		userNumOfPrimes = 10000000;					//default value
	
	cout << "You have selected " << userNumOfPrimes << " primes. Good choice!" << endl;
	cout << "\n";


	if (log10(userNumOfPrimes) > 6)					//if the user selected for 10,000,000 million primes...
	{
		cout << "While you wait, here is the latest xkcd: http://xkcd.com/" << endl;
		cout << "Perhaps you'd enjoy a personal favorite: http://sssscomic.com/" << endl;
		cout << "Have you heard about the latest events?: https://en.wikipedia.org/wiki/Portal:Current_events" << endl;
		cout << "\n";
	}


    clock_t timeOne,timeTwo;	//beginning of the stopwatch to test how fast the program runs
   	timeOne = clock();
	

	isPrime();					//call our isPrime function
    

    /*		//UNCOMMENT to only show output once all primes are calculated. You must also then COMMENT the outputResults() function in isPrime().
    cout << "\n";
	for (int a = 1; a <= log10(userNumOfPrimes); a++)
	{
		int index = pow(10,a);						//with the powers of 10 (i.e. 10, 100, 1000...1,000,000, 10,000,000)
		outputResults(index, primeArray[index]);	//call our outputResults function 
	}
    */	


    cout << "\n";
    timeTwo = clock();			//end of the stopwatch
    double difference ((double)timeTwo-(double)timeOne);	//get difference between timeOne and timeTwo
  	double seconds = difference / CLOCKS_PER_SEC;			//determine the number of seconds elapsed
    cout << seconds << " seconds elapsed." <<  endl;		//output the number of seconds elapsed

	
	return 0;					//return successful exit status
}


//----------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------//


void isPrime()			//our isPrime() function for the output of the first ten million primes
{
	for (int nPrime = 5; nthPrimeNumber < userNumOfPrimes; nPrime+=2)	//for the odd numbers between 5 and 10,000,000
	{
		for (int nTest = 1; primeArray[nTest] <= sqrt(nPrime); nTest++)	//for the (prime) test numbers between 2 and the square root of the prime number
		{	
			if (nPrime % primeArray[nTest] == 0)			//if the number % test number == 0...
				break;										//...the number is NOT prime
			if (sqrt(nPrime) < primeArray[nTest+1])			//if the next test would exceed the square root of the number...
			{												//...the number IS prime!
				nthPrimeNumber++;							//increase the number of primes
				primeArray[nthPrimeNumber] = nPrime;		//add our new prime number to the primeArray
				outputResults(nthPrimeNumber, nPrime);		//COMMENT to show output only AFTER all primes are calculated  
			}
		}
	}	
}


//----------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------//


void outputResults(int numberOfPrimes, int prime)		//function outputs the calculated results
{
	//cout << nthPrimeNumber << "     " << primeArray[nthPrimeNumber] << endl;	//uncomment for continuous output of primes
	switch(numberOfPrimes)								//Throw the lever Kronk!
	{
		case 10 : cout << left << setw(15) << "n:" << setw(10) << "nth Prime:" << endl;				//output the HEADER "n:		nth Prime:" 
				  cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;			//output the 10th prime number
		case 100 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;			//output the 100th prime number
		case 1000 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;			//output the 1,000th prime number
		case 10000 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;		//output the 10,000th prime number
		case 100000 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;		//output the 100,000th prime number
		case 1000000 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;		//output the 1,000,000th prime number
		case 10000000 : cout << setw(15) << numberOfPrimes << setw(10) << prime << endl; break;		//output the 10,000,000th prime number
	}
}


//----------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------//


/*
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  ~ ~ ~ ~ ~ ~ ~ Poetry of the Day! ~ ~ ~ ~ ~ ~ ~ 
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Today's Poem:
"Wherefore Art Thou Ten Million?" 

By yours truly, written in a state of coding daze.

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Ten million to one is so much fun,
	if you're looking for the primes
coding with style, waiting to compile
	in so very, very little time.

But what may happen, when everything fails,
and the program crashes abound?
First I lose all color, grow deathly pale
then weep, weep, weep, without a sound.

But what's this? I ask, hope rebounding
A figure on the screen -- 
	triumphant,
		 resounding!
Accurate and true, 'Tis the ten millionth number!
Off to bed, I seek my slumber.

*/