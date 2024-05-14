#include "leaderboard.h"
#include "IO.h"

void activate_leaderboard() {
    std::fstream file("./files/config.cfg", std::ios::in);
    std::string colCount, rowCount;
    getline(file, colCount, '\n');
    getline(file, rowCount, '\n');
    sf::RenderWindow game_window(sf::VideoMode((std::stoi(colCount) * 16),
                                               (std::stoi(rowCount) * 16) + 50), "Leaderboard");
    std::fstream player_content("./files/leaderboard.txt",std::ios::in);
    std::vector<std::string> player_time, player_name;
    while (player_content) {
        std::string time, name;
        getline(player_content, time, ',');
        getline(player_content, name, '\n');
        player_time.push_back(time);
        player_name.push_back(name);
    }
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < player_time.size() - 2; i++) {
            if (std::stoi(player_time[i].substr(0, 2)) > std::stoi(player_time[i + 1].substr(0, 2))) {
                sorted = false;
                std::string buffer_num, buffer_name;
                buffer_num = player_time[i];
                player_time[i] = player_time[i + 1];
                player_time[i + 1] = buffer_num;
                buffer_name = player_name[i];
                player_name[i] = player_name[i + 1];
                player_name[i + 1] = buffer_name;
            }
            else if (std::stoi(player_time[i].substr(0, 2)) == std::stoi(player_time[i + 1].substr(0, 2))) {
                if (std::stoi(player_time[i].substr(3, 2)) > std::stoi(player_time[i + 1].substr(3, 2))) {
                    sorted = false;
                    std::string buffer_num, buffer_name;
                    buffer_num = player_time[i];
                    player_time[i] = player_time[i + 1];
                    player_time[i + 1] = buffer_num;
                    buffer_name = player_name[i];
                    player_name[i] = player_name[i + 1];
                    player_name[i + 1] = buffer_name;
                }
            }
        }
    }
    sf::Font font;
    font.loadFromFile("./files/font.ttf");
    sf::Text welcome_text;
    welcome_text.setFont(font);
    welcome_text.setString("LEADERBOARD");
    welcome_text.setCharacterSize(20);
    welcome_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(welcome_text, ((std::stoi(colCount) * 16) / 2), (((std::stoi(rowCount) * 16) + 50) / 2) - 120);
    std::string buffer_string_first = "1.\t" + player_time[0] + "\t" + player_name[0] + "\n\n"
            + "2.\t" + player_time[1] + "\t" + player_name[1] + "\n\n"
            + "3.\t" + player_time[2] + "\t" + player_name[2] + "\n\n"
            + "4.\t" + player_time[3] + "\t" + player_name[3] + "\n\n"
            + "5.\t" + player_time[4] + "\t" + player_name[4] + "\n\n";
    sf::Text player_details;
    player_details.setFont(font);
    player_details.setString(buffer_string_first);
    player_details.setCharacterSize(18);
    player_details.setStyle(sf::Text::Bold);
    setText(player_details, ((std::stoi(colCount) * 16) / 2), (((std::stoi(rowCount) * 16) + 50) / 2) + 20);
    while (game_window.isOpen()) {
        sf::Event event;
        while (game_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game_window.close();
            }
        }
        game_window.clear(sf::Color::Blue);
        game_window.draw(welcome_text);
        game_window.draw(player_details);
        game_window.display();
        }
    }


void activate_leaderboard(std::string name, int time) {
    std::fstream file("./files/config.cfg", std::ios::in);
    std::string colCount, rowCount;
    getline(file, colCount, '\n');
    getline(file, rowCount, '\n');
    sf::RenderWindow game_window(sf::VideoMode((std::stoi(colCount) * 16),
                                               (std::stoi(rowCount) * 16) + 50), "Leaderboard");
    std::fstream player_content("./files/leaderboard.txt",std::ios::in);
    std::vector<std::string> player_time, player_name;
    while (player_content) {
        std::string time, name;
        getline(player_content, time, ',');
        getline(player_content, name, '\n');
        player_time.push_back(time);
        player_name.push_back(name);
    }
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < player_time.size() - 2; i++) {
            if (std::stoi(player_time[i].substr(0, 2)) > std::stoi(player_time[i + 1].substr(0, 2))) {
                sorted = false;
                std::string buffer_num, buffer_name;
                buffer_num = player_time[i];
                player_time[i] = player_time[i + 1];
                player_time[i + 1] = buffer_num;
                buffer_name = player_name[i];
                player_name[i] = player_name[i + 1];
                player_name[i + 1] = buffer_name;
            }
            else if (std::stoi(player_time[i].substr(0, 2)) == std::stoi(player_time[i + 1].substr(0, 2))) {
                if (std::stoi(player_time[i].substr(3, 2)) > std::stoi(player_time[i + 1].substr(3, 2))) {
                    sorted = false;
                    std::string buffer_num, buffer_name;
                    buffer_num = player_time[i];
                    player_time[i] = player_time[i + 1];
                    player_time[i + 1] = buffer_num;
                    buffer_name = player_name[i];
                    player_name[i] = player_name[i + 1];
                    player_name[i + 1] = buffer_name;
                }
            }
        }
    }
    sf::Font font;
    font.loadFromFile("./files/font.ttf");
    sf::Text welcome_text;
    welcome_text.setFont(font);
    welcome_text.setString("LEADERBOARD");
    welcome_text.setCharacterSize(20);
    welcome_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(welcome_text, ((std::stoi(colCount) * 16) / 2), (((std::stoi(rowCount) * 16) + 50) / 2) - 120);
    std::string buffer_string_first = "1.\t" + player_time[0] + "\t" + player_name[0] + "\n\n"
                                      + "2.\t" + player_time[1] + "\t" + player_name[1] + "\n\n"
                                      + "3.\t" + player_time[2] + "\t" + player_name[2] + "\n\n"
                                      + "4.\t" + player_time[3] + "\t" + player_name[3] + "\n\n"
                                      + "5.\t" + player_time[4] + "\t" + player_name[4] + "\n\n";
    sf::Text player_details;
    player_details.setFont(font);
    player_details.setString(buffer_string_first);
    player_details.setCharacterSize(18);
    player_details.setStyle(sf::Text::Bold);
    setText(player_details, ((std::stoi(colCount) * 16) / 2), (((std::stoi(rowCount) * 16) + 50) / 2) + 20);
    while (game_window.isOpen()) {
        sf::Event event;
        while (game_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game_window.close();
            }
        }
        game_window.clear(sf::Color::Blue);
        game_window.draw(welcome_text);
        game_window.draw(player_details);
        game_window.display();
    }
}