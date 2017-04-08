//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program allows one to search their library for a given author or title string.
// AUTHOR ---------- liam beckman
// DATE ------------ 01 december 2016 thursday
// SOURCES --------- http://www.cplusplus.com/reference/string/string/find/
//         --------- http://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
// ASSIGNMENT ------ cs161 lab 2 program 1 (due 02 december 2016 thursday)
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

    // Function prototypes
int loadData(string pathname);      //gets the filename and loads the data into bookTitle[] and bookAuthor[] arrays
void showAll(int count);            //outputs all data from bookTitle[] and bookAuthor[] arrays
int showBooksByAuthor (int count, string name);     //outputs data that matches search substring in bookAuthor[]
int showBooksByTitle (int count, string title);     //outputs data that matches search substring in bookTitle[]


//----------------------------------------------------------------------------------------------//


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


//----------------------------------------------------------------------------------------------//


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


//----------------------------------------------------------------------------------------------//


void showAll(int count)     //function to output ALL of the library's titles and authors
{
    cout << "\n";
    for (int i = 0; i < count; i++)                    //for every book in the library...
    {  
        cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;           //output TITLE (AUTHOR)
    }
    cout << "\n";
}


//----------------------------------------------------------------------------------------------//


int showBooksByAuthor (int count, string name)          //function to search library for given AUTHOR and output results
{
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


//----------------------------------------------------------------------------------------------//


int showBooksByTitle (int count, string title)          //function to search library for given TITLE and output results
{
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



//----------------------------------------------------------------------------------------------//



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
~ ~ ~ ~ ~ ~ ~ ~ Poem of the Day! ~ ~ ~ ~ ~ ~ ~ ~ ~
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
Today's Poem:
"Library Card" from "Arthur's Almost Live Not Real Music Festival". 

https://www.youtube.com/watch?v=lyxEDSnegTU 
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Part I

Everyone: Having fun isn't hard,
When you've got a library card.
Having fun isn't hard,
When you've got a library card.

Ms. Turner: Come on inside,
We've got everything you need.
There's plenty to do,
Or you can just sit and read.

Muffy: This book explains
How to make paper planes.
Arthur: This contour map
Can show you mountain range terrains.

Brain: Fly to the moon,
Explore the ocean floor.
Buster: Find out which one's the tiller,
And which one is the oar.

Fern: Here's "Charlie and the Chocolate Factory"
And "Half Magic".
Timmy: "Hop on Pop".
Tommy: And "Fox in Socks".
George: And books on doing card tricks! Everyone: Ooooooh!

Having fun isn't hard,
When you've got a library card.
Ms. Turner: That's right!
Everyone: Having fun isn't hard,
When you've got a library card.

Francine: Books on baseball,
Hockey and soccer
Mr. Ratburn: And even how to build yourself
A cool doorknocker.

Arthur: I could stay in this place
For hours and hours.
Binky: I like books with pictures
Of lotsa pretty flowers...
Being crushed by a giant pterodactyl.

Arthur: Jules Verne, HG Wells,
And Ray Bradbury:
Francine: You can take 'em home
So you don't have to
Read 'em in a hurry.

Everyone: Having fun isn't hard,
When you've got a library card.
Having fun isn't hard,
When you've got a library card. Having fun!


Part II

Everyone: Having fun isn't hard,
When you've got a library card.
Having fun isn't hard,
When you've got a library card.

Prunella: Paintings by Leonardo,
Rembrandt and Picasso.
Mr. Haney: Confidentially, I'm reading...
Everyone: ..."Go, Dog, Go"!

Buster: There's "The Giving Tree" and "Jumanji"
And "Where the Wild Things Are."
D.W.: And a book on why you shouldn't
Keep your brother in a jar.
Arthur: Let me out!

All the thoughts and dreams of people
Throughout history
And all you need's this little card
To borrow 'em for free!
Everyone: Yeah!

Having fun isn't hard,
When you've got a library card.
Having fun isn't hard,
When you've got a library card.

D.W.: There's story time
And lessons on how to use computers,
But there can't be any classes
On how to make me cuter.

Francine: Puppet shows and movies,
The cool things never end.
Ms. Turner: And don't forget,
The Dewey Decimal System is your friend.
D.W.: Who's Dewey?

Everyone: And don't forget,
The Dewey Decimal System is your friend.
D.W.: Who's Dewey?

Everyone: 1! 2! 3!

Having fun isn't hard,
When you've got a library card.
D.W.: Who's Dewey?

Everyone: Having fun isn't hard,
When you've got a library card.
Having fun isn't hard,
When you've got a library card.

D.W.: Who's Dewey?
Everyone: Having fun isn't hard,
When you've got a library card.
Having fun!

D.W.: Who is Dewey?!? 

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

