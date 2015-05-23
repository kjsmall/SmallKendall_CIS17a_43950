//Kendall Small
//MilTime class derived from Time class

#ifndef MILTIME_H
#define MILTIME_H
#include "time.h"
#include<iostream>

class MilTime : public Time{
	private:
		int milHour;
		int milSec;
	public:
		MilTime(int h, int s) : Time()
			{ 
			  if(h < 2400 && h > 0){
			    milHour = h;
			  }
			  else
			  	std::cout<<"Erroneous input for hours!\n";
			  if(s < 60 && s > 0){
			  	milSec = s;
			  }
			  else
			  	std::cout<<"Erroneous input for seconds!\n";
			  
			  hour = (milHour%1200)/100;
			  min = milHour%100;
			  sec = milSec;
			}
		void setTime(int h, int s){ 
			if(h < 2400 && h > 0){
			    milHour = h;
			  }
			  else
			  	std::cout<<"Erroneous input for hours!\n";
			  if(s < 60 && s > 0){
			  	milSec = s;
			  }
			  else
			  	std::cout<<"Erroneous input for seconds!\n";
			
			hour = (milHour%1300)/100;
			min = milHour%100;
			sec = milSec;
			}
		void getHour()
			{ std::cout<<milHour<<" and "<<milSec<<" seconds\n"; }
		void getStandHr()
			{ std::cout<<hour<<":"<<min<<" and "<<sec<<" seconds\n"; }
};

#endif
