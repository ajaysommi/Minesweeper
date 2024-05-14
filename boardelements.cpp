#include "boardelements.h"

Tile::Tile(bool isMine, bool isRevealed, bool flag, int x, int y) {
    this->isMine = isMine;
    this->isRevealed = isRevealed;
    this->flag = flag;
    this->num_value = num_value;
    this->x = x;
    this->y = y;
}

void Tile::set_mine_condition() {
    this->isMine = true;
}
