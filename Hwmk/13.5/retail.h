//Kendall Small 	10/05/15 17:55

#ifndef RETAIL_H
#define RETAIL_H
#include<string>

class RetailItem
{
	private:
		std::string dscrptn;
		int units;
		float price;
	public:
		RetailItem (std::string, int, float);
		RetailItem();
		void setDesc(std::string);
		void setUnit(int);
		void setPric(float);
		std::string getDesc();
		int getUnit();
		float getPric();		
};


#endif
