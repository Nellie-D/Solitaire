#include "Board.h"
#include <string>
#include <iostream>
using namespace std;



Board::Board() {

	//default board
	this->created = true;

	boardDeck.createDeck();

	boardDeck.shuffle();
	
	
}


//create the basic layout by putting card objects into a 2d array
void Board::layoutGameAlg() {
	

	int f = 51;


	for (int i = 0; i < 7; i++) {
		cout << "\n";
		
		for (int j = 0; j < 7; j++) {
			
			currCard = boardDeck.getCurrCard(f);
			
			if (i > j) {
				
				layoutArray[i][j] = new Card;
				
				
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


	printBoard();
	
}


//flip a specified card on the "board"
void Board::flipOnBoard(int i, int j) {

	boardDeck.flip(layoutArray[i][j]);

	
	
}

void Board::sortBoard() {

	boardDeck.sort();



}

//print the entire board in a layout that resembles the Solitaire game
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