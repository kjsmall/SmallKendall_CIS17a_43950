//Kendall Small
//Program 15-18 time class

#ifndef TIME_H
#define TIME_H

class Time
{
	protected:
		int hour;
		int min;
		int sec;
	public:
		Time()
			{ hour = 0; min = 0; sec = 0; }
		Time(int h, int m, int s)
			{ hour = h; min = m; sec = s; }
		int getHour()
			{ return hour; }
		int getMin()
			{ return min; }
		int getSec()
			{ return sec; }
};

#endif
