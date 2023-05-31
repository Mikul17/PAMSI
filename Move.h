//
// Created by miql on 27.05.2023.
//

#ifndef PAMSI_MOVE_H
#define PAMSI_MOVE_H


class Move {
private:
    int row;
    int column;
    int score;
public:
    Move(int row, int column, int score);
};


#endif //PAMSI_MOVE_H
