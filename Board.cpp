#include "Board.h"
#include <string>
#include <iostream>
using namespace std;



Board::Board() {

	this->created = true;

	boardDeck.createDeck();

	boardDeck.shuffle();
	
	
}

void Board::layoutGameAlg() {
	

	int f = 51;


	for (int i = 0; i < 7; i++) {
		cout << "\n";
		
		for (int j = 0; j < 7; j++) {
			
			currCard = boardDeck.getCurrCard(f);
			
			if (i > j) {
				
				layoutArray[i][j] = new Card;
				//cout << "  ";
				
			}
			else if (i == j) {
				
				layoutArray[i][j] = currCard;
				f--;
				
				//layoutArray[i][j]->Print();
			}

			else if (j > i) {
				
				layoutArray[i][j] = currCard;
				boardDeck.flip(currCard);
				f--;
				//currCard->Print();
			}
			
		}	
		
	}
	
	/*for (int c = 0; c < 24; c++) {
		currCard = boardDeck.getCurrCard(f);
		handArray[c] = currCard;
		f--;
	}
	 */

	printBoard();
	
}


void Board::flipOnBoard(int i, int j) {

	boardDeck.flip(layoutArray[i][j]);

	
	
}

void Board::printBoard() {

	int f = 51;
	for (int i = 0; i < 7; i++) {
		cout << "\n";

		for (int j = 0; j < 7; j++) {

			currCard = boardDeck.getCurrCard(f);

			if (i > j) {
				cout << "  ";
			}
			else if (i == j) {
				layoutArray[i][j]->Print();
			}
			else if (j > i) {
				layoutArray[i][j]->Print();
			}
			f--;
		}
	}

}