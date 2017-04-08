//--------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program times the sorting of a randomly populated set of arrays vis selection sorting.
// AUTHOR ---------- liam beckman
// DATE ------------ 08 december 2016 thursday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 2 program 1 (due 08 december 2016 thursday)
// COMPILED WITH --- gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 in Sublime Text 3 Build 3126       
//---------------------------------------------------------------------------------------------------------------

#include <iostream> //cout, cin
#include <ctime>   // clock_t, clock(), CLOCKS_PER_SEC
#include <iomanip> //setw(), left
#include <cstdlib>  //srand(), rand()

using namespace std;                        
const int maxArray = 1e5;                //there will be at most 100,000 elements in our arrays
const int maxRandom = 1e8;               //each element will be between 0 and 100,000,000

void init(int arr[10][maxArray]);           //our function to populate the arrays with random numbers between 0 and 100,000,000
void selectionSort(int arr[], int size);    //our function to sort the arrays via selection sorting


int main()
{
	static int arr[10][maxArray];                  //declare the 10 arrays that will hold our elements 
	init(arr);                                     //call init() function
	for (int i = 0; i<10 ; i++)                   //for each of the 10 arrays...
        selectionSort(arr[i], (maxArray/10)*i);    //sort the arrays through the selectionSort() function
    return 0;
}


void init(int arr[10][maxArray])                //our function to populate the arrays
{
    srand(time(NULL));                          //seed the random numbers

    for (int i = 0; i<10 ; i++)                 //for each of the 10 arrays...
    {
        for (int n = 0; n < maxArray; n++)      //for each of the elements in the array...
            arr[i][n] = rand() % maxRandom;     //assign the element a random value        
    }   
}


void selectionSort(int arr[], int size)      //
{
  	clock_t timeOne,timeTwo;	//beginning of the stopwatch to test how fast the program runs
   	timeOne = clock();
	int smallestIndex, temp;
	for(int index = 0; index < size-1; index++)         //for every element in the array...
	{
        smallestIndex = index;                          //assign the first element in that array as smallest  
        for (int location = index + 1; location < size; location++)    //for every element in the unsorted section of the array...
        {    
            if(arr[location]<arr[smallestIndex])        //if an element is smaller than the smallest element
                smallestIndex = location;               //that element is then assigned as the smallest
                

            temp = arr[smallestIndex];                  //temporary value assigned the value of the smallest array 
            arr[smallestIndex] = arr[index];            //smallest index is then assigned the value of element
            arr[index] = temp;                          //and finally that element is then assigned the value of the smallest array
        }
	}
    
    
    timeTwo = clock();			                                 //end of the stopwatch
    double difference ((double)timeTwo-(double)timeOne);         //get difference between timeOne and timeTwo
  	double milliseconds = difference / CLOCKS_PER_SEC * 1000;    //output the number of milliseconds elapsed
    cout << left << setw(9) << size << fixed << setprecision(0) 
         << setw(4) << milliseconds << endl;                     //output the length of the array and the number of milliseconds required to sort


    //for (int location = 0; location < size; location++)       //OPTIONAL output of array elements, to verify that selection is taking place
        //cout << "size: " << size << ", arr[location]" << arr[location] << endl;
}



/*
    gettimeofday()



Lab 10


This week you will do only the one following problem: implement selection sort and test how long it takes to sort lists of various sizes. Your main function should declare a two dimensional array,

static int arr[10][100000];

where the 'static' keyword is necessary to allocate the array where there is enough memory to hold it. You will then implement two functions that modify this array.


First, you will make an initializing function to put random numbers into the array as such:

void init(int arr[10][100000]);


Secondly, you will sort parts of the array and calculate how long it takes. Write a function that implements selection sort. Your function will be a little different than the book in that you will have an additional argument that limits how much of the array gets sorted. The prototype will look like this:

void selectionSort(int arr[], int size);


In main, you will call selectionSort in the context of a for loop. This for loop will sort lists of sizes that are factors of 10000 - it will loop 10 times, sorting a list of 10000, then 20000, then 30000, etc. up to 100000. You can use your two dimensional array that you declared above as the source lists for selectionSort. As you sort in your for loop, you should print how long each sort took, eventually printing 10 different times, one for each multiple of 10000. Bearing in mind that a two dimensional array is actually an array of arrays, the call to selectionSort should look like this:

selectionSort(arr[i], 10000*i);


Please print the time in milliseconds; on Windows, you can use the clock() command, on Mac/Linux, the gettimeofday() command. Please google these if you are not familiar with them. I get the following output from my program:

10000	156
20000	561
30000	1248
40000	2418
50000	3572
60000	5039
70000	6864
80000	9143
90000	11607
100000	14310

and yours should look somewhat similar. Finally, consider a rhetorical question... do these times follow an N^2 relationship as we suggested that they should in class? How could we determine this? If some of these times deviate from a perfect parabolic graph, why might that be?

*/