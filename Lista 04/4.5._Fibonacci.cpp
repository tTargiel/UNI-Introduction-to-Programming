#include <iostream>
#include <fstream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 5

int main()
{
    int fib[100000];
    int ile;
    cout << "Ile wyrazów ciągu Fibonacciego mam wyznaczyć? ";
    cin >> ile;
    ofstream my_file;
    my_file.open("4.5._Fibonacci.dat");
    fib[0] = 0;
    my_file << 0 << "\t" << fib[0] << endl;
    fib[1] = 1;
    my_file << 1 << "\t" << fib[1] << endl;
    for (int n = 2; n <= ile; n++)
    {
        fib[n] = fib[n - 1] + fib[n - 2];
        my_file << n << "\t" << fib[n] << endl;
    }
    my_file.close();
    for (int n = 0; n <= ile; n++)
    {
        cout << "Wyraz numer " << n << " jest równy " << fib[n] << endl;
    }
    cout << "\nDane zostały zapisane do pliku. Aby zobaczyć wykres f(n) wpisz w gnuplocie: plot \"fibonacci.dat\"." << endl;
    return 0;
}
