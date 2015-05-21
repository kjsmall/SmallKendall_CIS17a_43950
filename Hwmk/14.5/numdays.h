//Kendall Small
//NumDays class specification file


#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
	private:
		float hours;
		float days;
		void simplify();
	public:
		NumDays()
		{hours = 0; days = 0;}
		NumDays(float a)
		{hours = a;}
		void setHours(float);
		void setDays();
		float getHours();
		float getDays();
		float convert();
		NumDays operator +(const NumDays &);
		NumDays operator -(const NumDays &);
		NumDays operator++(int);
		NumDays operator++();
		NumDays operator--(int);
		NumDays operator--();
};

#endif 
