//
// Created by Joel on 12/11/2021.
//

#ifndef WEEK_6_BOARD_H
#define WEEK_6_BOARD_H
#include "Coordinate.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using std::list;
using std::string;

struct Move {
    Coordinate coordinate;
    unsigned value;
    unsigned old_value;
};

struct Square {
    int value;
    bool editable;
};

class Board {
public:
    /**
     * Creates a new board by reading it in from a file.
     * @param filename The name of the JSON file containing the board object.
     */
    Board(const string &filename);
//    void save() const; // We may not need this one.
    void save(const string &filename) const;
    void display() const;
    Square getSquare(Coordinate coordinate);
    bool isMoveValid(Move move) const;
    list<Move> getValidMoves() const;
    void editSquare(Coordinate coordinate);
    void undoMove();

private:
    Square board[9][9]{};
    list<Move> moveHistory;
    void load(const string &filename);
};

#endif //WEEK_6_BOARD_H
