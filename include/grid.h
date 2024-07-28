#ifndef PIECE_H
#define PIECE_H
#include "piece.h"
#endif
#include<vector>

namespace tic_tac_toe {
    class GRID {
        private:
            int __dim;
            PIECE* grid;
        public :
            GRID(const int& size);
            void print() const;
            void insert(const std::pair<int, int>& coor, const PIECE& type);
            PIECE getval(const std::pair<int, int>& coor) const;
            bool check_win(const std::pair<int, int>& coor) const;
            bool check_coor(const std::pair<int, int>& coor) const;
    };
}