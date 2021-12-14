#include <iostream>
#include <string>
#include <memory>
#include "Coordinate.h"
#include "Board.h"

using namespace std;

void test_isMoveValid(){
    const string filename = "easy.txt";
    unique_ptr<Board> board(new Board(filename));
    board->display();
    cout << (board->isMoveValid(Move {Coordinate(1, 1), 9}) ? "Pass" : "Fail") << endl; // Pass
    cout << (board->isMoveValid(Move {Coordinate(1, 1), 2}) ? "Pass" : "Fail") << endl; // Fail (block, col)
    cout << (board->isMoveValid(Move {Coordinate(0, 4), 9}) ? "Pass" : "Fail") << endl; // Fail (row)
}

void test_coordToString(){
    cout << Coordinate(0, 0).toString() << endl; // A1
    cout << Coordinate(8, 8).toString() << endl; // J9
    cout << Coordinate(4, 2).toString() << endl; // C5
}

void test_getUserMove(){
    const string filename = "easy.txt";
    unique_ptr<Board> board(new Board(filename));
    board->display();
    try{
        Move move = board->getUserMove();
        cout << move.value << "at " << move.coordinate.toString();
    } catch (UserAbortException &e){
        cout << "Save the board ok ok\n\n";
    }
    board->display();
}


int main() {
//    test_coordToString();
//    test_isMoveValid();
    test_getUserMove();
    return 0;
}
