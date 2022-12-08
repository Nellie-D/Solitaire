#include "Board.h"
#include <string>
#include <iostream>
using namespace std;



Board::Board() {
	this->created = true;
	
	
}

void Board::layoutGameAlg() {
	boardDeck.createDeck();
	boardDeck.shuffle();
	cout << "Hello" << endl;
	int iterA = 0;
	int iterB = 0;
	int f = 51;
	/*while (iterA * iterB < 37) {
		
		layoutArray[iterA][iterB] = boardDeck.getCurrCard(f);

		if (iterB > 6) {
			//cout << "iterAup" << endl;
			iterB = 0;
			iterA++;
		}
		else {
			iterB++;
			f--;
		}
		

	}	 */
	Card* currCard;
	for (int i = 0; i < 7; i++) {
		cout << "\n";
		
		for (int j = 0; j < 7; j++) {
			
			currCard = boardDeck.getCurrCard(f);
			
			if (i > j) {
				cout << "  ";
				
			}
			else if (i == j) {
				
				layoutArray[i][j] = currCard;
				layoutArray[i][j]->Print();
			}
			else if (j > i) {
				
				
				boardDeck.flip(currCard);
				currCard->Print();
			}
			f--;
		}

		
	}
	
	
	
}

