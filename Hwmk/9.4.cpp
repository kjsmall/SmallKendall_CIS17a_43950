//Kendall Small 20/03/15 20:01

using namespace std;
#include<iostream>
#include<iomanip>
#include<string.h>

void sort(int [],string[], int);


int main()
{
	int numScors, average;
	
	
	cout<<"Enter the number of students/scores to be input: \n";
	cin>>numScors;
	
	int *grades = new int[numScors];
	string *names = new string[numScors];
	
	for(int i=0;i<numScors;i++)
	{
		cin.ignore();
		cout<<"\nEnter the name of student "<<i+1<<":\n";
		getline(cin, *(names+i));
		cout<<"Please enter score "<<i+1<<":\n";
		cin>>grades[i];
		while(grades[i]<0){
			cout<<"Wrong!"<<endl<<"Please enter a nonnegative value: \n";
			cin>>grades[i];
		}
		
	}
	
	sort(grades, names, numScors);
	
	cout<<"\nThe sorted array of grades and names: \n";
	for(int i=0;i<numScors;i++){
		cout<<*(names+i)<<setw(30)<<*(grades+i)<<endl;
	}
		
		
	system("PAUSE");
	return 0;
}


void sort(int grades[], string names[], int size)
{
	int minVal, index;
	string swap;
	
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
		swap=names[index];
		names[index]=names[i];
		names[i]=swap;		
	}

}
