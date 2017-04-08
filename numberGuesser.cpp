
///* rand example: guess the number */
//#include <stdio.h>      /* printf, scanf, puts, NULL */
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
//
//
//int main ()
//{
//  int iSecret, iGuess;
//
//  /* initialize random seed: */
//  srand (time(NULL));
//  /* generate secret number between 1 and 10: */
//  iSecret = rand() % 10 + 1;
//
//  do {
//    printf ("Guess the number (1 to 10): ");
//    scanf ("%d",&iGuess);
//    if (iSecret<iGuess) puts ("The secret number is lower");
//    else if (iSecret>iGuess) puts ("The secret number is higher");
//  } while (iSecret!=iGuess);
//  puts ("Congratulations!");
//  return 0;
//}

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random(int min, int max)
  {
    //int max = 10, min = 0;
    int range = max - min + 1;
    return rand() % range + min;
  }

/*
int randomGen()
{
  int max = 10, min = 5, range; 
  range = max-min + 1;
  return rand()%range + min;
}
*/

int main()
{
  int num;
  int guess[10];
  bool found = false;
  int n = 0;
  char answer;
  int count=0;

  cout << random(1, 12) << endl;
/*
int randomgen(int max, int min) //Pass in range
{
  srand(time(NULL));  //Changed from rand(). srand() seeds rand for you.
  int random = rand() % max + min;
  return random;
}
*/
  cout << "hello!" << endl;
  cout << "think of a number, and i'll try to guess it!" << endl;

  int max = 10;
  int min = 1;

  for (int i=0;i<10;i++)
  {
    guess[i] = i + 1;
  }

  while (!found)
  {
    cout << "is your number: " << (rand() % max) + min/*guess[n]*/ << endl;
    cin >> answer;

    if(answer == 'y')
    {
      cout << "Yas!" << endl;
      cout << "correct guess in " << count << " guesses!" << endl;
      break;
    }
    else if(answer == 'l')
    {
      n++;
      count++;
      min = (rand() % max) + min;
      continue;
    }
    else if(answer == 's')
    {
      n--;
      count++;
      max = (rand() % max) + min;
      continue;
    }
    else
      count++;
  }

  return 0;
}

