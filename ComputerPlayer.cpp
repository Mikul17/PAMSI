//
// Created by miql on 27.05.2023.
//

#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(char symbol) {
    this->symbol = symbol;
}


Move ComputerPlayer::MinMaxAlfaBeta(Board &board, int depth, int alpha, int beta, bool isMaximizing) {
    int score = board.evaluateBoard();

    if(score != 0){
        char winner = score == 1 ? 'O' : 'X';
        if(score == 2){
            return {0};
        }else{
            return winner==symbol?Move(1000-depth):Move(-1000+depth);
        }
    }

    if(isMaximizing){
        Move bestMove(-1000);
        Board boardCopy = board;
        for(auto& move: board.getPossibleMoves()){
            boardCopy.makeMove(move, symbol);
            Move currentMove = MinMaxAlfaBeta(boardCopy, depth + 1, alpha, beta, false);
            currentMove.row= move.row;
            currentMove.column= move.column;
            if(currentMove.score>bestMove.score){
                bestMove=currentMove;
            }
            alpha = std::max(alpha, bestMove.score);
            if(beta <= alpha){
                break;
            }
        }
        return bestMove;
    }else{
        Move bestMove(1000);
        Board boardCopy = board;
        for(auto& move : board.getPossibleMoves()){
            boardCopy.makeMove(move, symbol=='X' ? 'O' : 'X');
            Move currentMove = MinMaxAlfaBeta(boardCopy, depth + 1, alpha, beta, true);
            currentMove.row= move.row;
            currentMove.column= move.column;
            if(currentMove.score<bestMove.score){
                bestMove=currentMove;
            }
            beta = std::min(beta, bestMove.score);
            if(beta <= alpha){
                break;
            }
        }
        return bestMove;
    }
}


void ComputerPlayer::makeMove(Board &board) {
    Move bestMove = MinMaxAlfaBeta(board, 0, -10000, 10000, true);
    board.setSymbol(bestMove.row, bestMove.column, symbol);
}
