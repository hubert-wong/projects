#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class board {
    //make a 2d array fr tho
    private:
    int num_leftover = 100;
    stringstream layout;
    string laid_out = layout.str();

    public:
    
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

    void make_board()
    {
        layout << "   ";
        for(int i = 1; i < 11; ++i)
        {
            layout << i << "  ";
        }
        layout << endl;
        for(char a = 65; a < 76; ++a)
        {
            layout << a << "  ";
            for(int b = 0; b < 10; ++b)
            {
                layout << "*  ";
            }
            layout << endl;
        }
        layout.str();
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