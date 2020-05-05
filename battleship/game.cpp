#include <string>
#include "board.h"
#include "battleship.h"

using namespace std;

int main()
{
    Board main;
    main.print_board();
    cout << main.num_empty() << endl;
    return 0;
}