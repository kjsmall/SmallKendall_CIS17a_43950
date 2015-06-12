//Main file for Master class
/*
	Use the copy constructor to load a game
	Use operator overload to keep track of the turns and use a do-while instead of a for-loop
	Use a static member variable somehow?
	Use polymorphism (with static function?) to display the score? or game stats?
	Possibly make a version where you pick how many games will be played, thus it would be an
		array of objects and you could use polymorphism to print how many points the current codemaker
		received after each round as well as then the total points score from a static function
	Virtual is for polymorphism so i guess i need two classes that I can pass to setcode
	
	I need to:
		figure out how to save 2 player game in classic
		see if I can figure out the copy constructor
		Implement the Series and 
		See if I can figure out operator overload and fit it in
		Try to fit in polymorphism (in master class)
		Try to fit in a static variable or function
		
		
	BUG REPORT:
		It doesn't tell you which turn youre on when you load a 2p game in classic
*/


#include "classic.h"
#include "series.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


int setTurn();


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int choice;
	do{
		cout<<"*********************************************************\n"
			<<"*                Welcome to Mastermind!			*\n"
			<<"*      Select which version you would like to play:     *\n"
			<<"*					        	*\n"
			<<"* 1. Classic-				                *\n"
			<<"*     In this version there is no scoring, just simple  *\n"
			<<"*     fun to see who can win with the least guesses.    *\n"
			<<"*						        *\n"
			<<"* 2. Series-					        *\n"
			<<"*     In this version there is scoring, and games are   *\n"
			<<"*     played in series.		                        *\n"
			<<"*						        *\n"
			<<"* 3. Advanced-				                *\n"
			<<"*     This version is just like the Series version,     *\n"
			<<"*     with one minor twist: blanks can be used in code! *\n"
			<<"*						        *\n"
			<<"* 4. Exit					        *\n"
			<<"*						        *\n"
			<<"*********************************************************\n"
			<<"Enter a numerical value from the menu: \n";
			
		cin>>choice;
		if(choice==1){		//<---------  CLASSIC MODE START HERE  ------------>
			int choice1;
			do{
				cout<<"\n***********************************************\n"
					<<"* Welcome to Classic Mastermind!              *\n"
					<<"* Please select an option from the menu:      *\n"
					<<"*                                             *\n"
					<<"* 1. Play against the CPU                     *\n"
					<<"* 2. Play against another player (2 player)   *\n"
					<<"* 3. See the rules			      *\n"
					<<"* 4. Return to main menu		      *\n"
					<<"*                                             *\n"
					<<"***********************************************\n";
				
				cin>>choice1;
				switch(choice1){
					int choice2;		
					case 1:{			//CLASSIC - 1P
						do{
							cout<<"\n***************************************\n"
								<<"*    You selected to play 1 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									Classic::setNumT();
									Classic round;
									round.setCode();
									std::cout<<"\nThe code has been set, play your first row: \n";
									round.match();
									break;
								}
								
								case 2:{
									cout<<"Loading game...\n";
									system("PAUSE");
									cout<<endl;
									Classic round;
									round.load();
									round.match();
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);
							
						break;
					}
					
					
					case 2:{			//CLASSIC - 2P
						do{
							cout<<"***************************************\n"
								<<"*    You selected to play 2 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									bool save = false;
									Classic::setNumT(); 
								    Classic round[2];
								    round[1].setCode();
									for(int i=0;i<2;i++){
										round[i].turn2P(i);
										round[i].setCode2();
										save = round[i].match2p();
										if(save==true){
											round[0].save2P("csave1p.txt");
											round[1].save2P("csave2p.txt");
											break;
										}
									}
									if(save==true){
										break;
									}
									cout<<"And the winner is... ";
									if(round[1].getGues() < round[0].getGues()){
										cout<<"Player 1 one with "<<round[1].getGues()<<" guesses!\n\n";
									}
									else if(round[0].getGues() < round[1].getGues()){
										cout<<"Player 2 one with "<<round[0].getGues()<<" guesses!\n\n";
									}
									else{
										cout<<"It was a tie!\n\n";
									}
									break;
								}
								
								case 2:{
									bool save = false;
									Classic round[2];
									round[0].load2P("csave1p.txt");
									round[1].load2P("csave2p.txt");
									if(Classic::getTurn()==0){
										save = round[0].match2p();
										if(save==true){
											round[0].save2P("csave1p.txt");
											round[1].save2P("csave2p.txt");
										}
										round[1].turn2P(1);
										round[1].setCode2();
										save = round[0].match2p();
										if(save==true){
											round[0].save2P("csave1p.txt");
											round[1].save2P("csave2p.txt");
										}
										break;
									}
									else if(Classic::getTurn()==1){
										save = round[1].match2p();
										if(save==true){
											round[0].save2P("csave1p.txt");
											round[1].save2P("csave2p.txt");
										}
									}									
									if(save==true){
										break;
									}
									cout<<"And the winner is... ";
									if(round[1].getGues() < round[0].getGues()){
										cout<<"Player 1 one with "<<round[1].getGues()<<" guesses!\n\n";
									}
									else if(round[0].getGues() < round[1].getGues()){
										cout<<"Player 2 one with "<<round[0].getGues()<<" guesses!\n\n";
									}
									else{
										cout<<"It was a tie!\n\n";
									}
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);
						
						break;
					}
					
					case 3:{
						//CLASSIC RULES
						break;
					}
					
					case 4:{
						cout<<"Returning to main menu...\n";
						system("PAUSE");
						cout<<endl;
						break;
					}
					
					default:{
						cout<<"Please enter one of the numerical values found\n"
							<<"in the menu to make a selection.\n";
						break;
					}
				}
			}while(choice1 != 4);
		}
		
		
		
		else if(choice==2){			//<------  SERIES MODE START HERE ---------->
			int choice1;
			do{
				cout<<"\n***********************************************\n"
					<<"* Welcome to Series Mastermind!               *\n"
					<<"* Please select an option from the menu:      *\n"
					<<"*                                             *\n"
					<<"* 1. Play against the CPU                     *\n"
					<<"* 2. Play against another player (2 player)   *\n"
					<<"* 3. See the rules			      *\n"
					<<"* 4. Return to main menu		      *\n"
					<<"*                                             *\n"
					<<"***********************************************\n";
				
				cin>>choice1;
				switch(choice1){
					int choice2;		
					case 1:{			//SERIES - 1P
						do{
							cout<<"\n***************************************\n"
								<<"*    You selected to play 1 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									int temp, i=0;
									Series::setRnds();
									Series::setNumT();
									while(Series::getRnd() < Series::getRnds()){
										cout<<"\nRound "<<i+1<<":\n";
										Series::turn2P(i++);
										Series round;
										round.setCode();
										round.match();
									}
									
									break;
								}
								
								case 2:{
									
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);
						break;
					}
					
					
					case 2:{			//SERIES - 2P
						do{
							cout<<"\n***************************************\n"
								<<"*    You selected to play 1 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									
									break;
								}
								
								case 2:{
									
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);						
						break;
					}
					
					case 3:{
						//SERIES RULES
						break;
					}
					
					case 4:{
						cout<<"Returning to previous menu...\n";
						system("PAUSE");
						break;
					}
					
					default:{
						cout<<"Please enter one of the numerical values found\n"
							<<"in the menu to make a selection.\n";
						break;
					}
					
				}
			}while(choice1 != 4);
		}
		
		
		
		else if(choice==3){			//<---------  ADVANCED MODE START HERE  ----------->
			int choice1;
			do{
				cout<<"\n***********************************************\n"
					<<"* Welcome to Advanced Mastermind!             *\n"
					<<"* Please select an option from the menu:      *\n"
					<<"*                                             *\n"
					<<"* 1. Play against the CPU                     *\n"
					<<"* 2. Play against another player (2 player)   *\n"
					<<"* 3. See the rules			      *\n"
					<<"* 4. Return to main menu		      *\n"
					<<"*                                             *\n"
					<<"***********************************************\n";
				
				cin>>choice1;
				switch(choice1){
					int choice2;		
					case 1:{			//ADVANCED - 1P
						do{
							cout<<"\n***************************************\n"
								<<"*    You selected to play 1 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									
									break;
								}
								
								case 2:{
									
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);
						break;
					}
					
					
					case 2:{			//ADVANCED - 2P
						do{
							cout<<"\n***************************************\n"
								<<"*    You selected to play 1 player!   *\n"
								<<"*                                     *\n"
								<<"* 1. New game                         *\n"
								<<"* 2. Load game                        *\n"
								<<"* 3. Return to previous menu          *\n"
								<<"*                                     *\n"
								<<"***************************************\n";
							cin>>choice2;
							
							switch(choice2){
								case 1:{
									
									break;
								}
								
								case 2:{
									
									break;
								}
								
								case 3:{
									cout<<"Returning to previous menu...\n";
									system("PAUSE");
									break;
								}
							}
						}while(choice2 != 3);						
						break;
					}
					
					case 3:{
						//ADVANCED RULES
						break;
					}
					
					case 4:{
						cout<<"Returning to previous menu...\n";
						system("PAUSE");
						break;
					}
					
					default:{
						cout<<"Please enter one of the numerical values found\n"
							<<"in the menu to make a selection.\n";
						break;
					}
					
				}
			}while(choice1 != 4);
		}
		
		else if(choice==4){
			cout<<"Goodbye! Thanks for playing!\n";
		}
		
		else{
			cout<<"Please enter one of the numerical values found\n"
				<<"in the menu to make a selection.\n";
		}
	}while(choice != 4);
	
	
	
	
	
	
	
/*
	// THIS IS THE COPY MATERIAL TO INSERT AND GO OFF OF
	
	//||||||||||||||||||||||||||||||||||||||||||||||||||
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	
	do{
				
		if(choice==1){ //Play against the CPU
			int choice1;
			do{
				cout<<"Player vs CPU menu:\n"
					<<"1. Load a saved game\n"
					<<"2. Start a new game\n"
					<<"3. Return to the main menu\n";
				cin>>choice1;
				
				switch(choice1){	//Loading a saved game
					case 1:{
						Cpu round;
						std::cout<<"Loading a saved game...\n";
						system("PAUSE");
						round.load();
						round.match();
						//Load a saved game
						break;
					}
					
					case 2:{	//Starting a new game
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
						Cpu round(temp);
						round.setCode();
						std::cout<<"\nThe code has been set, play your first row: \n";
						round.match();
						break;
					}
					
					case 3:{	//Return to main menu
						cout<<"Returning to main menu...\n";
						break;
					}
					
					default:{
						cout<<"Please select an option from the menu!\n";
						break;
					}
					cout<<endl;
				}
			}while(choice1 != 3);
		}
*/		
	system("PAUSE");
	return 0;
}
