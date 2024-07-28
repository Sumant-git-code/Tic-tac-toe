#ifndef MOVE_H
#define MOVE_H
#include "move.h"
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"
#endif

#include<iostream>
#include<deque>

#define SIZE 3

int main() {   
    std::string name;
    std::cout << "Enter the name of first player : ";
    std::cin >> name;
    tic_tac_toe::PLAYER player1(name, 'X');
    std::cout << "Enter the name of second player : ";
    std::cin >> name;
    tic_tac_toe::PLAYER player2(name, 'O');

    tic_tac_toe::MOVE moves(SIZE);

    std::deque<tic_tac_toe::PLAYER> list_player;
    list_player.push_back(player1);
    list_player.push_back(player2);
    tic_tac_toe::PLAYER curr_player;
    while(moves.check_terminate()==false & moves.check_win()==false) {
        curr_player = list_player.front();
        moves.get_move(curr_player);
        list_player.pop_front();
        list_player.push_back(curr_player);
    }
    if(moves.check_terminate()) {
        std::cout << "*************** DRAW ***************" << std::endl;
    }
    if(moves.check_win()) {
        std::cout << list_player.back().getname() << " WON" << std::endl;
    }
}