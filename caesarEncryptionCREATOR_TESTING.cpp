//------------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program decrypts a text file  based on the Caesar cipher.
// AUTHOR ---------- liam beckman
// DATE ------------ 18 november 2016 friday
// SOURCES --------- http://stackoverflow.com/questions/6171946/shifting-a-string-of-characters
// ASSIGNMENT ------ cs161 lab 8 assignment 8 encryption (due 18 november 2016 friday)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-------------------------------------------------------------------------------------------------------------

#include <iostream>     //cin .clear() .seekg() .get()
#include <fstream>      //ifstream .close() .eof()
using namespace std;


int arrayFiller(ifstream& textFile, string filePath);   //fills up array with letter counts
char commonLetterFinder(int letters[]);                 //finds most common letter in array
void stringOutput(ifstream& textFile, ofstream& outputTextFile);                  //shifts letter in first two functions to output correct test

char ch;                                    //our letters for both the encrypted text and decrypted text
int unencryptedAlphabet[26];                  //array to hold the letters of the encrypted text
int maxFreqChar = unencryptedAlphabet[0];     //the most frequent character in the encrypted text (assumed to be 'e')
char mostCommonChar = 'e' - 'a';            //we assume that the most common character is 'e'
int shift;                                  //the cipher shift we want to crack!
int lastLetterPos;                          //position of the letter that will cycle to the beginning of the alphabet


//-----------------------------------------------------------------------------------//


int main()
{

    ifstream unencryptedFile;                         //the encrypted text and the file path
    string unencryptedFilePath = "/home/liam/Documents/compSci1/compSci1/week8/encryptedINPUT.txt";
    ofstream outputFile;
    string outputFilePath = "/home/liam/Documents/compSci1/compSci1/week8/encryptedOUTPUT_test.txt";
    
    unencryptedFile.open(unencryptedFilePath.c_str());  //open encrypted text
    outputFile.open(outputFilePath.c_str());  //open encrypted text


    arrayFiller(unencryptedFile, unencryptedFilePath);  //call arrayFiller function with the encrypted text and file path
    commonLetterFinder(unencryptedAlphabet);          //call the commonLetterFinder function with the encrypted text
    
    unencryptedFile.clear();                          //clear the stream and...
    unencryptedFile.seekg(0);                         //...rewind to the beginning of the stream so stringOutput can output the letters

    stringOutput(unencryptedFile, outputFile);                    //call the stringOutput function with the encrypted text
      
    unencryptedFile.close();                          //close the encrypted text
    outputFile.close();
    return 0;                                       //return successful exit status
}


//-----------------------------------------------------------------------------------//   



    //fills up array with letter counts
int arrayFiller(ifstream& textFile, string filePath)
{
    while(!textFile.eof())      //while NOT at the end of the file
    {
        ch = textFile.get();    //assign ch the value of letters in the encrypted text
        ch = tolower(ch);       //use tolower(ch) to lowercase the letters

        if (isalpha(ch))        //if ch is a letter
            unencryptedAlphabet[ch - 'a']++;  //add 1 to the encryptedArray at position ch - 'a' ('a' = 97 in ascii)
    }
}


//-----------------------------------------------------------------------------------//


    //finds most common letter in array
char commonLetterFinder(int letters[])
{
    for (int freq = 0; freq < 26; freq++)           //for all the letters in the alphabet...
    {
        if (letters[maxFreqChar] < letters[freq])   //...if a letter has a lower frequency than the next letter... 
            maxFreqChar = freq;                     //...the next letter becomes the highest frequency letter
    }

    shift = maxFreqChar - mostCommonChar;           //cipher shift is equal to the highest frequency letter minus the most common letter
    lastLetterPos = 26 - shift;                     //last letter position is equal to the number of letters in the alphabet minus the shift
}

//-----------------------------------------------------------------------------------//
    

    //shifts letter in first two functions to output correct test
void stringOutput(ifstream& textFile, ofstream& outputTextFile)
{
    while(!textFile.eof())      //while NOT at the end of the file
    {      
        ch = textFile.get();    //assign ch the value of letters in the encrypted text
        
        if (islower(ch))        //if the letter is lower case...
            ch = (ch - 'a' + lastLetterPos) %26 + 'a';  //...ch = (convert letter to 0-26 range and shift it to the deciphered position) if letters are 26 or above, move them to the beginning of the alphabet, and finally convert letter back to ascii range
        
        else if (isupper(ch))   //else if the letter is upper-case...
            ch = (ch - 'A' + lastLetterPos) %26 + 'A';  //...same as above, except for upper-case letters
        
        cout << ch;             //and finally output the letter (e.g. the decrypted text!)
        outputTextFile << ch;
    }
    
cout << "\n\n";
cout << "------------------------------------------" << endl;
cout << "// The shift of this cipher is: " << shift << endl;            //outputs the cipher shift
cout << "// based on the most common character: " << static_cast<char>(mostCommonChar + 'a') << endl;  //outputs the most common letter
//cout << "$ the last letter position is: " << lastLetterPos << endl;   //uncomment to output the last letter position  
cout << "------------------------------------------" << endl;
    //cin.get();                //optional pause

}


//-----------------------------------------------------------------------------------//


/*

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
~ ~ ~ ~ ~ ~ ~ ~ Poetry of the Day! ~ ~ ~ ~ ~ ~ ~ ~
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Today's Poem:
A Mountain Home, written by Heinrich Heine, 
a 19th century German writer

https://en.wikipedia.org/wiki/Portal:Poetry/poem

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

On the mountain stands the shieling,
    Where the good old miner dwells;
Green firs rustle, and the moonbeams
    Gild the mountain heights and fells.

In the shieling stands an armchair,
    Carven quaint and cunningly;
Happy he who rests within it,
    And that happy guest am I.

On the footstool sits the lassie,
    Leans upon my lap her head;
Eyes of blue, twin stars in heaven,
    Mouth as any rosebud red.

And the blue eyes gaze upon me,
    Limpid, large as midnight skies;
And the lily finger archly
    On the opening rosebud lies.

"No, the mother cannot see us –
    At her wheel she spins away;
Father hears not-he is singing
    To the zitter that old lay."

So the little maiden whispers,
    Softly, that none else may hear,
Whispers her profoundest secrets
    Unmistrusting in my ear.

Now that auntie's dead, we cannot
    Go again to Goslar, where
People flock to see the shooting:
    'Tis as merry as a fair.

And up here it's lonely, lonely,
    On the mountain bleak and drear;
For the snow lies deep in winter;
    We are buried half the year.

And, you know, I'm such a coward,
    Frightened like a very child
At the wicked mountain spirits,
    Goblins who by night run wild."

Suddenly the sweet voice ceases;
    Startled with a strange surprise
At her own words straight the maiden
    Covers with both hands her eyes.

Louder outdoors moans the fir-tree,
    And the wheel goes whirring round;
Snatches of the song come wafted
    With the zitter's fitful sound.

Fear not, pretty one, nor tremble
    At the evil spirits' might;
Angels, dearest child, are keeping
    Watch around thee day and night.

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
*/