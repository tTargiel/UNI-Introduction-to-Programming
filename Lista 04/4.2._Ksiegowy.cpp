#include <iostream>
#include <fstream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 2

int main()
{
    ofstream my_file;
    my_file.open("4.2._Ksiegowy.dat");
    for (int n = 10; n <= 5000; n += 100)
    {
        float suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma += (double)rand() / (RAND_MAX + 1.0);
        }
        float wynik = suma / n;
        // cout << wynik << endl;
        my_file << n << "\t" << wynik << endl;
    }
    my_file.close();
    cout << "Dane zostały zapisane do pliku. Aby zobaczyć wykres s(n) wpisz w gnuplocie: plot \"ksiegowy.dat\"." << endl; // Wraz ze zwiększaniem się n, średnia zbliża się coraz bardziej do wartości 0.5
    return 0;
}
