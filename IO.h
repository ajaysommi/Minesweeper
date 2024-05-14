#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#ifndef MINESWEEPER_IO_H
#define MINESWEEPER_IO_H

std::string getCharacter(char input_char);
void setText(sf::Text &welcome_text, float x, float y);

#endif //MINESWEEPER_IO_H
