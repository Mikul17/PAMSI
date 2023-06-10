//
// Created by miql on 10.06.2023.
//

#include "Move.h"

Move::Move(int score) {
    this->score=score;
}

Move::Move(int row, int column, int score){
    this->row=row;
    this->column=column;
    this->score=score;
}

Move::Move(int row, int column){
    this->row=row;
    this->column=column;
    this->score=-1;
}

Move::Move(){
    this->row=-1;
    this->column=-1;
    this->score=-1;
}