//Kendall Small 20/03/15 20:01

using namespace std;
#include<iostream>
#include<iomanip>

int *sort(int [], int);
int avg(int [], int);

int main()
{
	int numScors, average;
	
	cout<<"Please enter the number of scores to be averaged: \n";
	cin>>numScors;
	
	int *grades = new int[numScors];
	
	for(int i=0;i<numScors;i++)
	{
		cout<<"Please enter score "<<i+1<<":\n";
		cin>>grades[i];
		while(grades[i]<0){
			cout<<"Wrong!"<<endl<<"Please enter a nonnegative value: \n";
			cin>>grades[i];
		}
	}
	
	grades = sort(grades, numScors);
	
	cout<<"\nThe sorted array of grades: \n";
	for(int i=0;i<numScors;i++)
		cout<<*(grades+i)<< " \n";
		
	cout<<"\nThe lowest scoring test was: "<<grades[0]<<endl;
	
	average = avg(grades, numScors);
	cout<<"\nAfter dropping the lowest score, your final averaged grade is: "<<average<<endl;	
		
	system("PAUSE");
	return 0;
}


int *sort(int grades[], int size)
{
	int minVal, index;
	
	for(int i=0;i<size-1;i++)
	{
		index=i;
		minVal=grades[i];
		for(int j=i+1;j<size;j++)
		{
			if(grades[j] < minVal)
			{
				minVal=grades[j];
				index=j;
			}
		}
		grades[index]=grades[i];
		grades[i]=minVal;		
	}
	return grades;
}

int avg(int grades[], int size)
{
	int count = 0;
	cout<<"\nYour scores and their averages are: \n"
		<<"Score #:"<<setw(10)<<"Score: "<<setw(11)<<"Average: \n";
	for(int i=0;i<size;i++)
	{
		count += *(grades+i);
		cout<<i+1<<setw(15)<<*(grades+i)<<setw(10)<<count / (i+1);
		cout<<endl;
	}
	
	return ((count-grades[0]) / (size-1));
}

