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

//function currently not in use. However since the project is still in progress, 
//I will save this for a later time

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

//create a Deck out of card objects

void Deck::createDeck() {


    int f = 0;
    while (f < 52) {
        //add each new card into the Deck Vector

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

//shuffle the deck

void Deck::shuffle() {
    
    localDeckVector.resize(52);
    for (int a = 0; a < 52; a++) {
        indexVector.push_back(a);
        
    }
    for (int i = 51; i > -1; i--) {

        //generate a random number 0-51 from a seed
        

        srand((unsigned)time(NULL));
        int localIndex = rand() % indexVector.size();
        int value = indexVector[localIndex];

        //place the card at the specified, random index of the local vector
        //a local deckVector is used to avoid duplicating the card in the global deckVector

        localDeckVector[value] = DeckVector[i];

        //erase the Deck in order to clear out the sorted deck
        //this will ensure that when we put the localDeck (sorted) into DeckVector (unsorted), it won't overflow
        DeckVector.erase(DeckVector.begin() + i);
        indexVector.erase(indexVector.begin() + localIndex);
        
    }

    for (int j = 51; j > -1; j--) {
        if (localDeckVector[j] == NULL) {

            //don't waste space (and thus time) by leaving localDeckVector
            // also clear it for future shuffles

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

    // ^^^ this is for user clarification, but too much to print while
    // creating code

    //change the Side of the card, so that upon printing, it will be flipped

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
    //Flip the entire deck

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

    //Sort the deck
    /*this function is a rudimentary algorithm that creates smaller vectors to hold
    cards of different suits. I am exploring options to create a simpler algorithm with
    my current Card specifications, as each card in the deck holds a number 1-13. Alone, these
    values are repeated four times, which could create sorting confusion if trying to compare values
    to the card with a higher and lower index than itself. 
    
    I may explore giving the Deck class a new attribute, in which each card is given a number 1-52 when
    a new Deck of cards is created. This would ensure that each card has a unique value and could simplify
    the sorting process.*/

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
    /*combine the smaller, sorted vectors into the newDeckVector, then swap the
    newDeckVector with the previously unsorted, global DeckVector.*/
    
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

    //explore erasing newDeckVector so as to save space


}

void Deck::print() {

    for (int i = 0; i < 52; i++) {
        DeckVector[i]->Print();
    }
}
