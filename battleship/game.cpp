#include <string>
#include "board.h"

using namespace std;

class Play_game
{
    private:
        string player1;
        string player2;
        Board p1_board;
        Board p2_board;
    public:
        Play_game(string p1_name, string p2_name)
            : player1(p1_name), player2(p2_name), p1_board(p1_name), p2_board(p2_name) {};
        
        bool pewpew(string guess, Board guesser, Board reciever)
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
            if(reciever.inner_lower_layout[row][col] != "*" && reciever.inner_lower_layout[row][col] != " ")
            {
                cout << "HIT!" << endl;
                reciever.inner_lower_layout[row][col] = "x";
                return true;
            }
            else
            {
                cout << "MISS!" << endl;
                reciever.inner_lower_layout[row][col] = "x";
                return false;
            }
        }
};


int main()
{
    return 0;
}