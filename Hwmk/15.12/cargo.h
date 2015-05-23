//Kendall Small
//CargoShip class specification file


#ifndef CARGO_H
#define CARGO_H
#include "ship.h"

class Cargo : public Ship{
	private:
		int capacity;
		
	public:
		Cargo()
		{ capacity = 0; }
		Cargo(int c, std::string n, std::string y) : Ship(n,y)
		{ capacity = c; }
		void setCap(int c)
		{ capacity = c; }
		int getCap()
		{ return capacity; }
		virtual void print() const
		{ std::cout<<"Ship's Name: "<<name<<std::endl;
		  std::cout<<"Maximum cargo capacity: "<<capacity<<std::endl; }
		  
};

#endif
