//Kendall Small

using namespace std;
#include<iostream>

int main()
{
    int begOrg, avgIncr, days, count;
    
    
    cout<<"Please input the number of starting organisms: \n";
    cin>>begOrg;
    while(begOrg<2)
    {
        cout<<"Error! Please enter a value greater than 1: \n";
        cin>>begOrg;
    }
    
    cout<<"Please enter the average daily increase in organism population "
        <<"as a percent\n";
    cin>>avgIncr;
    while(avgIncr<0)
    {
        cout<<"Error! Please enter a nonnegative value: \n";
        cin>>avgIncr;
    }
    
    cout<<"Please enter the number of days that the organisms will multiply: \n";
    cin>>days;
    while(days<1)
    {
        cout<<"Error! Please enter a value greater than 0: \n";
        cin>>days;
    }
    
    cout<<"The total number of organisms per day is: \n";
    count = begOrg;
    for(int i=0;i<days;i++)
    {
    
        cout<<"Day " << i+1 << ": " << count << endl;
        count = count + (count * (avgIncr / 100));
        
    }
    
    system("PAUSE");
    return 0;
}
    
    
