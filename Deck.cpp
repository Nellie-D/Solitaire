#include "Deck.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor 1

Deck::Deck(bool cardFace, int cardValue, CardSuit suitType) {
    this->cardFront = cardFace;
    this->cardValue = cardValue;
    this->suitType = suitType;
    
}

Deck::Deck() {
    this->cardFront = false;
    this->cardValue = 0;
    this->suitType = SPADE;

}

Deck::~Deck() {

    for (int i = 0; i < 51; i++) {
        
        delete DeckList[i];
    }
    cout << "Done" << endl;
}

Card* Deck::createDeck(int i) {


    int f = 0;
    while (f < 52) {
        for (int i = 1; i < 14; i++) {
            DeckList[f] = new Card(true, i, SPADE);
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckList[f] = new Card(true, i, CLUB);
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckList[f] = new Card(true, i, HEART);
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckList[f] = new Card(true, i, DIAMOND);
            f++;
        }
    }
    DeckList[i]->Print();

    return DeckList[i];
}

void Deck::shuffle() {
    
    
    for (int i = 0; i < 52; i++) {
        int localIndex = rand() % 52;
        DeckList[localIndex]->Print();
            
    }
        //FIXME: There are duplicate cards.
    
    
    


}

void Deck::print() {

    for (int i = 0; i < 52; i++) {
        DeckList[i]->Print();
    }
}