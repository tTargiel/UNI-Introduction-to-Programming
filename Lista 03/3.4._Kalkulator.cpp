#include <iostream>
#include <climits>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 4

void weryfikacja() // Definiuję funkcję odpowiedzialną za weryfikowanie wejścia - czy na pewno jest ono liczbą
{
    cout << "Podaj liczbę!" << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

int main()
{
    bool run = true;
    int a;
    float b;
    float c;
    int d;

    while (run)
    {
        cout << "\x1b[2J\x1b[0;0H\x1b[0m";

        cout << "Podaj działanie (0-dodawanie, 1-mnożenie): ";
        while (!(cin >> a))
        {
            weryfikacja();
        };
        cout << "OK: " << a << endl;

        cout << "Podaj pierwszą liczbę: ";
        while (!(cin >> b))
        {
            weryfikacja();
        }
        cout << "OK: " << b << endl;

        cout << "Podaj drugą liczbę: ";
        while (!(cin >> c))
        {
            weryfikacja();
        }
        cout << "OK: " << c << endl;

        if (a == 0)
        {
            cout << "Twój wynik dodawania to: " << b + c << endl;
        }
        else if (a == 1)
        {
            cout << "Twój wynik mnożenia to: " << b * c << endl;
        }
        else
        {
            cout << "Wprowadzono nieprawidłowy numer działania" << endl;
        }

        cout << "Chcesz spróbować jeszcze raz? (0-nie, 1-tak): " << endl;
        while (!(cin >> d))
        {
            weryfikacja();
        }
        cout << "OK: " << d << endl;

        if (d == 0)
        {
            cout << "Zamykam program..." << endl;
            run = false;
        }
        else if (d != 1)
        {
            cout << "Wprowadzono nieprawidłą opcję, zamykam program..." << endl;
            run = false;
        }
    }
    return 0;
}
