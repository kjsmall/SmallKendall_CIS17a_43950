//Kendall Small
//DayYear modified class specification file



#ifndef DAYYEAR2_H
#define DAYYEAR2_H
#include<string>

class DayYear2
{
	private:
		int day;
		void simplify();
	public:
		DayYear2(int);
		DayYear2(std::string, int);
		void print();
		static std::string month[12];
		int getDay()
		{return day;}
		DayYear2 operator++(int);
		DayYear2 operator++();
		DayYear2 operator--(int);
		DayYear2 operator--();
};

#endif
