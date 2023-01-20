#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main() {



    Board myBoard;
    
    myBoard.layoutGameAlg();
    //cout << "Specify a card to flip: " << endl;

    /* These values will specify the index for the 2D
    array to be flipped*/
    int i;
    int j;
    //cin >> i;
    //cin >> j;
   // myBoard.flipOnBoard(i, j);
    
    myBoard.sortBoard();
    myBoard.printBoard();
    
    


    return 0;
}
