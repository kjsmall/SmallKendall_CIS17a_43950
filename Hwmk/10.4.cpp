// Kendall Small	30/03/15 16:27

#include <iostream>
#include <cstring>
#include<iomanip>
using namespace std;

int wdCount(char *, int);
float ltCount(char *, int);

int main()
{
	char input[100];
	int size, numWrds;
	float avg;
	
	cout<<"Enter a phrase: \n";
	cin.get(input, 100);
	
	size = strlen(input);
	
	char *words = input;
	
	numWrds = wdCount(words, size);
		
	avg = ltCount(words, size);
	avg = avg / static_cast<float>(numWrds);
	
	
	cout<<setprecision(2);
	cout<<"The total number of words in your phrase is: "<<numWrds<<endl;
	cout<<"The average number of letters in each word is: "<<avg<<endl;
	
	system("PAUSE");
	return 0;
}

int wdCount(char *words,  int size)
{
	int total; 
	
	for(int i=0;i<size;i++)
		if(isspace(words[i]))
			total++;
			
	return (total + 1);
}

float ltCount(char *words, int size)
{
	float avg = size;
	
	for(int i=0;i<size;i++)
		if(isspace(words[i]))
			avg--;

	return avg;
}
