// Kendall Smal

using namespace std;
#include<iostream>
#include <iomanip>

int main()
{
    float real, assess, tax; // Real value, Assessment value, and property tax
    
    cout << "Please enter the actual value of the property: \n";
    cin >> real;
    
    assess = real * .60; // The assessment value is 60% of the actual value
    tax = assess * .0064;
    
    cout << fixed << setprecision(2);
    
    cout << "\nActual Value: " << setw(20) << "$" << setw (10) << real
         << "\nAssessment Value: " << setw(16) << "$" << setw (10) << assess 
         << "\nProperty Tax: " << setw(20) << "$" << setw (10) << tax << endl;
         
    system("PAUSE");
    return 0;
}
