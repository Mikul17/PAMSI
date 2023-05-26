//
// Created by miql on 26.05.2023.
//

#ifndef PAMSI_PLAYER_H
#define PAMSI_PLAYER_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

class Player {
private:
    char symbol;
    bool isComputer;
public:
    Player(char symbol, bool isComputer);
    char getSymbol();
    void move(vector<vector<char>>& board, int boardSize);
    void aiMove(vector<vector<char>>& board, int boardSize);
};


#endif //PAMSI_PLAYER_H
