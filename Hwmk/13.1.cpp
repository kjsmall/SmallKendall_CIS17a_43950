// Kendall Small	08/05/15 18:01


using namespace std;
#include<iostream>

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		void date1() const;
		void date2() const;
		void date3() const;	
};

void Date::setMonth(int m)
{
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setYear(int y)
{
	year = y;
}


void Date::date1() const
{
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}

void Date::date2() const
{
	if(month == 1)
		cout<<"January "<<day<<", "<<year<<endl;
	else if(month == 2)
		cout<<"February "<<day<<", "<<year<<endl;
	else if(month == 3)
		cout<<"March "<<day<<", "<<year<<endl;
	else if(month == 4)
		cout<<"April "<<day<<", "<<year<<endl;
	else if(month == 5)
		cout<<"May "<<day<<", "<<year<<endl;
	else if(month == 6)
		cout<<"June "<<day<<", "<<year<<endl;
	else if(month == 7)
		cout<<"July "<<day<<", "<<year<<endl;
	else if(month == 8)
		cout<<"August "<<day<<", "<<year<<endl;
	else if(month == 9)
		cout<<"September "<<day<<", "<<year<<endl;
	else if(month == 10)
		cout<<"October "<<day<<", "<<year<<endl;
	else if(month == 11)
		cout<<"November "<<day<<", "<<year<<endl;
	else if(month == 12)
		cout<<"December "<<day<<", "<<year<<endl;
		
}

void Date::date3() const
{
	if(month == 1)
		cout<<day<<" January "<<year<<endl;
	else if(month == 2)
		cout<<day<<" February "<<year<<endl;
	else if(month == 3)
		cout<<day<<" March "<<year<<endl;
	else if(month == 4)
		cout<<day<<" April "<<year<<endl;
	else if(month == 5)
		cout<<day<<" May "<<year<<endl;
	else if(month == 6)
		cout<<day<<" June "<<year<<endl;
	else if(month == 7)
		cout<<day<<" July "<<year<<endl;
	else if(month == 8)
		cout<<day<<" August "<<year<<endl;
	else if(month == 9)
		cout<<day<<" September "<<year<<endl;
	else if(month == 10)
		cout<<day<<" October "<<year<<endl;
	else if(month == 11)
		cout<<day<<" November "<<year<<endl;
	else if(month == 12)
		cout<<day<<" December "<<year<<endl;
}



int main()
{
	Date dates;
	int day, mon, year;
	
	cout<<"Please enter the day: \n";
	cin>>day;
	while(day > 31 || day < 1)
	{
		cout<<"Error! Enter value from 1 to 31: \n";
		cin>>day;
	}
	dates.setDay(day);
	cout<<"Please enter the month: \n";
	cin>>mon;
	while(mon > 12 || mon < 1)
	{
		cout<<"Error! Enter a value from 1 to 12: \n";
		cin>>mon;
	}
	dates.setMonth(mon);
	cout<<"Please enter the year: \n";
	cin>>year;
	dates.setYear(year);
	
	cout<<"\nThe formatted date is: \n";
	dates.date1();
	dates.date2();
	dates.date3();
	
}
