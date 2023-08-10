#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 3

int main()
{
    srand(time(0)); // Seed do randomizacji
    int zakresD;
    int zakresG;
    cout << "Podaj zakres dla losowania liczb: " << endl;
    cin >> zakresD;
    cin >> zakresG;
    int n = rand() % (zakresG - zakresD) + zakresD; // Losuję liczbę do zgadnięcia
    int proby = 1;
    int liczba;
    while (liczba != n)
    {
        cout << "\nPodaj liczbę: ";
        cin >> liczba;
        if (liczba == n)
        {
            cout << "Zgadłeś! Poprawną liczbą było: " << n << endl;
            cout << "Zgadnięcie tej liczby wymagało tylu prób: " << proby << endl;
        }
        else
        {
            cout << "Zgaduj dalej, " << liczba << " nie jest szukaną liczbą." << endl;
            proby += 1; // Dodaje kolejną nieudaną próbę do licznika
        }
    }
    return 0;
}
