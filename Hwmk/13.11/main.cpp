//Main.cpp
//main using number class


#include "number.h"
#include<iostream>
using namespace std;

int main(){
	int size, choice, index;
	float number;
	cout<<"This program creates an array of floats and\n"
		<<"offers a number of options for modifying the array.\n"
		<<"Please enter the size of the array: \n";
	cin>>size;
	Number num(size);
	do{
		cout<<"\nPlease choose an option from the menu: \n"
			<<"1. Add a number to the array\n"
			<<"2. Retrieve a number from the array\n"
			<<"3. Find the highest value in the array\n"
			<<"4. Find the lowest value in the array\n"
			<<"5. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter a number to add to the array: \n";
				cin>>number;
				cout<<"\nEnter which spot in the array you would like to fill: \n";
				cin>>index;
				while(index >= size || index < 0){
					cout<<"Error! Enter a valid index for the array!\n";
					cin>>index;
				}
				num.addNum(number, index);
				break;
			case 2:
				cout<<"\nEnter the spot in the array to retrieve a number from: \n";
				cin>>index;
				while(index >= size || index < 0){
					cout<<"Error! Enter a valid index for the array!\n";
					cin>>index;
				}
				cout<<num.getNum(index)<<endl;
				break;
			case 3:
				cout<<"\nThe highest number is: "<<num.getHigh()<<endl;
				break;
			case 4:
				cout<<"\nThe lowest number is: "<<num.getLow()<<endl;
				cout<<"If you havent filled every position in the array then the lowest\n"
					<<"number will be 0.\n";
				break;
			case 5:
				cout<<"Exit\n";
				break;
			default:
				cout<<"Erroneous input - try again!\n";
			}
	}while(choice != 5);
	
	
	system("PAUSE");
	return 0;
}
