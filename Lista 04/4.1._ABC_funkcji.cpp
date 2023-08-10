#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 1

void podpA()
{
    cout << "a) Hello world" << endl;
}

void podpB(float liczba)
{
    cout << "b) " << liczba << endl;
}

void podpC(int liczba_1, int liczba_2)
{
    cout << "c) " << liczba_1 + liczba_2 << endl;
}

int podpD(int wyjscie, float liczba_1, float liczba_2)
{
    wyjscie = liczba_1 * liczba_2;
    return wyjscie;
}

int podpE(int tablica[], int rozmiar)
{
    int iloczyn = 1;
    for (int i = 0; i < rozmiar; i++)
    {
        iloczyn *= tablica[i];
    }
    return iloczyn;
}

int main()
{
    int tablica[] = {1, 2, 4, 8};
    podpA();
    podpB(1.23123);
    podpC(4, 8);
    cout << "d) " << podpD(0, 1.23123, 3.21321) << endl;
    cout << "e) " << podpE(tablica, sizeof(tablica) / sizeof(int)) << endl;
    return 0;
}
