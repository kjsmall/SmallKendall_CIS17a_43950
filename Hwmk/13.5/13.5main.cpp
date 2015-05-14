// Kendall Small


#include "Retail.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


int main()
{
	RetailItem item[3];
	
	item[0].setDesc("Jacket");
	item[0].setUnit(12);
	item[0].setPric(59.95);
	
	item[1].setDesc("Designer Jeans");
	item[1].setUnit(40);
	item[1].setPric(34.95);
	
	item[2].setDesc("Shirt");
	item[2].setUnit(20);
	item[2].setPric(24.95);
	
	
	cout<<"\n\nItem #:"<<setw(20)<<"Description:"<<setw(15)<<"# units:"<<setw(16)<<"Price:\n";
	for(int i=0;i<3;i++)
	{
		cout<<i+1<<setw(25)<<item[i].getDesc()<<setw(15)<<item[i].getUnit()<<setw(15)<<item[i].getPric()<<endl;
	}
	
	
	
	
	
	system("PAUSE");
	return 0;
}
