//
// Created by Joel on 12/11/2021.
//

#ifndef WEEK_6_BOARD_H
#define WEEK_6_BOARD_H
#include <list>
#include <string>
#include "Coordinate.h"

using std::list;
using std::string;

struct Move {
    Coordinate coordinate;
    unsigned value;
    unsigned old_value;
};

struct Square {
    unsigned value;
    bool editable;
};

class Board {
public:
    Board(string filename);
    void save() const;
    void save(string filename) const;
    void display() const;
    Square getSquare(Coordinate coordinate);
    bool isMoveValid(Move move) const;
    list<Move> getValidMoves() const;
    void editSquare(Coordinate coordinate);
    void undoMove();

private:
    Square board[9][9];
    list<Move> moveHistory;
    void load(string filename);
};

#endif //WEEK_6_BOARD_H
