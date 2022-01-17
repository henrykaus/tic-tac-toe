/**
 * @file game.hpp
 * @author Henry Kaus (https://github.com/henrykaus)
 * @brief Holds definition for the game class.
 */
#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include <cstring>
#include "board.hpp"

/**
 * @brief The game class is the glue of the program. Handles turn taking, player
 *        management, win records and interacts with a board to fill spaces and
 *        check win conditions. Can use simply by calling the start() method.
 */
class game
{
    public:
        game();     // Default constructor

        void start();               // Starts tic-tac-toe session
        void initialize();          // Gets and assigns player names
        void print_players();       // Displays players, and their wins

    private:
        std::string player_1;   // Player 1 name
        std::string player_2;   // Player 2 name

        char player_1_letter;   // Player 1 symbol
        char player_2_letter;   // Player 2 symbol

        int player_1_wins;      // Number of wins for player 1
        int player_2_wins;      // Number of wins for player 2

        board game_board;       // Game board for tic-tac-toe

        void play();                // Handles gameplay for tic-tac-toe
        void choose_symbol();       // Has player 1 choose a symbol (X or O)
        // Player takes their turn filling in a spot
        void turn(const std::string &, char); 
        bool again();               // Asks if another round should be played
};

#endif // GAME