//Kendall Small
//Main file for Ship, CargoShip, and CruiseShip classes
//Using virtual print function


#include "cruise.h"
#include "cargo.h"
using namespace std;


int main()
{
	const int SIZE = 6;
	Ship *ships[SIZE] =
		{ new Cruise(6296, "Allure of the Seas", "2010"),
		  new Cargo(28000, "Small Handy Cargo", "2001"),
		  new Cruise(4905, "Quantum of the Seas", "2014"),
		  new Cargo(320000, "SuperTanker", "2004"),
		  new Cruise(6360, "Harmony of the Seas", "2016"),
		  new Cargo(550000, "Enormous Supertanker", "2015") };
		  
	for(int i=0;i<SIZE;i++){
		ships[i]->print();
		cout<<endl;
	}
	
	system("PAUSE");
	return 0;
}
