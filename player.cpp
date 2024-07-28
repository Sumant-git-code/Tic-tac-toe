#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"
#endif

tic_tac_toe::PLAYER::PLAYER(const std::string& name, const char& type) : __name(name) {
    __piece = PIECE(type);
}

std::string tic_tac_toe::PLAYER::getname() const {
    return __name;
}

tic_tac_toe::PIECE tic_tac_toe::PLAYER::getpiece() const {
    return __piece;
}