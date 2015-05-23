//Kendall Small
//CruiseShip specification file

#ifndef CRUISE_H
#define CRUISE_H
#include "ship.h"

class Cruise : public Ship{
	private:
		int passngr;
		
	public:
		Cruise()
		{ passngr = 0; }
		Cruise(int p, std::string n, std::string y) : Ship(n,y)
		{ passngr = p; }
		void setPass(int p)
		{ passngr = p; }
		int getPass()
		{ return passngr; }
		virtual void print() const
		{ std::cout<<"Ship's Name: "<<name<<std::endl;
		  std::cout<<"Maximum Number of Passengers: "<<passngr<<std::endl; }
};


#endif
