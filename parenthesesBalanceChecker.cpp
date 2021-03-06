//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program determines whther a string of parentheses is balanced (i.e. ((()))  )
// AUTHOR ---------- liam beckman
// DATE ------------ 10 november 2016 thursday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 7 functions (due november 10th 2016)
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------

#include <iostream>					//cout, cin
#include <string>					//find(), empty(), erase()

using namespace std;

bool isBalanced(string paren);		//our isBalanced function prototype


//--------------------------------------------------------------------------------//


string paren;						//declare string variable to hold the user's parentheses

int main()
{
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n" << endl;
	
	//string name = "liam is a cool guy";
	//bool found;	//found is set to false;
	//cout << "name.find('s') " << name.find('s') << endl;

	cout << "please enter your string of parentheses." << endl;	//prompt user for their parentheses
	cout << "user input:   ";		
	cin >> paren;					
	cout << boolalpha << isBalanced(paren) << endl;				//call and output isBalanced function

	cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

	return 0;						//return successful exit status
}


//--------------------------------------------------------------------------------//


bool isBalanced(string paren)				//our function that will check whether the paren string is balanced or not
{
	while (paren.find("()") < string::npos)	//while the substring "()" is still found in the paren string...
	{
		paren.erase(paren.find("()"), 2);	//...erase "()"...
		cout << paren << endl;				//...and output the new paren string
	}


	if (paren.empty()==0)	//if, after all "()" erasures, paren is NOT empty...
	{	
		cout << "Your string is not balanced. Balance = ";
		return false;		//...return false (the string is NOT balanced)
	}
	else					//else, if after all "()" erasures, paren IS empty...
	{		
		cout << "Your string is balanced! Balance = ";
		return true;		//...return true (the string IS balanced)
	}
}


/*

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  ~ ~ ~ ~ ~ ~ ~ Poetry of the Day! ~ ~ ~ ~ ~ ~ ~ 
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Today's Poem:
Clair de Lune by Paul Verlaine, written in 1869
Both the English and French versions!

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
 	
Your soul is like a landscape fantasy,
Where masks and Bergamasks, in charming wise,
Strum lutes and dance, just a bit sad to be
Hidden beneath their fanciful disguise.

Singing in minor mode of life's largesse
And all-victorious love, they yet seem quite
Reluctant to believe their happiness,
And their song mingles with the pale moonlight,

The still moonlight, sad and beautiful,
Sets the birds softly dreaming in the trees,
And makes the marbled fountains, gushing, streaming--
Slender jet-fountains—sob their ecstasies.

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Votre âme est un paysage choisi
Que vont charmant masques et bergamasques
Jouant du luth et dansant et quasi
Tristes sous leurs déguisements fantasques.

Tout en chantant sur le mode mineur
L'amour vainqueur et la vie opportune
Ils n'ont pas l'air de croire à leur bonheur
Et leur chanson se mêle au clair de lune,

Au calme clair de lune triste et beau,
Qui fait rêver les oiseaux dans les arbres
Et sangloter d'extase les jets d'eau,
Les grands jets d'eau sveltes parmi les marbres.
	
*/
