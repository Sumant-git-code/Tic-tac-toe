#ifndef MOVE_H
#define MOVE_H
#include "move.h"
#endif

tic_tac_toe::MOVE::MOVE(const int& size) {
    grid = new GRID(size);
    num_move = 0;
    total_num_move = size*size;
    min_move = size+(size-1);
    grid->print();
}
void tic_tac_toe::MOVE::get_move(const PLAYER& player) {
    std::cout << "Enter move for " << player.getname() << std::endl;
    int x, y;
    std::cin >> x >> y;
    x -= 1;
    y -= 1;
    move = std::make_pair(x, y);
    if(!check_move() | !check_coor()){
        std::cout << "Invalid Move : " << std::endl;
        get_move(player);
    }
    else {
        grid->insert(move, player.getpiece());
        grid->print();
        num_move++;
    }
}

bool tic_tac_toe::MOVE::check_move() const {
    PIECE curr_piece = grid->getval(move);
    return (curr_piece.getpiece()==0);
}

bool tic_tac_toe::MOVE::check_win() const {
    return (grid->check_win(move) & num_move >= (min_move));
}

bool tic_tac_toe::MOVE::check_terminate() const {
    return num_move == total_num_move;
}

bool tic_tac_toe::MOVE::check_coor() const {
    return grid->check_coor(move);
}