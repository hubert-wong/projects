#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Board {
    private:

    int num_leftover = 100;
    stringstream layout; //layout that makes it easy to sort and do things
    string laid_out = layout.str(); //board as a string
    string inner_layout[10][10]; //board itself without the numbers or the letters

    public:
    
    Board()
    {
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                inner_layout[i][j] = '*';
            }
        }
    }

    void print_board()
    {
        layout << "Welcome to Battleship by Hubert Wong" << endl;
        layout << "   ";
        for(int i = 1; i < 11; ++i)
        {
            layout << i << "  ";
        }
        layout << endl;
        int row = 0;
        for(char a = 65; a < 75; ++a)
        {
            layout << a << "  ";
            for(int col = 0; col < 10; ++col)
            {
                layout << inner_layout[row][col] << "  ";
            }
            ++row;
            layout << endl;
        }
        cout << layout.str();
    }

    int get_height()
    {
        cout << "height: 10 spaces" << endl;
        return 10;
    }
    int get_width()
    {
        cout << "width: 10 spaces" << endl;
        return 10;
    }

    int num_empty()
    {
        int length = laid_out.length();
        for(int i = 0; i < length; ++i)
        {
            cout << laid_out << endl;
            if(laid_out.substr(0,1) != "*" && laid_out.substr(0,1) != " ")
            {
                --num_leftover;
            }
            laid_out = laid_out.substr(1);
        }
        return num_leftover;  
    }
};