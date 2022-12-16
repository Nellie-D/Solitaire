#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main() {



    Board myBoard;
    
    myBoard.layoutGameAlg();
    cout << "Specify a card to flip: " << endl;
    int i;
    int j;
    cin >> i;
    cin >> j;
    myBoard.flipOnBoard(i, j);
    myBoard.printBoard();
    
    


    return 0;
}
