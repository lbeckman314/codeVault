#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "hello!" << endl;
    cout << "enter num 1: ";
    string numOne;// = "49";
    cin >> numOne;
    cout << "enter num 2: ";
    string numTwo;// = "49";
    cin >> numTwo;
    string numLongest="";
    string numShortest="";
    char ch1, ch2, sch1, sch2;
    int addition[512];
    int subtraction[512];

    if (numOne.length() > numTwo.length())
    {
        numLongest = numOne;
        numShortest = numTwo;
    }
    else
    {
        numLongest = numTwo;
        numShortest = numOne;
    }

    int lengthDiff = numLongest.length() - numShortest.length();
    int startDiff = numLongest.length() - lengthDiff;

    

    for (int i = 0; i<=numShortest.length()-1;i++)
    {    
        //cin.get(ch1);
        ch1 = numLongest[i+lengthDiff];
        ch1 = static_cast<int>(ch1)-48;
        sch1 = numOne[i+lengthDiff];
        sch1 = static_cast<int>(sch1)-48;
        //cout << ch1 << endl;
        
        //cin.get(ch2);
        ch2 = numShortest[i];
        ch2 = static_cast<int>(ch2)-48;
        sch2 = numTwo[i];
        sch2 = static_cast<int>(sch2)-48;
        //cout << ch2 << endl;
        addition[i+lengthDiff] = ch1 + ch2;
        subtraction[i] = sch1 - sch2;
        //cout << "subtraction[0]: " << subtraction[0] << endl;
        //char ch1Future = cin.peek();
        //cout << "ch1Future: " << ch1Future << endl;

        //char ch2Future = cin.peek();
        //cout << "ch2Future: " << ch2Future << endl;
        
        //if(ch3Future >= 10)
        {
          //  ch3++;
          // ch3Future -= 10;
        } 
        //while(i < lengthDiff)
        {
          //  cout << numLongest[i];
           // i++;
        }
        //cout << ch3;// << endl;
    }

    for (int i = 0; i < lengthDiff; i++)
        {
            addition[i] = numLongest[i]-48;
            //subtraction[i] = numLongest[i]-48;
            //cout << "numLonegst[i]" << numLongest[i] << endl;
        }

    for (int i = numLongest.length(); i > 0; i--)
    {
        if (addition[i] >= 10)
        {
            addition[i-1]++;
            addition[i]-=10;
        }
    }

  for (int i = 0; i<numLongest.length(); i++)
    {
        cout << addition[i];
    }
     
cout << "\n";

     for (int i = numLongest.length(); i > 0; i--)
    {
        if (subtraction[i] < 0)
        {
            //subtraction[i-1]++;
            //subtraction[i]*=-1;
            if (i!=1)
                subtraction[i-1]--;
            subtraction[i]+=10;
            //cout << "subtraction[0]: " << subtraction[0] << endl;
        }
    }

    if(numTwo > numOne)
        subtraction[0] *= -1;

  

    for (int i = 0; i<numLongest.length(); i++)
    {
        //cout << "subtraction[0]: " << subtraction[0] << endl;
        cout << subtraction[i];
    }
  
    return 0;
}