//
// Created by Joel on 12/11/2021.
//

#ifndef WEEK_6_BOARD_H
#define WEEK_6_BOARD_H
#include "Coordinate.h"
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>

using std::list;
using std::stack;
using std::string;
using std::exception;

struct UserAbortException : public exception
{
    const char * what () const noexcept
    {
        return "User Cancelled Action";
    }
};

struct FileException : public exception
{
    const char * what () const noexcept
    {
        return "User Cancelled Action";
    }
};

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
//    void playTurn(Coordinate coordinate);
    void executeMove(Move move, bool addToHistory);
    /**
     * Prompts the user for a coordinate to edit on the board, then calls
     * getUserValue() to obtain a valid move at a given coordinate.
     * @return The Move the user decided to execute.
     */
    Move getUserMove();
    void undoLastMove();

private:
    Square board[9][9]{};
    stack<Move> moveHistory;
    void load(const string &filename);
    /**
     * Repeatedly prompts the user for a value to go in a given coordinate.
     * Value is guaranteed to be valid for that coordinate, but will throw
     * UserAbortException if 'C' is entered instead of a value.
     * Also calls listValidMoves(getValidMoves()) if user inputs 'S'.
     * @param coordinate The coordinate at which to enter a value.
     * @return The user's chosen value for that coordinate.
     */
    int getUserValue(Coordinate &coordinate) const;

    static string listValidMoves(const list<Move>& moves);
};

#endif //WEEK_6_BOARD_H
