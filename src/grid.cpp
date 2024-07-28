#ifndef GRID_H
#define GRID_H
#include "grid.h"
#endif
#include<iostream>
#include<stdexcept>

tic_tac_toe::GRID::GRID(const int& size) {
    grid = new PIECE[size*size];
    __dim = size;
}

void tic_tac_toe::GRID::insert(const std::pair<int, int>& coor, const PIECE& type) {
    grid[coor.first*__dim+coor.second] = type;
}

void tic_tac_toe::GRID::print() const {
    for(int i=0; i<__dim; i++) {
        // std::cout << " ---------" << std::endl;
        std::cout << "\t\t\t| ";
        for(int j=0; j<__dim; j++) {
            std::cout << grid[i*__dim + j].getpiece() << " | ";
        }
        std::cout << std::endl;
        // std::cout << " ---------" << std::endl;
    }
}

tic_tac_toe::PIECE tic_tac_toe::GRID::getval(const std::pair<int, int>& coor) const{
    return grid[coor.first*__dim + coor.second];
}

bool tic_tac_toe::GRID::check_win(const std::pair<int, int>& coor) const {
    // Checking for vertical
    bool ver = true;
    for(int i=1; i<__dim; i++) {
        if(grid[(i-1)*__dim+coor.second].getpiece()!=grid[i*__dim+coor.second].getpiece()) {
            ver = false;
            break;
        }
    }

    // Checking for vertical
    bool hor = true;
    for(int i=1; i<__dim; i++) {
        if(grid[(i-1)+coor.first*__dim].getpiece()!=grid[i+coor.first*__dim].getpiece()) {
            hor = false;
            break;
        }
    }

    // Checking for diagonal
    bool diag = true;
    for(int i=1; i<__dim; i++) {
        if(grid[(i-1)*(__dim+1)].getpiece()!=grid[i*(__dim+1)].getpiece()) {
            diag = false;
            break;
        }
    }

    // Checking for anti-diagonal
    bool anti_diag = true;
    for(int i=1; i<__dim; i++) {
        if(grid[(i-1)*__dim + (__dim-i)].getpiece()!=grid[i*(__dim) + (__dim-i-1)].getpiece()) {
            anti_diag = false;
            break;
        }
    }

    std::cout << "HOR = " << hor << ", VER = " << ver << ", DIAG = " << diag << ", ANTI-DIAG = " << anti_diag << std::endl;

    return (hor | ver | diag | anti_diag);
}

bool tic_tac_toe::GRID::check_coor(const std::pair<int, int>& coor) const {
    return !(coor.first >= __dim | coor.first < 0 | coor.second >= __dim | coor.second < 0);
}