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
    int value;
    int old_value;
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
    explicit Board(const string &filename);
//    void save() const; // We may not need this one.
    void save(const string &filename) const;
    void display() const;
    Square getSquare(Coordinate coordinate) const;
    bool isMoveValid(Move move) const;
    list<Move> getValidMoves(Coordinate coordinate) const;
    void playTurn(Coordinate coordinate);
    void executeMove(Move move);
    void undoMove(Move move);

private:
    Square board[9][9]{};
    list<Move> moveHistory;
    void load(const string &filename);
};

#endif //WEEK_6_BOARD_H
