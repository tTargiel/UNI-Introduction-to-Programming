#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 4_2

int main()
{
    cout << "\x1b[42m    \x1b[0m"; // Lewy-górny róg tabliczki mnożenia

    for (int k = -5; k <= 5; k++) // Górny nagłówek tabliczki (kolor zielony)
    {
        if (k < 0)
        {
            cout << "\x1b[42m  " << k << " \x1b[0m"; // Dla wartości ujemnych stosuje dwie spację przed i jedną po wartości liczbowej (suma znaków musi być równa 5)
        }
        else
        {
            cout << "\x1b[42m   " << k << " \x1b[0m"; // Dla wartości nieujemnych stosuje trzy spacje przed i jedną po (suma znaków musi być równa 5)
        }
    }

    cout << endl;

    for (int i = -5; i <= 5; i++) // Zaczynam pętlę podwójną
    {
        if (i < 0) // Lewy nagłówek tabliczki (kolor zielony)
        {
            cout << "\x1b[42m " << i << " \x1b[0m"; // Dla wartości ujemnych jedna spacja przed, jedna po (suma 4)
        }
        else
        {
            cout << "\x1b[42m  " << i << " \x1b[0m"; // Dla nieujemnych dwie przed, jedna po (suma 4)
        }

        for (int j = -5; j <= 5; j++) // Część właściwa tabliczki mnożenia
        {
            if (i * j <= -10)
            {
                cout << "\x1b[41m " << i * j << " \x1b[0m"; // Dla ujemnych dwucyfrowych jedna spracja przed i jedna po (stąd się wzięła suma 5 w górnym nagłówku)
            }
            else if (i * j >= 10 || i * j < 0)
            {
                cout << "\x1b[41m  " << i * j << " \x1b[0m"; // Dla dodatnich dwucyfrowych oraz ujemnych jednocyfrowych po dwie spacje przed i jedna po (tak by suma była 5)
            }
            else
            {
                cout << "\x1b[41m   " << i * j << " \x1b[0m"; // Dla jednocyfrowych nieujemnych trzy spacje przed i jedna po (suma 5)
            }
        }
        cout << endl;
    }
    return 0;
}
