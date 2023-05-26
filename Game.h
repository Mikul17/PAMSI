//
// Created by miql on 26.05.2023.
//

#ifndef PAMSI_GRA_H
#define PAMSI_GRA_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>
#include "Player.h"

using namespace std;


class Game {
private:
    int turn = 1;
    int boardSize;
    int winCondition;
    vector<vector<char>> board;
    vector<Player> players;
public:
    Game();
    void initializeGame();
    void displayBoard();
    int checkWin();
    void startGame();
};


#endif //PAMSI_GRA_H
