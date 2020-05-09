#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

int welcome_screen();
void display(fstream &ifile);
void input_games(int decision);
int decision;
string title;
///////////////////////boring time stuff///////////////////////////////////////////////
time_t current = time(0);
tm *ct = localtime(&current);
int month = 1 + ct->tm_mon;
int day = ct->tm_mday;
int year = 1900 + ct->tm_year;
///////////////////////boring time stuff end///////////////////////////////////////////
string current_time = to_string(month) + "/" + to_string(day) + "/" + to_string(year);


int welcome_screen()
{
    cout << "xxx           xxx xxxxxxxxxxx xxx          xxxxxxxxxxx xxxxxxxxxxxx xxxxxxxxxxxxxxxxx xxxxxxxxxxx" << endl;
    cout << "xxx           xxx xxxxxxxxxxx xxx          xxxxxxxxxxx xxxxxxxxxxxx xxxxxxxxxxxxxxxxx xxxxxxxxxxx" << endl;
    cout << "xxx           xxx xxx         xxx          xxx         xxx      xxx xxx    xxx    xxx xxx        " << endl;
    cout << "xxx           xxx xxx         xxx          xxx         xxx      xxx xxx    xxx    xxx xxx        " << endl;
    cout << "xxx    xxx    xxx xxxxxxxxxxx xxx          xxx         xxx      xxx xxx    xxx    xxx xxxxxxxxxxx" << endl;
    cout << "xxx    xxx    xxx xxxxxxxxxxx xxx          xxx         xxx      xxx xxx    xxx    xxx xxxxxxxxxxx" << endl;
    cout << "xxx    xxx    xxx xxx         xxx          xxx         xxx      xxx xxx    xxx    xxx xxx        " << endl;
    cout << "xxx    xxx    xxx xxx         xxx          xxx         xxx      xxx xxx    xxx    xxx xxx        " << endl;
    cout << "xxxxxxxxxxxxxxxxx xxxxxxxxxxx xxxxxxxxxxxx xxxxxxxxxxx xxxxxxxxxxxx xxx    xxx    xxx xxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxx xxxxxxxxxxx xxxxxxxxxxxx xxxxxxxxxxx xxxxxxxxxxxx xxx    xxx    xxx xxxxxxxxxxx" << endl;
    cout << "     Hubert Wong's Videogame Database that can keep being added to! Wow that's pretty cool.      " << '\n' << endl;
    cout << "                                           Database Legend:                                     " << endl;
    cout << "To cancel -> 0     Nintendo Switch -> 1      PC -> 2      Playstation 4 -> 3     Nintendo 3DS -> 4" << endl;
    cin >> decision;
    return decision;
}

void input_games(int decision, std::ostream& ofile)
{
    int num_titles;
    while(decision != 0)
    {
        cout << "how many titles do you want to input?  ";
        cin >> num_titles;
        cin.ignore();
        if(num_titles == 0)
        {
            break;
        }
        if(decision == 1)
        {
            for(int i = 0; i < num_titles; ++i)
            {
                cout << "Enter the title of the game: ";
                getline(cin, title);
                ofile << "Nintendo Switch" << endl;
                ofile << title << '\n' << current_time << endl;
            }
        }
        else if(decision == 2)
        {
            for(int i = 0; i < num_titles; ++i)
            {
                cout << "Enter the title of the game: ";
                getline(cin, title);
                ofile << "PC" << endl;
                ofile << title << '\n' << current_time << endl;
            }
        }
        else if(decision == 3)
        {
            for(int i = 0; i < num_titles; ++i)
            {
                cout << "Enter the title of the game: ";
                getline(cin, title);
                ofile << "Playstation 4" << endl;
                ofile << title << '\n' << current_time << endl;
            }
        }
        else if(decision == 4)
        {
            for(int i = 0; i < num_titles; ++i)
            {
                cout << "Enter the title of the game: ";
                getline(cin, title);
                ofile << "Nintendo 3DS" << endl;
                ofile << title << '\n' << current_time << endl;
            }
        }
        else
        {
            break;
        }
        cout << "If you would like to add more games from a different console, enter a new number: " << endl;
        cout << "If done -> 0" << '\t' << "Nintendo Switch -> 1" << '\t' << "PC -> 2" << '\t' << "Playstation 4 -> 3" << '\t' << "Nintendo 3DS -> 4" << endl;
        cin >> decision;
    }
}

void display(ifstream &ifile)
{
    string to_print;
    int count = 0;
    cout << "Console" << '\t' << '\t' << '\t' << " Title " << '\t' << '\t' << '\t' << '\t' << " Date " << endl;
    while(getline(ifile, to_print))
    {
        if(count == 3)
        {
            count = 0;
            cout << endl;
        }
        cout << to_print << '\t' << '\t';
        ++count;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("database.txt", ifstream::app);
    ofile.open("database.txt", ofstream::app);
    int x = welcome_screen();
    input_games(x, ofile);
    display(ifile);
    return 0;
}