//Main file for Inventory class


#include "inventory.h"
#include<iostream>
using namespace std;


int main()
{
	int size, num, qnt;
	float cst;
	
	cout<<"How many items for inventory?\n";
	cin>>size;
	while(size<0){
			cout<<"Please enter a positive value: \n";
			cin>>size;
		}
	
	Inventory item[size];
	
	for(int i=0;i<size;i++){
		cout<<"Item Number: \n";
		cin>>num;
		while(num<0){
			cout<<"Please enter a positive value: \n";
			cin>>num;
		}
		item[i].setItem(num);
		cout<<"Quantity: \n";
		cin>>qnt;
		while(qnt<0){
			cout<<"Please enter a positive value: \n";
			cin>>qnt;
		}
		item[i].setQuant(qnt);
		cout<<"Cost: \n";
		cin>>cst;
		while(cst<0){
			cout<<"Please enter a positive value: \n";
			cin>>cst;
		}
		item[i].setCost(cst);
		item[i].setTotl();
		cout<<endl<<endl;
		
	}
	
	
	cout<<"Inventory Results: \n\n";
	for(int i=0;i<size;i++){
		cout<<"Item #: "<<item[i].getItem()<<endl;
		cout<<"Quantity: "<<item[i].getQuant()<<endl;
		cout<<"Cost: "<<item[i].getCost()<<endl;
		cout<<"Total cost: "<<item[i].getTotl()<<endl;
		cout<<endl<<endl;
	}
	
	
	
	system("PAUSE");
	return 0;
}
