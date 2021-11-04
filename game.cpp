#include "game.hpp"
using namespace std;

game::game() : player_1("NONE"), player_2("NONE"), player_1_letter('0'), player_2_letter('0'), player_1_wins(0), player_2_wins(0)
{
}

void game::start()
{
    cout << "Welcome to Tic-Tac-Toe!" << endl << endl;

    initialize();
    play();
}

void game::print_players()
{
    cout << "Player 1: " << player_1 << " | " << player_1_letter << " | " << player_1_wins << " wins" << endl
         << "Player 2: " << player_2 << " | " << player_2_letter << " | " << player_2_wins << " wins" << endl;
}

void game::initialize()
{
    char letter_1;

    cout << "Who is player 1? ";
    getline(cin, player_1);
    cout << "Who is player 2? ";
    getline(cin, player_2);

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

    player_1_letter = letter_1;

    if (player_1_letter == 'X')
        player_2_letter = 'O';
    else
        player_2_letter = 'X';
}

void game::play()
{
    int  winner;
    char winning_letter;
    int  whos_turn;

    do
    {    
        cout << endl;
        print_players();
	    whos_turn = choose_starting_player();
        cout << endl;
        game_board.display();
        cout << endl << endl;

	    do
	    {
	        if (whos_turn % 2 != 0)
	            turn(player_1, player_1_letter);
	        else
	            turn(player_2, player_2_letter);
	        ++whos_turn;
            winner = game_board.check_win();
	    } while (!winner && !game_board.board_is_full());
	
	    if (winner == -1)
	        winning_letter = 'O';
	    else if (winner == 1)
	        winning_letter = 'X';
        else
            winning_letter = 'D';
	
        if (winning_letter == player_1_letter)
        {
	        cout << player_1 << " is the winner!" << endl;
            ++player_1_wins;
        }
	    else if (winning_letter == player_2_letter)
        {
	        cout << player_2 << " is the winner!" << endl;
            ++player_2_wins;
        }
        else
            cout << "Sometimes, no one wins." << endl;

    } while (again());
}

bool game::again()
{
    char option;

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

    game_board.reset();

    if (option == 'Y')
        return true;
    else
        return false;
}

void game::turn(const string & player, char letter)
{
    char y_axis;
    int  x_axis;

    cout << "Pick a spot " << player << " [" << letter << "] (A/B/C 1/2/3): ";
    cin >> y_axis >> x_axis;
    while (cin.fail() || !game_board.mark_spot(letter, y_axis, x_axis))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Pick a valid spot that hasn't been taken (A/B/C 1/2/3): ";
        cin >> y_axis >> x_axis; 
    }
    
    cout << endl;
    game_board.display();
    cout << endl << endl;
}

char game::choose_starting_player()
{
    int option;

    cout << "Who would like to go first (1/2)? ";
    cin  >> option;

    while (cin.fail() || option < 1 || option > 2)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter a valid number: ";
        cin  >> option;
    } 
    
    return option;
}