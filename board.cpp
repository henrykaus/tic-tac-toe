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
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = source.game_board[i][j];
}

// Resets board to default conditions
void board::reset()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = ' ';

    spaces_used = 0;
}

// Prints board
void board::display()
{
    char start = 'A';
    
    cout << "             1 2 3" << endl << endl;
    for (int j = 0; j < 3; ++j, ++start)
    {
        cout << "          " << start << "  ";
	    for (int i = 0; i < 3; ++i)
	    {
	        cout << game_board[j][i];

	        if (i != 2)
	            cout << '|';
	    }
        // Prints line below each row except last
        if (j != 2)
	        cout << endl << "             -----" << endl;
    }
}

// Returns if no more moves can be played
bool board::board_is_full()
{
    return spaces_used == 9;
}

bool board::mark_spot(char letter, char y_axis, int x_axis)
{
    int x_pos, y_pos;
    letter = toupper(letter);
    y_axis = toupper(y_axis);

    if (letter != 'X' && letter != 'O')
        return false;
    else if (x_axis < 1 || x_axis > 3)
        return false;
    else if (y_axis < 'A' || y_axis > 'C')
        return false;

    x_pos = x_axis - 1;
    y_pos = y_axis - 65;

    if (game_board[y_pos][x_pos] != ' ')
        return false;
    
    game_board[y_pos][x_pos] = letter;
    ++spaces_used;

    return true; 
}

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