//Kendall Small
//ProductionWorker


#ifndef WORKER_H
#define WORKER_H
#include "employee.h"
#include<iostream>

class Worker : public Employee{
	private:
		int shift;
		float pay;
	public:
		Worker()
		{ shift = 1; pay = 9.00; }
		Worker(int a, float b){
		if(a == 1 || a == 2){
			shift = a;
		}
		else
			std::cout<<"Erroneous value for shift!\n";
		pay = b;
		}
		void setShift(int a)
		{ shift = a; }
		void setPay(float a)
		{ pay = a; }
		int getShift()
		{ return shift; }
		float getPay()
		{ return pay; }		
};


#endif
