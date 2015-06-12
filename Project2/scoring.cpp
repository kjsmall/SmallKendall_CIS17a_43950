//Scoring implementation file


#include "scoring.h"
#include<iostream>
 
 
void Scoring::setRnds(){
	int temp;
	std::cout<<"How many rounds would you like to play?\n";
	std::cin>>temp;
	while(temp<1){
		std::cout<<"Please enter a value greater than 0:\n";
		std::cin>>temp;
	}
	rounds = temp;
}
int Scoring::getRnds(){
	return rounds;
}
int Scoring::getRnd(){
	return round;
}
void Scoring::getScore(){
	std::cout<<score<<" points, "<<wins<<" wins, "<<losses<<" losses.\n";
}

/*Scoring Scoring::operator++()
{
	++round;
	std::cout<<round<<std::endl;
	return *this;
}*/
