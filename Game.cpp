//
// Created by miql on 26.05.2023.
//

#include "Game.h"

Game::Game() {
    boardSize = 0;
    winCondition = 0;
}

void Game::initializeGame() {
    cout<<"Define what size of board you want to play with (1-10): "<<endl;
    cin>>boardSize;
    while (boardSize < 1 || boardSize > 10 || std::cin.fail()) {
        std::cout << "Wrong input! Try again: " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> boardSize;
    }

    cout<<"Define how many symbols in a row you need to win (1-10): "<<endl;
    cin >> winCondition;
    while (winCondition < 1 || winCondition > boardSize || std::cin.fail()) {
        std::cout << "Wrong input! Try again: " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> winCondition;
    }

    cout<<"Do you want to start first? (y/n)"<<endl;
    char answer;
    cin>>answer;
    while (answer != 'y' && answer != 'n') {
        std::cout << "Wrong input! Try again: " << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> answer;
    }
    if(answer == 'n') {
        Player player1('X', true);
        Player player2('O', false);
        players.push_back(player1);
        players.push_back(player2);
    }else{
        Player player1('X', false);
        Player player2('O', true);
        players.push_back(player1);
        players.push_back(player2);
    }


    for(int i = 0; i < boardSize; i++) {
        vector<char> row;
        row.reserve(boardSize);
        for(int j = 0; j < boardSize; j++) {
            row.push_back('*');
        }
        board.push_back(row);
    }
}

void Game::displayBoard() {
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

int Game::checkWin() {
    // Check win condition vertically
    for (int col = 0; col < boardSize; col++) {
        for (int row = 0; row <= boardSize - winCondition; row++) {
            int countPlayer1 = 0;
            int countPlayer2 = 0;
            for (int i = 0; i < winCondition; i++) {
                if (board[row + i][col] == players[0].getSymbol()) {
                    countPlayer1++;
                } else if (board[row + i][col] == players[1].getSymbol()) {
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
                if (board[row][col + i] == players[0].getSymbol()) {
                    countPlayer1++;
                } else if (board[row][col + i] == players[1].getSymbol()) {
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
                if (board[row + i][col + i] == players[0].getSymbol()) {
                    countPlayer1++;
                } else if (board[row + i][col + i] == players[1].getSymbol()) {
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
                if (board[row + i][col - i] == players[0].getSymbol()) {
                    countPlayer1++;
                } else if (board[row + i][col - i] == players[1].getSymbol()) {
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

    if(turn == boardSize * boardSize){
        return 2; // Remis
    }
    turn++;
    return 0; // Nikt nie wygrał
}

void Game::startGame() {
    initializeGame();
    displayBoard();
    int result = 0;

    while (turn <= boardSize * boardSize && result == 0) {
        players.at((turn-1) % 2).move(board,boardSize);
        displayBoard();
        result = checkWin();
    }

    switch (result) {
        case -1:
            std::cout << "Player 1 (X) won!" << std::endl;
            break;
        case 1:
            std::cout << "Player 2 (0) won!" << std::endl;
            break;
        case 2:
            std::cout << "Tie!" << std::endl;
            break;
        default:
            std::cout << "Error 404 - result not found" << std::endl;
            break;
    }
}

