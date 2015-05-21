//Kendall Small
//NumDays implementation file

#include "numdays.h"

void NumDays::simplify(){
	
}


void NumDays::setHours(float a){
	hours = a;
	setDays();	
}

void NumDays::setDays(){
	days = hours/24;
}

float NumDays::getHours(){
	return hours; 
}

float NumDays::getDays(){
	return days;
}

float NumDays::convert(){
	days = hours / 24;
	return days;
}

NumDays NumDays::operator +(const NumDays &right){
	NumDays temp(0);
	
	temp.hours = hours + right.hours;
	temp.setDays();
	return temp;
}

NumDays NumDays::operator -(const NumDays &right){
	NumDays temp(0);
	
	temp.hours = hours - right.hours;
	temp.setDays();
	return temp;
}

NumDays NumDays::operator++(){
	++hours;
	setDays();
	return *this;
}

NumDays NumDays::operator++(int){
	NumDays temp(hours);
	hours++;
	setDays();
	return temp;
}

NumDays NumDays::operator--(){
	--hours;
	setDays();
	return *this;
}

NumDays NumDays::operator--(int){
	NumDays temp(hours);
	hours--;
	setDays();
	return temp;
}
