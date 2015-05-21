//Kendall Small
//Numbers class main

#include "numbers.h"
#include<iostream>
using namespace std;

int main()
{	
	int number;
	cout<<"Please enter an integer value in the range of 0-9999: \n";
	cin>>number;
	
	Numbers num(number);
	num.print();
	
	system("PAUSE");
	return 0;
}
