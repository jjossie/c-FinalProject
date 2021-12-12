//
// Created by Joel on 12/11/2021.
//

#include "Board.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


void Board::display() const {
    string horiz_separator = "   -----+-----+-----\n";
    cout << "   A B C D E F G H I\n";
    for (int row = 0; row < 9; row++){
        if (row == 3 || row == 6)
            cout << horiz_separator;
        stringstream rowString;
        rowString << row + 1;
        for (int col = 0; col < 9; col++){
            Square square = board[row][col];
            if (col == 3 || col == 6)
                rowString << "|";
            else
                rowString << " ";
            if (square.value != 0)
                rowString << square.value;
            else
                rowString << " ";
        }
        cout << rowString.str() << endl;
    }
}
