#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"
#endif

#ifndef GRID_H
#define GRID_H
#include "grid.h"
#endif

#include<iostream>

namespace tic_tac_toe {
    class MOVE {
        private:
            std::pair<int, int> move;
            GRID* grid;
            int num_move;
            int total_num_move;
            int min_move;
        public:
            MOVE(const int& size);
            void get_move(const PLAYER& player);
            bool check_move() const;
            bool check_win() const;
            bool check_terminate() const;
            bool check_coor() const;
    };
}