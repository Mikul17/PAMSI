//
// Created by miql on 27.05.2023.
//

#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Board& board,char symbol) {
    this->symbol = symbol;
}


Move ComputerPlayer::minimax(Board &board, int depth, int alpha, int beta, bool isMaximizing) {
    int score = board.evaluateBoard();
    if(score == 1){
        return Move(1);
    }else if(score == -1){
        return Move(-1);
    }else if(score==2){
        return Move(0);
    }

    if(isMaximizing){
        Move bestMove(-1000);
        Board boardCopy = board;
        for(auto& move: board.getPossibleMoves()){
            boardCopy.makeMove(move, symbol);
            Move currentMove = minimax(boardCopy, depth+1, alpha, beta, false);
            boardCopy.undoMove(move);
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
            Move currentMove = minimax(boardCopy, depth+1, alpha, beta, true);
            boardCopy.undoMove(move);
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
    Move bestMove = minimax(board, 0, -1000, 1000, true);
    board.setSymbol(bestMove.row, bestMove.column, symbol);
}
