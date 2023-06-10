//
// Created by miql on 10.06.2023.
//

#ifndef PAMSI_MOVE_H
#define PAMSI_MOVE_H


class Move {
public:
    int row;
    int column;
    int score;
    Move(int score);
    Move(int row, int column, int score);
    Move();
    Move(int row, int column);

};


#endif //PAMSI_MOVE_H
