#include "board.hpp"
using namespace std;

// Default Constructor
board::board()
{
    game_board = new int*[3];
    for (int i = 0; i < 3; ++i)
        game_board[i] = new int[3];

    reset();
}

// Copy Constructor
board::board(const board & source) : spaces_used(source.spaces_used)
{
    game_board = new int*[3];
    for (int i = 0; i < 3; ++i)
        game_board[i] = new int[3];

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = source.game_board[i][j];
    }
}

// Destructor
board::~board()
{
    for (int i = 0; i < 3; ++i)
    {
        delete [] game_board[i];
    }
    delete [] game_board;
    game_board  = nullptr;
    spaces_used = 0;
}

// Resets board to default conditions
void board::reset()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            game_board[i][j] = 0;
    }
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
	        if (game_board[j][i] == 1)
	            cout << 'X';
	        else if (game_board[j][i] == -1)
	            cout << 'O';
	        else
	            cout << ' ';

	        if (i != 2)
	            cout << '|';
	    }
        if (j != 2)
	        cout << endl << "             -----" << endl;
    }
}

// Returns if no more moves can be played
bool board::board_is_full()
{
    if (spaces_used == 9)
        return true;
    else
        return false;
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

    if (game_board[y_pos][x_pos] != 0)
        return false;
    
    if (letter == 'X')
        game_board[y_pos][x_pos] = 1;
    else
        game_board[y_pos][x_pos] = -1;

    ++spaces_used;
    return true; 
}

// Key: 0=no winners, 1=X wins, -1=O wins
int board::check_win()
{
    // Check vertical wins
    for (int i = 0; i < 3; ++i)
    {
        if (game_board[i][0] == game_board[i][1] && game_board[i][0] == game_board[i][2])
        {
	        if (game_board[i][0] == 1)
	            return 1;
	        else if (game_board[i][0] == -1)
	            return -1;
        }
    }

    // Check horizontal wins
    for (int i = 0; i < 3; ++i)
    {
        if (game_board[0][i] == game_board[1][i] && game_board[0][i] == game_board[2][i])
        {
	        if (game_board[0][i] == 1)
	            return 1;
	        else if (game_board[0][i] == -1)
	            return -1;
        }
    }

    // Check Downward Diagonal
    if (game_board[0][0] == game_board[1][1] && game_board[0][0] == game_board[2][2])
    {
        if (game_board[0][0] == 1)
            return 1;
        else if (game_board[0][0] == -1)
            return -1;
    }

    // Check Upward Diagonal
    if (game_board[0][2] == game_board[1][1] && game_board[0][2] == game_board[2][0])
    {
        if (game_board[0][2] == 1)
            return 1;
        else if (game_board[0][2] == -1)
            return -1;
    }

    // No win, return 0
    return 0;
}