//Kendall Small
//DayYear2 modified DayYear class implementation file

#include "dayyear2.h"
#include<iostream>
#include<string>
using namespace std;

	std::string DayYear2::month[12] = {"January", "February",
								"March", "April", "May", "June",
								"July", "August", "September",
								"October", "November", "December"};
	
							
	DayYear2::DayYear2(int n)
	{
		day = n;
	}
	
	void DayYear2::simplify(){
		if(day >= 366){
			day = day%365;
		}
		else if(day <= 0){
			day += 365;
		}
	}
	
	DayYear2 DayYear2::operator++(){
		++day;
		simplify();
		return *this;
	}
	
	DayYear2 DayYear2::operator++(int){
		DayYear2 temp(day);
		day++;
		simplify();
		return temp;
	}
	
	DayYear2 DayYear2::operator--(){
		--day;
		simplify();
		return *this;
	}
	
	DayYear2 DayYear2::operator--(int){
		DayYear2 temp(day);
		day--;
		simplify();
		return temp;
	}
	
	DayYear2::DayYear2(string a, int b)
	{
		bool check = false;
		if(day < 1){
			cout<<"Invalid value given for day! Bye!\n";
			exit(0);
		}
		for(int i=0;i<12;i++){
			if(a == month[i]){
				check = true;
				if(i==0){
					if(b > 31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b;
				}
				else if(i==1){
					if(b > 28){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 31;
				}
				else if(i==2){
					if(b > 31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 59;
				}
				else if(i==3){
					if(b>30){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 90;
				}
				else if(i==4){
					if(b>31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 120;
				}
				else if(i==5){
					if(b>30){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 151;
				}
				else if(i==6){
					if(b>31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 181;
				}
				else if(i==7){
					if(b>31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 212;
				}
				else if(i==8){
					if(b>30){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 243;
				}
				else if(i==9){
					if(b>31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 273;
				}
				else if(i==10){
					if(b>30){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 304;
				}
				else if(i==11){
					if(b>31){
						cout<<"Invalid day for the given month!\n";
						exit(0);
					}
					day = b + 334;
				}
			}
		}
		
		if(check == false){
			cout<<"You entered an invalid month! Bye!\n";
			exit(0);
		}
		
		else
			cout<<a<<" "<<b<<" is the "<<day<<" day of the year\n";
	}
	
		
	void DayYear2::print()
	{
		if(day>0&&day<=31){
			cout<<month[0]<<" "<<day<<endl;
		}
		else if(day>31&&day<=59){
			cout<<month[1]<<" "<<day - 31<<endl;
		}
		else if(day>59&&day<=90){
			cout<<month[2]<<" "<<day - 59<<endl;
		}
		else if(day>90&&day<=120){
			cout<<month[3]<<" "<<day - 90<<endl;
		}
		else if(day>120&&day<=151){
			cout<<month[4]<<" "<<day - 120<<endl;
		}
		else if(day>151&&day<=181){
			cout<<month[5]<<" "<<day - 151<<endl;
		}
		else if(day>181&&day<=212){
			cout<<month[6]<<" "<<day - 181<<endl;
		}
		else if(day>212&&day<=243){
			cout<<month[7]<<" "<<day - 212<<endl;
		}
		else if(day>243&&day<=273){
			cout<<month[8]<<" "<<day - 243<<endl;
		}
		else if(day>273&&day<=304){
			cout<<month[9]<<" "<<day - 273<<endl;
		}
		else if(day>304&&day<=334){
			cout<<month[10]<<" "<<day - 304<<endl;
		}
		else if(day>334&&day<=365){
			cout<<month[11]<<" "<<day - 334<<endl;
		}
		else
			cout<<"What the heck?\n";
	}
	
