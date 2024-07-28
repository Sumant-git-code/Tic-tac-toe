#ifndef PIECE_H
#define PIECE_H
#include "piece.h"
#endif

#include<iostream>

namespace tic_tac_toe {
    class PLAYER {
        private:
            std::string __name;
            PIECE __piece;
        public:
            PLAYER() {}
            PLAYER(const std::string& name, const char& type);
            std::string getname() const;
            PIECE getpiece() const;
    };
}