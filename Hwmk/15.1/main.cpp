//Kendall Small
//Main file for exercise 15.1 class Employee and derived
//class ProductionWorker or Worker for short


#include "worker.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int choice;
	do{
		cout<<"Menu:\n"
			<<"1. Use a random shift and pay rate for schedule\n"
			<<"2. Enter your own shifts and pay rates\n"
			<<"3. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:{
				int size;
				string name, number, date;
				cout<<"How many employees?\n";
				cin>>size;
				cin.clear();
				cin.ignore(10000, '\n');
				Worker worker[size];
				for(int i=0;i<size;i++){
					int shift = rand()%2+1;
					float pay = rand()%6+9;
					cout<<"Employee #"<<i+1<<":\n"
						<<"Employee name: \n";
					getline(cin, name);
					worker[i].setName(name);
					cout<<"Employee number: \n";
					getline(cin, number);
					worker[i].setNum(number);
					cout<<"Employee hire date: (mm/dd/yyyy)\n";
					getline(cin, date);
					worker[i].setDate(date);
					worker[i].setShift(shift);
					worker[i].setPay(pay);
				}
				cout<<"The schedule for the week: \n";
				cout<<"Name:"<<setw(25)<<"Number: "<<setw(18)<<"Hire Date: "<<setw(15)<<"Shift:"<<setw(14)
					<<"Pay: \n";
				for(int i=0;i<size;i++){
				cout<<worker[i].getName()<<setw(17)<<worker[i].getNum()<<setw(16)
					<<worker[i].getDate()<<setw(15)<<worker[i].getShift()<<setw(15)<<worker[i].getPay()<<endl;
				}
				cout<<endl<<endl;
				break;
			}
			case 2:{
				int size, shift;
				float pay;
				string name, number, date;
				cout<<"How many employees?\n";
				cin>>size;
				cin.clear();
				cin.ignore(10000, '\n');
				Worker worker[size];
				for(int i=0;i<size;i++){
					cout<<"Employee #"<<i+1<<":\n"
						<<"Employee name: \n";
					getline(cin, name);
					worker[i].setName(name);
					cout<<"Employee number: \n";
					getline(cin, number);
					worker[i].setNum(number);
					cout<<"Employee hire date: (mm/dd/yyyy)\n";
					getline(cin, date);
					worker[i].setDate(date);
					cout<<"Employee shift: (1 for day, 2 for night)\n";
					cin>>shift;
					worker[i].setShift(shift);
					cout<<"Employee pay rate: \n";
					cin>>pay;
					cin.clear();
					cin.ignore(10000, '\n');
					worker[i].setPay(pay);
				}
				cout<<"\n\nThe schedule for the week: \n";
				cout<<"Name:"<<setw(25)<<"Number: "<<setw(18)<<"Hire Date: "<<setw(15)<<"Shift:"<<setw(14)
					<<"Pay: \n";
				for(int i=0;i<size;i++){
				cout<<worker[i].getName()<<setw(17)<<worker[i].getNum()<<setw(16)
					<<worker[i].getDate()<<setw(15)<<worker[i].getShift()<<setw(15)<<worker[i].getPay()<<endl;
				}
				cout<<endl<<endl;
				break;
			}
			case 3:{
				
				break;
			}
			default:{
				cout<<"Wrong input!\n";
				break;
			}
		}
	}while(choice != 3);
	
	
	system("PAUSE");
	return 0;
}
