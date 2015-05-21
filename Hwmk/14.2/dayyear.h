//Kendall Small
// DayYear class specification file

#ifndef DAYYEAR_H
#define DAYYEAR_H
#include<string>


class DayYear
{
	private:
		int day;
	public:
		DayYear(int);
		void print();
		static std::string month[12];
};




#endif
