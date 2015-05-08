//Kendall Small		03/04/15 15:40

//Libraries
#include<iostream>
#include<iomanip>
using namespace std;

//Enum to step through arrays
enum Months {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER,
				OCTOBER, NOVEMBER, DECEMBER};

struct Weather
{
	float rain; //Total Rainfaull
	float hiTemp; //Highest Temperature
	float loTemp; //Lowest Temperature
	float avgTemp; //Average Temperature	
};

//Function prototypes
void fill(Weather [], Months, int);
float avgR(Weather [], Months, int);
float totRain(Weather [], Months, int);
float highest(Weather [], Months, int);
float lowest(Weather [], Months, int);
float avgavg(Weather [], Months, int);


int main()
{
	const int size = 12;
	Weather month[size];
	Months name = JANUARY;
	float avgRain, totalR, high, low, avg;
	
	fill(month, name, size);
	
	avgRain = avgR(month, name, size);
	totalR = totRain(month, name, size);
	high = highest(month, name, size);
	low = lowest(month, name, size);
	avg = avgavg(month, name,size);
	
	cout<<fixed<<setprecision(2);
	cout<<"The average rainfall per month was: "<<avgRain<<"	(Inches)\n"
		<<"The total rainfall for the year was: "<<totalR<<"	(Inches)\n"
		<<"The highest temperature for the year was: "<<high<<"	(Deg. Farenheit)\n"
		<<"The lowest temperature for the year was: "<<low<<"	(Deg. Farenheit)\n"
		<<"The average temperature for the year was: "<<avg<<"	(Deg. Farenheit)\n";	
	
	
	system("PAUSE");
	return 0;
}

//User inputs info
void fill(Weather month[], Months name, int size)
{
	for(int i=JANUARY;i<=DECEMBER;i++)
	{
		cout<<"Please enter the total rainfall (inches) for month: "<<i+1<<endl;
		cin>>month[i].rain;
		cout<<"Please enter the highest temperature (farenheit) for month: "<<i+1<<endl;
		cin>>month[i].hiTemp;
		while(month[i].hiTemp < -100 || month[i].hiTemp > 140)
		{
			cout<<"Error! Please enter a temperature (farenheit) between -100 and 140: \n";
			cin>>month[i].hiTemp;
		}
		cout<<"Please enter the lowest temperature (farenheit) for month: "<<i+1<<endl;
		cin>>month[i].loTemp;
		while(month[i].loTemp < -100 || month[i].loTemp > 140)
		{
			cout<<"Error! Please enter a temperature (farenheit) between -100 and 140\n";
		}
		cout<<"Please enter the average temperature (farenheit) for month: "<<i+1<<endl;
		cin>>month[i].avgTemp;
		while(month[i].avgTemp < -100 || month[i].avgTemp > 140)
		{
			cout<<"Error! Please enter a temperature (farenheit) between -100 and 140\n";
			cin>>month[i].avgTemp;
		}
		cout<<endl;
	}
}

//Average rainfaill for the year
float avgR(Weather month[], Months name, int size)
{
	float total;
	
	for(int i=JANUARY;i<=DECEMBER;i++)
	{
		total = total + month[i].rain;
	}
	
	return (total / size);
}

//Total rainfall for the year
float totRain(Weather month[], Months name, int size)
{
	float total;
	
	for(int i=JANUARY;i<=DECEMBER;i++)
	{
		total = total + month[i].rain;
	}
	
	return total;
}

//Highest temperature for the year
float highest(Weather month[], Months name, int size)
{
	float max = month[0].hiTemp;
	for(int i=(JANUARY+1);i<=DECEMBER;i++)
	{
		if(month[i].hiTemp > max)
		{
			max = month[i].hiTemp;
		}
	}
	return max;
}

//Lowest temperature for the year
float lowest(Weather month[], Months name, int size)
{
	float min = month[0].loTemp;
	for(int i=(JANUARY+1);i<=DECEMBER;i++)
	{
		if(month[i].loTemp < min)
		{
			min = month[i].loTemp;
		}
	}
	return min;
}

//Average temperature, of the average temperature per month
float avgavg(Weather month[], Months name, int size)
{
	float total;
	for(int i=JANUARY;i<=DECEMBER;i++)
	
	{
		total += month[i].avgTemp;
	}
	return (total / size);
}
