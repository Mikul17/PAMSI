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
#include "Board.h"
#include "ComputerPlayer.h"

using namespace std;


class Game {
private:
    Board board=Board(3,3);
    bool isComputerFirst=false;
    int gameState=0;
    int turn=0;
    ComputerPlayer computerPlayer=ComputerPlayer('O');
public:
    void initializeGame();
    void startGame();
    void playerMove();
   };


#endif //PAMSI_GRA_H
