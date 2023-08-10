#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 6_2

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i % 2 == 0)
            {
                cout << "\x1b[47m  \x1b[0m" << "\x1b[40m  \x1b[0m";
            }
            else
            {
                cout << "\x1b[40m  \x1b[0m" << "\x1b[47m  \x1b[0m";
            }
        }
        cout << "\n";
    }
    return 0;
}
