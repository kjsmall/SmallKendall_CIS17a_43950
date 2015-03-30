//Kendall Small

using namespace std;
#include<iostream>
#include<iomanip>

float celsius(float);

int main()
{
    float faren, cels;
    
    cout<<"The temperatures of 0-20 in Farenheit, converted to celsius, are: \n\n";
    cout<<"Farenheit"<<setw(23)<<"Celsius\n\n";
    for(int i=0;i<21;i++)
    {
            faren = i;
            cels = celsius(faren);
            cout<<faren<<setw(30)<<cels<<endl;
    }
 
    system("PAUSE");
    return 0;    
}


float celsius(float temp) 
{
      float convert;
      convert = (5.f/9.f) * (temp - 32); 
      return convert;
}
      
      
