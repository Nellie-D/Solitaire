#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Deck.h"
using namespace std;

class Board {


public:
	Board();
	void layoutGameAlg();
	void flipOnBoard(int i, int j);
	void setMap();
	void getMap();
	void printBoard();

private:
	Card* layoutArray[7][7];
	bool created;
	Deck boardDeck;
	Card* localCard;
	Card* currCard;
	Card* handArray[24];

};


#endif