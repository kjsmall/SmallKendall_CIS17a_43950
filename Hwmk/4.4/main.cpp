//Kendall Small
//Main file for NumDays class

#include "numdays.h"
#include<iostream>
#include<iomanip>
using namespace std;


int main(){
	NumDays day(0);
	float hours, days;
	int choice;
	
	do{
		cout<<"Menu:\n"
			<<"1. Convert hours to days\n"
			<<"2. Set number of hours\n"
			<<"3. Increment number of hours\n"
			<<"4. Decrement number of hours\n"
			<<"5. Add two people's hours\n"
			<<"6. Subtract one persons hours from another\n"
			<<"7. Get number of hours\n"
			<<"8. Get number of days\n"
			<<"9. Exit\n"; 
		cin>>choice;
		cout<<fixed<<setprecision(2); 
		switch(choice){
			case 1:{
				cout<<"Enter the number of hours to be converted to days:\n";
				cin>>hours;
				day.setHours(hours);
				cout<<"The number of days worked is: "<<day.convert()<<endl<<endl;
				break;
			}
			case 2:{
				cout<<"Enter the number of hours: \n";
				cin>>hours;
				day.setHours(hours);
				cout<<endl<<endl;
				break;
			}
			case 3:{
				cout<<"Before increment: "<<day.getHours()<<endl;
				day++;
				cout<<"After increment: "<<day.getHours()<<endl;
				break;
			}
			case 4: {
				cout<<"Before decrement: "<<day.getHours()<<endl;
				day--;
				cout<<"After decrement: "<<day.getHours()<<endl;
				break;
			}
			case 5:{
				NumDays p1(0), p2(0), total(0);
				cout<<"Enter first persons hours: \n";
				cin>>hours;
				p1.setHours(hours);
				cout<<"Enter the second persons hours: \n";
				cin>>hours;
				p2.setHours(hours);
				total = p1+p2;
				cout<<"The total hours are: "<<total.getHours()<<endl;
				cout<<"The total days are: "<<total.getDays()<<endl;
				break;
			}
			case 6:{
				NumDays p1(0), p2(0), total(0);
				cout<<"Enter first persons hours: \n";
				cin>>hours;
				p1.setHours(hours);
				cout<<"Enter the second persons hours: \n";
				cin>>hours;
				p2.setHours(hours);
				total = p1-p2;
				cout<<"The total hours are: "<<total.getHours()<<endl;
				cout<<"The total days are: "<<total.getDays()<<endl;
				break;
			}
			case 7:{
				cout<<"Hours: "<<day.getHours()<<endl<<endl;
				break;
			}
			case 8:{
				cout<<"Days: "<<day.getDays()<<endl<<endl;
				break;
			}
			case 9:{
				cout<<"Bye bye!\n";
				break;
			}
			default:{
				cout<<"You didn't choose an option from the menu.\n\n";
				break;
			}
		}
	}while(choice != 9);
	
	
	system("PAUSE");
	return 0;
}
