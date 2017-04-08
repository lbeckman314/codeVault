//-------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program determines both the longest word and frequencies of different english words
// AUTHOR ---------- liam beckman
// DATE ------------ 27 october 2016 thursday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 5 english words (due october 27th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//--------------------------------------------------------------------------------------------------------------


/*
Lab 5

CS 161

For this lab, you will use a list of English words to find out interesting things about our language.
Please hard code the path of the file into your program and do not ask the user to input it - 
if you put it in the C drive, it would make my life easier. Mac/Linux people, don't worry about that.
Also, if you could put all of your responses into one file (clearly commented!), that would be easier
for both of us. This week, please do all three questions!

1. Find the largest word on the list, print it, and print it's length (the str.length() function will help here!).

2. Find all of the words with one letter and print them.

3. Find the number of words of every possible length and print how many there are in a table.
   The table should start off looking like this:

	Length	Number of Words
	1	2
	2	140
	.	.
	.	.
	.	.

   What is the commonest length of English word?
*/

#include <iostream>		//cin, cout
#include <fstream>		//ifstream, .eof(), .open()
#include <string>		//string, .length()
#include <iomanip>		//setw(), left, right
using namespace std;


int main()
{

//-------------------DECLARE VARIABLES AND READ FILE-------------------------------------------------------//

	string word;					//string for getline() function
	double numberOfWords = 0;		//total number of words, used to calculate relative frequency of word lengths
	int length = 0;					//the number of letters in our longest word
	string longestWord;				//this string will be assigned the longest word in our word file
	string oneLetterWords[100];	//our one letter STRING array
	int oneLetterTotal = 0;			//total number of one letter words
	int xLetterWords[29];			//our INTEGER array used to store the number of x-length words (where 1 <= x <= 28)
	int commonest = 0;				//the most common length of word
	int commonLength = 0;			//the number of words that have the most common length
	double lengthFreq[30];			//DOUBLE array to hold the relative frequencies of all word lengths


	ifstream wordFile;				//input stream variable to input word file
	wordFile.open("/home/liam/Documents/pcc2016FallCopy/compSci1/week5/EnglishWords.txt");		
	if (!wordFile)
	{
		cout << "I am unable to find the file. I did find a rad quote though!" << endl;
		cout << "\"Infinite profundity is the gate whence comes the beginning of all parts of the Universe. ~ Laozi\"" << endl;
		return 1;
	}

//-----------------RUN OUR CACLULATIONS------------------------------------------------------//


	while (!wordFile.eof())		
	{
		getline(wordFile, word);

		if(word.length() > length)					//if the length of a  given word is more than the length of the longest word so far...
		{
			length = word.length();					//...the length of the longest word is updated to include that of the new word...
			longestWord = word;						//...and the new word becomes our new longest word
		}
		
		if(word.length()-1 == 1)					//if the word is one letter long
		{
			oneLetterWords[oneLetterTotal] = word;	//adding one letter word to the oneLetterWord STRING array
			oneLetterTotal++;						//total number of one letter words
		}
		
		for (int i=0; i <= 28; i++)					//looping through all lengths of words
		{
			if (word.length()-1 == i) 				//if the length of the word matches i...
				xLetterWords[i] += 1;				//...add 1 to the i-element in xLetterWords
			
			if (xLetterWords[i] > commonLength)		//if the number of x-letter words is more than the length of the most common word...
			{
				commonest = i;						//...assign the length i as the commonest word length... 
				commonLength = xLetterWords[i];		//...and assign the number of x-letter words to the length of the most common word 
			}
		}
		
		numberOfWords++;							//increase the total number of words by 1
	}

	
//----------OUTPUT LONGEST WORD----------------------------------------------------------------//


	cout << "longest word: " << longestWord << endl;	//output our longest word
	cout << "length of longest word: " 
		 << longestWord.length() - 1 << endl;			//output the length of our longest word

	cout << "\n\n";


//----------OUTPUT ONE LETTER WORDS------------------------------------------------------------//


	for(int n; n < oneLetterTotal; n ++)							//while n is less than the total number of one letter words...
		cout << "one letter words: " << oneLetterWords[n] << endl;	//...out put the one letter words

	cout << "\n\n";
	

//----------OUTPUT NUMBER OF WORDS OF EACH LENGTH----------------------------------------------//


	cout << setw(9) << left << "length" << setw(15) 
		 << "number of words" << endl;												//output header for WORD LENGTH and NUMBER OF WORDS 
	
	for(int k = 1; k < longestWord.length(); k++)									//while k is less than the length of our longest word...
	{
		lengthFreq[k] = 100 * xLetterWords[k] / numberOfWords;						//...populate the frequency array...
		cout << setw(3) << left << k << right << setw(7)
			 << xLetterWords[k] << endl;											//...and output the WORD LENTH and NUMBER OF WORDS...
	}

	cout << "\n\n";

	cout << "The commonest word length is " << commonest << " letters." << endl;	//output the most common word length
	cout << "(frequency = " << lengthFreq[commonest] 
		 << " %, representing " << xLetterWords[commonest] 							//output common length analysis
		 << " words out of a total of " << numberOfWords << " words)" << endl; 

	return 0;	//return successful exit status
}