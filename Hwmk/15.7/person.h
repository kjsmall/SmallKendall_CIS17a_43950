//Kendall Small
//Person class specification file

#ifndef PERSON_H
#define PERSON_H
#include<string>

class Person{
	private:
		std::string last;
		std::string first;
		std::string address;
		std::string city;
		std::string state;
		std::string zip;
		std::string phone;
	public:
		Person()
		{ last = "N/A";
		  first = "N/A";
		  address = "N/A";
		  city = "N/A";
		  state = "N/A";
		  zip = "N/A";
		  phone = "N/A"; }
		   
		void setLast(std::string l)
		{ last = l; }
		void setFirst(std::string f)
		{ first = f; }
		void setAdrs(std::string a)
		{ address = a; }
		void setCity(std::string c)
		{ city = c; }
		void setStat(std::string s)
		{ state = s; }
		void setZip(std::string z)
		{ zip = z; }
		void setPhon(std::string p)
		{ phone = p; }
		std::string getLast()
		{ return last; }
		std::string getFirst()
		{ return first; }
		std::string getADrs()
		{ return address; }
		std::string getCity()
		{ return city; }
		std::string getStat()
		{ return state; }
		std::string getZip()
		{ return zip; }
		std::string getPhon()
		{ return phone; }
};

#endif
