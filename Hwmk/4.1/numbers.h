// Kendall Small
//Number class specification file


#ifndef NUMBERS_H
#define NUMBERS_H
#include<string>
#include<iostream>
using namespace std;

class Numbers
{
	private:
		int number;
		static std::string less20[20];
		static std::string more20[8];
		static std::string hundred;
		static std::string thousand;
		
	public:
		Numbers(int n)
		{number = n;}
		void print()
		{
			if(number >= 1000){
				cout<<less20[number/1000]<<" "<<thousand<<" ";
				if((number%1000) == 0)
				{
					cout<<"What the hell\n";
					
				}
				cout<<less20[(number%1000) / 100]<<" ";
				cout<<hundred<<" ";
				if(number%100==0){break;}
				
				cout<<more20[((number%100) / 10) - 2]<<" ";
				if(number%10==0){break;}
				
				cout<<less20[number%10]<<" ";
			}
			
			else if(number >= 100){
				cout<<less20[(number%1000) / 100]<<" ";
				cout<<hundred<<endl;
				if(number%100==0){break;}
				cout<<more20[((number%100) / 10) - 2]<<" ";
				if(number%10==0){break;}
				cout<<less20[number%10]<<" ";
			}
			
			else if(number >=20){
				cout<<more20[((number%100) / 10) - 2]<<" ";
				if(number%10==0){break;}
				cout<<less20[number%10]<<" ";
			}
			
			else{
				cout<<less20[number];
			}
		}
};

	std::string Numbers::less20[20] = {"zero ", "one ", "two ", "three ", "four ",
				  					"five ", "six ", "seven ", "eight ", "nine ",
				  					"ten ", "eleven ", "twelve ", "thirteen ",
				  					"fourteen ", "fifteen ", "sixteen ", "seventeen ",
				  					"eighteen ", "nineteen "};
	std::string Numbers::more20[8] = {"twenty ", "thirty ", "fourty ", "fifty ",
			  						"sixty ", "seventy ", "eighty ", "ninety "};
	std::string Numbers::hundred = "hundred ";
	std::string Numbers::thousand = "thousand ";

#endif
