/**
 * @file board.hpp
 * @author Henry Kaus (https://github.com/henrykaus)
 * @brief Holds definition of the board class.
 */
#ifndef BOARD
#define BOARD

#include <iostream>

/**
 * @brief The board class controls marking spots on the 3x3 tic-tac-toe board,
 *        along with checking win conditions, draw conditions, displaying, and
 *        resetting the board.
 */
class board
{
    public:
        board();                // Default constructor
        board(const board &);   // Copy constructor

        void reset();           // Resets the game board to initial conditions
        void display();         // Displays game board with axis labels
        bool board_is_full();   // Checks if there are no available spots on board
        // Marks a spot on the board with an X or O given the coordinates
        bool mark_spot(char, char, int); 
        char check_win();       // Checks if there is a win on the board
        
    private:
        char game_board[3][3];  // 2D 3x3 array to hold Xs and Os
        int  spaces_used;       // How many spaces have been used so far
};

#endif // BOARD