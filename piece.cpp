#ifndef PIECE_H
#define PIECE_H
#include "piece.h"
#endif

tic_tac_toe::PIECE::PIECE() {
    __piece = 0;
}

tic_tac_toe::PIECE::PIECE(const char& type) : __piece(type) {}

char tic_tac_toe::PIECE::getpiece() const {
    return __piece;
}