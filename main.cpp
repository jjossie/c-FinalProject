#include <iostream>
#include <memory>
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
//    test_getUserMove();

    // Main Program Control

    // Load a board
    string filename;
    shared_ptr<Board> board;
    while (true){
        // Prompt for file
        cout << "Where is your board file located?" << endl;
        cin >> filename;
        try{
            board = make_shared<Board>(filename);
            break;
        } catch (FileException &fe){
            // File not found
            cout << "Unable to open file \"" << filename << "\"." << endl;
        } catch (...){
            cout << "File \"" << filename << "\" corrupted." << endl;
        }
    }

    // Play the game

    while (true){
        try{
            board->display();
            Move move = board->getUserMove();
            board->executeMove(move, true);
        } catch (UserAbortException &uae) {
            // User wants to save and quit
            break;
        }
    }

    // Save and Quit
    string newFilename;
    while (true) {
        cout << "Where would you like to save your board? (press enter to accept default \"" << filename << "\")."
             << endl;
        cin.ignore();
        getline(cin, newFilename, '\n');
        if (newFilename.empty()) {
            board->save(filename);
            cout << endl << "Saved Successfully. Goodbye!" << endl;
            break;
        } else {
            try {
                board->save(newFilename);
                cout << endl << "Saved Successfully. Goodbye!" << endl;
                break;
            } catch (FileException &fe) {
                cout << "Unable to write to " << filename << endl;
            }
        }
    }

    return 0;
}
