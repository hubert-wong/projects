#include <string>
#include <vector>
#include <utility>
#include <bits/stdc++.h> 

using namespace std;

class Ships
{
    public:
    vector<pair<string, int>> ship_bank;

    Ships()
    {
        string ship_names[5] = {"carrier", "battleship", "destroyer", "submarine", "patrol boat"};
        int ship_length[5] = {5, 4, 3, 3, 2};
        for(int i = 0; i < 5; ++i)
        {
            ship_bank.push_back(make_pair(ship_names[i], ship_length[i]));
        }
    }

};