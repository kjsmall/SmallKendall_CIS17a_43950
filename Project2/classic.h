//Kendall Small
//Classic class for playing against a computer


#ifndef CLASSIC_H
#define CLASSIC_H
#include "master.h"
#include <iostream>


class Classic : public Master {
	private:				
		int win;				
		static int turn;
		static int numTurn;
	public:
		Classic();		
		Classic(int a);
		~Classic()
			{ delete [] game.code; delete [] play; }
		virtual void setCode();
		virtual void setCode2();
		void codeIn();
		void save();
		void save2P(std::string);
		void load();
		void load2P(std::string);
		void rules();
		void board();
		void match();
		bool match2p();
		bool move();
		bool move2p();
		bool won();
		void fdBack();
		int getGues();
		
		static void setNumT();
		static void turn2P(int);
		static int getTurn();
};


#endif
