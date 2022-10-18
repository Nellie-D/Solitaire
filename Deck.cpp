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

    for (int i = 0; i < 52; i++) {
        
        delete DeckList[i];
    }
    cout << "Done" << endl;
}

/*Card* Deck::createDeck(int i) {


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
}*/

void Deck::createDeck() {


    int f = 0;
    while (f < 52) {
        for (int i = 1; i < 14; i++) {
            DeckVector.push_back(new Card(true, i, SPADE));
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckVector.push_back(new Card(true, i, CLUB));
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckVector.push_back(new Card(true, i, HEART));
            f++;
        }
        for (int i = 1; i < 14; i++) {
            DeckVector.push_back(new Card(true, i, DIAMOND));
            f++;
        }
        
    }
    
    

    
}

void Deck::shuffle() {
    
    
    /*for (int i = 0; i < 52; i++) {
        int localIndex = rand() % 52;
        DeckList[localIndex]->Print();
            
    }  */
        //FIXME: There are duplicate cards.
    
    localDeckVector.resize(52);
    for (int a = 0; a < 52; a++) {
        indexVector.push_back(a);
        
    }
    for (int i = 51; i > -1; i--) {

        //cout << indexVector[i] << " :Index array" << endl;
        
        int localIndex = rand() % indexVector.size();
        int value = indexVector[localIndex];
        
        //cout << localIndex << " :local index" << endl;
        //cout << value << " :value" << endl;


        localDeckVector[value] = DeckVector[i];
        
        DeckVector.erase(DeckVector.begin() + i);
        indexVector.erase(indexVector.begin() + localIndex);
        //cout << DeckVector.size() << endl;

        //cout << "IndexVector size: " << indexVector.size() << endl;
       
        
    }

    for (int j = 0; j < localDeckVector.size(); j++) {
        if (localDeckVector[j] == NULL) {
           // cout << "null" << endl;
            localDeckVector.erase(localDeckVector.begin() + j);
        }
      
        //localDeckVector[j]->Print();
        
        
        
    }
    DeckVector.swap(localDeckVector);
    cout << "---------------------------------------" << endl;
    cout << DeckVector.size() << endl;
    //DeckVector.swap(localDeckVector);
   // cout << DeckVector.size() << endl;
    for (int f = 1; f < DeckVector.size(); f++) {
        DeckVector[f]->Print();
    }

    //cout << localDeckVector.size() << endl;
    

}

void Deck::print() {

    for (int i = 0; i < 52; i++) {
        DeckVector[i]->Print();
    }
}