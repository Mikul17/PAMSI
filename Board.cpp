//
// Created by miql on 27.05.2023.
//

#include "Board.h"

Board::Board(int boardSize, int winCondition) {
    this->boardSize = boardSize;
    this->winCondition = winCondition;
    initializeBoard();
}

void Board::initializeBoard() {
    for(int i = 0; i < boardSize; i++) {
        vector<char> row;
        for(int j = 0; j < boardSize; j++) {
            row.push_back('*');
        }
        board.push_back(row);
    }
}

void Board::displayBoard() {
    cout << "\033[2J\033[1;1H"; // ANSI to clear terminal in CLion

    cout << " ";
    for (int i = 0; i < board.size(); i++) {
        cout << setw(3) << static_cast<char>('a' + i);
    }
    cout << endl;

    for (const auto& row : board) {
        cout<<setw(2)<<(&row - &board[0]) + 1;
        for (const auto& cell : row) {
            cout <<"|"<< setw(2) << cell << " ";
        }
        cout << "|" << endl;
    }
}

char Board::getSymbol(int row, int column) {
    return board[row][column];
}

void Board::setSymbol(int row, int column, char symbol) {
    if(board[row][column] == '*'){
        board[row][column] = symbol;
    }
}

int Board::getBoardSize() {
    return boardSize;
}

int Board::getNumberOfPossibleMoves() {
    int possibleMoves = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize ; j++) {
            if (board[i][j] == '*') {
                possibleMoves++;
            }
        }
    }
    return possibleMoves;
}

int Board::evaluateBoard() {
    // Check win condition vertically
    for (int col = 0; col < boardSize; col++) {
        for (int row = 0; row <= boardSize - winCondition; row++) {
            int countPlayer1 = 0;
            int countPlayer2 = 0;
            for (int i = 0; i < winCondition; i++) {
                if (board[row + i][col] == 'X') {
                    countPlayer1++;
                } else if (board[row + i][col] == 'O') {
                    countPlayer2++;
                }
            }
            if (countPlayer1 == winCondition) {
                return -1; // Gracz 1 (X) wygrał
            } else if (countPlayer2 == winCondition) {
                return 1; // Gracz 2 (O) wygrał
            }
        }
    }

    // Check win condition horizontally
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col <= boardSize - winCondition; col++) {
            int countPlayer1 = 0;
            int countPlayer2 = 0;
            for (int i = 0; i < winCondition; i++) {
                if (board[row][col + i] == 'X') {
                    countPlayer1++;
                } else if (board[row][col + i] == 'O') {
                    countPlayer2++;
                }
            }
            if (countPlayer1 == winCondition) {
                return -1; // Gracz 1 (X) wygrał
            } else if (countPlayer2 == winCondition) {
                return 1; // Gracz 2 (O) wygrał
            }
        }
    }

    // Check win condition diagonally (from top left to bottom right)
    for (int row = 0; row <= boardSize - winCondition; row++) {
        for (int col = 0; col <= boardSize - winCondition; col++) {
            int countPlayer1 = 0;
            int countPlayer2 = 0;
            for (int i = 0; i < winCondition; i++) {
                if (board[row + i][col + i] == 'X') {
                    countPlayer1++;
                } else if (board[row + i][col + i] == 'O') {
                    countPlayer2++;
                }
            }
            if (countPlayer1 == winCondition) {
                return -1; // Gracz 1 (X) wygrał
            } else if (countPlayer2 == winCondition) {
                return 1; // Gracz 2 (O) wygrał
            }
        }
    }

    // Check win condition diagonally (from top right to bottom left)
    for (int row = 0; row <= boardSize - winCondition; row++) {
        for (int col = winCondition - 1; col < boardSize; col++) {
            int countPlayer1 = 0;
            int countPlayer2 = 0;
            for (int i = 0; i < winCondition; i++) {
                if (board[row + i][col - i] == 'X') {
                    countPlayer1++;
                } else if (board[row + i][col - i] == 'O') {
                    countPlayer2++;
                }
            }
            if (countPlayer1 == winCondition) {
                return -1; // Gracz 1 (X) wygrał
            } else if (countPlayer2 == winCondition) {
                return 1; // Gracz 2 (O) wygrał
            }
        }
    }

    if(getNumberOfPossibleMoves() == 0){
        return 2; // Remis
    }
    return 0; // Nikt nie wygrał
}

void Board::makeMove(Move move, char symbol) {
    setSymbol(move.row, move.column, symbol);
}

vector<Move> Board::getPossibleMoves() {
    vector<Move> possibleMoves;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize ; j++) {
            if (board[i][j] == '*') {
               Move move (i, j);
                possibleMoves.push_back(move);
            }
        }
    }
    return possibleMoves;
}

