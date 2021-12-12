#include <iostream>
#include <string>
#include <memory>
#include "Coordinate.h"
#include "Board.h"

using namespace std;

int main() {

    return 0;
}

void test_isMoveValid(){
    const string filename = "easy.txt";
    unique_ptr<Board> board(new Board(filename));
//    board->display();
    cout << (board->isMoveValid(Move {Coordinate(1, 1), 9}) ? "Pass" : "Fail") << endl; // Pass
    cout << (board->isMoveValid(Move {Coordinate(1, 1), 2}) ? "Pass" : "Fail") << endl; // Fail (block, col)
    cout << (board->isMoveValid(Move {Coordinate(0, 4), 9}) ? "Pass" : "Fail") << endl; // Fail (row)
}