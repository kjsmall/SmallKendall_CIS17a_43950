//Kendall Small
//Implementation file for Cpu class


#include "classic.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;

int Classic::turn=0;
int Classic::numTurn=0;

Classic::Classic()			//Default constructor
{
	game.numTurn = numTurn;
	game.SIZE=4;
	game.count=0;
	game.guesses=0; //Opposite players guesses;EX. this is p1 class so p1 sets code but it holds p2 guesses
	play = new Ply[game.numTurn];
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<game.SIZE;j++)
		{
			play[i].slot[j] = 'X';
			play[i].fslot[j] = "Empty";
		}
	}
}
		
Classic::Classic(int a)		//Constructor that takes an int to set numTurn
{
	game.numTurn=a; 
	game.SIZE = 4;
	game.count=0;
	game.guesses=0;
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<game.SIZE;j++)
		{
			play[i].slot[j] = 'X';
			play[i].fslot[j] = "Empty";
		}
	} 
}


void Classic::setCode() //Random generated code
{
	game.code = new char[game.SIZE];
	for(int i=0;i<game.SIZE;i++)
	{ 
		game.code[i] = rand()%5+1;
	}
	
	for(int i=0;i<game.SIZE;i++)
	{
		if(game.code[i] == 1)
		{
			game.code[i] = 'B';
		}
		if(game.code[i] == 2)
		{
			game.code[i] = 'G';
		}
		if(game.code[i] == 3)
		{
			game.code[i] = 'O';
		}
		if(game.code[i] == 4)
		{
			game.code[i] = 'P';
		}
		if(game.code[i] == 5)
		{
			game.code[i] = 'R';
		}
		if(game.code[i] == 6)
		{
			game.code[i] = 'Y';
		}
	}
	//cout<<(game.code);	//If you want to see the code for testing purposes.
	std::cout<<std::endl;
}


void Classic::setCode2(){ 		//Man made code
	game.code = new char[game.SIZE];
	char confirm;
	do{
		cout<<"\n\nPlayer "<<turn+1<<" will be the codemaker this round\n"
			<<"\n**Dont let the other player see your code!**\n"
			<<"**Write your code down so that you can remember it!**\n\n"
			<<"Your code may consist of any combination of:\n"
			<<"B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n";
		for(int i=0;i< 4;i++){
			cout<<"Enter code slot "<<i+1<<":\n";
			cin>>game.code[i];
			game.code[i] = toupper(game.code[i]);
		}
		cout<<"Your code is: "<<game.code<<"\n"
			<<"Enter Y to confirm this code, any other letter to re-do:\n";
		cin>>confirm;
	}while(toupper(confirm) != 'Y');
}

void Classic::save()		//One player save
{
	std::fstream file;
	char temp[5];					
	
	file.open("csave.txt", ios::out | ios::binary);
	if (!file)
	{
		std::cout << "Error opening file. Program aborting.\n";
		exit(0);
	}

	file.seekp(0, ios::beg);
	
	file.write(reinterpret_cast<char *>(&game.count), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.numTurn), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.SIZE), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.guesses), sizeof(game.guesses));
	
	for(int i=0;i<game.SIZE;i++)
	{
		file.write(reinterpret_cast<char *>(&game.code[i]), sizeof(1));
	}
	
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<4;j++)
		{
			file.write(reinterpret_cast<char *>(&play[i].slot[j]), sizeof(1));
		}
	}
	for(int i=0;i<game.numTurn;i++)
	{		
		for(int j=0;j<game.SIZE;j++)
		{
			strcpy(temp, play[i].fslot[j].c_str());
			file.write(reinterpret_cast<char *>(&temp), sizeof(temp));
			
		}		
	}
	
	file.close();
	file.clear();
	
	std::cout<<"Successfully saved to file.\n";	
}

void Classic::save2P(string b)			//Two player save
{
	std::fstream file;
	char temp[5];					

	file.open(b.c_str(), ios::out | ios::binary);
	if (!file)
	{
		std::cout << "Error opening file. Program aborting.\n";
		exit(0);
	}

	file.seekp(0, ios::beg);
	file.write(reinterpret_cast<char *>(&win), sizeof(win));
	file.write(reinterpret_cast<char *>(&turn), sizeof(turn));
	file.write(reinterpret_cast<char *>(&game.count), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.numTurn), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.SIZE), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.guesses), sizeof(game.guesses));
	
	for(int i=0;i<game.SIZE;i++)
	{
		file.write(reinterpret_cast<char *>(&game.code[i]), sizeof(1));
	}
	
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<4;j++)
		{
			file.write(reinterpret_cast<char *>(&play[i].slot[j]), sizeof(1));
		}
	}
	for(int i=0;i<game.numTurn;i++)
	{		
		for(int j=0;j<game.SIZE;j++)
		{
			strcpy(temp, play[i].fslot[j].c_str());
			file.write(reinterpret_cast<char *>(&temp), sizeof(temp));
			
		}		
	}
	
	file.close();
	file.clear();
	
	std::cout<<"Successfully saved to file.\n";
}

void Classic::load()			//One player load
{
	fstream file;
	char temp[5];
	int a;
	
	file.open("csave.txt", ios::in | ios::binary);
	if (!file)
	{
		std::cout << "Error opening file. Program aborting.\n";
		exit(0);
	}
	
	file.clear();
	file.seekg(0, ios::beg);
	a = file.peek();
	if(a == EOF)
	{
		cout<<"The file is empty! Please create a save game before attempting to load a game.\n";
		exit(0);
	}
	
	file.read(reinterpret_cast<char *>(&game.count), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.numTurn), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.SIZE), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.guesses), sizeof(game.guesses));
	
	game.code = new char[game.SIZE];
	
	for(int i=0;i<game.SIZE;i++)
	{
		file.read(reinterpret_cast<char *>(&game.code[i]), sizeof(1));
	}
	
	play = new Ply[game.numTurn];
	
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<4;j++)
		{
			file.read(reinterpret_cast<char *>(&play[i].slot[j]), sizeof(1));
		}		
	} 
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<game.SIZE;j++)
		{
			file.read(reinterpret_cast<char *>(&temp), sizeof(temp));
			play[i].fslot[j].assign(temp);
		}		
	}
	file.close(); 
}

void Classic::load2P(string b)				//Two player load
{
	fstream file;
	char temp[5];
	int a;
	
	file.open(b.c_str(), ios::in | ios::binary);
	if (!file)
	{
		std::cout << "Error opening file. Program aborting.\n";
		exit(0);
	}
	
	file.clear();
	file.seekg(0, ios::beg);
	a = file.peek();
	if(a == EOF)
	{
		cout<<"The file is empty! Please create a save game before attempting to load a game.\n";
		exit(0);
	}
	
	file.read(reinterpret_cast<char *>(&win), sizeof(win));
	file.read(reinterpret_cast<char *>(&turn), sizeof(turn));
	file.read(reinterpret_cast<char *>(&game.count), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.numTurn), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.SIZE), sizeof(4));
	file.read(reinterpret_cast<char *>(&game.guesses), sizeof(game.guesses));
	
	game.code = new char[game.SIZE];
	
	for(int i=0;i<game.SIZE;i++)
	{
		file.read(reinterpret_cast<char *>(&game.code[i]), sizeof(1));
	}
	
	play = new Ply[game.numTurn];
	
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<4;j++)
		{
			file.read(reinterpret_cast<char *>(&play[i].slot[j]), sizeof(1));
		}		
	} 
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<game.SIZE;j++)
		{
			file.read(reinterpret_cast<char *>(&temp), sizeof(temp));
			play[i].fslot[j].assign(temp);
		}		
	}
	file.close(); 
}

void Classic::rules(){			//Classic rules
	std::cout<<"\n****************************** R U L E S *************************************\n\n"
		<<"The computer has selected a secret combination of 4 colors chosen from a total \n" 
		<<"of 6 different colors, and you have to guess that combination in 10 or fewer \ntries to win.\n\n"
		<<"To create your guess select a color to input until you've filled\n"
		<<"a row with your combination (you can delete any guess that hasnt been played).\n"
		<<"Then simply enter y to confirm and play your guess.\n"
		<<"Each time you submit a guess the machine will use key pegs to let you know how \nclose your guess was.\n"
		<<"For each guess, a black score peg indicates one of your pegs is the right color\nand in "
		<<"the right position.\nA white key peg indicates that one of your pegs is the right color but\n"
		<<"in the wrong position. \nNo key peg indicates wrong color.\n"
		<<"Use these key pegs to guide your next guess. If you don't guess\n"
		<<"the correct combo in the allowed number of turns then you lose!\n\n";
}

void Classic::board()			//Displays current board
{
	std::cout<<"\nThis is your board. There are "<<game.numTurn<<" rows, one for each turn.\n"
		<<"The four slots to the right of the rows are the feedback slots.\n"
		<<"B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n"
		<<"Key pegs: Black = correct color and position, White =  correct color wrong position.\n\n";
		
	std::cout<<"                |---------------|"<<endl;
	for(int i=0;i<game.numTurn;i++)
	{
		std::cout<<"  		| ";
		for(int j=0;j<game.SIZE;j++)
		{ 
			std::cout<<play[i].slot[j];
			if(j<(game.SIZE - 1))
				cout<<"   ";
		}
		std::cout<<" |  "<<endl<<"                |---------------|"
			<<"     Turn "<<i+1<<":   "<<play[i].fslot[0]<<" "<<play[i].fslot[1]<<" "<<play[i].fslot[2]<<" "<<play[i].fslot[3]<<endl;
	}
	std::cout<<endl;
}

void Classic::match(){			//Controls the flow of one round, one player
	bool a,s; 	
	for(int i=0;i<game.numTurn;i++)
	{	
	++game.guesses;	
	s=move();
	if(s==true){
		save();
		break;
	}
	
	fdBack();
	
	board();
	
	
	if((a=won()) == true){
		break;
	}
	
	game.count++;
	}
}

bool Classic::match2p(){			//Controls the flow of one round, two player
	bool a,s; 	
	for(int i=0;i<game.numTurn;i++)
	{	
	++game.guesses;	
	s = move2p();
	if(s==true){
		return true;
	}
	fdBack();
	
	board();
	
	
	if((a=won()) == true){
		return false;
	}
	
	game.count++;
	}
	return false;
}

void Classic::turn2P(int a){			//Sets the variable turn to which turn the two player game is on
	turn = a;
}

void Classic::setNumT(){				//Static function to set the numTurn before the class is instantiated
	int temp;
	char confirm;
	std::cout<<"\nPlease enter the number of turns you would like to allow the codebreaker.\n"
	<<"Generally there are 10 turns. Less than that increases difficulty while more \ndecreases difficulty: \n";
	std::cin>>temp;
	while(temp < 1)
	{
		std::cout<<"Please input a number greater than 0:\n";
		std::cin>>temp;
	}
							
	std::cout<<"You selected to give the codebreaker "<<temp<<" turns, is this correct? (Y/N)\n";
	std::cin>>confirm;
	while(toupper(confirm) != 'Y'){
		std::cout<<"Lets try again:\n\n";
		std::cout<<"Please enter the number of turns you would like to allow the codebreaker.\n"
				 <<"Generally there are 10 turns. Less than that increases difficulty while more decreases difficulty: \n";
		std::cin>>temp;
							
		std::cout<<"You selected to give the codebreaker "<<temp<<" turns, is this correct? (Y/N)\n";
		std::cin>>confirm;
	}
	numTurn = temp;
}


int Classic::getTurn(){		//Gets which turn the two player game is on
	 return turn; 
}



bool Classic::won(){
	if(win == 4)
	{
		std::cout<<"YOU WON! Great Job!\n\n";
		return true;
	}
	else if(game.count == (game.numTurn - 1))
	{
		std::cout<<"Sorry, you lost. Better luck next time!\n"
				 <<"The code was: "<<(game.code)<<endl<<endl;
				 game.guesses = 11;
		return true;
	}
	else{
		return false;
	}
}

int Classic::getGues(){
		return game.guesses;
}

bool Classic::move() //Maybe split this up or put it in main
{

	char confirm, choice;
	std::cout<<"\nEnter a letter to play, enter S to save and exit. \n"
		  "B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n"; 
	do
	{

		for(int i=0;i<game.SIZE;i++)
		{ 	  
			std::cout<<"Enter input for slot "<<i+1<<": ";
			std::cin>>play[game.count].slot[i];
			while(toupper(play[game.count].slot[i]) != 'B' && toupper(play[game.count].slot[i]) != 'G' &&
				  toupper(play[game.count].slot[i]) != 'O' && toupper(play[game.count].slot[i]) != 'P' &&
				  toupper(play[game.count].slot[i]) != 'R' && toupper(play[game.count].slot[i]) != 'Y'
				  && toupper(play[game.count].slot[i]) != 'S')
			{
				std::cout<<"Please enter a valid code color: \n";
				std::cin>>play[game.count].slot[i];
			}
			play[game.count].slot[i] = toupper(play[game.count].slot[i]);
			if(toupper(play[game.count].slot[i]) == 'S')
			{
				play[game.count].slot[i] = 'X';
				return true;
			}
		}
	std::cout<<"Continue? Enter Y to continue, anything else to re-do this turn: \n";
	std::cin>>confirm;
	}while(toupper(confirm) != 'Y');
	return false;
}

bool Classic::move2p() //Maybe split this up or put it in main
{
	char confirm, choice;
	std::cout<<"\nEnter a letter to play, enter S to save and exit. \n"
		  "B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n"; 
	do
	{

		for(int i=0;i<game.SIZE;i++)
		{ 	  
			std::cout<<"Enter input for slot "<<i+1<<": ";
			std::cin>>play[game.count].slot[i];
			while(toupper(play[game.count].slot[i]) != 'B' && toupper(play[game.count].slot[i]) != 'G' &&
				  toupper(play[game.count].slot[i]) != 'O' && toupper(play[game.count].slot[i]) != 'P' &&
				  toupper(play[game.count].slot[i]) != 'R' && toupper(play[game.count].slot[i]) != 'Y'
				  && toupper(play[game.count].slot[i]) != 'S')
			{
				std::cout<<"Please enter a valid code color: \n";
				std::cin>>play[game.count].slot[i];
			}
			play[game.count].slot[i] = toupper(play[game.count].slot[i]);
			if(toupper(play[game.count].slot[i]) == 'S')
			{
				play[game.count].slot[i] = 'X';
				return true;
			}
		}
	std::cout<<"Continue? Enter Y to continue, anything else to re-do this turn: \n";
	std::cin>>confirm;
	}while(toupper(confirm) != 'Y');
	return false;
}


void Classic::fdBack()			//Gives the feedback pegs
{
	std::string index[game.SIZE];
	std::string swap;
	int temp;
	win=0;
	char a[4], b[4];
	for(int i=0;i<game.SIZE;i++)
	{												//Creates copy strings to manipulate
		a[i] = game.code[i];	
		b[i] = play[game.count].slot[i];
	}
	for(int i=0;i<game.SIZE;i++)						
	{ 													
		if(a[i] == b[i])								//If the code equals the guess then its a black peg
		{ 												//Otherwise if the code equals one of the guesses then its a white peg
			index[i] = "Black";							//Otherwise the feedback is empty.
			win++;										//After comparison the copy guess string is deleted to avoid duplicates
			b[i] = 'X';
		}
		 
		else if(a[i] == b[0] || a[i] == b[1] || a[i] == b[2] || a[i] == b[3])
		{ 
			for(int j=0;j<game.SIZE;j++)
			{
				if(a[i] == b[j])
				{
					index[i] = "White";
					b[j] = 'X';
					break;
				}
			}
		}
		//otherwise empty
		else {
			index[i] = "Empty"; }
	}
	
	
	//Swaps the feedback pegs before putting them into the structure, 
	//this way the player sees black and white pegs but is unsure of which guessed colors
	//the feedback pegs correspond to
	swap = index[0];
	index[0] = index[3];
	index[3] = swap;
	for(int i=0;i<game.SIZE;i++)
	{
		temp = rand()%4;
		while(temp == i)
		{
			temp = rand()%4;
		}
		swap = index[i];
		index[i] = index[temp];
		index[temp] = swap;
	}
	for(int i=0; i<game.SIZE;i++)
	{
		play[game.count].fslot[i] = index[i];
	}
}
