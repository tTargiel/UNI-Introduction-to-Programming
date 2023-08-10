#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 3_2

int main()
{
    int silnia = 1; // By uzyskać silnie dużych wyrazów (od 13! wypadałoby zastosować long int lub long long int (są to typy zmiennych o zdecydowanie większej pojemności)
    for (int n = 1; n <= 40; n++)
    {
        silnia *= n;
        cout << n << "!=" << silnia << endl;
    }
    return 0;
}
