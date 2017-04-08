//----------------------------------------------------------------------------------------------------------
// PURPOSE --------- This program calculates the cost of a BC ferry for anyone and everyone!
// AUTHOR ---------- liam beckmanc
// DATE ------------ 21 october 2016 friday
// SOURCES --------- https://github.com/haarcuba/cpp-text-table
// ASSIGNMENT ------ cs161 assignment 3
// COMPILED WITH --- gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) in Sublime Text 3 Build 3126
//-----------------------------------------------------------------------------------------------------------


#include <iostream>		//cout, cin
#include <iomanip>		//setprecision(), fixed, showpoint 


using namespace std;	


int main()
{
									//declaring and initializing our variables	
	double adultPrice = 13.00;		//ADULTS ticket charge
	double adultFuel = 1.25;		//ADULTS fuel charge
	double childPrice = 6.50;		//CHILDREN ticket charge (age 5 to 11) (Under 5 years of age: free)
	double childFuel = 1.25;		//CHILDREN fuel charge

	double vehiclePrice = 43.00;	//VEHICLE ticket charge 
	double vehicleFuel = 4.15;		//VEHICLE fuel charge
	double xlengthPrice = 2.15;		//VEHICLE extra length ticket charge (per foot over 20 feet)
	double xlengthFuel = 0.0;		//VEHICLE extra length fuel charge
	
	double oversizePrice = 69.00;	//OVERSIZE VEHICLE charge
	double oversizeFuel = 10.40;	//OVERSIZE VEHICLE charge
	double osxlengthPrice = 3.45;	//OVERSIZE VEHICLE extra length ticket charge (per foot over 20 feet)
	double osxlengthFuel = 0.0;		//OVERSIZE VEHICLE extra length fuel charge

	double priceTotal = 0.0;		//TOTAL ticket charge
	double fuelTotal = 0.0;			//TOTAL fuel charge

	int adults;			//number of ADULTS
	int children;		//number of CHILDREN
	char vehicle;		//is there a VEHICLE? (y/n) 
	double length;		//length of VEHICLE (feet)
	char oversize;		//is the VHICLE oversized (taller than 7 ft)


	
	
	cout << "Welcome to liam's Fare Calculator" << endl;				
	cout << "How many adults (age 12 or over) are in your party? ";	//prompt to enter number of ADULTS
		cin >> adults;													
	cout << "How many children (age 5 to 11) are in your party? ";	//prompt to enter number of CHILDREN
		cin >> children;												
	cout << "Are you driving a vehicle onto the ferry? (y/n): "; 	//prompt to enter yes or no to VEHICLE
		cin >> vehicle;													
	
	

	if (vehicle == 'y')												//if party is taking a VEHICLE onboard.
	{				
		cout << "what is the length of the vehicle in feet? "; 		//prompt to enter length of VEHICLE
			cin >> length;												
		cout << "Is the vehicle over 7 feet high? (y/n): "; 		//prompt to enter yes or no to OVERSIZED VEHICLE
			cin >> oversize;											
	}

	

	priceTotal += adultPrice * adults;		//appending the ADULTS ticket charge * number of adults to TOTAL ticket charge
	fuelTotal += adultFuel * adults;		//appending the ADULTS fuel charge * number of adults to TOTAL ticket charge

	priceTotal += childPrice * children;	//appending the CHILDREN ticket charge * number of adults to TOTAL ticket charge
	fuelTotal += childFuel * children;		//appending the CHILDREN fuel charge * number of adults to TOTAL ticket charge


	if (vehicle == 'n')		//If there is a vehicle and if it is NOT oversized and LESS THAN 20 feet.
	{
		priceTotal += 0;								//appending the VEHICLE ticket charge to TOTAL ticket charge
		fuelTotal = 0;
		childFuel = 0;
		adultFuel = 0;
		vehicleFuel= 0;									//appending the VEHICLE fuel ticket charge to TOTAL fuel charge
	}	

	if (vehicle == 'y' && oversize == 'n' && length < 20)		//If there is a vehicle and if it is NOT oversized and LESS THAN 20 feet.
	{
		priceTotal += vehiclePrice;								//appending the VEHICLE ticket charge to TOTAL ticket charge
		fuelTotal += vehicleFuel;								//appending the VEHICLE fuel ticket charge to TOTAL fuel charge
	}		
	
	else if (vehicle == 'y' && oversize == 'n' && length > 20)	//If there is a vehicle and if it is NOT oversized and OVER  20 feet.
	{
		priceTotal += xlengthPrice;								//appending the VEHICLE extra length ticket charge * number of adults to TOTAL ticket charge
		priceTotal += (length - 20) * xlengthPrice;				//appending the VEHICLE extra length ticket charge to TOTAL ticket charge
		fuelTotal += xlengthFuel;								//appending the VEHICLE extra length fuel ticket charge to TOTAL fuel charge
	}		

	else if (vehicle == 'y' && oversize == 'y' && length < 20)	//If there is a vehicle and if it IS oversized and LESS THAN 20 feet.
	{	
		priceTotal += oversizePrice;							//appending the OVERSIZE VEHICLE ticket charge to TOTAL ticket charge
		fuelTotal += oversizeFuel;								//appending the OVERSIZE VEHICLE fuel ticket charge to TOTAL fuel charge
	}
	
	else if(vehicle == 'y' && oversize == 'y' && length > 20)	//If there is a vehicle and if it IS oversized and OVER 20 feet.
	{
		priceTotal += oversizePrice;							//appending the OVERSIZE VEHICLE ticket charge to TOTAL ticket charge
		priceTotal += (length - 20) * osxlengthPrice;			//appending the OVERSIZE VEHICLE extra length ticket charge to TOTAL ticket charge
		fuelTotal += oversizeFuel;								//appending the OVERSIZE VEHICLE fuel ticket charge to TOTAL fuel charge
	}

	

	cout << fixed << showpoint << setprecision(2);								//formatting our output					
	cout << "\n\n" << "Your fare is $" << priceTotal 							//outputs TOTAL ticket charge
		 << " plus a fuel surcharge of $" << fuelTotal << endl;;				//outputs TOTAL fuel charge
	cout << "The total amount payable is $" << priceTotal + fuelTotal << endl;	//outputs TOTAL CHARGE	
	cout << "Thank you for using liam's Fare Calculator" << "\n\n\n"; 			

	

	cout << "   --- R E C I E P T --- O F --- C H A R G E S ---          " << "\n\n";	//reciept table

	cout << "NAME OF CHARGE" << " |  " << "VALUE OF CHARGE"  		     << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "adult price" << "    |  " << "$" << adultPrice * adults     << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "adult fuel" << "     |  " << "$ " << adultFuel  * adults     << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "child price" << "    |  " << "$" << childPrice * children   << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "child fuel" << "     |  " << "$ " << childFuel  * children   << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "vehichle price" << " |  " << "$" << vehiclePrice 		     << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "vehicle fuel" << "   |  " << "$ " << vehicleFuel 		     << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "ticket charge" << "  |  " << "$" << priceTotal				 << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "fuel surcharge" << " |  " << "$ " << fuelTotal		         << endl;	
	cout << "----------------------------------------------------------" << endl;	
	cout << "TOTAL CHARGE" << "   |  " << "$" << priceTotal + fuelTotal  << endl;	
	cout << "----------------------------------------------------------" << endl;	

								
	return 0;	
}
