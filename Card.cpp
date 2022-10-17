#include "Card.h"
#include <string>
#include <iostream>
using namespace std;


//Constructor

Card::Card() {
    this->cardFace = false;
    this->cardNumber = 0;
    this->cardSuit = SPADE;
}

//Default Constructor 

Card::Card(bool cardFront, int cardInt, CardSuit suitType) {
    cardFace = cardFront;
    cardNumber = cardInt;
    cardSuit = suitType;

}

//Setters 

void Card::SetSide(bool cardFront) {
    cardFace = cardFront;
}

void Card::SetNumber(int cardInt) {
    cardNumber = cardInt;
}

void Card::SetSuit(CardSuit suitType) {
    cardSuit = suitType;
    suit = "Joker";
    if (cardSuit == SPADE) {
        suit = "SPADES";
    }
    else if (cardSuit == CLUB) {
        suit = "CLUBS";
    }
    else if (cardSuit == HEART) {
        suit = "HEARTS";
    }
    else {
        suit = "DIAMONDS";
    }

}

//Getters

bool Card::GetSide() {
    return cardFace;
}

int Card::GetNumber() {
    return cardNumber;
}

CardSuit Card::GetSuit() {
    return cardSuit;
}

// Print

void Card::Print() {
   
    suit = "Joker";
    if (cardSuit == SPADE) {
        suit = "SPADES";
    }
    else if (cardSuit == CLUB) {
        suit = "CLUBS";
    }
    else if (cardSuit == HEART) {
        suit = "HEARTS";
    }
    else {
        suit = "DIAMONDS";
    }

    if (cardNumber == 1) {
        cout << "Ace of " << suit << endl;
    }
    else if (cardNumber == 11) {
        cout << "Jack of " << suit << endl;
    }
    else if (cardNumber == 12) {
        cout << "Queen of " << suit << endl;
    }
    else if (cardNumber == 13) {
        cout << "King of " << suit << endl;
    }
    else {
        cout << cardNumber << " of " << suit << endl;
    }
    cout << "\n" << endl;
    //}
    //else {
    //  cout << "Card is facing down. We don't know what it is yet." << endl;
    //}
}
