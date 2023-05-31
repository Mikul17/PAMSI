//
// Created by miql on 26.05.2023.
//

#include "Game.h"
#include "ComputerPlayer.h"


void Game::initializeGame() {
    int boardSize;
    int winCondition;

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

    this->board=Board(boardSize, winCondition);
    answer=='y'?isComputerFirst=false:isComputerFirst=true;

}

void Game:: startGame() {
    initializeGame();
    this->computerPlayer=ComputerPlayer(board, isComputerFirst?'X':'O');

    while (gameState == 0) {
        board.displayBoard();
        if(isComputerFirst){
            if(turn%2==0){
                computerPlayer.makeMove(board);
            }else{
                playerMove();
            }
        }else{
            if(turn%2==0){
                playerMove();
            }else{
                computerPlayer.makeMove(board);
            }
        }
        turn++;
        gameState = board.evaluateBoard();
    }
    board.displayBoard();
    switch (gameState) {
        case -1:
            isComputerFirst ? cout << "Player 1 (X) won!" << endl :cout << "Player 2 (0) won!" << endl;
            break;
        case 1:
            isComputerFirst ? cout << "Player 2 (O) won!" << endl :cout << "Player 2 (X) won!" << endl;
            break;
        case 2:
            std::cout << "Tie!" << std::endl;
            break;
        default:
            std::cout << "Error 404 - result not found" << std::endl;
            break;
    }
}

void Game::playerMove() {
        char column;
        int row;
        cout << "Enter coordinates of your move: (column row)" << endl;
        cout<<"Player move: ";
        cin>>column>>row;
        while (row < 1 || row > this->board.getBoardSize() || column < 'a' || column > 'a' + this->board.getBoardSize() ||  this->board.getSymbol(row-1,column-'a')!= '*' || std::cin.fail()) {
            std::cout << "Wrong input! Try again: " << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cin >> column >> row;
        }
        this->board.setSymbol(row-1,column-'a',isComputerFirst?'O':'X');
}





