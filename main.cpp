/**
 * @file main.cpp
 * @author Henry Kaus (https://github.com/henrykaus)
 * @brief Driver for the tic-tac-toe program.
 * @version 1.0
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 */
#include "game.hpp"
using namespace std;

// MAIN
int main()
{
    game tic_tac_toe;       // Tic Tac Toe game object
    tic_tac_toe.start();    // Begins game

    return 0;
}