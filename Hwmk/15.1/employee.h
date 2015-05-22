//Kendall Small
//Sorry! Tanya is made uncomfortable by Kendall. Whoever
//reads this should know that Kendall feels offended.
//Because the woman that he loves with all of his
//life force, just rejects him and makes him feel unwanted.


#ifndef EMPLOYEE_H 
#define EMPLOYEE_H
#include<string>

class Employee{
	private:
		std::string name;
		std::string number;
		std::string date;
	public:
		Employee()
		{name = "Blank"; 
		 number = "ooooooo"; 
		 date = "00/00/0000"; }
		void setName(std::string a)
		{name = a;}
		void setNum(std::string a)
		{number = a;}
		void setDate(std::string a)
		{date = a;}
		std::string getName()
		{return name;}
		std::string getNum()
		{return number;}
		std::string getDate()
		{return date;}
};

#endif
