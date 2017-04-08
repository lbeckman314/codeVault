//Authors Note: EVERY TIME YOU SWAP AN TITLE BUT NOT THE AUTHOR, A PUPPY SHEDS A TEAR. 


//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program outputs sorted book names of a library
// AUTHOR ---------- liam beckman
// DATE ------------ 09 december 2016 friday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 assignment 10 (due 09 december 2016 friday)
// COMPILED WITH --- gcc (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904 in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>     //cin, cout
#include <string>       //string, npos, c_str()
#include <fstream>      //istream, open(), .eof()
using namespace std;

    // These declarations should be at file scope
const int ARRAY_SIZE = 1000;        //max size of library (in number of books)
string bookTitle  [ARRAY_SIZE];     //array to hold the title strings in the library
string bookAuthor [ARRAY_SIZE];     //array to hold the author strings in the library

// These declarations should be at file scope.
struct Book {
    string title;
    string author;
};

//const int ARRAY_SIZE = 1000;
Book books [ARRAY_SIZE];


    // Function prototypes
int loadData(string pathname);      //gets the filename and loads the data into bookTitle[] and bookAuthor[] arrays
void showAll(int count);            //outputs all data from bookTitle[] and bookAuthor[] arrays
int showBooksByAuthor (int count, string name);     //outputs data that matches search substring in bookAuthor[]
int showBooksByTitle (int count, string title);     //outputs data that matches search substring in bookTitle[]

void sortByTitle (int count);
void sortByAuthor (int count);


int main()
{
    loadData("library.txt");            //call loadData() with our library file
    char userInput;                     //user input for menu below
    string authorName;                  
    string bookTitle;                   
    
    bool endOfProgram = false;          //it is NOT yet the end of the program!
    while(endOfProgram == false)        //and while it is NOT the end of the program prompt user for their menu selection
    {                                                                           
        cout << "would you like to  SHOW all books/authors (s)" << endl;        //CALLS showAll()
        cout << "------------------ search by AUTHOR (a)" << endl;              //CALLS showBooksByAuthor()
        cout << "------------------ search by TITLE (t)" << endl;               //CALLS showBooksByTitle()
        cout << "------------------ or QUIT program (q)?" << endl;              //BREAKS the while loop
        cout << "\nUSER INPUT: ";
        cin >> userInput;               //input user's menu selection 
        
        switch(userInput)
        {
            case('s'):      //showAll()
            {   
                showAll(loadData("library.txt"));                   //load the library data from the txt file
                break;     
            }
            case('a'):      //showBooksByAuthor()
            {
                cout << "\nname of author (case sensitive!): ";     //prompt user for AUTHOR name
                cin >> authorName;                                  //input AUTHOR name    
                cout << showBooksByAuthor(loadData("library.txt"), authorName) 
                     << " records found.\n" << endl;                //search by AUTHOR name
                break;     
            }
            case('t'):      //showBooksByTitle()
            {
                cout << "\nname of title (case sensitive!): ";      //prompt user for TITLE of book
                cin >> bookTitle;                                   //input TITLE of book
                cout << "\n"; 
                cout << showBooksByTitle(loadData("library.txt"), bookTitle) 
                     << " records found.\n" << endl;                //search by book TITLE
                break;     
            }
            case('q'):      //if the user wishes to quit the program...
            {
                endOfProgram = true;                                //...then the program is ENDED!
                cout << "happy trails!" << endl;
                break;     
            }
        }

    }

    return 0;   //return successful exit status
}


int loadData(string pathname)       //function to load the library data from txt file
{
    int count = 0;                  //index for the while loop
    ifstream inFile;                //initialize the input file...
    inFile.open(pathname.c_str());  //...and open that file
    if (!inFile)                    //if there is no file at specified path...
        return -1;                  //...return unsuccessful exit status
    else
    {
        while(!inFile.eof())        //while NOT at the end of the input file
        {   
            getline(inFile, bookTitle[count]);      //appends the title to bookTitle[] array
            getline(inFile, bookAuthor[count]);     //appends the author to bookAuthor[] array
            count++;                                //increment the count variable
        }
    }
    return count;                   //return the count variable
} 


void showAll(int count)     //function to output ALL of the library's titles and authors
{
    sortByTitle(count);

    cout << "\n";
    for (int i = 0; i < count; i++)                    //for every book in the library...
    {  
        cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;           //output TITLE (AUTHOR)
    }
    cout << "\n";
}


int showBooksByAuthor (int count, string name)          //function to search library for given AUTHOR and output results
{
    sortByAuthor(count);
    
    int authorCount = 0;                                
    for (int i = 0; i < count; i++)                     //for every book in the library...
    {
        //if (name == bookAuthor[i])
        if (bookAuthor[i].find(name) != string::npos)   //if name is in bookAuthor[i] before the end of the string (npos)...
        {
            cout << bookTitle[i] << " (" 
                 << bookAuthor[i] << ")" << endl;       //...output TITLE (AUTHOR)...
            authorCount++;                              //...and increment number of authors
        }
    } 
    return authorCount;                                 //return the number of AUTHORS found
    
}


int showBooksByTitle (int count, string title)          //function to search library for given TITLE and output results
{
    sortByTitle(count);
    
    int titleCount = 0;                                 
    for (int i = 0; i < count; i++)                     //for every book in the library...
    {
        if (bookTitle[i].find(title) != string::npos)   //if title is in bookTitle[i] before the end of the string (npos)...
        {
            cout << bookTitle[i] << " (" 
                 << bookAuthor[i] << ")" << endl;       //...output TITLE (AUTHOR)...
            titleCount++;                               //...and increment number of titles
        }
    }
    return titleCount;                                  //return the number of TITLES found
    
}


void sortByTitle (int count)    //function to sort the names of the titles alphabetically (via SLECTION SORT)
{
    int smallestIndex;
    string temp;
    for (int index = 0; index < count; index++)                     //for every book in the library...
    {
        for (int location = index+1; location < count; location++)  //and for every book in the unsorted list...
        {    
            if (bookTitle[location] < bookTitle[smallestIndex])     //if the book is higher in the alphabet than the highest book so far...
                smallestIndex = location;                           //then that book is now the highest book (in the alphabet)
        }                
        temp = bookTitle[smallestIndex];                            //swap the highest book so far and the the book in the unsorted list
        bookTitle[smallestIndex] = bookTitle[index];
        bookTitle[index] = temp;
    }
}


void sortByAuthor (int count)   //function to sort the names of the authors alphabetically (via SLECTION SORT)
{
    int smallestIndex;
    string temp;
    for (int index = 0; index < count; index++)                     //for every book in the library...
    {
        for (int location = index+1; location < count; location++)  //and for every book in the unsorted list...
        {
            if (bookAuthor[location] < bookAuthor[smallestIndex])   //if the book is higher in the alphabet than the highest book so far...
                smallestIndex = location;                           //then that book is now the highest book (in the alphabet)
        }
        temp = bookAuthor[smallestIndex];                           //swap the highest book so far and the the book in the unsorted list
        bookAuthor[smallestIndex] = bookAuthor[index];
        bookAuthor[index] = temp;
    }
}
