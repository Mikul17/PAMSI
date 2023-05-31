//
// Created by miql on 27.05.2023.
//

#ifndef PAMSI_BOARD_H
#define PAMSI_BOARD_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

struct Move{
    int row;
    int column;
    int score;
    Move() : score(0){};
    Move(int s) : score(s){}
    Move(int r, int c) : row(r), column(c), score(0){};
};


class Board {
private:
    int boardSize;
    int winCondition;
    vector<vector<char>> board;
public:
    Board(int boardSize, int winCondition);
    void initializeBoard();
    void displayBoard();
    char getSymbol(int row, int column);
    void setSymbol(int row, int column, char symbol);
    int getBoardSize();
    int getNumberOfPossibleMoves();
    vector<Move> getPossibleMoves();
    void makeMove(Move move, char symbol);
    void undoMove(Move move);
    int evaluateBoard();
};


#endif //PAMSI_BOARD_H
