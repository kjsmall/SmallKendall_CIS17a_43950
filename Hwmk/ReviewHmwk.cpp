// Kendall Small


// Libraries
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


// Fills the array with random numbers
void fill(int [], int);

// Prints the contents of the array
void print(int [], int);

// Prints the results of the binary search
void results(int);

int main()
{
    
    int size = 100,
        array[size],
        first = 0,
        last = size - 1,
        middle,
        position = -1, // first, last, middle, position, and also found variables for the binary search
        value = 50,
        temp;
    bool found = false, // swap and temp variables for the bubble sort
         swap;
    
    // fills the array with random numbers
    fill(array, size);
    
    // prints the contents of the array
    cout<<"The unsorted array: \n";
    print(array, size); 
    
    // bubble sort 
    do
    {
         swap = false;
         for (int count = 0; count < (size - 1); count++)
         {
             if(array[count] > array[count + 1])
             {
                             temp = array[count];
                             array[count] = array[count + 1];
                             array[count + 1] = temp;
                             swap = true;
             }
         }
    } while (swap); 
    
    cout<<endl<<endl<<endl<<"The sorted array: \n";
    print(array, size); //Prints the sorted array
    
    // binary search
    while (!found && first <= last)
    {
          middle = (first + last) / 2;
          if(array[middle] == value)
          {
                           found = true;
                           position = middle;
          }
          else if(array[middle] > value)
               last = middle - 1;
          else
              first = middle + 1;
    }
    
    // prints the results of the binary search
    results(position);            
        
    
    
    system("PAUSE");
    return 0;
}


void fill(int array[], int size)
{
     srand( time( NULL )); // using srand to get better randomization
     
     for(int count = 0; count < 100; count++)
    {
            array[count] = 10 + rand() % 90; // % 99 for only 2 digit numbers
    }
    
}


void print(int array[], int size)
{
     int col = 0;
     for(int num = 0; num < 100; num++)
    {
            cout << array[num] << setw(8);
            col++;
            if(col == 10)
            {
                   cout << "\n";
                   col = 0;
            }
    }
    
}

void results(int position)
{
     if(position == -1)
        cout << "\n\nThe number 50 was not found in the array.\n";
    else
        cout << "\n\nThe number 50 was found at position " << position << " of the array\n";
}


     
