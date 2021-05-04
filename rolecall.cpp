#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <getopt.h>
#include <string.h>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    srand((unsigned) time(0));
    vector<string> players;
    vector<string> roles;
    roles.push_back("top");
    roles.push_back("jg");
    roles.push_back("mid");
    roles.push_back("adc");
    roles.push_back("sup");
    string name;
    for(unsigned int i = 0; i < roles.size(); ++i)
    {
        cin >> name;
        players.push_back(name);
    }
    int counter = 0;
    int result;
    while(counter != 5)
    {
        result = (rand() % 5);
        if(roles.at(result) != "")
        {
            cout << players.at(counter) << " is playing " << roles.at(result) << endl;
            roles.at(result) = "";
            counter++;
        }
    }
    return 0;
}