//Kendall Small
//Main file DayYear class


#include "dayyear.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int day;
	char again = 'N';
	do{	
		cout<<"Enter a day of the year (0-365): \n";
		cin>>day;
		while(day < 0 && day > 365){
			cout<<"Error! Value outside of specified range. Try again.\n";
			cin>>day;
		}
		DayYear date(day);
		date.print();
		cout<<"Again? (Y to try again, anything else to exit)\n";
		cin>>again;
		cout<<endl;
	}while(toupper(again) == 'Y');
	cout<<"Exit!\n";
	
	system("PAUSE");
	return 0;	
}
