#pragma once
#ifndef DECK_H
#define DECK_H
#include <string>
#include "Card.h"
#include <vector>
using namespace std;

class Deck {
public:

    Deck();
    Deck(bool cardFront, int cardValue, CardSuit suitType);
    void createDeck();
    ~Deck();
    void setCurrCard(int i);
    Card* getCurrCard(int i);
    void shuffle();
    void flipAll();
    void flip(Card*);
    void sort();
    void print();
  

private:
    bool cardFront;
    int cardValue;
    CardSuit suitType;
    Card* shuffledDeckList[52];
    vector <Card*> DeckVector;
    Card* DeckList[52];
    vector <Card*> localDeckVector;
    vector<int> indexVector;
    vector <Card*> newDeckVector;
 
};

#endif