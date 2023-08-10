#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 5

int main()
{
    for (int i = 0; i <= 107; i++) // Pętla działa w zakresie 0-107, ponieważ zgodnie z https://en.wikipedia.org/wiki/ANSI_escape_code jest dokładnie 108 parametrów SGR ANSI
    {
        cout << "Dla ANSI ESC=" << i << ": ";
        cout << "\x1b[" << i << "m test \x1b[0m" << endl;
    }
    return 0;
}
