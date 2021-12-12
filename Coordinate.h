//
// Created by Joel on 12/12/2021.
//

#ifndef WEEK_6_COORDINATE_H
#define WEEK_6_COORDINATE_H
#include <string>
using std::string;

class Coordinate {
public:
    explicit Coordinate(const string &coordString);
    Coordinate(unsigned row, unsigned col);
    unsigned getRow() const;
    unsigned getCol() const;
    string toString() const;
    bool isValid() const;
private:
    unsigned row;
    unsigned col;
    bool valid;
    /**
     * Parses a two-character string containing a letter and number into a Coordinate.
     * @param coordString the actual string to be parsed. Chars beyond the first two are ignored.
     * @return True if a valid coordinate was found and set, false if not.
     */
    bool parseCoordinate(const string &coordString);
};


#endif //WEEK_6_COORDINATE_H
