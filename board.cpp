/**
 * @file board.cpp
 * @author Henry Kaus (https://github.com/henrykaus)
 * @brief Holds definitions for the board class. The board class manages a 3x3
 *          tic-tac-toe board and has functionality for checking for a win,
 *          displaying to console, resetting, checking for a full board, and
 *          marking a spot with either an X or O.
 */
#include "board.hpp"
using namespace std;

// Default Constructor
board::board()
{
    reset();
}


// Copy Constructor
board::board(const board & source) : spaces_used(source.spaces_used)
{
    // Copies board spot conditions from source
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = source.game_board[i][j];
}


/**
 * @brief Resets the board to default conditions (all spaces in the 3x3 are
 *        empty [' ']).
 */
void board::reset()
{
    // Assigns all spots on board to ' '
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = ' ';

    this->spaces_used = 0;
}


/**
 * @brief Prints tic-tac-toe board to terminal with a axis labels
 *        (1 2 3  &  A B C).
 */
void board::display()
{
    char start = 'A';   // Starting y-axis location for printing
    
    // Prints x-axis label
    cout << "             1 2 3" << endl << endl;
    // Prints the game board row-by-row, by printing a buffer, the y-axis label
    // each spot on the board along with dividers between each column.
    for (int j = 0; j < 3; ++j, ++start)
    {
        cout << "          " << start << "  ";
	    for (int i = 0; i < 3; ++i)
	    {
	        cout << game_board[j][i];
	        if (i != 2)
	            cout << '|';
	    }
        // Prints dividing line below each row except the last
        if (j != 2)
	        cout << endl << "             -----" << endl;
    }
}


/**
 * @brief Checks if all spaces on board are not empty.
 * 
 * @return true if 9 spaces have been used.
 * @return false if less than 9 spaces have been used.
 */
bool board::board_is_full()
{
    return spaces_used == 9;
}


/**
 * @brief Marks spot on board with the letter, provides for error checking.
 * 
 * @param letter is the players letter (X or O)
 * @param y_axis is location across the vertical (A, B, or C)
 * @param x_axis is location across the horizontal (1, 2, or 3)
 * @return true if a spot was marked.
 * @return false if a spot was not marked as a result of the letter not being an
 *         X or Y, the x-axis not being between 1 and 3 inclusive, the y-axis
 *         not being A, B, or C, and/or the spot was already taken.
 */
bool board::mark_spot(char letter, char y_axis, int x_axis)
{
    int x_pos, y_pos;   // Holds x and y indexes for the 2D array
    letter = toupper(letter);
    y_axis = toupper(y_axis);

    // Conditions for bad arg failure
    if (letter != 'X' && letter != 'O')
        return false;
    else if (x_axis < 1 || x_axis > 3)
        return false;
    else if (y_axis < 'A' || y_axis > 'C')
        return false;

    // Transform arg data into indexable numbers
    x_pos = x_axis - 1;
    y_pos = y_axis - 65;

    // If board spot has been filled, return false
    if (game_board[y_pos][x_pos] != ' ')
        return false;
    
    // Mark spot
    game_board[y_pos][x_pos] = letter;
    ++spaces_used;

    return true; 
}


/**
 * @brief Determines if there is a winner on the game board.
 * 
 * @return char of either X or O if there is a win, or D if there is no winner.
 */
char board::check_win()
{
    // Check vertical wins
    for (int i = 0; i < 3; ++i)
    {
        if (game_board[i][0] == game_board[i][1] && game_board[i][0] == game_board[i][2] && game_board[i][0] != ' ')
            return game_board[i][0];
    }

    // Check horizontal wins
    for (int i = 0; i < 3; ++i)
    {
        if (game_board[0][i] == game_board[1][i] && game_board[0][i] == game_board[2][i] && game_board[0][i] != ' ')
	        return game_board[0][i];
    }

    // Check Downward Diagonal
    if (game_board[0][0] == game_board[1][1] && game_board[0][0] == game_board[2][2] && game_board[0][0] != ' ')
        return game_board[0][0];

    // Check Upward Diagonal
    if (game_board[0][2] == game_board[1][1] && game_board[0][2] == game_board[2][0] && game_board[0][2] != ' ')
        return game_board[0][2];

    // No win, return D
    return 'D';
}