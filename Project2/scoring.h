//Scoring class header file


#ifndef SCORING_H
#define SCORING_H


class Scoring{
	protected:
		static int rounds;
		static int round;
		int score;
		int wins;
		int losses;
	public:
		Scoring() { round = 0; }
		static int getRnds();
		static int getRnd();
		void getScore();//This will just cout the scores in a table p1 and p2, that way I dont need
						 //functions to set and get each value for each player
		static void setRnds();
};



#endif
