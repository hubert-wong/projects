#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

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

class cancelException {};   //exceptions custom class;


int welcome_screen()
{
    cout << "xxx           xxx  xxxxxxxxxxx  xxx           xxxxxxxxxxx  xxxxxxxxxxxx  xxxxxxxxxxxxxxxxx  xxxxxxxxxxx" << endl;
    cout << "xxx           xxx  xxxxxxxxxxx  xxx           xxxxxxxxxxx  xxxxxxxxxxxx  xxxxxxxxxxxxxxxxx  xxxxxxxxxxx" << endl;
    cout << "xxx           xxx  xxx          xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxx        " << endl;
    cout << "xxx           xxx  xxx          xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxx        " << endl;
    cout << "xxx    xxx    xxx  xxxxxxxxxxx  xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxxxxxxxxxx" << endl;
    cout << "xxx    xxx    xxx  xxxxxxxxxxx  xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxxxxxxxxxx" << endl;
    cout << "xxx    xxx    xxx  xxx          xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxx        " << endl;
    cout << "xxx    xxx    xxx  xxx          xxx           xxx          xxx      xxx  xxx    xxx    xxx  xxx        " << endl;
    cout << "xxxxxxxxxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxx  xxx    xxx    xxx  xxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxx  xxx    xxx    xxx  xxxxxxxxxxx" << endl;
    cout << '\n' << "     Hubert Wong's Videogame Database that can keep being added to! Wow that's pretty cool.      " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                                           Database Legend:                                      " << endl;
    cout << "To cancel -> 0     Nintendo Switch -> 1      PC -> 2      Playstation 4 -> 3    Nintendo 3DS -> 4" << endl;
    cin >> decision;
    return decision;
}

void input_games(int decision, std::ostream& ofile)
{
    int num_titles;
    while(decision != 0)
    {
        try
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
                    if(title == "cancel" || title == "CANCEL")
                    {
                        throw cancelException();
                    }
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
                    if(title == "cancel" || title == "CANCEL")
                    {
                        throw cancelException();
                    }
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
                    if(title == "cancel" || title == "CANCEL")
                    {
                        throw cancelException();
                    }
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
                    if(title == "cancel" || title == "CANCEL")
                    {
                        throw cancelException();
                    }
                    ofile << "Nintendo 3DS" << endl;
                    ofile << title << '\n' << current_time << endl;
                }
            }
            else
            {
                break;
            }
        }
        catch(cancelException x)
        {
            break;
        }
        cout << "If you would like to add more games from a different console, enter a new number: " << endl;
        cout << "If done -> 0" << '\t' << "Nintendo Switch -> 1" << '\t' << "PC -> 2" << '\t' << "Playstation 4 -> 3" << '\t' << "Nintendo 3DS -> 4" << endl;
        cin >> decision;
    }
}

void display_sorted_by_date(ifstream &ifile)
{
    string to_print;
    int count = 0;
    int beginning_change = 0;
    cout << "    Console" << '\t' << '\t' << '\t' << " Title " << '\t' << '\t' << '\t' << '\t' << "       Date added" << endl;
    while(getline(ifile, to_print))
    {
        cout << to_print << '\t' << '\t';
        if(count == 1 && to_print.length() <= 25)
        {
            cout << '\t';
            if(to_print.length() == 23)
            {
                cout << '\t';
            }
            else if(to_print.length() <= 20)
            {
                cout << '\t' << '\t';
            }
            else if(to_print.length() <= 15)
            {
                cout << '\t';
            }
        }
        if(beginning_change == 1)
        {
            cout << '\t';
        }
        if(count == 2)
        {
            count = 0;
            cout << endl;
            continue;
        }
        ++beginning_change;
        ++count;
    }
    cout << endl;
}

void helper_console(vector<vector<string>> &x)
{
    if(x.size() == 0)
    {
        return;
    }
    for(int j = 0; j < 3; ++j)
    {
        cout << x.at(0).at(j) << '\t' << '\t';
        if(j == 1)
        {
            // cout << '\t';
            // if(x.at(0).at(j).length() < 20)
            // {
            //     cout << '\t' << '\t';
            // }
            break;
        }
    }
    cout << endl;
    for(unsigned int i = 1; i < x.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cout << x.at(i).at(j) << '\t' << '\t';
            if(j == 1)
            {
                break;
            }
            // else if(j == 1 && x.at(i).at(j).length() < 20)
            // {
            //     cout << '\t' << '\t';
            //     if(x.at(i).at(j).length() <= 15)
            //     {
            //         cout << '\t';
            //     }
            // }
        }
        cout << endl;
    }
}

void display_sorted_by_console(ifstream &ifile, int choice)
{
    vector<vector<string>> Switch;
    vector<vector<string>> Playstation;
    vector<vector<string>> PC;
    vector<vector<string>> DS;
    vector<string> entry;
    string to_print;
    bool switch0 = false;
    bool playstation = false;
    bool pc = false;
    bool ds = false;
    int count = 0;
    while(getline(ifile, to_print))
    {
        if(entry.size() == 3)
        {
            if(switch0)
            {
                Switch.push_back(entry);
                switch0 = false;
                entry.clear();
            }
            else if(playstation)
            {
                Playstation.push_back(entry);
                playstation = false;
                entry.clear();
            }
            else if(pc)
            {
                PC.push_back(entry);
                pc = false;
                entry.clear();
            }
            else if(ds)
            {
                DS.push_back(entry);
                ds = false;
                entry.clear();
            }
        }

        if(count == 0)
        {
            if(to_print == "Nintendo Switch")
            {
                switch0 = true;
            }
            else if(to_print == "Playstation 4")
            {
                playstation = true;
            }
            else if(to_print == "PC")
            {
                pc = true;
            }
            else if(to_print == "Nintendo 3DS")
            {
                ds = true;
            }
        }
        entry.push_back(to_print);
        if(count == 2)
        {
            count = 0;
            continue;
        }
        ++count;
    }
    cout << "    Console" << '\t' << '\t' << '\t' << " Title " << endl;
    if(choice == 1)
    {
       helper_console(Switch); 
    }
    else if(choice == 2)
    {
        helper_console(Playstation);
    }
    else if(choice == 3)
    {
        helper_console(PC);
    }
    else if(choice == 4)
    {
        helper_console(DS);
    }
    else
    {
        helper_console(Switch);
        helper_console(Playstation);
        helper_console(PC);
        helper_console(DS);
    }
}


int main(int argc, char* argv[])
{
    int display;
    ifstream ifile;
    ofstream ofile;
    ifile.open("database.txt", ifstream::app);
    ofile.open("database.txt", ofstream::app);
    int x = welcome_screen();
    input_games(x, ofile);
    cout << '\n' << "                 How do you want to display your games?" << endl;
    cout << "No display -> 0       By increasing date of entry -> 1       By console -> 2" << endl;
    cin >> display;
    cout << '\t' << '\t' << "DISPLAY" << '\t' << '\t' << '\t'<< "DISPLAY" << '\t' << '\t' << '\t' << "DISPLAY";
    cout << '\n' << "//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    switch (display)
    {
    case 0:
        break;
    case 1:
        display_sorted_by_date(ifile);
        break;
    case 2:
        int display_choice;
        cout << "Would you like to display all consoles? Or separate consoles?" << endl;
        cout << "Display all -> 0       Nintendo Switch -> 1       Playstation 4 -> 2       PC -> 3       Nintendo 3DS -> 4" << endl;
        cin >> display_choice;
        cout << '\n' << endl;
        display_sorted_by_console(ifile, display_choice);
        break;
    }
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////" << '\n' << endl;
    return 0;
}