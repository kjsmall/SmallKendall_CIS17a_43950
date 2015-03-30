//Kendall Small 19/03/15 13:25


/* Write a program that asks the user for a file name. 
Assume the file contains a series of numbers, each written on a separate line. 
The program should read the contents of the file into an array and then display the 
following data:
Lowest number
Highest number
Total of numbers
Average of numbers*/



using namespace std;
#include<iostream>
#include<fstream>

int main()
{
	ifstream inFile;
	string fName;
	int numbers [100];
	int number, size = 0;
	
	cout<<"Please enter a file name to be opened: \n";
	cin>>fName;
	
	inFile.open(fName.c_str());
	
	while(inFile >> number ){
	cout << number << " ";
	numbers[size] = number;
	size++;
	}
	
	cout<<endl<<endl;
	
	for(int i = 0; i<(size);i++)
		cout<<numbers[i]<<" ";
		
		
	system("PAUSE");
	return 0;
	
}
