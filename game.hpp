#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include <cstring>
#include "board.hpp"

class game
{
    public:
        game();

        void start();
        void initialize();
        void print_players();
        void play();
        char choose_starting_player();
        bool again();

    private:
        std::string player_1;
        std::string player_2;

        char player_1_letter;
        char player_2_letter;

        int player_1_wins;
        int player_2_wins;

        board game_board;

        void turn(const std::string &, char);
};

#endif