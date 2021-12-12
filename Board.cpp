//
// Created by Joel on 12/11/2021.
//

#include "Board.h"
#include <algorithm>
//#include <memory>
//#include <numeric>


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
            if (square.value != 0) // TODO come up with a way to color this square if it's editable or not (or something)
                rowString << square.value;
            else
                rowString << " ";
        }
        cout << rowString.str() << endl;
    }
}

Board::Board(const string &filename) {
    load(filename);
}

void Board::save(const string &filename) const {
    // open a file for writing
    ofstream f_out(filename);
    if (f_out.fail()) {
        cout << "Unable to write to " << filename << endl;
        return;
    }

    for (const auto & iRow : board) {
        for (auto square : iRow){
            f_out << square.value << (square.editable ? 't' : 'f') << '|';
        }
        f_out << endl;
    }

    f_out.close();
}

void Board::load(const string &filename) {
    // Open file and ensure it's not empty
    ifstream f_in(filename);
    if (f_in.fail()) {
        cout << "Error, unable to open file " << filename << endl;
        return;
    }
    int iRow = 0;
    int iCol = 0;
    // Loop through each line in the file
    while (!f_in.fail()){
        // TODO Assert iRow < 9
        string rowString;
        getline(f_in, rowString, '\n');
        string delim = "|";
        size_t pos = 0;
        string token;
        // Loop through each token (separated by delim '|') in the line
        while ((pos = rowString.find(delim)) != string::npos){
            // TODO Assert iCol < 9
            token = rowString.substr(0, pos);
            // TODO Assert token.length() == 2
            Square s = {int(token[0]) - int('0'), token[1] == 't'};
            board[iRow][iCol] = s;
            iCol++;
            rowString.erase(0, pos + 1);
        }
        iRow++;
    }
    f_in.close();
}
