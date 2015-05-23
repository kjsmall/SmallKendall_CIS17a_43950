//Kendall Small
//Customer class specification file

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "person.h"
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>

class Customer : public Person{
	private:
		std::string custNum;
		bool mailLst;
	public:
		void setNum()
		{ srand(static_cast<unsigned int>(time(NULL)));
		  char a[6];
		  for(int i=0;i<6;i++){
		  	a[i] = (rand()%10)+48;
			//std::cout<<"Testing: "<<a[i]<<std::endl;	
		  }
		  std::string b(a);
		  custNum = b;		  
		}
		void setMail(bool m)
		{ mailLst = m; }
		std::string getNum()
		{ return custNum; }
		bool getMail()
		{ return mailLst; }  
};

#endif
