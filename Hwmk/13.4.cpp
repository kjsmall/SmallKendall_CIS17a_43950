//Kendall Small 	09/05/15 10:51


#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Info
{
	private:
		string name;
		string address;
		int age;
		char phone[10];
	public:
		void setName(string);
		void setAdrs(string);
		void setAge(int);
		void setNum(char []);
		void getName() const;
		void getAdrs() const;
		void getAge() const;
		void getPhone() const;
};


void Info::setName(string a)
{
	 name = a;
}

void Info::setAdrs(string a)
{
	address = a;
}

void Info::setAge(int a)
{
	age = a;
}

void Info::setNum(char a[])
{
	for(int i=0;i<10;i++)
	{
		phone[i] = a[i];
	}
}

void Info::getName() const
{
	cout<<name<<endl;
}

void Info::getAdrs() const
{
	cout<<address<<endl;
}

void Info::getAge() const
{
	cout<<age<<endl;
}

void Info::getPhone() const
{
	cout<<phone<<endl;
}


int main()
{
	Info person, frend, family;
	string name;
	string adress;
	int age;
	char phon[10];
	
	cout<<"Please enter info for three people: \n"
		<<"Enter info for yourself, a friend, or a family member:\n";
		
	cout<<"Person name: \n";
	getline(cin, name);
	person.setName(name);
	cout<<"Person address: \n";
	getline(cin, adress);
	person.setAdrs(adress);
	cout<<"Person age: \n";
	cin>>age;
	person.setAge(age);
	cout<<"Person phone number: \n";
	cin.ignore();
	cin.get(phon, 10);
	person.setNum(phon);
	cin.clear();
	cin.ignore(1000, '\n');
	
	
	cout<<"\nFriends name: \n";
	getline(cin, name);
	frend.setName(name);
	cout<<"Friends address: \n";
	getline(cin, adress);
	frend.setAdrs(adress);
	cout<<"Friends age: \n";
	cin>>age;
	frend.setAge(age);
	cout<<"Friends phone number: \n";
	cin.ignore();
	cin.get(phon, 10);
	frend.setNum(phon);
	cin.clear();
	cin.ignore(1000, '\n');	
	
	
	cout<<"\nFamily members name: \n";
	getline(cin, name);
	family.setName(name);
	cout<<"Family members address: \n";
	getline(cin, adress);
	family.setAdrs(adress);
	cout<<"Family members age: \n";
	cin>>age;
	family.setAge(age);
	cout<<"Family members phone number: \n";
	cin.ignore();
	cin.get(phon, 10);
	family.setNum(phon);
	cin.clear();
	cin.ignore(1000, '\n');
	
	
	cout<<endl<<endl;
	person.getName();
	person.getAdrs();
	person.getAge();
	person.getPhone();
	
	cout<<endl<<endl;
	frend.getName();
	frend.getAdrs();
	frend.getAge();
	frend.getPhone();
		
	cout<<endl<<endl;
	family.getName();
	family.getAdrs();
	family.getAge();
	family.getPhone();
	
	
	system("PAUSE");
	return 0;
}
