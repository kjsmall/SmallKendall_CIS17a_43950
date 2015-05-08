//Kendall Small		03/04/15 13:46


#include<iostream>
#include<iomanip>
using namespace std;


//Structure type for the rain and temperature variables
struct Weather
{
	float rain; //Total Rainfaull
	float hiTemp; //Highest Temperature
	float loTemp; //Lowest Temperature
	float avgTemp; //Average Temperature	
};

//Function prototypes
void fill(Weather [], int);
float avgR(Weather [], int);
float totRain(Weather [], int);
float highest(Weather [], int);
float lowest(Weather [], int);
float avgavg(Weather [], int);


int main()
{
	const int size = 12;
	Weather month[size];
	float avgRain, totalR, high, low, avg;
	
	fill(month, size);
	
	avgRain = avgR(month, size);
	totalR = totRain(month, size);
	high = highest(month, size);
	low = lowest(month, size);
	avg = avgavg(month,size);
	
	cout<<fixed<<setprecision(2);
	cout<<"The average rainfall per month was: "<<avgRain<<"	(Inches)\n"
		<<"The total rainfall for the year was: "<<totalR<<"	(Inches)\n"
		<<"The highest temperature for the year was: "<<high<<"	(Deg. Farenheit)\n"
		<<"The lowest temperature for the year was: "<<low<<"	(Deg. Farenheit)\n"
		<<"The average temperature for the year was: "<<avg<<"	(Deg. Farenheit)\n";	
	
	
	system("PAUSE");
	return 0;
}

//User input information
void fill(Weather month[],int size)
{
	for(int i=0;i<12;i++)
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

//Average rain per year
float avgR(Weather month[], int size)
{
	float total;
	
	for(int i=0;i<size;i++)
	{
		total = total + month[i].rain;
	}
	
	return (total / size);
}

//Total rain per year
float totRain(Weather month[], int size)
{
	float total;
	
	for(int i=0;i<size;i++)
	{
		total = total + month[i].rain;
	}
	
	return total;
}

//Highest temperature for the year
float highest(Weather month[], int size)
{
	float max = month[0].hiTemp;
	for(int i=1;i<size;i++)
	{
		if(month[i].hiTemp > max)
		{
			max = month[i].hiTemp;
		}
	}
	return max;
}

//Lowest temperature for the year
float lowest(Weather month[], int size)
{
	float min = month[0].loTemp;
	for(int i=1;i<size;i++)
	{
		if(month[i].loTemp < min)
		{
			min = month[i].loTemp;
		}
	}
	return min;
}

//Average of the average temperatures per month
float avgavg(Weather month[], int size)
{
	float total;
	for(int i=0;i<size;i++)
	{
		total += month[i].avgTemp;
	}
	return (total / size);
}
