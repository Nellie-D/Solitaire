#include <iostream>
#include <string>
#include "Deck.h"
using namespace std;

int main() {

    Deck myDeck;
    for (int i = 0; i < 52; i++) {
        myDeck.createDeck(i);
    };
    //myDeck.print();
    cout << "SHUFFLING THE DECK" << endl;
    myDeck.shuffle();
    
    //myDeck.print();


    return 0;
}