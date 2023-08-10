#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 4

int main()
{
    for (int i = -5; i <= 5; i++)
    {
        for (int j = -5; j <= 5; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}
