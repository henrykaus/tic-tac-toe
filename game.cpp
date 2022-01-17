/**
 * @file game.cpp
 * @author Henry Kaus (https://github.com/henrykaus)
 * @brief Holds definitions for the game class. The game class puts everything
 *        together to get players, track their win stats, and interact with the
 *        board class to run an actual game of tic-tac-toe. This includes
 *        initialization, taking turns, queuing the board class for marking
 *        spots, checking for a winner, etc.
 */
#include "game.hpp"
using namespace std;

// Default Constructor
game::game() : player_1("NONE"), player_2("NONE"), player_1_letter('0'), player_2_letter('0'), player_1_wins(0), player_2_wins(0)
{
}


/**
 * @brief Kickstarts game by calling game::initialize() and game::play().
 */
void game::start()
{
    cout << "Welcome to Tic-Tac-Toe!" << endl << endl;

    initialize();
    play();
}


/**
 * @brief Asks for names for player 1 and player 2.
 */
void game::initialize()
{
    cout << "Who is player 1? ";
    getline(cin, player_1);
    cout << "Who is player 2? ";
    getline(cin, player_2);
}


/**
 * @brief Handles the outer gameplay of taking turns, switching turns, starting
 *        a round, and checking for win conditions.
 */
void game::play()
{
    char winner;                // The winning symbol for a round
    bool is_player_1s_turn;     // Is player 1's turn to go

    // Play a round of tic-tac-toe, quits when user quits from game::again().
    do
    {    
        cout << endl;
        // Symbols are chosen for the players and a starting player is decided.
	    choose_symbol();
        is_player_1s_turn = (player_1_letter == 'X');

        cout << endl;
        print_players();
        cout << endl;
        game_board.display();
        cout << endl << endl;

        // Gameplay of tic-tac-toe, continues until a draw or there is a winner
	    do
	    {
	        if (is_player_1s_turn)
	            turn(player_1, player_1_letter);
	        else
	            turn(player_2, player_2_letter);
            // Switch turns and check win
	        is_player_1s_turn = !is_player_1s_turn;
            winner = game_board.check_win();
	    } while (winner == 'D' && !game_board.board_is_full());
	
        // Winner output statements and win tracking
        if (winner == player_1_letter)
        {
	        cout << player_1 << " is the winner!" << endl;
            ++player_1_wins;
        }
	    else if (winner == player_2_letter)
        {
	        cout << player_2 << " is the winner!" << endl;
            ++player_2_wins;
        }
        else
            cout << "Sometimes, no one wins." << endl;
    } while (again());

    // Final score output
    cout << endl << "Final Score:" << endl;
    print_players();
}


/**
 * @brief Gets user input to assign a letter to each player (X or O).
 */
void game::choose_symbol()
{
    char letter_1;  // Temp letter variable

    // Gets letter for player 1 with error checking.
    cout << player_1 << ", what letter would you like to take (X/O)? ";
    cin  >> letter_1;
    letter_1 = toupper(letter_1);
    cin.ignore(10000, '\n');
    while (letter_1 != 'X' && letter_1 != 'O')
    {
        cout << "Enter a valid option: ";
        cin  >> letter_1;
        letter_1 = toupper(letter_1);
        cin.ignore(10000, '\n');
    } 

    // Assigns letter to player 1 and opposite letter to player 2.
    player_1_letter = letter_1;
    player_2_letter = (player_1_letter == 'X') ? 'O' : 'X';
}


/**
 * @brief Prints both players along with their current letter and number of wins.
 */
void game::print_players()
{
    cout << "Player 1: " << player_1 << " | " << player_1_letter << " | "
         << player_1_wins << " wins" << endl;
    cout << "Player 2: " << player_2 << " | " << player_2_letter << " | "
         << player_2_wins << " wins" << endl;
}


/**
 * @brief Allows a player to take their turn and mark a spot on the board with
 *        error checking.
 * 
 * @param player the current player's name.
 * @param letter the assigned letter (X or O) to the current player.
 */
void game::turn(const string & player, char letter)
{
    char y_axis;    // Y position on the board (A, B, C)
    int  x_axis;    // X position on the board (1, 2, 3)

    // Get input from user for a spot to fill.
    cout << "Pick a spot " << player << " [" << letter << "] (A/B/C 1/2/3): ";
    cin >> y_axis >> x_axis;
    while (cin.fail() || !game_board.mark_spot(letter, y_axis, x_axis))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Pick a valid spot that hasn't been taken (A/B/C 1/2/3): ";
        cin >> y_axis >> x_axis; 
    }
    
    // Display updated game board.
    cout << endl;
    game_board.display();
    cout << endl << endl;
}


/**
 * @brief Asks user if they want to play another round of tic-tac-toe.
 * 
 * @return true if user wants to play another game (Y)
 * @return false if user wants to quit tic-tac-toe (N)
 */
bool game::again()
{
    char option;    // Holds user's response (Y or N)

    // Asks user if they want to play another round of tic-tac-toe.
    cout << "Would you like to play again (Y/N)? ";
    cin  >> option;
    option = toupper(option);
    cin.ignore(10000, '\n');
    while (option != 'Y' && option != 'N')
    {
        cout << "Enter a valid option: ";
        cin  >> option;
        option = toupper(option);
        cin.ignore(10000, '\n');
    } 

    // Results game board and returns if the user entered Y
    game_board.reset();
    return option == 'Y';
}