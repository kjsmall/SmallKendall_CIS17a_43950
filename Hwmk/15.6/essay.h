//Kendall Small
//Essay class specification file


#ifndef ESSAY_H
#define ESSAY_H
#include<iostream>
#include "gradedactivity.h"


class Essay : public GradedActivity{
	private:
		float grammar;
		float spelling;
		float length;
		float content;
	public:
		Essay()
			{ grammar = 0; spelling = 0; length = 0; content = 0; }
		
		void total(){
			float temp;
			temp = grammar+spelling+length+content;
			setScore(temp); }
		
		void setGram(float g){ 
			if(g <=30 && g >= 0)
				grammar = g;
			else
				std::cout<<"Erroneous input for grammar score!\n"; }
		void setSpell(float s){ 
			if(s <= 20 && s >= 0)
				spelling = s;
			else
				std::cout<<"Erroneous input for spelling score!\n"; }
		void setLen(float l){ 
			if(l <=20 && l>=0)
				length = l;
			else
				std::cout<<"Erroneous input for length score!\n"; }
		void setCon(float c){ 
			if(c<=30 && c>=0)
				content = c;
			else
				std::cout<<"Erroneous input for content score!\n"; }
};


#endif
