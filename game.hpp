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
        void play();
        void choose_symbol();
        void print_players();
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

#endif // GAME