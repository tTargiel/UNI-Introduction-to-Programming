#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 7

int main()
{
    double pi = 3.14159;
    ofstream my_file;
    my_file.open("2.7._Cosinus.dat");
    for (float x = 0; x < 2 * pi; x += 0.001)
    {
        my_file << x << "\t";
        my_file << cos(x) << "\t";
        my_file << cos(x) * cos(x) << "\n";
    }
    my_file.close();
    cout << "Dane zostały zapisane do pliku" << endl;
    return 0;
}
