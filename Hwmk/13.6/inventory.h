// inventory.h header
//Specification for Inventory class


#ifndef INVENTORY_H
#define INVENTORY_H


class Inventory
{
	private:
		int itemNum;
		int quant;
		float cost;
		float totCost;
	public:
		Inventory();
		Inventory(int, float, int);
		void setItem(int);
		void setQuant(int);
		void setCost(float);
		void setTotl();
		int getItem();
		int getQuant();
		float getCost();
		float getTotl();
};


#endif
