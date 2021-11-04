#ifndef BOARD
#define BOARD

#include <iostream>

class board
{
    public:
        board();
        board(const board &);
        ~board();

        void reset();
        void display();
        bool board_is_full();
        bool mark_spot(char, char, int);
        int  check_win();
        
    private:
        int ** game_board;
        int spaces_used;
};

#endif