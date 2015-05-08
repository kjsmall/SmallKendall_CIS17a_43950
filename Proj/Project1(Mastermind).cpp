/*	
	Author: Kendall Small
	
	Purpose: CSC 17A Project 1: MASTERMIND
	
	Date: 23/04/15 15:11
	
	*/
	
	
	
/*
	So I need: 
	
	6 colored pegs (Blue, green, orange, purple, red, yellow)
	
	2 key pegs, for right color/position and just right color
	
	game board with 4 slots, plus 4 slots for the feedback pegs 
	
	
	
	I need to use:
	
	Memory allocation

    Functions with structures, used as input and output

    Pointers with arrays and arrays of structures, internally as well as externally.

    Use of character arrays as well as string objects.

    Reading and wrting to binary files.	
*/

//Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>
using namespace std;
 
//Globals
//A structure to hold the outline of the game: turns, and points
struct Game{
	int numTurn;
	int count;
	char *code;
	int SIZE;
};

//A structure to hold each row of pegs played
struct Ply{
	
	char slot[4];
	string fslot[4];
};


//Function prototypes
// mostly self explanatory
void save(Game, Ply []);
void load(Game);
void rules();
void board(Game, Ply []);
void newGame(Game, Ply []);
void lodGame(Game, Ply []);
void menu(Game);
Game setCode(Game);
void move(Game, Ply []);
void filBord(Game, Ply []);
int fdBack(Game, Ply []);


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Game game;
	game.SIZE = 4;
	game.count = 0;
	
	cout<<"Welcome to Mastermind!\n";		
		
	menu(game);
	
	system("PAUSE");
	return 0;	
}


void newGame(Game game, Ply play[]){
	int win;	
	
	game = setCode(game);
	
	filBord(game, play);
	
	cout<<"\nThe code has been set, play your first row: \n";
	
	for(int i=0;i<game.numTurn;i++)
	{
	move(game, play);
	
	win = fdBack(game, play);
	
	board(game, play);
	if(win == 1)
	{
		cout<<"YOU WON! Great Job! Thanks for playing!\n";
		break;
	}
	else if(game.count == (game.numTurn - 1))
	{
		cout<<"Sorry, you lost. Better luck next time!\n";
	}
	game.count++;
	}
	
	delete [] game.code;
	delete [] play;
	
}


void lodGame(Game game, Ply play[]){
	int win;
	
	cout<<"\nGame successfully loaded, you are on turn: "<<game.count+1<<"\n";
	
	for(int i=0;i<game.numTurn;i++)
	{

	move(game, play);
	
	win = fdBack(game, play);

	board(game, play);
	if(win == 1)
	{
		cout<<"YOU WON! Great Job! Thanks for playing!\n";
		break;
	}
	else if(game.count == (game.numTurn - 1))
	{
		cout<<"Sorry, you lost. Better luck next time!\n";
	}
	game.count++;
	}
	
	delete [] game.code;
	delete [] play;
	
}

//Accepts a combination of 4 colors as a guess and converts all letters to uppercase
void move(Game game, Ply play[])
{

	char confirm, choice;
	cout<<"Enter a letter to play, enter S to save and exit. \n"
		  "B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n"; 
	do
	{

		for(int i=0;i<game.SIZE;i++)
		{ 	  
			cout<<"Enter input for slot "<<i+1<<": ";
			cin>>play[game.count].slot[i];
			while(toupper(play[game.count].slot[i]) != 'B' && toupper(play[game.count].slot[i]) != 'G' &&
				  toupper(play[game.count].slot[i]) != 'O' && toupper(play[game.count].slot[i]) != 'P' &&
				  toupper(play[game.count].slot[i]) != 'R' && toupper(play[game.count].slot[i]) != 'Y'
				  && toupper(play[game.count].slot[i]) != 'S')
			{
				cout<<"Please enter a valid code color: \n";
				cin>>play[game.count].slot[i];
			}
			play[game.count].slot[i] = toupper(play[game.count].slot[i]);
			if(toupper(play[game.count].slot[i]) == 'S')
			{
				play[game.count].slot[i] = 'X';
				save(game, play);
			}
		}
	cout<<"Continue? Enter Y to continue, anything else to re-do this turn: \n";
	cin>>confirm;
	}while(toupper(confirm) != 'Y');
}

//Fill the board with X and Empty so that the entire board may be visualised and filled with guesses turn by turn
void filBord(Game game, Ply play[])
{
	for(int i=0;i<game.numTurn;i++)
	{
		for(int j=0;j<game.SIZE;j++)
		{
			play[i].slot[j] = 'X';
			play[i].fslot[j] = "Empty";
		}
	} 
}

//Feedback function, determines which pegs are correct in position and/or color
int fdBack(Game game, Ply play[])
{
	string index[game.SIZE];
	string swap;
	int temp, win=0;
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
					b[j] = 'X';cout<<index[i]<<i<<"\n";
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
	if(win == 4)
	{
		return 1;
	}
	
	else
		return 0;
}

//Outputs a text based board for visualization
void board(Game game, Ply play[])
{
	cout<<"\nThis is your board. There are "<<game.numTurn<<" rows, one for each turn.\n"
		<<"The four slots to the right of the rows are the feedback slots.\n"
		<<"B = blue, G = green, O = orange, P = purple, R = red, Y = yellow.\n"
		<<"Key pegs: Black = correct color and position, White =  correct color wrong position.\n\n";
		
	cout<<"                |---------------|"<<endl;
	for(int i=0;i<game.numTurn;i++)
	{
		cout<<"  		| ";
		for(int j=0;j<game.SIZE;j++)
		{ 
			cout<<play[i].slot[j];
			if(j<(game.SIZE - 1))
				cout<<"   ";
		}
		cout<<" |  "<<endl<<"                |---------------|"
			<<"     Turn "<<i+1<<":   "<<play[i].fslot[0]<<" "<<play[i].fslot[1]<<" "<<play[i].fslot[2]<<" "<<play[i].fslot[3]<<endl;
	}
	cout<<endl;
}

//Fills the code array with integer values and then assigns a color based on the
//given integer. 
Game setCode(Game game)
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
	cout<<(game.code);
	return game;
}

//Saves the current game to file and then exits
//char array temp to hold the string object in the Ply structure when writing and reading
void save(Game game, Ply play[])
{
	fstream file;
	char temp[5];					
	
	file.open("save.txt", ios::out | ios::binary);
	if (!file)
	{
		cout << "Error opening file. Program aborting.\n";
		exit(0);
	}

	file.seekp(0, ios::beg);
	
	file.write(reinterpret_cast<char *>(&game.count), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.numTurn), sizeof(4));
	file.write(reinterpret_cast<char *>(&game.SIZE), sizeof(4));
	
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
	
	cout<<"Successfully saved to file.\n"
		<<"Bye.";
	
	delete [] game.code;
	delete [] play;
	exit(0);
}

//Loads the saved game from the save file
//char array temp to hold string object in Ply struct when writing/reading
void load(Game game)
{
	fstream file;
	char temp[5];
	int a;
	
	file.open("save.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "Error opening file. Program aborting.\n";
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
	
	game.code = new char[game.SIZE];
	
	for(int i=0;i<game.SIZE;i++)
	{
		file.read(reinterpret_cast<char *>(&game.code[i]), sizeof(1));
	}
	
	Ply *play = new Ply[game.numTurn];
	
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
	lodGame(game, play);
}

 
void rules(){
	cout<<"\n****************************** R U L E S *************************************\n\n"
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


void menu(Game game){
	int choice;
	do
	{
		cout<<"\nReady to get started? Simply choose an option from the menu: \n(Be aware that you can only have ONE saved game at any given time)\n"
			<<"1. Start a new game\n"
			<<"2. Load a saved game\n"
			<<"3. See the rules\n"
			<<"4. Exit\n";
		cin>>choice;
	
		if(choice == 1){
			cout<<"\nLoading new game...\n";
			system("PAUSE");
			char confirm;
		
			cout<<"\nPlease enter the number of turns you would like to allow the codebreaker.\n"
			<<"Generally there are 10 turns. Less than that increases difficulty while more \ndecreases difficulty: \n";
		
			cin>>game.numTurn;
			while(game.numTurn < 1)
			{
				cout<<"Please input a number greater than 0:\n";
				cin>>game.numTurn;
			}
	
			cout<<"You selected to give the codebreaker "<<game.numTurn<<" turns, is this correct? (Y/N)\n";
			cin>>confirm;
			while(toupper(confirm) != 'Y'){
				cout<<"Lets try again:\n\n";
				cout<<"Please enter the number of turns you would like to allow the codebreaker.\n"
					<<"Generally there are 10 turns. Less than that increases difficulty while more decreases difficulty: \n";
				cin>>game.numTurn;
	
				cout<<"You selected to give the codebreaker "<<game.numTurn<<" turns, is this correct? (Y/N)\n";
				cin>>confirm;
			}
	
	
			Ply *play = new Ply[game.numTurn]; 	//Holds the colors and feedback for each turn, initially X or Empty
			newGame(game, play);
		
		}
	
		else if(choice == 2){
			cout<<"\nLoading saved game...\n";
			system("PAUSE");
			load(game);
		}
	
		else if(choice == 3){
			rules();
		}
	
		else if(choice == 4){
			cout<<"\nGoodbye!\n";
		}
		
		else
			cout<<"Sorry, that's not an option. Try again!\n";
			
	}while(choice != 4);
	
}
	
