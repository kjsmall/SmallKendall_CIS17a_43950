//Kendall Small
//main file for DayYear2 modified dayyear class


#include "dayyear2.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int day, choice, choice1;
	string month;
	do{
	cout<<"1. Input a day of the year from 0-365 \n"
		<<"2. Input a month and day and get the day of the year \n"
		<<"3. Exit\n";
	cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Enter a day: (0-365)\n";
				cin>>day;
				while(day < 0 && day > 365){
					cout<<"Error! Value outside of specified range. Try again.\n";
					cin>>day;
				}
				DayYear2 date(day);
				date.print();
				cout<<endl;
				do{
					cout<<"Menu:\n"
						<<"1. Print\n"
						<<"2. Increment the day\n"
						<<"3. Decrement the day\n"
						<<"4. Return to previous menu\n";
					cin>>choice1;
					switch(choice1){
						case 1:{
							date.print();
							break;
							}
						case 2:{
							cout<<"Day before increment: "<<endl;
							date.print();
							date++;
							cout<<"Day after increment: "<<endl;
							date.print();
							break;
						}
						case 3:{
							cout<<"Day before decrement: "<<endl;
							date.print();
							date--;
							cout<<"Day after decrement: "<<endl;
							date.print();
							break;
						}
						case 4:{
							cout<<"Returning to previous menu\n\n";
							break;
						}
						default:{
							cout<<"Invalid input\n";
							break;
						}
					}
				}while(choice1 != 4); 
				break;
				break;
			}
			case 2:{
				cout<<"Enter month (Case sensitive, January, February, etc)\n";
				cin>>month;
				cout<<"Enter a valid day for that month: \n";
				cin>>day;
				DayYear2 montDay(month, day); //Month and day;
				do{
					cout<<"Menu:\n"
						<<"1. Print\n"
						<<"2. Increment the day\n"
						<<"3. Decrement the day\n"
						<<"4. Return to the previous menu\n";
					cin>>choice1;
					switch(choice1){
						case 1:{
							montDay.print();
							break;
						}
						case 2:{
							cout<<"Day before increment: "<<montDay.getDay()<<endl;
							montDay++;
							cout<<"Day after increment: "<<montDay.getDay()<<endl;
							break;
						}
						case 3:{
							cout<<"Day before decrement: "<<montDay.getDay()<<endl;
							montDay--;
							cout<<"Day after decrement: "<<montDay.getDay()<<endl;
							break;
						}
						case 4:{
							cout<<"Returning to previous menu\n";
							break; 
						}
					}
				}while(choice1 != 4);
				break;
				break;
			}
			case 3:{
				break;
			}
			default:{
				cout<<"Default case\n";
				break;
			}
					
		}
	}while(choice != 3);
	cout<<"Exit!\n";
	
	system("PAUSE");
}
