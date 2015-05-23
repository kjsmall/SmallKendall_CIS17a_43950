//Kendall Small
//MilTime derived Time class main file

#include "miltime.h"
#include<iostream>
using namespace std;

int main()
{
	int milH, milS, h, m, s;
	cout<<"Enter the time in military format: \n";
	cin>>milH;
	cout<<"Enter the seconds: \n";
	cin>>milS;
	MilTime time(milH, milS);
	cout<<"The time in military format is: ";
	time.getHour();
	cout<<endl;
	cout<<"The time in standard format is: ";
	time.getStandHr();
	cout<<endl<<endl;
	
	system("PAUSE");
	return 0;
}
