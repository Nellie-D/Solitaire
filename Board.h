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
	void setMap();
	void getMap();
private:
	Card* layoutArray[7][7];
	bool created;
	Deck boardDeck;

};


#endif