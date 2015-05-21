//Kendall Small
//timeoff main


#include "timeoff.h"
#include "numdays.h"
#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	TimeOff time(200, 50, 240, 50, 200, 50);
	cout<<setprecision(2);
	int choice;
	do{
		cout<<"Menu: \n"
			<<"1. Print the employees time off info\n"
			<<"2. Set the maximum sick days for the employee\n"
			<<"3. Set the sick days taken for the employee\n"
			<<"4. Set the maximum vacation days for the employee\n"
			<<"5. Set the vacation days taken for the employee\n"
			<<"6. Set the Maximum unpaid vacation days for the employee\n"
			<<"7. Set the unpaid vacation days taken for the employee\n"
			<<"8. Get the maximum sick days for the employee\n"
			<<"9. Get the sick days taken for the employee\n"
			<<"10. Get the maximum vacation days for the employee\n"
			<<"11. Get the vacation days taken for the employee\n"
			<<"12. Get the maximum unpaid vacation days for the employee\n"
			<<"13. Get the unpaid vacation days taken for the employee\n"
			<<"14. Exit\n";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"The employees sick, vacation, and unpaid vacation information: \n";
				cout<<"Maximum sick days: "<<time.gMaxSick()<<endl;
				cout<<"Sick days taken: "<<time.gSickTaken()<<endl;
				cout<<"Maximum vacation days: "<<time.gMaxVac()<<endl;
				cout<<"Vacation days taken: "<<time.gVacTaken()<<endl;
				cout<<"Max unpaid vacation days: "<<time.gMaxUnp()<<endl;
				cout<<"Unpaid vacation days taken: "<<time.gUnpTaken()<<endl;
				break;
			}
			case 2:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sMaxSick(a);
				break;
			}
			case 3:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sSickTaken(a);
				break;
			}
			case 4:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sMaxVac(a);
				break;
			}
			case 5:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sVacTaken(a);
				break;
			}
			case 6:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sMaxUnp(a);
				break;
			}
			case 7:{
				float a;
				cout<<"Enter a value in hours: \n";
				cin>>a;
				time.sUnpTaken(a);
				break;
			}
			case 8:{
				cout<<"Max sick days: "<<time.gMaxSick()<<endl;
				break;
			}
			case 9:{
				cout<<"Taken sick days: "<<time.gSickTaken()<<endl;
				break;
			}
			case 10:{
				cout<<"Max vacation days: "<<time.gMaxVac()<<endl;
				break;
			}
			case 11:{
				cout<<"Taken vacation days: "<<time.gVacTaken()<<endl;
				break;
			}
			case 12:{
				cout<<"Max unpaid vacation days: "<<time.gMaxUnp()<<endl;
				break;
			}
			case 13:{
				cout<<"Taken unpaid vacation days: "<<time.gUnpTaken()<<endl;
				break;
			}
			case 14:{
				cout<<"Bye!\n";
				break;
			}
			default:{
				cout<<"Erroneous input!!\n";
				break;
			}
		}
	}while(choice != 14);	
	system("PAUSE");
	return 0;	
}
