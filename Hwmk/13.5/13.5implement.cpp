// Kendall Small
//Implementation file for retailItem class


#include "retail.h"
#include<iostream>
#include<string>
using namespace std;

RetailItem::RetailItem(string desc, int u, float p)
{
	cout<<"Welcome to the constructor!\n";
	dscrptn = desc;
	units = u;
	price = p; 
}

RetailItem::RetailItem()
{
	cout<<"This is a test of the default constructor.\n";
	dscrptn = "Default";
	units = 0;
	price = 0;
}


void RetailItem::setDesc(string a)
{
	dscrptn = a;
}
void RetailItem::setUnit(int a)
{
	units = a;
}
void RetailItem::setPric(float a)
{
	price = a;
}
string RetailItem::getDesc()
{
	return dscrptn;
}
int RetailItem::getUnit()
{
	return units;
}
float RetailItem::getPric()
{
	return price;
}
