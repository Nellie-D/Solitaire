#pragma once
#ifndef CARD_H
#define CARD_H
#include "CardSuit.h"
#include <string>
using namespace std;

class Card {
public:

    //Accessors

    Card();

    Card(bool frontBack, int cardValue, CardSuit suitType);

    void SetSide(bool cardFace);
    void SetNumber(int cardNumber);
    void SetSuit(CardSuit cardSuit);

    //Mutators

    bool GetSide();
    int GetNumber();
    CardSuit GetSuit();

    //prints card
    void Print();

private:
    bool cardFace;
    int cardNumber;
    CardSuit cardSuit;
    string suit;
    string royalty;

};


#endif