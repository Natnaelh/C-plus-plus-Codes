#include <iostream>
#include<string>

using namespace std;

const int N_COINS = 5;
const int MAX_MOVE = 3;
const int NO_GOOD_MOVE = -1;

enum Player
{
	HUMAN, COMPUTER
	
}; 

Player opponent(Player player){
	if (player == HUMAN){
		return COMPUTER;
	}
	else{
		return HUMAN;
	}
}

const Player STARTING_PLAYER  = HUMAN;

class SimpleNim{
	public:

		void play(){
			nCoins = N_COINS;
			whoseTurn = STARTING_PLAYER;

			while(nCoins > 1){
				cout<<"There are "<<nCoins<<" in the pile."<<endl;
				if (whoseTurn == HUMAN){
					nCoins -= getHumanMove();
				} 
				else{
					int computerMove = getComputerMove();
					cout<<"I will take "<<computerMove << " coins"<<endl;
					nCoins -= computerMove;
				}

				whoseTurn = opponent(whoseTurn);
			}

			announceResult();
		}



		void printInstructions(){
			cout<<"Welcome to the game of Nim! "<<endl;
			cout<<"In this game we will start with a pile of "<<endl;
			cout<<N_COINS<< " coins on the table. on each turn, you "<<endl;
			cout<< "and i will alternatively take between 1 and "<<endl;
			cout<< MAX_MOVE << " coins from the table. The player who "<<endl;
			cout << "takes the last coin loses."<<endl<<endl;

		}


	private:

		int nCoins;
		Player whoseTurn;

		int getComputerMove(){
			int nTaken = findGoodMove(nCoins);
			return (nTaken == NO_GOOD_MOVE) ? 1 : nTaken;
		}	

		int findGoodMove(int nCoins){
			int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
			for (int nTaken = 1; nTaken < limit ; nTaken++){
				if(isBadPosition(nCoins - nTaken)) return nTaken;

			}
			return NO_GOOD_MOVE;  
		}


		bool isBadPosition(int nCoins){
			if(nCoins == 1) return 1;
			return findGoodMove(nCoins)== NO_GOOD_MOVE;
		}


		int getHumanMove(){
			while(true){
				int nTaken;
				cout << "How many would you like? ";
				cin>>nTaken;
				int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
				if(nTaken > 0 && nTaken <= limit) return nTaken;
				cout<<" That is Cheating! please choose a number. ";
				cout<<" between 1 and " << limit<<" . "<<endl;
				cout<<" There are "<<nCoins <<" in the pile. "<<endl;
			}

		}


		void announceResult(){
			if (nCoins == 0) {
				cout << "You took the last coin. You Lose. "<<endl;
			} else{
				cout<<"There is only 1 coin left"<<endl;
				if(whoseTurn == HUMAN){
					cout<<"I win! "<<endl;			
				}
				else{
					cout<<" I Lose! "<<endl;
				}
			}

		}



};



int main(){
	SimpleNim game;
	game.printInstructions();
	game.play();
	return 0;
}