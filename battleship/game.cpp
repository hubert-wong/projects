#include <string>
#include <iostream>
#include "board.h"

using namespace std;

class Play_game
{
    public:
        Ships player1;
        Ships player2;
        Board p1_board;
        Board p2_board;
        string guess;

        Play_game(string p1_name, string p2_name)
            : player1(p1_name), player2(p2_name), p1_board(p1_name), p2_board(p2_name) {};
        
        bool pewpew(string guess, Board &guesser, Board &reciever)
        {
            //inserting in a set returns two values: the inserted and if
            //the inserted is already in the set or not (a bool)
            auto guessed = guesser.guesses.insert(guess);   
            if(!guessed.second) //if the guess has already been made
            {
                cout << "Already Guessed this space. Try again!" << endl;
                return true;
            }
            //guesser.guesses.insert(guess) //maybe need this to actually insert it into the guesses?
            int row = reciever.string_conversion(guess.substr(0,1));
            int col = stoi(guess.substr(1));
            if(reciever.inner_lower_layout[row][col-1] != "*" && reciever.inner_lower_layout[row][col] != " ")
            {
                cout << "HIT!" << endl;
                guesser.inner_upper_layout[row][col-1] = "w";
                reciever.inner_lower_layout[row][col-1] = "w";
                vector<string>::iterator erased = reciever.location.begin();
                for(unsigned int i = 0; i < reciever.location.size(); ++i)
                {
                    if(guess == reciever.location.at(i))
                    {
                        reciever.location.erase(erased);
                    }
                    else
                    {
                        ++erased;
                    }
                }
                return true;
            }
            else
            {
                cout << "MISS!" << endl;
                guesser.inner_upper_layout[row][col-1] = "x";
                reciever.inner_lower_layout[row][col-1] = "x";
                return false;
            }
        }

        void fire()
        {
            bool gameplay = true;
            int round = 1;
            while(gameplay)
            {
                string display;
                cout << "Player: " << p1_board.get_name() << " will go. Would you like to see the hit board? (Y/N)" << endl;
                cin >> display;
                cout << "Take your guess!" << endl;
                cin >> guess;
                while(pewpew(guess, p1_board, p2_board))
                {
                    if(display == "Y")
                    {
                        p1_board.print_upper_board();
                    }
                    cout << p2_board.location.size() << endl;
                    if(p2_board.location.size() == 0)
                    {
                        gameplay = false;
                        break;
                    }
                    cout << "nice shot! go again!" << endl;
                    cin >> guess;
                }
                if(!gameplay)
                {
                    break;
                }
                cout << "dang miss! Player " << p2_board.get_name() << " it is your turn now. Would you like to see the hit board? (Y/N)" << endl;
                cin >> display;
                cout << "Take your guess!" << endl;
                cin >> guess;
                while(pewpew(guess, p2_board, p1_board))
                {
                    if(display == "Y")
                    {
                        p1_board.print_upper_board();
                    }
                    if(p1_board.location.size() == 0)
                    {
                        gameplay = false;
                        break;
                    }
                    cout << "nice shot! go again!" << endl;
                    cin >> guess;
                }
                cout << "round " << round << " done!" << endl;
                ++round;
            }

            if(p1_board.location.size() == 0)
            {
                cout << p2_board.get_name() << " has won the game! Congratulations."
                << " On the other hand, " << p1_board.get_name() << " you suck." << endl;
            }
            else
            {
                cout << p1_board.get_name() << " has won the game! Congratulations."
                << " On the other hand, " << p2_board.get_name() << " you suck." << endl; 
            }
        }

        void ship_placement()   //cover edge case about making wrong points (not done)
        {
            string starting_point;
            string finishing_point;
            cout << "Player: " << player1.name << " please place your ships." << endl;
            for(int i = 0; i < 5; ++i)
            {

                cout << "You currently have: ";
                for(unsigned int j = 0; j < player1.ship_bank.size(); ++j)
                {
                    cout << player1.ship_bank[j].first << " " << player1.ship_bank[j].second << '\t';
                }
                cout << endl;
                p1_board.print_lower_board();
                cout << "Please enter a valid starting point (A-J and 1-10): " << endl;
                cin >> starting_point;
                cout << "Please enter a valid finishing point (A-J and 1-10): " << endl;
                cin >> finishing_point;
                if(starting_point == "debug")   //debug speed process
                {
                    p1_board.place_ship("A1","A5", player1);
                    p1_board.place_ship("B1","B4", player1);
                    p1_board.place_ship("C1","C3", player1);
                    p1_board.place_ship("D1","D3", player1);
                    p1_board.place_ship("E1","E2", player1);
                    break;
                }
                p1_board.place_ship(starting_point, finishing_point, player1);
                cout << endl;
            }
            cout << "Player: " << player2.name << " please place your ships." << endl;
            for(int i = 0; i < 5; ++i)
            {
                cout << "You currently have: ";
                for(unsigned int j = 0; j < player2.ship_bank.size(); ++j)
                {
                    cout << player2.ship_bank[j].first << " " << player2.ship_bank[j].second << '\t';
                }
                cout << endl;
                cout << "Please enter a valid starting point (A-J and 1-10): " << endl;
                cin >> starting_point;
                cout << "Please enter a valid finishing point (A-J and 1-10): " << endl;
                cin >> finishing_point;
                if(starting_point == "debug")   //debug speed process
                {
                    p2_board.place_ship("A1","A5", player2);
                    p2_board.place_ship("B1","B4", player2);
                    p2_board.place_ship("C1","C3", player2);
                    p2_board.place_ship("D1","D3", player2);
                    p2_board.place_ship("E1","E2", player2);
                    break;
                }
                p2_board.place_ship(starting_point, finishing_point, player2);
                cout << endl;
            }
            p2_board.lower_num_empty();
        }
};

void play(string p1, string p2)
{
    Play_game x(p1, p2);
    x.ship_placement();
    x.fire();
}

int main()
{
    string p1;
    string p2;
    cout << "Welcome to Battleship! Please enter the two players names: " << endl;
    cin >> p1; 
    cin >> p2;
    cout << "Good luck and have fun: " << p1 << " and " << p2 << "!" << endl;
    play(p1, p2);
    return 0;
}