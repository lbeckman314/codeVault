//-------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program determines both the longest word and frequencies of different english words.
// AUTHOR ---------- liam beckman
// DATE ------------ 27 october 2016 thursday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 5 english words (due october 27th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//--------------------------------------------------------------------------------------------------------------

#include <iostream>		//cin, cout
#include <fstream>		//ifstream, .eof(), .open()
#include <string>		//string, .length()
using namespace std;


int main()
{
//----------------------------------------------------------------------------------------------------//


		//FUNCTION PROTOTYPES
int vowelFunc(string word);
int consonantFunc(string word);


//----------------------------------------------------------------------------------------------------//
		

			//DECLARE VARIABLES
	string word;					//string for getline() function
	char letter;
	int numberOfWords;
	ifstream wordFile;				//input stream variable to input word file
	char mode;
	char viewFile;
	double percentConsonants;
	double percentVowels;
	int fileVowels;
	int fileConsonants;
	//int vowels;
	//int consonants;


//----------------------------------------------------------------------------------------------------//


			//PROMPT USER
	cout << "~/---------------------------------------------------------------/~" << endl;
	cout << "~////~~~///   P H O N E T I C -- O -- T R O N   3000    ///~~~////~" << endl;
	cout << "~/---------------------------------------------------------------/~" << endl;
	cout << "\n";
	cout << "Prepared to be SHOCKED and AMAZED as I tell you how many VOWELS and CONSONANTS" << endl;
	cout << "                  lie in the HEART of your WORD!" << endl;
	cout << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n";

	cout << "Would you like to enter a word? (e)" << endl;								//prompt the user if they want to enter a word...
	cout << "Or would you like me to read from a file of english words? (f)" << endl;	//...or read the file of english words (>100,000 words)
	cout << "USER INPUT: ";
	
	cin >> mode;


//----------------------------------------------------------------------------------------------------//


			//IF THE USER ENTERS A WORD
	if (mode == 'e')
	{
		cout << "Please enter your word (lower case please): ";
		cin >> word;

		cout << "\n";
		cout << "Number of vowels: " << vowelFunc(word) << endl;						//call our vowel function and append the results to the total number of vowels
		cout << "Number of consonants: " << consonantFunc(word) << endl;				//call our consonant function and append the results to the total number of consonant

			
		numberOfWords++;																//increase the total number of words by 1
		percentVowels = static_cast<double>(vowelFunc(word)) / word.length();			//calculate the vowel frequencies
		percentConsonants = static_cast<double>(consonantFunc(word)) / word.length();	//calculate the consonant frequencies
		cout << "Percentage of vowels in this word: " << percentVowels << endl;			
		cout << "Percentage of consonants in this word: " << percentConsonants << endl;	
	}


//----------------------------------------------------------------------------------------------------//


			//IF THE USER CHOOSES TO READ FROM THE ENGLISH WORD FILE
	else if (mode == 'f')
	{
		wordFile.open("/home/liam/Documents/compSci1/compSci1/week5/EnglishWords.txt");	//	
		
		if (!wordFile)	//if file is unable to be found
		{
			cout << "I am unable to find the file. I did find a rad quote though!" << endl;
			cout << "\"Infinite profundity is the gate whence comes the beginning of all parts of the Universe. ~ Laozi\"" << endl;
			return 1;
		}

		while (!wordFile.eof())						//while NOT the end of file...
		{
			getline(wordFile, word);				//insert the word into the input stream
			fileVowels += vowelFunc(word);			//call our vowel function and append the results to the total number of vowels
			fileConsonants += consonantFunc(word); 	//call our consonants function and append the results to the total number of consonants


					
			numberOfWords++;						//increase the total number of words by 1
			percentVowels = static_cast<double>(fileVowels) / (fileVowels + fileConsonants);			//calculate the vowel frequencies
			percentConsonants = static_cast<double>(fileConsonants) / (fileVowels + fileConsonants);	//calculate the consonant frequencies

		}
		
		wordFile.close();							//close our file

				//OUTPUT OUR ANALYSIS
		cout << "\n";
		cout << "Percentage of vowels in this file: " << percentVowels << endl;
		cout << "Percentage of consonants in this file: " << percentConsonants << endl;
		cout << "\n";
		cout << "Number of vowels: " << fileVowels << endl;
		cout << "Number of consonants: " << fileConsonants << endl;
		cout << "\n";
		
		cout << "Would you like to view the (VERY MANY) words in this file? (v)" << endl;
		cout << "Or would you like to exit the program? (x)" << endl;
		cout << "USER INPUT: ";
		cin >> viewFile;

		if (viewFile == 'v')
		{	
			wordFile.open("/home/liam/Documents/compSci1/compSci1/week5/EnglishWords.txt");		//reopen file
			while (!wordFile.eof())			//while NOT the end of file...
			{
				getline(wordFile, word);	//...read each word from the file...
				cout << word << endl;		//...and output the word
			}
		}
		wordFile.close();					//finally close the file
		cout << "\n";
		cout << "If you would like to create your own program with these words, they may be found at:" << endl;
		cout << "https://raw.githubusercontent.com/lbeckman314/cs161/master/week5/EnglishWords.txt" << endl;
	}


	return 0;	//return successful exit status
}

//----------------------------------------------------------------------------------------------------//


		//RUN OUR CACLULATIONS FOR VOWELS
int vowelFunc(string word)						//our vowel counting function
{
	int vowels = 0;								//intialize number of vowels to zero
	for (int n = 0; n < word.length(); n++)		//for each letter in the word...
	{		
		char letter = word[n];					//...letter equals the letter at position n in word
		switch(letter)							//
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vowels++;					//if letter = a, e, i, o, OR u, increase the number of vowels by one
		}
	}
	return vowels;								//return total number of vowels
}


//----------------------------------------------------------------------------------------------------//


		//RUN OUR CACLULATIONS FOR CONSONATS
int consonantFunc(string word)					//our lean, mean, consonant counting MACHINE!
{	
	int consonants = 0;							//intialize number of consonants to zero
	for (int i = 0; i < word.length(); i++)		//for each letter in the word...
	{			
		char letter = word[i];					//...letter equals the letter at position n in word
		switch(letter)							//
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': break; 					//if letter = a, e, i, o, OR u, BREAK
			default : consonants++;				//otherwise increase the number of consonants by one
		}
	}
	return consonants;							//return total number of consonants
}


