//number.cpp 
//Implementation file for number class

#include "number.h"


Number::Number(int a){
	size = a;
	array = new float[size];
	for(int i=0;i<size;i++){
		array[i] = 0;
	}
}

void Number::addNum(float number, int index){
	array[index] = number;
}
float Number::getNum(int index){
	return array[index];
}

float Number::getHigh(){	
	float max = array[0];
	for(int i=1;i<size;i++)
	{
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
}

float Number::getLow(){
	float min = array[0];
	for(int i=1;i<size;i++)
	{
		if(array[i]<min){
			min = array[i];
		}
	}
	return min;
}

float Number::getAvg(){
	int count = 0;
	for(int i=0;i<size;i++){
		count += array[i];
	}
	
	return (count / size);
}
