//Kendall Small		03/04/15 10:44

//Libraries
#include<iostream>
#include<string.h>
using namespace std;

//Global variables
struct Bureau 
{
	string name;
	char number[15];
	string topic;
	float fee;
};

//Function prototypes
void input(Bureau [], int, int);
void print(Bureau [], int, int);
void change(Bureau [],int, int);

int main()
{
	const int SIZE = 10;
	Bureau speaker[SIZE];
	int select,index = 0, element;
	
	do
	{
		cout<<"Please select an option: \n"
			<<"1. Enter speaker info\n"
			<<"2. Change the contents of an element\n"
			<<"3. Display the data stored in the array\n"
			<<"4. Exit\n";
		cin>>select;
		
		if(select==1)
		{
			input(speaker,SIZE, index);
			index++;				
		}
		
		else if(select==2)
		{
			cout<<"\nWhich speaker's info would you like to change?\n";
			for(int i=0;i<index;i++)
				cout<<i+1<<". "<<speaker[i].name<<"\n";
				
			cin>>element;
			while(element < 1 && element > 10)
			{
				cout<<"Error! Enter choose a speaker: \n";
				cin>>element;
			}
			element -= 1;
			change(speaker,SIZE,element);
			
		}
		
		else if(select == 3)
		{
			print(speaker,SIZE,index);
		}
		
		else if(select == 4)
		{
			cout<<"Exit! Bye!\n";
		}
		
		else
		{
			cout<<"You didn't choose an option. Try again.\n";
		}
			
	}while(select != 4);
	
	system("PAUSE");
	return 0;
}

//Enter information about a new speaker
void input(Bureau s[],int size, int i)
{
	cout<<"\nPlease enter the speakers name: \n";
	cin.ignore();
	getline(cin, s[i].name);
	cout<<"Please enter the speakers telephone number: \n";
	cin.getline(s[i].number,15);
	cout<<"Please enter the speakers topic: \n";
	getline(cin,s[i].topic);
	cout<<"Please enter the speakers fee: \n";
	cin>>s[i].fee;
	cin.ignore();
	cout<<endl;
}

//Change an element in any given speakers structure
void change(Bureau s[],int size, int i)
{
	int choice;
	cout<<"\nWhich element would you like to change: \n"
		<<"1. Name\n"
		<<"2. Phone number\n"
		<<"3. Topic\n"
		<<"4. Fee\n";
		
	cin>>choice;
	cin.ignore();
	while(choice<1 && choice>4)
	{
		cout<<"Error! Choose a valid selection from the menu: \n";
		cin>>choice;
		cin.ignore();
		cout<<endl;
	}
	
	if(choice==1)
	{
		cout<<"Enter the new/changed name for: "<<s[i].name<<endl;
		getline(cin,s[i].name);
		cout<<endl;
	}
	
	else if(choice==2)
	{
		cout<<"Enter the new/changed phone number for: "<<s[i].number<<endl;
		cin.getline(s[i].number,15);
		cout<<endl;
	}
	
	else if(choice==3)
	{
		cout<<"Enter the new/changed topic for: "<<s[i].topic<<endl;
		getline(cin,s[i].topic);
		cout<<endl;
	}
	
	else if (choice==4)
	{
		cout<<"Enter the new/changed fee for: "<<s[i].fee<<endl;
		cin>>s[i].fee;
		cin.ignore();
		cout<<endl;
	}	
}

//Print the contents of the array of structures
void print(Bureau s[], int size, int index)
{
	for(int i=0;i<index;i++)
	{
		cout<<"\nSpeaker #"<<i+1<<"\nName: "<<s[i].name<<"\nPhone Number: "<<s[i].number
			<<"\nTopic: "<<s[i].topic<<"\nFee: $"<<s[i].fee<<endl;
	}
	system("PAUSE");
	cout<<endl;
}




