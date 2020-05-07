#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include "battleship.h"

using namespace std;

class Board {
    private:
    string name;
    int num_upper_leftover = 100;
    int num_lower_leftover = 100;
    stringstream lower_layout; //layout that makes it easy to sort and do things
    stringstream upper_layout; //layout that makes it easy to sort and do things


    public:
    string inner_lower_layout[10][10]; //board itself without the numbers or the letters
    string inner_upper_layout[10][10]; //board itself without the numbers or the letters
    set<string> guesses;
    
    Board() {};

    Board(string name) : name(name)
    {
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                inner_lower_layout[i][j] = "*";
                inner_upper_layout[i][j] = "*";
            }
        }
    }

    void print_upper_board()
    {
        upper_layout.str("");
        upper_layout << "   ";
        for(int i = 1; i < 11; ++i)
        {
            upper_layout << i << "  ";
        }
        upper_layout << endl;
        int row = 0;
        for(char a = 65; a < 75; ++a)
        {
            upper_layout << a << "  ";
            for(int col = 0; col < 10; ++col)
            {
                upper_layout << inner_upper_layout[row][col] << "  ";
            }
            ++row;
            upper_layout << endl;
        }
        cout << upper_layout.str();
    }

    void print_lower_board()
    {
        lower_layout.str("");
        lower_layout << "   ";
        for(int i = 1; i < 11; ++i)
        {
            lower_layout << i << "  ";
        }
        lower_layout << endl;
        int row = 0;
        for(char a = 65; a < 75; ++a)
        {
            lower_layout << a << "  ";
            for(int col = 0; col < 10; ++col)
            {
                lower_layout << inner_lower_layout[row][col] << "  ";
            }
            ++row;
            lower_layout << endl;
        }
        cout << lower_layout.str();
    }

    void print_boards()
    {
        cout << '\t' << "Upper Board" << endl;
        print_upper_board();
        cout << '\t' << "Lower Board" << endl;
        print_lower_board();
    }

    string get_name()
    {
        return name;
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

    int upper_num_empty() //number of empty spots on upper board
    {
        for(int row = 0; row < 10; ++row)
        {
            for(int col = 0; col < 10; ++col)
            {
                if(inner_lower_layout[row][col] != "*" && inner_lower_layout[row][col] != " ")
                {
                    --num_lower_leftover;
                }
                if(inner_upper_layout[row][col] != "*" && inner_upper_layout[row][col] != " ")
                {
                    --num_upper_leftover;
                }
            }
        }
        cout << "There are: " << num_upper_leftover << " empty spaces that can be guessed on your opponents board." << endl;
        return num_upper_leftover;  
    }

    int lower_num_empty()
    {
        for(int row = 0; row < 10; ++row)
        {
            for(int col = 0; col < 10; ++col)
            {
                if(inner_lower_layout[row][col] != "*" && inner_lower_layout[row][col] != " ")
                {
                    --num_lower_leftover;
                }
            }
        }
        cout << "There are: " << num_lower_leftover << " empty spaces on your board." << endl;
        return num_lower_leftover;
    }

    bool place_ship(string start, string finish, Ships &player)
    {
        int start_row = string_conversion(start.substr(0,1));
        int start_col = stoi(start.substr(1));
        int finish_row = string_conversion(finish.substr(0,1));
        int finish_col = stoi(finish.substr(1));
        int h_length = abs(finish_col - start_col) + 1;
        int v_length = abs(finish_row - start_row) + 1;
        string ship = "";
        if(player.ship_bank.size() == 0)
        {
            cout << "No more ships to place." << endl;
            return false;
        }
        vector<pair<string,int>>::iterator erased = player.ship_bank.begin();
        for(unsigned int i = 0; i < player.ship_bank.size() + 1; ++i)
        {
            if(h_length == player.ship_bank[i].second || v_length == player.ship_bank[i].second)
            {
                ship = player.ship_bank[i].first;
                player.ship_bank.erase(erased);
                break;
            }
            else if(i == player.ship_bank.size() - 1)
            {
                cout << "Already placed ship of this size or not an appropriate size." << endl;
                return false;
            }
            ++erased;
        }
        if(start_row == finish_row)
        {
            if(finish_col < start_col)
            {
                int temp = start_col;
                start_col = finish_col;
                finish_col = temp;
            }
            for(int col = start_col - 1; col < finish_col; ++col)
            {
                if(inner_lower_layout[start_row][col] == "o")
                {
                    cout << "Sorry, a ship is already here. Place somewhere else loser." << endl;
                    return false;
                }
            }
            for(int col = start_col - 1; col < finish_col; ++col)
            {
                inner_lower_layout[start_row][col] = "o";
            }
        }
        else if(start_col == finish_col)
        {
            if(finish_row < start_row)
            {
                int temp = start_row;
                start_row = finish_row;
                finish_row = temp;
            }
            for(int row = start_row; row < finish_row + 1; ++row)
            {
                if(inner_lower_layout[row][start_col - 1] == "o")
                {
                    cout << "Sorry, a ship is already here. Place somewhere else loser." << endl;
                    return false;
                }
            }
            for(int row = start_row; row < finish_row + 1; ++row)
            {
                inner_lower_layout[row][start_col - 1] = "o";
            }
        }
        else
        {
            cout << "Incorrect placement, make sure it is strictly vertical or horizontal placement" << endl;
            return false;
        }
        cout << ship << " has been placed. Good job" << endl;
        return true;
    }

    int string_conversion(string letter)
    {
        if(letter == "A")
        {
            return 0;
        }
        else if(letter == "B")
        {
            return 1;
        }
        else if(letter == "C")
        {
            return 2;
        }
        else if(letter == "D")
        {
            return 3;
        }
        else if(letter == "E")
        {
            return 4;
        }
        else if(letter == "F")
        {
            return 5;
        }
        else if(letter == "G")
        {
            return 6;
        }
        else if(letter == "H")
        {
            return 7;
        }
        else if(letter == "I")
        {
            return 8;
        }
        else if(letter == "J")
        {
            return 9;
        }
        else
        {
            return 100;
        }
    }
};