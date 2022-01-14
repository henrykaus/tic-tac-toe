#ifndef BOARD
#define BOARD

#include <iostream>

class board
{
    public:
        board();
        board(const board &);

        void reset();
        void display();
        bool board_is_full();
        bool mark_spot(char, char, int);
        char check_win();
        
    private:
        char game_board[3][3];
        int  spaces_used;
};

#endif // BOARD