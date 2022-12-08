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
    DeckVector.clear();
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

void Deck::setCurrCard(int i) {
    Card* currentCard = DeckVector[i];
}

Card* Deck::getCurrCard(int i) {
    
    return DeckVector[i];
}

void Deck::shuffle() {
    
    localDeckVector.resize(52);
    for (int a = 0; a < 52; a++) {
        indexVector.push_back(a);
        
    }
    for (int i = 51; i > -1; i--) {

        srand((unsigned)time(NULL));
        int localIndex = rand() % indexVector.size();
        int value = indexVector[localIndex];

        localDeckVector[value] = DeckVector[i];

        DeckVector.erase(DeckVector.begin() + i);
        indexVector.erase(indexVector.begin() + localIndex);
        
    }

    for (int j = 51; j > -1; j--) {
        if (localDeckVector[j] == NULL) {
          
            localDeckVector.erase(localDeckVector.begin() + j);
        }
        
    }
    DeckVector.swap(localDeckVector);
    cout << "---------------------------------------" << endl;
    cout << DeckVector.size() << endl;
    
    

}

void Deck::flip(Card* specCard) {
   /* cout << "Specify a card to flip" << endl;
    cout << "Spade = 0" << endl;
    cout << "Club = 1" << endl;
    cout << "Diamond = 2" << endl;
    cout << "Heart = 3" << endl;
    int cardNumber;
    int cardSuitType;
    cout << "Card Suit: ";
    cin >> cardSuitType;
    cout << "Card Number: ";
    cin >> cardNumber;
    */
    Card* specifiedCard = specCard;
    if (specifiedCard->GetSide()) {
        specifiedCard->SetSide(false);
    }
    else {
        specifiedCard->SetSide(true);
    }

    
   /* for (int i = 0; i < DeckVector.size(); i++) {
        int currCardNum = DeckVector[i]->GetNumber();
        int currCardSuit = DeckVector[i]->GetSuit();
        if (currCardNum == cardNumber && currCardSuit == cardSuitType) {
            if (DeckVector[i]->GetSide()) {
                DeckVector[i]->SetSide(false);
            }
            else {
                DeckVector[i]->SetSide(true);
            }
        }

    }*/
}

void Deck::flipAll() {
    for (int f = 0; f < DeckVector.size(); f++) {
        bool cardFace = DeckVector[f]->GetSide();
        
        if (cardFace) {
            DeckVector[f]->SetSide(false);
            
        }
        else {
            DeckVector[f]->SetSide(true);
        }
    }
}

void Deck::sort() {
    vector<Card*> localSpade;
    localSpade.resize(13);
    vector<Card*> localClub;
    localClub.resize(13);
    vector<Card*> localDiamond;
    localDiamond.resize(13);
    vector<Card*> localHeart;
    localHeart.resize(13);
   

    for (int i = 51; i > -1; i--) {
        int currNum = DeckVector[i]->GetNumber();
        int localIndex = currNum - 1;
        CardSuit currCardSuit = DeckVector[i]->GetSuit();
        if (currCardSuit == 0) {
           
            localSpade[localIndex] = DeckVector[i];
        }
        else if (currCardSuit == 1) {
         
            localClub[localIndex] = DeckVector[i];
        }
        else if (currCardSuit == 2) {
        
            localDiamond[localIndex] = DeckVector[i];
        }
        else {
           
            localHeart[localIndex] = DeckVector[i];
        }
       
    }
    
    
    for (int a = 0; a < 13; a++) {
        newDeckVector.push_back(localSpade[a]);
    }
    for (int b = 0; b < 13; b++) {
        newDeckVector.push_back(localClub[b]);
    }
    for (int c = 0; c < 13; c++) {
        newDeckVector.push_back(localDiamond[c]);
    }
    for (int d = 0; d < 13; d++) {
        newDeckVector.push_back(localHeart[d]);
    }
    DeckVector.swap(newDeckVector);
    cout << DeckVector.size();

    


}

void Deck::print() {

    for (int i = 0; i < 52; i++) {
        DeckVector[i]->Print();
    }
}