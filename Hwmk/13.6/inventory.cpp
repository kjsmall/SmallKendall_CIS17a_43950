//Implementation file for Inventory class



#include "inventory.h"
#include<iostream>
using namespace std;

Inventory::Inventory()
{
	itemNum = 0;
	quant = 0;
	cost = 0;
	totCost = 0;	
}

Inventory::Inventory(int a, float b, int c)
{
	itemNum = a;
	cost = b;
	quant = c;
	setTotl();
}

void Inventory::setItem(int a)
{
	itemNum = a;
}

void Inventory::setQuant(int a)
{
	quant = a;
}

void Inventory::setCost(float a)
{
	cost = a;
}

void Inventory::setTotl()
{
	totCost = quant * cost;
}

int Inventory::getItem()
{
	return itemNum;
}

int Inventory::getQuant()
{
	return quant;
}

float Inventory::getCost()
{
	return cost;
}

float Inventory::getTotl()
{
	return totCost;
}
