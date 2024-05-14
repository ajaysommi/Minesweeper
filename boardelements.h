#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#ifndef MINESWEEPER_BOARDELEMENTS_H
#define MINESWEEPER_BOARDELEMENTS_H

class Tile {
public:
    bool isMine = false;
    bool isRevealed = false;
    bool flag = false;
    int num_value;
    int x;
    int y;
    Tile(bool isMine, bool isRevealed, bool flag, int x, int y);

    void set_mine_condition();
};





#endif //MINESWEEPER_BOARDELEMENTS_H
