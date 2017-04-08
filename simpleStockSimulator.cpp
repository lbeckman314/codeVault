//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program simulates the buying and selling of stocks!
// AUTHOR ---------- liam beckman
// DATE ------------ 12 october 2016 wednesday
// SOURCES --------- none
// ASSIGNMENT ------ cs161 lab 3 program 2/4
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

int main()
{
	double stockAmt;		//number of shares
	double stockBuy;		//stock cost when buying
	double stockSell;		//stock value when selling
	float brokerageFee; 	//brokerage fee based on (number of shares * stock value when selling)

	cout << "Enter amount of stocks" << endl;
	cin >> stockAmt;		//user inputs the total number of shares

	cout << "Enter stock cost when buying" << endl;
	cin >> stockBuy;		//user inputs the cost of each share when buying

	cout << "Enter stock value when selling" << endl;
    cin >> stockSell;		//user inputs the value of each share when selling

	cout << "Enter the brokerage fee" << endl;
	cin >> brokerageFee;
        if (brokerageFee > 1)		//allows for 1.5% to be inputed instead of just 0.015
            brokerageFee /= 100;

	double netChange = stockAmt * (stockSell - stockBuy);				//change of stock value
	double profit = netChange - (stockAmt * stockSell * brokerageFee);	//overall profit (or loss)

	if (profit >= 0)						//if there is an overall profit
        cout << "$" << profit << endl;
    else if (profit < 0)					//if there is an overall loss
        cout << "-$" << profit * -1 << endl;

	return 0;
}

int main()
