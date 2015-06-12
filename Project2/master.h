//I need a virtual class so how about a basic game class
// and then two classes, one for cpu play and one for
// 2 player


#ifndef MASTER_H
#define MASTER_H
#include<string>

struct Game{
	int numTurn;
	int count;
	char *code;
	int SIZE;
	int guesses;
};

struct Ply{
	char slot[4];
	std::string fslot[4];
};

class Master {
	protected:
		Game game;
		Ply* play;
	public: 
		
	virtual void setCode() = 0;     	
};

#endif
