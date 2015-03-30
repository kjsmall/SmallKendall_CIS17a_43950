// Kendall Small

using namespace std;
#include<iostream>
#include <iomanip>

int main()
{
    string month;
    int year;
    float t, s, cTax, sTax, tax; // Defined variables to hold the values for
                                 // the output at the end of the program.
    
    cout << "Please enter the month: \n";
    cin >> month;
    
    cout << "\nPlease enter the year: \n";
    cin >> year;
    
    cout << "\nPlease enter the total amount of product sales before tax: \n";
    cin >> s;
    
    t = s + (s * .06);
    cTax = s * .02;
    sTax = s * .04;
    tax = s * .06;  // State tax is 4%, county tax is 2%, total is 6%
    
    cout << fixed << setprecision(2);
    
    cout << "\nMonth: " << month << "\n-------------------------"
         << "\nTotal Collected: " << setw(20) << "$" << setw(10) << t
         << "\nProduct Sales: " << setw(30) << "$" << setw(10) << s
         << "\nCounty Sales Tax: " << setw(19) << "$" << setw(10) << cTax
         << "\nState Sales Tax: " << setw(20) << "$" << setw(10) << sTax
         << "\nTotal Sales Tax: " << setw(20) << "$" << setw(10) << tax << endl;
         
    system("PAUSE");
    return 0;
}
    

