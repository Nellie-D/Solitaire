#pragma once
#ifndef DECK_H
#define DECK_H
#include <string>
#include "Card.h"
using namespace std;

class Deck {
public:

    Deck();
    Deck(bool cardFront, int cardValue, CardSuit suitType);
    Card* createDeck(int i);
    ~Deck();
    void shuffle();
    void flip();
    void print();


private:
    bool cardFront;
    int cardValue;
    CardSuit suitType;
    Card* shuffledDeckList[52];
    Card* DeckList[52];

};

#endif