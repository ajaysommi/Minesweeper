#include "gamewindow.h"
#include "leaderboard.h"
#include "boardelements.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

void activate_game_window() {
    std::fstream file("./files/config.cfg", std::ios::in);
    std::string colCount;
    std::string rowCount;
    std::string mineCount;
    getline(file, colCount, '\n');
    getline(file, rowCount, '\n');
    getline(file, mineCount, '\n');
    std::cout << colCount << rowCount << mineCount << std::endl;
    sf::RenderWindow game_window(sf::VideoMode((std::stoi(colCount) * 32),
                                               (std::stoi(rowCount) * 32) + 100),"Minesweeper");
    game_window.clear(sf::Color::White);
    //declaring map to store digits images to integer values
    std::map<char, sf::Sprite> digits_map;
    bool run_digits_once = false;
    bool active_buttons = true;
    bool lose_face = false;
    std::string digits_compare;
    //declaring universal mine counter
    int univeral_mine_count = stoi(mineCount);
    //texture for hidden_tile
    sf::Texture hidden_tile_image;
    hidden_tile_image.loadFromFile("./files/images/tile_hidden.png");
    sf::Sprite hidden_sprite;
    hidden_sprite.setTexture(hidden_tile_image);
    //texture for revealed_tile
    sf::Texture revealed_tile_image;
    revealed_tile_image.loadFromFile("./files/images/tile_revealed.png");
    sf::Sprite revealed_sprite;
    revealed_sprite.setTexture(revealed_tile_image);
    //texture for debug
    sf::Texture debug_image;
    debug_image.loadFromFile("./files/images/debug.png");
    sf::Sprite debug_sprite;
    debug_sprite.setTexture(debug_image);
    debug_sprite.setPosition((((stoi(colCount))*32)-304), 32*(stoi(rowCount)+0.5));

    //texture for digits
    sf::Texture digits_image;
    digits_image.loadFromFile("./files/images/digits.png");
    sf::Sprite digits_sprite;
    digits_sprite.setTexture(digits_image);

    //digit 0 in digits image
    sf::Sprite digit_0;
    digit_0.setTexture(digits_image);
    digit_0.setTextureRect(sf::IntRect(0,0,21,32));
    digits_map.emplace('0',digit_0);
    //digit 1 in digits image
    sf::Sprite digit_1;
    digit_1.setTexture(digits_image);
    digit_1.setTextureRect(sf::IntRect(21,0,21,32));
    digits_map.emplace('1',digit_1);
    //digit 2 in digits image
    sf::Sprite digit_2;
    digit_2.setTexture(digits_image);
    digit_2.setTextureRect(sf::IntRect(42,0,21,32));
    digits_map.emplace('2',digit_2);
    //digit 3 in digits image
    sf::Sprite digit_3;
    digit_3.setTexture(digits_image);
    digit_3.setTextureRect(sf::IntRect(63,0,21,32));
    digits_map.emplace('3',digit_3);
    //digit 4 in digits image
    sf::Sprite digit_4;
    digit_4.setTexture(digits_image);
    digit_4.setTextureRect(sf::IntRect(84,0,21,32));
    digits_map.emplace('4',digit_4);
    //digit 5 in digits image
    sf::Sprite digit_5;
    digit_5.setTexture(digits_image);
    digit_5.setTextureRect(sf::IntRect(105,0,21,32));
    digits_map.emplace('5',digit_5);
    //digit 6 in digits image
    sf::Sprite digit_6;
    digit_6.setTexture(digits_image);
    digit_6.setTextureRect(sf::IntRect(126,0,21,32));
    digits_map.emplace('6',digit_6);
    //digit 7 in digits image
    sf::Sprite digit_7;
    digit_7.setTexture(digits_image);
    digit_7.setTextureRect(sf::IntRect(147,0,21,32));
    digits_map.emplace('7',digit_7);
    //digit 8 in digits image
    sf::Sprite digit_8;
    digit_8.setTexture(digits_image);
    digit_8.setTextureRect(sf::IntRect(168,0,21,32));
    digits_map.emplace('8',digit_8);
    //digit 2 in digits image
    sf::Sprite digit_9;
    digit_9.setTexture(digits_image);
    digit_9.setTextureRect(sf::IntRect(189,0,21,32));
    digits_map.emplace('9',digit_9);
    //digit neg in digits image
    sf::Sprite digit_neg;
    digit_neg.setTexture(digits_image);
    digit_neg.setTextureRect(sf::IntRect(210,0,21,32));
    digits_map.emplace('-',digit_neg);

    //texture for happy_face
    sf::Texture happy_image;
    happy_image.loadFromFile("./files/images/face_happy.png");
    sf::Sprite happy_sprite;
    happy_sprite.setTexture(happy_image);
    if (!lose_face) {
        happy_sprite.setPosition((((stoi(colCount)/2.0f)*32)-32), 32*(stoi(rowCount)+0.5));
    }
    //texture for lose_image
    sf::Texture lose_image;
    lose_image.loadFromFile("./files/images/face_lose.png");
    sf::Sprite lose_sprite;
    lose_sprite.setTexture(lose_image);
    if (lose_face) {
        lose_sprite.setPosition((((stoi(colCount)/2.0f)*32)-32), 32*(stoi(rowCount)+0.5));
    }
    //texture for win_face
    sf::Texture win_image;
    win_image.loadFromFile("./files/images/face_win.png");
    sf::Sprite win_sprite;
    win_sprite.setTexture(win_image);
    //texture for flag
    sf::Texture flag_image;
    flag_image.loadFromFile("./files/images/flag.png");
    sf::Sprite flag_sprite;
    flag_sprite.setTexture(flag_image);
    //texture for leaderboard_iamge
    sf::Texture leaderboard_image;
    leaderboard_image.loadFromFile("./files/images/leaderboard.png");
    sf::Sprite leader_sprite;
    leader_sprite.setTexture(leaderboard_image);
    leader_sprite.setPosition((((stoi(colCount))*32)-176), 32*(stoi(rowCount)+0.5));
    //texture for mine
    sf::Texture mine_image;
    mine_image.loadFromFile("./files/images/mine.png");
    sf::Sprite mine_sprite;
    mine_sprite.setTexture(mine_image);
    //texture for numbers
    sf::Texture one_image;
    one_image.loadFromFile("./files/images/number_1.png");
    sf::Sprite sprite_one;
    sprite_one.setTexture(one_image);
    sf::Texture two_image;
    two_image.loadFromFile("./files/images/number_2.png");
    sf::Sprite sprite_two;
    sprite_two.setTexture(two_image);
    sf::Texture three_image;
    three_image.loadFromFile("./files/images/number_3.png");
    sf::Sprite sprite_three;
    sprite_three.setTexture(three_image);
    sf::Texture four_image;
    four_image.loadFromFile("./files/images/number_4.png");
    sf::Sprite sprite_four;
    sprite_four.setTexture(four_image);
    sf::Texture five_image;
    five_image.loadFromFile("./files/images/number_5.png");
    sf::Sprite sprite_five;
    sprite_five.setTexture(five_image);
    sf::Texture six_image;
    six_image.loadFromFile("./files/images/number_6.png");
    sf::Sprite sprite_six;
    sprite_six.setTexture(six_image);
    sf::Texture seven_image;
    seven_image.loadFromFile("./files/images/number_7.png");
    sf::Sprite sprite_seven;
    sprite_seven.setTexture(seven_image);
    sf::Texture eight_image;
    eight_image.loadFromFile("./files/images/number_8.png");
    sf::Sprite sprite_eight;
    sprite_eight.setTexture(eight_image);
    //texture for pause_image
    sf::Texture pause_image;
    pause_image.loadFromFile("./files/images/pause.png");
    sf::Sprite sprite_pause;
    sprite_pause.setPosition((((stoi(colCount))*32)-240), 32*(stoi(rowCount)+0.5));
    sprite_pause.setTexture(pause_image);
    //texture for play_image
    sf::Texture play_image;
    play_image.loadFromFile("./files/images/play.png");
    sf::Sprite sprite_play;
    sprite_play.setTexture(play_image);
    sprite_play.setPosition((((stoi(colCount))*32)-240), 32*(stoi(rowCount)+0.5));

    bool play_pause = true;
    std::vector<std::vector<Tile>> grid_total_vector;
    bool add_vector = true;
    bool show_mines = false;
    bool reveal_reveal = false;
    bool leader_clickable = true;
    int counter = 0;
    int mine_max_count = stoi(mineCount);
    int mine_counter = 0;
    while (game_window.isOpen()) {
        game_window.clear(sf::Color::White);
        sf::Event event;
        sf::Sprite temp_tile;
        sf::Sprite tile_sprite;
        sf::Sprite hidden_tile_sprite;
        sf::Sprite mine_sprite1;
        sf::Sprite mine_sprite2;
        sf::Sprite revealll;



        //rand = col
        //rand = row
        //create vector of tiles manually
        //create setter (set_mine_condition) inside tile class
        //go to each random col and row and set that "isMine" to true, only if it is already false
        srand(time(nullptr));
        //back-end portion. this for-loop simply places tiles into 2D vector and assigns random conditions
        if (add_vector) {
            //only creates new tile objects and sets all to false by default
            for (int i = 0; i < stoi(colCount); i++) {
                std::vector<Tile> grid_first_vector;
                for (int j = 0; j < stoi(rowCount); j++) {
                    Tile newTile(false, false, false, j * 32, i * 32);
                    grid_first_vector.push_back(newTile);
                }
                grid_total_vector.push_back(grid_first_vector);
            }

            //sets random tile objects in the vector to have mines
            while (mine_counter < mine_max_count) {
                int rand_col = rand() % stoi(colCount);
                int rand_row = rand() % stoi(rowCount);
                if (rand_col > 25) {
                    std::cout << rand_col << "is the random column" << std::endl;
                }
                if (rand_row > 16) {
                    std::cout << rand_row << "is the random row" << std::endl;
                }
                if (!grid_total_vector[rand_col][rand_row].isMine) {
                    grid_total_vector[rand_col][rand_row].set_mine_condition();
                    mine_counter++;
                }
            }
        }
        add_vector = false;


        //front-end portion. these following for-loops draw the images onto the display where the user can view them
        //have bool and if bool then run the following code. if the user presses the debug button, then the last hidden
        //one should become false and not show
        for (int i = 0; i < stoi(colCount); i++) {
            for (int j = 0; j < stoi(rowCount); j++) {
                tile_sprite.setTexture(revealed_tile_image);
                tile_sprite.setPosition(i*32, j*32);
                //may need to create new texture each run
                game_window.draw(tile_sprite);
            }
        }
        if (show_mines) {
            for (int i = 0; i < stoi(colCount); i++) {
                for (int j = 0; j < stoi(rowCount); j++) {
                    hidden_tile_sprite.setTexture(hidden_tile_image);
                    hidden_tile_sprite.setPosition(i*32, j*32);
                    //may need to create new texture each run
                    game_window.draw(hidden_tile_sprite);
                }
            }
            for (int i = 0; i < stoi(colCount); i++) {
                for (int j = 0; j < stoi(rowCount); j++) {
                    mine_sprite1.setTexture(mine_image);
                    mine_sprite1.setPosition(i*32, j*32);
                    //may need to create new texture each run
                    if (grid_total_vector[i][j].isMine && !grid_total_vector[i][j].flag) {
                        game_window.draw(mine_sprite1);
                    }
                }
            }
        }
        if (!show_mines) {
            for (int i = 0; i < stoi(colCount); i++) {
                for (int j = 0; j < stoi(rowCount); j++) {
                    hidden_tile_sprite.setTexture(hidden_tile_image);
                    hidden_tile_sprite.setPosition(i*32, j*32);
                    flag_sprite.setPosition(i*32, j*32);
                    hidden_tile_sprite.setPosition(i*32, j*32);
                    revealed_sprite.setPosition(i*32, j*32);

                    //may need to create new texture each run
                    game_window.draw(hidden_tile_sprite);
                    if (grid_total_vector[i][j].flag) {
                        game_window.draw(flag_sprite);
                    }
                    //////////////
                    if (grid_total_vector[i][j].isRevealed) {
                        game_window.draw(revealed_sprite);
                    }
                }
            }
        }
        if (!play_pause) {
            for (int i = 0; i < stoi(colCount); i++) {
                for (int j = 0; j < stoi(rowCount); j++) {
                    revealll.setTexture(revealed_tile_image);
                    revealll.setPosition(i*32, j*32);
                    //may need to create new texture each run
                    game_window.draw(revealll);
                }
            }
        }
        while(game_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                game_window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Mouse mouse_click;
                int mouse_x = mouse_click.getPosition(game_window).x;
                int mouse_y = mouse_click.getPosition(game_window).y;
                if (active_buttons) {
                    if (play_pause) {
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                            std::cout << "right" << std::endl;
                            grid_total_vector[mouse_x/32][mouse_y/32].flag = !grid_total_vector[mouse_x/32][mouse_y/32].flag;
                            if (!grid_total_vector[mouse_x/32][mouse_y/32].flag) {
                                univeral_mine_count++;
                            }
                            else {
                                univeral_mine_count--;
                            }
                            run_digits_once = false;
                        }
                    }
                    if(sprite_play.getGlobalBounds().contains(mouse_x, mouse_y)) {
                        play_pause = !play_pause;
                    }
                    if (play_pause) {
                        if(debug_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
                            show_mines = !show_mines;
                        }
                    }
                }
                if(leader_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
                    activate_leaderboard();
                }
                if (play_pause) {
                    if(happy_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
                        grid_total_vector.clear();
                        mine_counter = 0;
                        univeral_mine_count = stoi(mineCount);
                        add_vector = true;
                        run_digits_once = false;
                        active_buttons = true;
                        if (lose_face) {
                            lose_face = !lose_face;
                        }
                        if (show_mines) {
                            show_mines = !show_mines;
                        }
                    }
                    if(lose_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
                        grid_total_vector.clear();
                        mine_counter = 0;
                        univeral_mine_count = stoi(mineCount);
                        add_vector = true;
                        run_digits_once = false;
                        if (lose_face) {
                            lose_face = !lose_face;
                        }
                        if (show_mines) {
                            show_mines = !show_mines;
                        }
                    }
                    else {
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            int x_val = mouse_x / 32;
                            int y_val = mouse_y / 32;
                            if (x_val < stoi(colCount) && y_val < stoi(rowCount)) {
                                bool fd = grid_total_vector[x_val][y_val].isMine;
                                if (fd && !grid_total_vector[x_val][y_val].flag) {
                                    if (!lose_face) {
                                        active_buttons = false;
                                        lose_face = !lose_face;
                                        lose_sprite.setPosition((((stoi(colCount) / 2.0f) * 32) - 32),
                                                                32 * (stoi(rowCount) + 0.5));
                                        if (!show_mines) {
                                            show_mines = !show_mines;
                                        }
                                        std::cout << "loser" << std::endl;
                                    }
                                }
                                /////////
                                if (!fd && !grid_total_vector[x_val][y_val].flag) {
                                    grid_total_vector[mouse_x/32][mouse_y/32].isRevealed = true;
                                }
                                std::cout << fd;
                                //function that takes in x and y, and knows which tile was clicked
                            }
                        }
                    }
                }
            }
        }

        game_window.draw(debug_sprite);
        if (!lose_face) {
            game_window.draw(happy_sprite);
        }
        if (lose_face) {
            game_window.draw(lose_sprite);
        }
//        game_window.draw(tile_sprite);
        if (play_pause == false) {
            game_window.draw(sprite_play);
        }
        else {
            game_window.draw(sprite_pause);
        }

        //creating buffer sprites to display as digits for counter
        sf::Sprite negative_val;
        sf::Sprite first_digit;
        sf::Sprite second_digit;
        sf::Sprite third_digit;

        ///////////
        sf::Sprite digit_0_t;
        digit_0_t.setTexture(digits_image);
        digit_0_t.setTextureRect(sf::IntRect(0,0,21,32));
        digit_0_t.setPosition((stoi(colCount)*32)-97, 32*((stoi(rowCount))+0.5)+16);

        sf::Sprite digit_1_t;
        digit_1_t.setTexture(digits_image);
        digit_1_t.setTextureRect(sf::IntRect(0,0,21,32));
        digit_1_t.setPosition((stoi(colCount)*32)-76, 32*((stoi(rowCount))+0.5)+16);

        sf::Sprite digit_2_t;
        digit_2_t.setTexture(digits_image);
        digit_2_t.setTextureRect(sf::IntRect(0,0,21,32));
        digit_2_t.setPosition((stoi(colCount)*32)-54, 32*((stoi(rowCount))+0.5)+16);

        sf::Sprite digit_3_t;
        digit_3_t.setTexture(digits_image);
        digit_3_t.setTextureRect(sf::IntRect(0,0,21,32));
        digit_3_t.setPosition((stoi(colCount)*32)-33, 32*((stoi(rowCount))+0.5)+16);

        int first_val_d;
        int second_val_d;
        int third_val_d;

        bool neg_checker = false;
        if (univeral_mine_count < 0) {
            neg_checker = true;
            digit_neg.setPosition(12, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_neg);
        }
        int digit_placement = 0;
        if (!run_digits_once) {
            std::string mine_count_str = std::to_string(univeral_mine_count);
            if (univeral_mine_count >= 0) {
                if (mine_count_str.size() == 3) {
                    first_val_d = mine_count_str[0] - '0';
                    second_val_d = mine_count_str[1] - '0';
                    third_val_d = mine_count_str[2] - '0';
                }
                if (mine_count_str.size() == 2) {
                    first_val_d = 0;
                    second_val_d = mine_count_str[0] - '0';
                    third_val_d = mine_count_str[1] - '0';
                }
                if (mine_count_str.size() == 1) {
                    first_val_d = 0;
                    second_val_d = 0;
                    third_val_d = mine_count_str[0] - '0';
                }
            }
            if (univeral_mine_count < 0) {
                if (mine_count_str.size() == 4) {
                    first_val_d = mine_count_str[1] - '0';
                    second_val_d = mine_count_str[2] - '0';
                    third_val_d = mine_count_str[3] - '0';
                }
                if (mine_count_str.size() == 3) {
                    first_val_d = 0;
                    second_val_d = mine_count_str[1] - '0';
                    third_val_d = mine_count_str[2] - '0';
                }
                if (mine_count_str.size() == 2) {
                    first_val_d = 0;
                    second_val_d = 0;
                    third_val_d = mine_count_str[1] - '0';
                }
            }
        }

        if (first_val_d == 0) {
            digit_0.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_0);
        }
        else if (first_val_d == 1) {
            digit_1.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_1);
        }
        else if (first_val_d == 2) {
            digit_2.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_2);
        }
        else if (first_val_d == 3) {
            digit_3.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_3);
        }
        else if (first_val_d == 4) {
            digit_4.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_4);
        }
        else if (first_val_d == 5) {
            digit_5.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_5);
        }
        else if (first_val_d == 6) {
            digit_6.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_6);
        }
        else if (first_val_d == 7) {
            digit_7.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_7);
        }
        else if (first_val_d == 8) {
            digit_8.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_8);
        }
        else if (first_val_d == 9) {
            digit_9.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_9);
        }

        if (second_val_d == 0) {
            digit_0.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_0);
        }
        else if (second_val_d == 1) {
            digit_1.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_1);
        }
        else if (second_val_d == 2) {
            digit_2.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_2);
        }
        else if (second_val_d == 3) {
            digit_3.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_3);
        }
        else if (second_val_d == 4) {
            digit_4.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_4);
        }
        else if (second_val_d == 5) {
            digit_5.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_5);
        }
        else if (second_val_d == 6) {
            digit_6.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_6);
        }
        else if (second_val_d == 7) {
            digit_7.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_7);
        }
        else if (second_val_d == 8) {
            digit_8.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_8);
        }
        else if (second_val_d == 9) {
            digit_9.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_9);
        }

        if (third_val_d == 0) {
            digit_0.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_0);
        }
        else if (third_val_d == 1) {
            digit_1.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_1);
        }
        else if (third_val_d == 2) {
            digit_2.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_2);
        }
        else if (third_val_d == 3) {
            digit_3.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_3);
        }
        else if (third_val_d == 4) {
            digit_4.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_4);
        }
        else if (third_val_d == 5) {
            digit_5.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_5);
        }
        else if (third_val_d == 6) {
            digit_6.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_6);
        }
        else if (third_val_d == 7) {
            digit_7.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_7);
        }
        else if (third_val_d == 8) {
            digit_8.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_8);
        }
        else if (third_val_d == 9) {
            digit_9.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
            game_window.draw(digit_9);
        }
        run_digits_once = true;
        first_digit.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
        second_digit.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
        third_digit.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
        //add flag num should go down, and num should go up if flag removed

        game_window.draw(leader_sprite);
        game_window.draw(first_digit);
        game_window.draw(second_digit);
        game_window.draw(third_digit);
        game_window.draw(digit_0_t);
        game_window.draw(digit_1_t);
        game_window.draw(digit_2_t);
        game_window.draw(digit_3_t);
        game_window.display();
    }
}



//CHRONOO
//std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
//start is now the "now" time value
//std::chrono::duration<long long, std::name> timeElapsed(end - start);
//std::cout << "time elapsed: " << timeElapsed.count() << std::endl;
//shows time duration of a given chunk of code in _nanoseconds??
//turn count into double and then divide by 10000.
//use sf::Time
//sf::Time


//
//#include "gamewindow.h"
//#include "leaderboard.h"
//#include "boardelements.h"
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <map>
//
//void activate_game_window() {
//    std::fstream file("./files/config.cfg", std::ios::in);
//    std::string colCount;
//    std::string rowCount;
//    std::string mineCount;
//    getline(file, colCount, '\n');
//    getline(file, rowCount, '\n');
//    getline(file, mineCount, '\n');
//    std::cout << colCount << rowCount << mineCount << std::endl;
//    sf::RenderWindow game_window(sf::VideoMode((std::stoi(colCount) * 32),
//                                               (std::stoi(rowCount) * 32) + 100),"Minesweeper");
//    game_window.clear(sf::Color::White);
//    //declaring map to store digits images to integer values
//    std::map<char, sf::Sprite> digits_map;
//    bool run_digits_once = false;
//    bool active_buttons = true;
//    bool lose_face = false;
//    std::string digits_compare;
//    //declaring universal mine counter
//    int univeral_mine_count = stoi(mineCount);
//    //texture for hidden_tile
//    sf::Texture hidden_tile_image;
//    hidden_tile_image.loadFromFile("./files/images/tile_hidden.png");
//    sf::Sprite hidden_sprite;
//    hidden_sprite.setTexture(hidden_tile_image);
//    //texture for revealed_tile
//    sf::Texture revealed_tile_image;
//    revealed_tile_image.loadFromFile("./files/images/tile_revealed.png");
//    sf::Sprite revealed_sprite;
//    revealed_sprite.setTexture(revealed_tile_image);
//    //texture for debug
//    sf::Texture debug_image;
//    debug_image.loadFromFile("./files/images/debug.png");
//    sf::Sprite debug_sprite;
//    debug_sprite.setTexture(debug_image);
//    debug_sprite.setPosition((((stoi(colCount))*32)-304), 32*(stoi(rowCount)+0.5));
//
//    //texture for digits
//    sf::Texture digits_image;
//    digits_image.loadFromFile("./files/images/digits.png");
//    sf::Sprite digits_sprite;
//    digits_sprite.setTexture(digits_image);
//
//    //digit 0 in digits image
//    sf::Sprite digit_0;
//    digit_0.setTexture(digits_image);
//    digit_0.setTextureRect(sf::IntRect(0,0,21,32));
//    digits_map.emplace('0',digit_0);
//    //digit 1 in digits image
//    sf::Sprite digit_1;
//    digit_1.setTexture(digits_image);
//    digit_1.setTextureRect(sf::IntRect(21,0,21,32));
//    digits_map.emplace('1',digit_1);
//    //digit 2 in digits image
//    sf::Sprite digit_2;
//    digit_2.setTexture(digits_image);
//    digit_2.setTextureRect(sf::IntRect(42,0,21,32));
//    digits_map.emplace('2',digit_2);
//    //digit 3 in digits image
//    sf::Sprite digit_3;
//    digit_3.setTexture(digits_image);
//    digit_3.setTextureRect(sf::IntRect(63,0,21,32));
//    digits_map.emplace('3',digit_3);
//    //digit 4 in digits image
//    sf::Sprite digit_4;
//    digit_4.setTexture(digits_image);
//    digit_4.setTextureRect(sf::IntRect(84,0,21,32));
//    digits_map.emplace('4',digit_4);
//    //digit 5 in digits image
//    sf::Sprite digit_5;
//    digit_5.setTexture(digits_image);
//    digit_5.setTextureRect(sf::IntRect(105,0,21,32));
//    digits_map.emplace('5',digit_5);
//    //digit 6 in digits image
//    sf::Sprite digit_6;
//    digit_6.setTexture(digits_image);
//    digit_6.setTextureRect(sf::IntRect(126,0,21,32));
//    digits_map.emplace('6',digit_6);
//    //digit 7 in digits image
//    sf::Sprite digit_7;
//    digit_7.setTexture(digits_image);
//    digit_7.setTextureRect(sf::IntRect(147,0,21,32));
//    digits_map.emplace('7',digit_7);
//    //digit 8 in digits image
//    sf::Sprite digit_8;
//    digit_8.setTexture(digits_image);
//    digit_8.setTextureRect(sf::IntRect(168,0,21,32));
//    digits_map.emplace('8',digit_8);
//    //digit 2 in digits image
//    sf::Sprite digit_9;
//    digit_9.setTexture(digits_image);
//    digit_9.setTextureRect(sf::IntRect(189,0,21,32));
//    digits_map.emplace('9',digit_9);
//    //digit neg in digits image
//    sf::Sprite digit_neg;
//    digit_neg.setTexture(digits_image);
//    digit_neg.setTextureRect(sf::IntRect(210,0,21,32));
//    digits_map.emplace('-',digit_neg);
//
//    //texture for happy_face
//    sf::Texture happy_image;
//    happy_image.loadFromFile("./files/images/face_happy.png");
//    sf::Sprite happy_sprite;
//    happy_sprite.setTexture(happy_image);
//    if (!lose_face) {
//        happy_sprite.setPosition((((stoi(colCount)/2.0f)*32)-32), 32*(stoi(rowCount)+0.5));
//    }
//    //texture for lose_image
//    sf::Texture lose_image;
//    lose_image.loadFromFile("./files/images/face_lose.png");
//    sf::Sprite lose_sprite;
//    lose_sprite.setTexture(lose_image);
//    if (lose_face) {
//        lose_sprite.setPosition((((stoi(colCount)/2.0f)*32)-32), 32*(stoi(rowCount)+0.5));
//    }
//    //texture for win_face
//    sf::Texture win_image;
//    win_image.loadFromFile("./files/images/face_win.png");
//    sf::Sprite win_sprite;
//    win_sprite.setTexture(win_image);
//    //texture for flag
//    sf::Texture flag_image;
//    flag_image.loadFromFile("./files/images/flag.png");
//    sf::Sprite flag_sprite;
//    flag_sprite.setTexture(flag_image);
//    //texture for leaderboard_iamge
//    sf::Texture leaderboard_image;
//    leaderboard_image.loadFromFile("./files/images/leaderboard.png");
//    sf::Sprite leader_sprite;
//    leader_sprite.setTexture(leaderboard_image);
//    leader_sprite.setPosition((((stoi(colCount))*32)-176), 32*(stoi(rowCount)+0.5));
//    //texture for mine
//    sf::Texture mine_image;
//    mine_image.loadFromFile("./files/images/mine.png");
//    sf::Sprite mine_sprite;
//    mine_sprite.setTexture(mine_image);
//    //texture for numbers
//    sf::Texture one_image;
//    one_image.loadFromFile("./files/images/number_1.png");
//    sf::Sprite sprite_one;
//    sprite_one.setTexture(one_image);
//    sf::Texture two_image;
//    two_image.loadFromFile("./files/images/number_2.png");
//    sf::Sprite sprite_two;
//    sprite_two.setTexture(two_image);
//    sf::Texture three_image;
//    three_image.loadFromFile("./files/images/number_3.png");
//    sf::Sprite sprite_three;
//    sprite_three.setTexture(three_image);
//    sf::Texture four_image;
//    four_image.loadFromFile("./files/images/number_4.png");
//    sf::Sprite sprite_four;
//    sprite_four.setTexture(four_image);
//    sf::Texture five_image;
//    five_image.loadFromFile("./files/images/number_5.png");
//    sf::Sprite sprite_five;
//    sprite_five.setTexture(five_image);
//    sf::Texture six_image;
//    six_image.loadFromFile("./files/images/number_6.png");
//    sf::Sprite sprite_six;
//    sprite_six.setTexture(six_image);
//    sf::Texture seven_image;
//    seven_image.loadFromFile("./files/images/number_7.png");
//    sf::Sprite sprite_seven;
//    sprite_seven.setTexture(seven_image);
//    sf::Texture eight_image;
//    eight_image.loadFromFile("./files/images/number_8.png");
//    sf::Sprite sprite_eight;
//    sprite_eight.setTexture(eight_image);
//    //texture for pause_image
//    sf::Texture pause_image;
//    pause_image.loadFromFile("./files/images/pause.png");
//    sf::Sprite sprite_pause;
//    sprite_pause.setPosition((((stoi(colCount))*32)-240), 32*(stoi(rowCount)+0.5));
//    sprite_pause.setTexture(pause_image);
//    //texture for play_image
//    sf::Texture play_image;
//    play_image.loadFromFile("./files/images/play.png");
//    sf::Sprite sprite_play;
//    sprite_play.setTexture(play_image);
//    sprite_play.setPosition((((stoi(colCount))*32)-240), 32*(stoi(rowCount)+0.5));
//
//    bool play_pause = true;
//    std::vector<std::vector<Tile>> grid_total_vector;
//    bool add_vector = true;
//    bool show_mines = false;
//    bool leader_clickable = true;
//    int counter = 0;
//    int mine_max_count = stoi(mineCount);
//    int mine_counter = 0;
//    while (game_window.isOpen()) {
//        game_window.clear(sf::Color::White);
//        sf::Event event;
//        sf::Sprite temp_tile;
//        sf::Sprite tile_sprite;
//        sf::Sprite hidden_tile_sprite;
//        sf::Sprite mine_sprite1;
//        sf::Sprite mine_sprite2;
//
//
//
//        //rand = col
//        //rand = row
//        //create vector of tiles manually
//        //create setter (set_mine_condition) inside tile class
//        //go to each random col and row and set that "isMine" to true, only if it is already false
//        srand(time(nullptr));
//        //back-end portion. this for-loop simply places tiles into 2D vector and assigns random conditions
//        if (add_vector) {
//            //only creates new tile objects and sets all to false by default
//            for (int i = 0; i < stoi(colCount); i++) {
//                std::vector<Tile> grid_first_vector;
//                for (int j = 0; j < stoi(rowCount); j++) {
//                    Tile newTile(false, false, false, j * 32, i * 32);
//                    grid_first_vector.push_back(newTile);
//                }
//                grid_total_vector.push_back(grid_first_vector);
//            }
//
//            //sets random tile objects in the vector to have mines
//            while (mine_counter < mine_max_count) {
//                int rand_col = rand() % stoi(colCount);
//                int rand_row = rand() % stoi(rowCount);
//                if (rand_col > 25) {
//                    std::cout << rand_col << "is the random column" << std::endl;
//                }
//                if (rand_row > 16) {
//                    std::cout << rand_row << "is the random row" << std::endl;
//                }
//                if (!grid_total_vector[rand_col][rand_row].isMine) {
//                    grid_total_vector[rand_col][rand_row].set_mine_condition();
//                    mine_counter++;
//                }
//            }
//        }
//        add_vector = false;
//
//
//        //front-end portion. these following for-loops draw the images onto the display where the user can view them
//        //have bool and if bool then run the following code. if the user presses the debug button, then the last hidden
//        //one should become false and not show
//        for (int i = 0; i < stoi(colCount); i++) {
//            for (int j = 0; j < stoi(rowCount); j++) {
//                tile_sprite.setTexture(revealed_tile_image);
//                tile_sprite.setPosition(i*32, j*32);
//                //may need to create new texture each run
//                game_window.draw(tile_sprite);
//            }
//        }
//        if (show_mines) {
//            for (int i = 0; i < stoi(colCount); i++) {
//                for (int j = 0; j < stoi(rowCount); j++) {
//                    hidden_tile_sprite.setTexture(hidden_tile_image);
//                    hidden_tile_sprite.setPosition(i*32, j*32);
//                    //may need to create new texture each run
//                    game_window.draw(hidden_tile_sprite);
//                }
//            }
//            for (int i = 0; i < stoi(colCount); i++) {
//                for (int j = 0; j < stoi(rowCount); j++) {
//                    mine_sprite1.setTexture(mine_image);
//                    mine_sprite1.setPosition(i*32, j*32);
//                    //may need to create new texture each run
//                    if (grid_total_vector[i][j].isMine && !grid_total_vector[i][j].flag) {
//                        game_window.draw(mine_sprite1);
//                    }
//                }
//            }
//        }
//        if (!show_mines) {
//            for (int i = 0; i < stoi(colCount); i++) {
//                for (int j = 0; j < stoi(rowCount); j++) {
//                    hidden_tile_sprite.setTexture(hidden_tile_image);
//                    hidden_tile_sprite.setPosition(i*32, j*32);
//                    flag_sprite.setPosition(i*32, j*32);
//                    hidden_tile_sprite.setPosition(i*32, j*32);
//                    revealed_sprite.setPosition(i*32, j*32);
//
//                    //may need to create new texture each run
//                    game_window.draw(hidden_tile_sprite);
//                    if (grid_total_vector[i][j].flag) {
//                        game_window.draw(flag_sprite);
//                    }
//                    //////////////
//                    if (grid_total_vector[i][j].isRevealed) {
//                        game_window.draw(revealed_sprite);
//                    }
//                }
//            }
//        }
//        while(game_window.pollEvent(event)) {
//            if(event.type == sf::Event::Closed) {
//                game_window.close();
//            }
//            if(event.type == sf::Event::MouseButtonPressed) {
//                sf::Mouse mouse_click;
//                int mouse_x = mouse_click.getPosition(game_window).x;
//                int mouse_y = mouse_click.getPosition(game_window).y;
//                if (active_buttons) {
//                    if (play_pause) {
//                        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
//                            std::cout << "right" << std::endl;
//                            grid_total_vector[mouse_x/32][mouse_y/32].flag = !grid_total_vector[mouse_x/32][mouse_y/32].flag;
//                            if (!grid_total_vector[mouse_x/32][mouse_y/32].flag) {
//                                univeral_mine_count++;
//                            }
//                            else {
//                                univeral_mine_count--;
//                            }
//                            run_digits_once = false;
//                        }
//                    }
//                    if(sprite_play.getGlobalBounds().contains(mouse_x, mouse_y)) {
//                        play_pause = !play_pause;
//                    }
//                    if (play_pause) {
//                        if(debug_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
//                            show_mines = !show_mines;
//                        }
//                    }
//                }
//                if(leader_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
//                    activate_leaderboard();
//                }
//                if (play_pause) {
//                    if(happy_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
//                        grid_total_vector.clear();
//                        mine_counter = 0;
//                        univeral_mine_count = stoi(mineCount);
//                        add_vector = true;
//                        run_digits_once = false;
//                        active_buttons = true;
//                        if (lose_face) {
//                            lose_face = !lose_face;
//                        }
//                        if (show_mines) {
//                            show_mines = !show_mines;
//                        }
//                    }
//                    if(lose_sprite.getGlobalBounds().contains(mouse_x, mouse_y)) {
//                        grid_total_vector.clear();
//                        mine_counter = 0;
//                        univeral_mine_count = stoi(mineCount);
//                        add_vector = true;
//                        run_digits_once = false;
//                        if (lose_face) {
//                            lose_face = !lose_face;
//                        }
//                        if (show_mines) {
//                            show_mines = !show_mines;
//                        }
//                    }
//                    else {
//                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//                            int x_val = mouse_x / 32;
//                            int y_val = mouse_y / 32;
//                            if (x_val < stoi(colCount) && y_val < stoi(rowCount)) {
//                                bool fd = grid_total_vector[x_val][y_val].isMine;
//                                if (fd && !grid_total_vector[x_val][y_val].flag) {
//                                    if (!lose_face) {
//                                        active_buttons = false;
//                                        lose_face = !lose_face;
//                                        lose_sprite.setPosition((((stoi(colCount) / 2.0f) * 32) - 32),
//                                                                32 * (stoi(rowCount) + 0.5));
//                                        if (!show_mines) {
//                                            show_mines = !show_mines;
//                                        }
//                                        std::cout << "loser" << std::endl;
//                                    }
//                                }
//                                /////////
//                                if (!fd && !grid_total_vector[x_val][y_val].flag) {
//                                    grid_total_vector[mouse_x/32][mouse_y/32].isRevealed = true;
//                                }
//                                std::cout << fd;
//                                //function that takes in x and y, and knows which tile was clicked
//                            }
//                        }
//                    }
//                }
//            }
//        }
//
//        game_window.draw(debug_sprite);
//        if (!lose_face) {
//            game_window.draw(happy_sprite);
//        }
//        if (lose_face) {
//            game_window.draw(lose_sprite);
//        }
////        game_window.draw(tile_sprite);
//        if (play_pause == false) {
//            game_window.draw(sprite_play);
//        }
//        else {
//            game_window.draw(sprite_pause);
//        }
//
//        //creating buffer sprites to display as digits for counter
//        sf::Sprite negative_val;
//        sf::Sprite first_digit;
//        sf::Sprite second_digit;
//        sf::Sprite third_digit;
//
//        ///////////
//        sf::Sprite digit_0_t;
//        digit_0_t.setTexture(digits_image);
//        digit_0_t.setTextureRect(sf::IntRect(0,0,21,32));
//        digit_0_t.setPosition((stoi(colCount)*32)-97, 32*((stoi(rowCount))+0.5)+16);
//
//        sf::Sprite digit_1_t;
//        digit_1_t.setTexture(digits_image);
//        digit_1_t.setTextureRect(sf::IntRect(0,0,21,32));
//        digit_1_t.setPosition((stoi(colCount)*32)-76, 32*((stoi(rowCount))+0.5)+16);
//
//        sf::Sprite digit_2_t;
//        digit_2_t.setTexture(digits_image);
//        digit_2_t.setTextureRect(sf::IntRect(0,0,21,32));
//        digit_2_t.setPosition((stoi(colCount)*32)-54, 32*((stoi(rowCount))+0.5)+16);
//
//        sf::Sprite digit_3_t;
//        digit_3_t.setTexture(digits_image);
//        digit_3_t.setTextureRect(sf::IntRect(0,0,21,32));
//        digit_3_t.setPosition((stoi(colCount)*32)-33, 32*((stoi(rowCount))+0.5)+16);
//
//        int first_val_d;
//        int second_val_d;
//        int third_val_d;
//
//        bool neg_checker = false;
//        if (univeral_mine_count < 0) {
//            neg_checker = true;
//            digit_neg.setPosition(12, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_neg);
//        }
//        int digit_placement = 0;
//        if (!run_digits_once) {
//            std::string mine_count_str = std::to_string(univeral_mine_count);
//            if (univeral_mine_count >= 0) {
//                if (mine_count_str.size() == 3) {
//                    first_val_d = mine_count_str[0] - '0';
//                    second_val_d = mine_count_str[1] - '0';
//                    third_val_d = mine_count_str[2] - '0';
//                }
//                if (mine_count_str.size() == 2) {
//                    first_val_d = 0;
//                    second_val_d = mine_count_str[0] - '0';
//                    third_val_d = mine_count_str[1] - '0';
//                }
//                if (mine_count_str.size() == 1) {
//                    first_val_d = 0;
//                    second_val_d = 0;
//                    third_val_d = mine_count_str[0] - '0';
//                }
//            }
//            if (univeral_mine_count < 0) {
//                if (mine_count_str.size() == 4) {
//                    first_val_d = mine_count_str[1] - '0';
//                    second_val_d = mine_count_str[2] - '0';
//                    third_val_d = mine_count_str[3] - '0';
//                }
//                if (mine_count_str.size() == 3) {
//                    first_val_d = 0;
//                    second_val_d = mine_count_str[1] - '0';
//                    third_val_d = mine_count_str[2] - '0';
//                }
//                if (mine_count_str.size() == 2) {
//                    first_val_d = 0;
//                    second_val_d = 0;
//                    third_val_d = mine_count_str[1] - '0';
//                }
//            }
//        }
//
//        if (first_val_d == 0) {
//            digit_0.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_0);
//        }
//        else if (first_val_d == 1) {
//            digit_1.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_1);
//        }
//        else if (first_val_d == 2) {
//            digit_2.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_2);
//        }
//        else if (first_val_d == 3) {
//            digit_3.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_3);
//        }
//        else if (first_val_d == 4) {
//            digit_4.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_4);
//        }
//        else if (first_val_d == 5) {
//            digit_5.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_5);
//        }
//        else if (first_val_d == 6) {
//            digit_6.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_6);
//        }
//        else if (first_val_d == 7) {
//            digit_7.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_7);
//        }
//        else if (first_val_d == 8) {
//            digit_8.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_8);
//        }
//        else if (first_val_d == 9) {
//            digit_9.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_9);
//        }
//
//        if (second_val_d == 0) {
//            digit_0.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_0);
//        }
//        else if (second_val_d == 1) {
//            digit_1.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_1);
//        }
//        else if (second_val_d == 2) {
//            digit_2.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_2);
//        }
//        else if (second_val_d == 3) {
//            digit_3.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_3);
//        }
//        else if (second_val_d == 4) {
//            digit_4.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_4);
//        }
//        else if (second_val_d == 5) {
//            digit_5.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_5);
//        }
//        else if (second_val_d == 6) {
//            digit_6.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_6);
//        }
//        else if (second_val_d == 7) {
//            digit_7.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_7);
//        }
//        else if (second_val_d == 8) {
//            digit_8.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_8);
//        }
//        else if (second_val_d == 9) {
//            digit_9.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_9);
//        }
//
//        if (third_val_d == 0) {
//            digit_0.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_0);
//        }
//        else if (third_val_d == 1) {
//            digit_1.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_1);
//        }
//        else if (third_val_d == 2) {
//            digit_2.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_2);
//        }
//        else if (third_val_d == 3) {
//            digit_3.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_3);
//        }
//        else if (third_val_d == 4) {
//            digit_4.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_4);
//        }
//        else if (third_val_d == 5) {
//            digit_5.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_5);
//        }
//        else if (third_val_d == 6) {
//            digit_6.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_6);
//        }
//        else if (third_val_d == 7) {
//            digit_7.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_7);
//        }
//        else if (third_val_d == 8) {
//            digit_8.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_8);
//        }
//        else if (third_val_d == 9) {
//            digit_9.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//            game_window.draw(digit_9);
//        }
//        run_digits_once = true;
//        first_digit.setPosition(33, 32*(stoi(rowCount)+0.5)+16);
//        second_digit.setPosition(54, 32*(stoi(rowCount)+0.5)+16);
//        third_digit.setPosition(75, 32*(stoi(rowCount)+0.5)+16);
//        //add flag num should go down, and num should go up if flag removed
//
//        game_window.draw(leader_sprite);
//        game_window.draw(first_digit);
//        game_window.draw(second_digit);
//        game_window.draw(third_digit);
//        game_window.draw(digit_0_t);
//        game_window.draw(digit_1_t);
//        game_window.draw(digit_2_t);
//        game_window.draw(digit_3_t);
//        game_window.display();
//    }
//}
//
//
//
////CHRONOO
////std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
////start is now the "now" time value
////std::chrono::duration<long long, std::name> timeElapsed(end - start);
////std::cout << "time elapsed: " << timeElapsed.count() << std::endl;
////shows time duration of a given chunk of code in _nanoseconds??
////turn count into double and then divide by 10000.
////use sf::Time
////sf::Time




