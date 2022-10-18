#include <iostream>
#include <string>
#include "Deck.h"
using namespace std;

int main() {

    Deck myDeck;
   
    myDeck.createDeck();
   
    //myDeck.print();
    int shuffleAmount;
    cout << "SHUFFLING THE DECK" << endl;
    cout << "How many times should we shuffle the deck?" << endl;
    cin >> shuffleAmount;
    
    for (int i = 0; i < shuffleAmount; i++) {
        myDeck.shuffle();
    }
    
    
   
    //myDeck.print();


    return 0;
}