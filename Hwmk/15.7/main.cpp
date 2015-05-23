//Kendall Small
//person and customer class main file

#include "customer.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


int main()
{
	int size;
	string temp;
	bool mailer;
	int yn;
	cout<<"How many customers?\n";
	cin>>size;
	cin.clear();
	cin.ignore(10000, '\n');
	
	Customer id[size];
	for(int i=0;i<size; i++){
		cout<<"Enter information for customer "<<i+1<<":\n"
			<<"Last Name: \n";
		getline(cin, temp);
		id[i].setLast(temp);
		cout<<"First Name: \n";
		getline(cin, temp);
		id[i].setFirst(temp);
		cout<<"Address: \n";
		getline(cin, temp);
		id[i].setAdrs(temp);
		cout<<"City: \n";
		getline(cin, temp);
		id[i].setCity(temp);
		cout<<"State: \n";
		getline(cin, temp);
		id[i].setStat(temp);
		cout<<"Zip: \n";
		getline(cin, temp);
		id[i].setZip(temp);
		cout<<"Phone Number: (Ex. 555-555-5555)\n";
		getline(cin, temp);
		id[i].setPhon(temp);
		cout<<"Enter 1 to be on the mailing list, any other number for no\n";
		cin>>yn;
		if(yn == 1){
			mailer = true;
			id[i].setMail(mailer);
		}
		else{
			mailer = false;
			id[i].setMail(mailer);
		}
		id[i].setNum();
	}
	
	cout<<"Customer Information:\n";
	for(int i=0;i<size;i++){
		bool tmp = id[i].getMail();
		cout<<"Name: "<<setw(25)<<id[i].getLast()<<", "<<id[i].getFirst()<<endl
			<<"Address: "<<setw(34)<<id[i].getADrs()<<endl
			<<"City: "<<setw(37)<<id[i].getCity()<<endl
			<<"State: "<<setw(36)<<id[i].getStat()<<endl
			<<"Zip: "<<setw(38)<<id[i].getZip()<<endl
			<<"Phone: "<<setw(36)<<id[i].getPhon()<<endl
			<<"Customer Number: "<<setw(26)<<id[i].getNum()<<endl
			<<"Mailer: ";
		if(tmp == true)
			cout<<setw(35)<<"Yes";
		else
			cout<<setw(35)<<"No";
		cout<<endl<<endl;
	}
	

	
	system("PAUSE");
	return 0;
}
