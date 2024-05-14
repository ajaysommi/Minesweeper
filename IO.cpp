#include "IO.h"

std::string getCharacter(char input_char) {

}

void setText(sf::Text &welcome_text, float x, float y) {
    sf::FloatRect textRect = welcome_text.getLocalBounds();
    welcome_text.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
    welcome_text.setPosition(sf::Vector2f(x, y));
}
