//Kendall Small 21/03/15 11:57

using namespace std;
#include<iostream>

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
	int NUM_DONATIONS; // Number of donations
	
	cout<<"Please input the number of donations to be entered: \n";
	cin>>NUM_DONATIONS;
	
	// An array containing the donation amounts.
	int *donations = new int[NUM_DONATIONS];
	
	cout<<"\nPlease enter the value of each donation: \n";
	for(int i=0;i<NUM_DONATIONS;i++)
	{
		cout<<"Donation #"<<i+1<<": ";
		cin>>donations[i];
	}

	// An array of pointers to int.
	int *arrPtr[NUM_DONATIONS];

	// Each element of arrPtr is a pointer to int. Make each
	// element point to an element in the donations array.
	for (int count = 0; count < NUM_DONATIONS; count++)
		arrPtr[count] = &donations[count];

	// Sort the elements of the array of pointers.
	arrSelectSort(arrPtr, NUM_DONATIONS);

	// Display the donations using the array of pointers. This
	// will display them in sorted order.
	cout << "\nThe donations, sorted in descending order, are: \n";
	showArrPtr(arrPtr, NUM_DONATIONS);

	// Display the donations in their original order.
	cout << "\nThe donations, in their original order, are: \n";
	showArray(donations, NUM_DONATIONS);
	return 0;
}




void arrSelectSort(int *arr[], int size)
{
	int startScan, minIndex;
	int *minElem;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = arr[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (*(arr[index]) > *minElem)
			{
			minElem = arr[index];
			minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minElem;
	}
}



void showArray(const int arr[], int size)
{
	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}


void showArrPtr(int *arr[], int size)
{
 	for (int count = 0; count < size; count++)
		cout << *(arr[count]) << " ";
	cout << endl;
 }
