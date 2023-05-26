//
// Created by miql on 26.05.2023.
//

#include "Player.h"

Player::Player(char symbol, bool isComputer) {
    this->symbol = symbol;
    this->isComputer = isComputer;
}

char Player::getSymbol() {
    return symbol;
}

void Player::aiMove(vector<vector<char>>& board, int boardSize){

}

void Player::move(vector<vector<char>>& board, int boardSize) {
    char column;
    int row;
    if(isComputer) {
        row = rand () % boardSize + 1;
        column = 'a' + rand () % boardSize;
        while(board[row - 1][column - 'a'] != '*'){
            row = rand () % boardSize + 1;
            column = 'a' + rand () % boardSize;
        }
        board[row - 1][column - 'a'] = symbol;
    } else {
       cout << "Enter coordinates of your move: (column row)" << endl;
       cout<<"Player move: ";
       cin>>column>>row;
         while (row < 1 || row > boardSize || column < 'a' || column > 'a' + boardSize || board[row - 1][column - 'a'] != '*' || std::cin.fail()) {
              std::cout << "Wrong input! Try again: " << std::endl;

              std::cin.clear();
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

              std::cin >> column >> row;
         }
         board[row - 1][column - 'a'] = symbol;
    }
}
