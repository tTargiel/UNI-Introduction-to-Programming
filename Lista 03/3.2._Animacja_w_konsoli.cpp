#include <iostream>
#include <unistd.h>

#if defined(_WIN32) // Jeżeli twój system to Windows...
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>   // Biblioteka potrzebna do pozyskania wymiarów terminala
#else                  // Jeżeli twój system to Linux lub macOS <3
#include <sys/ioctl.h> // Biblioteka potrzebna do pozyskania wymiarów terminala
#endif

using namespace std;

// Tomasz Targiel
// Lista 3
// Zadanie 2

// Poniższa animacja jest inspirowana "deszczem" z trylogii Matrix
// Najlepiej wygląda w terminalu w trybie fullscreen

// int random(int min, int max)
// {
//     random_device rd; // Pozyskuje losowy numer sprzętowy
//     mt19937 gen(rd()); // Generatorowi Mersenne Twister podaje seed (którym jest losowy numer sprzętowy)
//     uniform_int_distribution<> distr(min, max); // Definiuje zakres z użyciem argumentów wejścia

//     return distr(gen);
// }

void matrix()
{
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // Pozyskuje wymiary okna terminala
    int H = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;               // Deklaruję maksymalną wysokość animacji w oparciu o rozmiar terminala
    int W = csbi.srWindow.Right - csbi.srWindow.Left + 1;               // Deklaruję maksymalną szerokość animacji w oparciu o rozmiar terminala
    SetConsoleOutputCP(65001);                                          // Ustawiam kodowanie UTF-8 specjalnie dla Windowsa...
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Pozyskuje wymiary okna terminala
    int H = w.ws_row;                     // Deklaruję maksymalną wysokość animacji w oparciu o rozmiar terminala
    int W = w.ws_col;                     // Deklaruję maksymalną szerokość animacji w oparciu o rozmiar terminala
#endif

    int X = rand() % W;          // Losuję na osi X miejsce do narysowania kolumny znaków
    for (int i = 0; i <= H; i++) // Czyszczę kolumnę X z możliwych pozostałości
    {
        cout << "\x1b[" << i << ";" << X << "H" << "\x1b[0m ";
    }
    for (int j = 0; j <= (rand() % H) + H / 5; j++) // Rysuję w kolumnie X znaki z tabeli ASCII (z zakresu 33-64) - rysuje ich losową ilość (nie większą niż zadeklarowana wysokość animacji), H / 5 odpowiada za zwiększenie prawdopodobieństa wylosowania liczb większych niż 1/5 wysokości terminala
    {
        int kolor[10] = {2, 10, 22, 28, 34, 40, 46, 70, 76, 82}; // Tablica zawierająca kody ANSI specyficzne dla różnych odcieni zielonego
        char znak = rand() % 31 + 33;                            // Losuje znaki z tabeli ASCII (z zakresu 33-64)
        cout << "\x1b[" << j << ";" << X << "H" << "\x1b[38;5;" << kolor[rand() % 10] << "m" << znak << "\x1b[0m ";
        usleep(8000); // Czekam 0.8 sekundy przed następnym wykonaniem pętli
    }
    X = 0;
}

int main()
{
    bool petla = true;
    cout << "\x1b[2J"; // Czyszczę ekran
    while (petla)
    {
        matrix();
        cout << "\x1b[0;0H" << "Aby wyjść naciśnij CTRL+C" << endl; // Wyświetlam na ekranie (w punkcie zero) informację o sposobie wyjścia
    }
    cout << "\x1b[0m";
    return 0;
}
