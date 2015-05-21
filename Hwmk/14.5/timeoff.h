//Kendall Small
//TimeOff class specification file


#ifndef TIMEOFF_H
#define TIMEOFF_H
#include "numdays.h"
#include<iostream>

class TimeOff{
	private:
		NumDays maxSickDays;
		NumDays sickTaken;
		NumDays maxVacation;
		NumDays vacTaken;
		NumDays maxUnpaid;
		NumDays unpaidTaken;
	public:
		TimeOff(float maxS, float takenS, float maxV,
				float takenV, float maxU, float takenU){
			maxSickDays.setHours(maxS);
			sickTaken.setHours(takenS);
			if(maxV > 240 || maxV < 0){
				std::cout<<"Error! Max number of paid vacation hours is 240.\n";
				maxVacation.setHours(0);
			}
			else
				maxVacation.setHours(maxV);
			vacTaken.setHours(takenV);
			maxUnpaid.setHours(maxU);
			unpaidTaken.setHours(takenU);
		}
		void sMaxSick(float a){
			maxSickDays.setHours(a);
		}
		void sSickTaken(float a){
			sickTaken.setHours(a);
		}
		void sMaxVac(float a){
			if(a>240 || a<0){
				std::cout<<"Error! Max number of paid vacation hours is 240.\n";
				maxVacation.setHours(0);
			}
			else
				maxVacation.setHours(a);
		}
		void sVacTaken(float a){
			vacTaken.setHours(a);
		}
		void sMaxUnp(float a){
			maxUnpaid.setHours(a);
		}
		void sUnpTaken(float a){
			unpaidTaken.setHours(a);
		}
		
		float gMaxSick(){
			return maxSickDays.getDays();
		}
		float gSickTaken(){
			return sickTaken.getDays();
		}
		float gMaxVac(){
			return maxVacation.getDays();
		}
		float gVacTaken(){
			return vacTaken.getDays();
		}
		float gMaxUnp(){
			return maxUnpaid.getDays();
		}
		float gUnpTaken(){
			return unpaidTaken.getDays();
		}
};

#endif
