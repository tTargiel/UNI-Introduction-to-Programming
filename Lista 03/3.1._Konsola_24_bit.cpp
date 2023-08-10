#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 1

int main()
{
    const int wysokosc = 16;
    const int szerokosc = 48;
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            int r = (j / float(szerokosc)) * 255;
            int g = (i / float(wysokosc)) * 155;
            int b = (j / float(szerokosc)) * 55;
            cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m" << " \x1b[0m";
        }
        cout << endl;
    }
    return 0;
}
