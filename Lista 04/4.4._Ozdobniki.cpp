#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 4

int main()
{
    srand(time(0)); // Seed do randomizacji
    int zakresD;
    int zakresG;
    int theShowMustGoOn = 1; // Zmienna odpowiedzialna za trwanie gry
    cout << "\x1b[30;43m *               ZASADY GRY                  * \x1b[0m" << endl;
    cout << "\x1b[30;43m * Twoim celem jest odgadnięcie wylosowanej  * \x1b[0m" << endl;
    cout << "\x1b[30;43m *   przez komputer liczby, która znajduje   * \x1b[0m" << endl;
    cout << "\x1b[30;43m *  się we wskazanym przez ciebie zakresie.  * \x1b[0m" << endl;
    cout << endl;
    while (theShowMustGoOn == 1)
    {
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
                cout << "\x1b[30;102m           __   __   __        __   \x1b[0m" << endl;
                cout << "\x1b[30;102m  |  | \\/ | __ |__| |__| |\\ | |__|  \x1b[0m" << endl;
                cout << "\x1b[30;102m  |/\\| |  |__| |  \\ |  | | \\| |  |  \x1b[0m" << endl;
                cout << "\x1b[30;102m                                    \x1b[0m" << endl;
                cout << "\n\x1b[30;104mZgadłeś! Poprawną liczbą było: " << n << "\x1b[0m" << endl;
                cout << "Zgadnięcie tej liczby wymagało tylu prób: " << proby << endl;
                cout << "Czy chcesz zagrać jeszcze raz? [0=nie, 1=tak]: ";
                cin >> theShowMustGoOn; // Jeżeli użytkownik wprowadzi 1, to gra ponownie się zacznie; w innym wypadku zostanie przerwana
                cout << "\n\n";
            }
            else
            {
                cout << "\x1b[30;104mZgaduj dalej, " << liczba << " nie jest szukaną liczbą.\x1b[0m" << endl;
                proby += 1; // Dodaje kolejną nieudaną próbę do licznika
            }
        }
    }
    return 0;
}
