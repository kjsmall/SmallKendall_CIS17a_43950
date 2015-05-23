//Kendall Small
//Ship class specification file


#ifndef SHIP_H
#define SHIP_H
#include<string>
#include<iostream>

class Ship{
	protected:
		std::string name;
		std::string year;
	public:
		Ship()
		{ name = "N/A"; year = "N/A"; }
		Ship(std::string n, std::string y)
		{ name = n; year = y; }
		void setName(std::string n)
		{ name = n; }
		void setYear(std::string y)
		{ year = y; }
		std::string getName()
		{ return name; }
		std::string getYear()
		{ return year; }
		
		virtual void print() const
		{ std::cout<<"Ship's Name: "<<name<<std::endl;
		  std::cout<<"Year built: "<<year<<std::endl; }
};


#endif
