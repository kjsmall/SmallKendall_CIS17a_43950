//number.h header file
//Specification file for Number class


#ifndef NUMBER_H
#define NUMBER_H


class Number {
	private:
		int size;
		float *array;
	public:
		Number(int);
		void addNum(float, int);
		const float getNum(int);
		const float getHigh();
		const float getLow();
		const float getAvg();
		~Number()
		{ delete [] array; }
};


#endif
