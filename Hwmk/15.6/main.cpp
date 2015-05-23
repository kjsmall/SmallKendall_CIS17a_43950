//Kendall Small
//Essay class implementation


#include "essay.h"
#include<iostream>
using namespace std;

int main()
{
	Essay essay;
	float temp;
	
	cout<<"Enter the score for grammar: \n";
	cin>>temp;
	essay.setGram(temp);
	cout<<"Enter the score for spelling: \n";
	cin>>temp;
	essay.setSpell(temp);
	cout<<"Enter the score for correct length: \n";
	cin>>temp;
	essay.setLen(temp);
	cout<<"Enter the score for content: \n";
	cin>>temp;
	essay.setCon(temp);
	essay.total();
	cout<<"The final score is: "<<essay.getScore()<<endl;
	cout<<"The final grade is: "<<essay.getLetterGrade()<<endl;
	
	system("PAUSE");
	return 0;
}
