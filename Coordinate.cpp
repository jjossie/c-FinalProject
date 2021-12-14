//
// Created by Joel on 12/12/2021.
//

#include "Coordinate.h"
#include <sstream>
using std::stringstream;

Coordinate::Coordinate(const string &coordString) { // NOLINT(cppcoreguidelines-pro-type-member-init)
    valid = parseCoordinate(coordString);
}

Coordinate::Coordinate(int row, int col) : row(row), col(col) {
    valid = ((0 <= row && row <= 8) && (0 <= col && col <= 8));
}

bool Coordinate::parseCoordinate(const string &coordString) {
    // Make sure we at least have two values
    if (coordString.length() < 2 )
        return false;
    bool numberUsed = false;
    bool letterUsed = false;
    for (int i = 0; i < 2; i++){
        if (isdigit(coordString[i]) && !numberUsed) {
//            int number = (int)(unsigned char)coordString[i];
            int number =  int((unsigned char)coordString[i]) - int('0') - 1;
            if( 0 <= number && number <= 9){
                numberUsed = true;
                row = number;
            }
        }
        else if (isalpha(coordString[i]) && !letterUsed){
            char letter = tolower(coordString[i]);
            if (int('a') <= int(letter) && int(letter) <= int('j')){
                letterUsed = true;
                col = letter - int('a');
            }
        }
    }
    if (!letterUsed || !numberUsed)
        return false;
    else
        return true;
}

int Coordinate::getRow() const { return row; }

int Coordinate::getCol() const { return col; }

string Coordinate::toString() const {
    return char(col + int('A')) + std::to_string(row + 1);
}

bool Coordinate::isValid() const {
    return valid;
}

