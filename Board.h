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
#include "Move.h"


using namespace std;



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
    int evaluateBoard();
};


#endif //PAMSI_BOARD_H
