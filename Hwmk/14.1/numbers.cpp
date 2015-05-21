//Kendall Small
//Implementation file for Numbers class


#include "numbers.h"
#include<iostream>
using namespace std;

Numbers::Numbers(int n)
{
	number = n;
	std::string Numbers::less20[20] = {"zero", "one", "two", "three", "four",
				  					"five", "six", "seven", "eight", "nine",
				  					"ten", "eleven", "twelve", "thirteen",
				  					"fourteen", "fifteen", "sixteen", "seventeen",
				  					"eighteen", "nineteen"};
	std::string Numbers::more20[8] = {"twenty", "thirty", "fourty", "fifty",
			  						"sixty", "seventy", "eighty", "ninety"};
	std::string Numbers::hundred = "hundred";
	std::string Numbers::thousand = "thousand";
}

void Numbers::print()
{ 
	if(number >= 1000){
		cout<<less20[number/1000];
		cout<<thousand;
		cout<<less20[(number%1000) / 100];
		cout<<hundred;
		cout<<more20[((number%100) / 10) - 2];
		cout<<less20[number%10];
	
	}
	
	else if(number >= 100){
		cout<<less20[(number%1000) / 100];
		cout<<hundred;
		cout<<more20[((number%100) / 10) - 2];
		cout<<less20[number%10];
	}
	
	else if(number >=20){
		cout<<more20[((number%100) / 10) - 2];
		cout<<less20[number%10];
	}
	
	else{
		cout<<less20[number];
	}	
		
}
