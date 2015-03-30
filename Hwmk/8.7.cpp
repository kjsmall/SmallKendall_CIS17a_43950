// Kendall Small 19/03/15 15:16
/*
Modify the binarySearch function presented in this 
chapter so it searches an arrayof strings instead of 
an array of ints. Test the function with a driver program. 
UseProgram 8-8 as a skeleton to complete. 
(The array must be sorted before the binarysearch will work.)
*/

#include <iostream>
#include <string>  
using namespace std;  

int main()  
{       
	const int NUM_NAMES = 20;       
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",                                  
							   "Griffin, Jim", "Stamey, Marty", "Rose, Geri",                                  
							   "Taylor, Terri", "Johnson, Jill",                                 
							   "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",                                  
							   "James, Jean", "Weaver, Jim", "Pore, Bob",                                  
							   "Rutherford, Greg", "Javens, Renee",                                  
							   "Harrison, Rose", "Setzer, Cathy",                                  
							   "Pike, Gordon", "Holland, Beth" }; 
	
	
	int i, minIndx;
	string minVal;
	for(i=0;i<(NUM_NAMES - 1);i++)
	{
		minIndx = i;
		minVal = names[i];
		for(int j=i+1;j<NUM_NAMES; j++)
		{
			if(names[j] < minVal)
			{
				minVal = names[j];
				minIndx = j;
			}
		}
		names[minIndx] = names[i];
		names[i] = minVal;
	}
	cout<<endl<<endl;
	
	for(int i=0;i<NUM_NAMES;i++)
		cout<<names[i]<<endl;
		
		
		
	int first = 0,
		last = NUM_NAMES - 1,
		middle,
	    position = -1;
	bool found = false;
	string search;
	
	cout<<"Please enter a name to search for: \n";
	cin>>search;
	
	while(!found && first <= last)
	{
		middle = (first + last) / 2;
		if(names[middle] == search)
		{
			found = true;
			position = middle;
		}
		else if(names[middle] > search)
			last = middle - 1;
		else
			first = middle + 1;
	}
	cout<<position;
	if(position == -1)
		cout<<"That name was not found\n";
	else 
		cout<<"That name is located at the " << position << "position in the array\n";
		   
								 
								 
	system("PAUSE");							 
	return 0;
}
