//
// Created by miql on 27.05.2023.
//

#ifndef PAMSI_COMPUTERPLAYER_H
#define PAMSI_COMPUTERPLAYER_H

#include "Board.h"




class ComputerPlayer{
private:
    char symbol;
public:
    ComputerPlayer(char symbol);
    Move MinMaxAlfaBeta(Board& board, int depth, int alpha, int beta, bool isMaximizing);
    void makeMove(Board& board);
};


#endif //PAMSI_COMPUTERPLAYER_H
