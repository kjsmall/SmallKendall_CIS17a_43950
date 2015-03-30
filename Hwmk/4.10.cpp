// Kendall Small

using namespace std;
#include <iostream>
#include <iomanip>


int main()
{
    int quantity;
    float discount, cost;
    
    cout << "Welcome to Software Company!\n";
    cout << "We offer a quality software package for only $99!\n";
    cout << "Check the table below to find out about our discounts!\n";
    
    cout << "\n************************************************************\n"
         << " Quantity" << setw(30) << "Discount\n"
         << "------------------------------------------------------------\n"
         << " 10-19" << setw(28) << "20%\n"
         << " 20-49" << setw(28) << "30%\n"
         << " 50-99" << setw(28) << "40%\n"
         << " 100+" << setw(29) << "50%\n"
         << "************************************************************\n"
         << "\nHow many would you like to purchase? ";
    cin >> quantity;
    
    do 
    {
        if (quantity <= 0)
        {
           cout << "\nYou must purchase at least one item!\n";
           cin >> quantity;
        }
    }while(quantity <= 0);
    
    cost = 99 * quantity;
    
    if (quantity > 9 && quantity < 20)
       cost = cost - (cost * .20);
       
    else if (quantity > 19 && quantity < 50 )
       cost = cost - (cost * .20);
       
    else if (quantity > 49 && quantity < 100)
       cost = cost - (cost * .20);
       
    else if (quantity > 100)
       cost = cost - (cost * .20);
    
    cout << fixed << setprecision(2);
       
    cout << "The total cost of your purchase is: $" << cost << endl;
    
    system("PAUSE");
    return 0;
    
}   
