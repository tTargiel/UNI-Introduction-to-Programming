#include <climits> // Biblioteka potrzebna do weryfikacji wejścia
#include <iostream>
#include <stdlib.h> // Biblioteka potrzebna do randomizacji
#include <time.h>   // Biblioteka dzięki której dostarczam seed do randomizera

#if defined(_WIN32) // Jeżeli twój system to Windows...
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h> // Biblioteka potrzebna do pozyskania wymiarów terminala
#else                // Jeżeli twój system to Linux lub macOS <3
// Biblioteki potrzebne do pozyskania wymiarów terminala
#include <sys/ioctl.h>
#include <unistd.h>
#endif

using namespace std;

// Tomasz Targiel
// Lista 5
// Zadanie 1

// Na sztywno ustalam wymiary gry
int wMax = 96;
int hMax = 24;
int suma = 0;

// Inicjuje funkcje, których będę używał w mainie
void weryfikacja();
void ekranZero();
void ekranFamiliada();
void ekranInformacje();
void ekranGra();
void ekranBledy(int bledy);

int main()
{
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // Pozyskuje wymiary okna terminala
    int W = csbi.srWindow.Right - csbi.srWindow.Left + 1;               // Deklaruję zmienną W jako szerokość w oparciu o rozmiar terminala
    int H = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;               // Deklaruję zmienną H jako wysokość w oparciu o rozmiar terminala
    SetConsoleOutputCP(CP_UTF8);                                        // Ustawiam kodowanie UTF-8 specjalnie dla Windowsa...
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Pozyskuje wymiary okna terminala
    int W = w.ws_col;                     // Deklaruję zmienną W jako szerokość w oparciu o rozmiar terminala
    int H = w.ws_row;                     // Deklaruję zmienną H jako wysokośćw oparciu o rozmiar terminala
#endif

    if (W < 97 || H < 32)
    {
        cout << "Wykryto terminal o zbyt małych wymiarach" << endl;
        cout << "Powiększ okno co najmniej do rozmiarów 97px szerokości oraz 32px wysokości i spróbuj ponownie" << endl;
        cout << "\nAktualne wymiary twojego terminala: " << W << "px szerokości oraz " << H << "px wysokości" << endl;
        return 0;
    }

MENU:
    ekranFamiliada();
    // Wyświetlam polecenia poniżej ekranu gry
    cout << "1 - Zagraj w Familiadę" << endl;
    cout << "2 - Pokaż opis oraz zasady gry" << endl;
    cout << "\nWybierz opcję (domyślnie 1): ";
    int opcja = 0;
    while (!(cin >> opcja)) // Z użyciem napisanej funkcji, weryfikuję czy podany arg wejścia jest liczbą całkowitą
    {
        weryfikacja();
    }
    switch (opcja) // Na podstawie argumentu wejścia decyduję czy wyświetlić opis i zasady gry czy też może rozpocząć rundę
    {
    case 2:
        ekranInformacje();
        cout << "Aby wrócić do ekranu głównego wpisz dowolny znak, a następnie wciśnij Enter: ";
        char znak;
        cin >> znak;
        goto MENU;
        break;
    default:
        ekranGra();
        break;
    }
    return 0;
}

void weryfikacja() // Definiuję funkcję odpowiedzialną za weryfikowanie wejścia - czy na pewno jest ono liczbą całkowitą
{
    cout << "\n\33[2K"; // Przenoszę się do linijki terminala niżej i czyszczę cały wiersz do końca
    cout << "Podaj liczbę!: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void ekranZero()
{
    cout << "\x1b[2J\x1b[0;0H\x1b[0m"; // Czyszczę cały ekran z użyciem kodów ANSI, a następnie idę do punktu zero (0;0) terminala
    for (int h = 0; h <= hMax; h++)    // Pętla będzie się wykonywać aż ekran gry osiągnie pożądaną wysokość
    {
        for (int w = 0; w <= wMax; w++) // Pętla będzie się wykonywać aż ekran gry osiągnie pożądaną szerokość
        {
            if (((h == 0) || (h == hMax)) || (((w == 0) || (w == 1)) || ((w == wMax - 1) || (w == wMax)))) // Tworzę obramowanie ekranu gry w kolorze szarym
            {
                cout << "\x1b[48;5;8m \x1b[0m";
            }
            else // Wypełniam ekran gry kolorem czarnym
            {
                cout << "\x1b[48;5;0m \x1b[0m";
            }
        }
        cout << endl;
    }
}

void ekranFamiliada()
{
    ekranZero(); // Drukuję pusty ekran gry, by nowa treść nie zlewała się ze starą
    // Na środku ekranu drukuję napis FAMILIADA z użyciem żółtych bloków ANSI
    cout << "\x1b[38;5;11m\x1b[48;5;0m";
    cout << "\x1b[11;17H███████  █████  ███    ███ ██ ██       ██  █████  ██████   █████";
    cout << "\x1b[12;17H██      ██   ██ ████  ████ ██ ██       ██ ██   ██ ██   ██ ██   ██";
    cout << "\x1b[13;17H█████   ███████ ██ ████ ██ ██ ██       ██ ███████ ██   ██ ███████";
    cout << "\x1b[14;17H██      ██   ██ ██  ██  ██ ██ ██       ██ ██   ██ ██   ██ ██   ██";
    cout << "\x1b[15;17H██      ██   ██ ██      ██ ██ ████████ ██ ██   ██ ██████  ██   ██";
    cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
}

void ekranInformacje()
{
    ekranZero(); // Drukuję pusty ekran gry, by nowa treść nie zlewała się ze starą
    // Na środku ekranu drukuję opis oraz zasady gry
    cout << "\x1b[38;5;11m\x1b[48;5;0m";
    cout << "\x1b[7;8HTak jak w Polskim teleturnieju o nazwie Familiada, zadaniem gracza jest odgadnąć";
    cout << "\x1b[8;8Hwszystkie słowa, które odpowiadają na pytanie prowadzącego.";
    cout << "\x1b[10;8HKażde słowo dodaje pewną ilość punktów, co składa się na wynik końcowy.";
    cout << "\x1b[11;8HOdpowiedzi częściej wymieniane przez ankietowanych dodają większą ilość punktów.";
    cout << "\x1b[12;8HWynik końcowy większy (lub równy) 80 punktów oznacza wygraną.";
    cout << "\x1b[14;8HTrzy niepoprawne zgadnięcia hasła skutkują przegraną.";
    cout << "\x1b[15;8HNa ilość popełnionych błędów wskazują znaki \"X\" po lewej stronie ekranu.";
    cout << "\x1b[17;8HProszę wprowadzać słowa zaczynając od wielkiej litery np. Kot, Pies, Ryba.";
    cout << "\x1b[18;8HDodatkowo hasła są jednoczłonowe i w liczbie pojedynczej.";
    cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
}

void ekranGra()
{
GRAJ:
    int bledy = 0;
    int koniec = 0;
    int odgadniete[6];
    fill_n(odgadniete, 6, 0);
    suma = 0;
    // Deklaruję tablice zmiennych odpowiadających za pytania, odpowiedzi oraz punkty za poprawne odpowiedzi
    string pytania[] = {"Jaki rok nie zaczyna się pierwszego stycznia?", "Część garderoby na literę \"S\"?", "Państwo, którego nazwa kończy się na \"nia\"?", "Wąsate zwierzę?"};
    string odpowiedzi1[] = {"Szkolny", "Akademicki", "Chiński", "Żydowski", "Liturgiczny", "Świetlny"};
    string odpowiedzi2[] = {"Spodnie", "Sukienka", "Sweter", "Szalik", "Skarpeta", "Stanik"};
    string odpowiedzi3[] = {"Dania", "Estonia", "Hiszpania", "Rumunia", "Japonia", "Słowenia"};
    string odpowiedzi4[] = {"Kot", "Mysz", "Foka", "Mors", "Sum", "Wiewiórka"};
    int punkty[] = {30, 25, 20, 19, 16, 13};
    srand(time(0));                      // Przeprowadzam inicjalizację SEEDu randomizera w oparciu o zegar systemowy
    int random = rand() % 4;             // Do zmiennej random zapisuję jednorazowo wylosowaną wartość (od 0 do 4)
    ekranZero();                         // Drukuję pusty ekran gry, by nowa treść nie zlewała się ze starą
    cout << "\x1b[38;5;11m\x1b[48;5;0m"; // Cały tekst na ekranie będzie w kolorze żółtym (na czarnym tle)
    for (int k = 4; k <= 22; k++)
    {
        cout << "\x1b[" << k << ";20H█"; // Drukuję na ekranie żółty separator (będzie on separował błędy od odpowiedzi)
    }
    cout << "\x1b[6;26HPytanie prezentera: " << pytania[random]; // Wyświetl na ekranie wylosowanie (na podstawie zmiennej random) pytanie prezentera z tablicy pytania
    cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;         // Wyłączam wszystkie atrybuty kodów ANSI i przenoszę się dwa wiersze poniżej ekranu gry
    while ((koniec != 6) && (bledy != 3))                        // Deklaruję pętlę while, która będzie działać dopóki zmienna koniec nie osiągnie wartości 6 lub zmienna bledy wartości 3
    {
        cout << "\33[2K"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim
        cout << "Wpisz odpowiedź na pytanie prezentera: ";
        string odpowiedz;
        cin >> odpowiedz;
        bool zgadnieteHaslo = false;
        for (int j = 0; j < 6; j++)
        {
            // Jeżeli random zostanie wylosowany 0 to sprawdzaj odpowiedzi z tablicy odpowiedzi1. Jeżeli random 1, to odpowiedzi2 itd.
            if ((random == 0 && (odpowiedz == odpowiedzi1[j])) || (random == 1 && (odpowiedz == odpowiedzi2[j])) || (random == 2 && (odpowiedz == odpowiedzi3[j])) || (random == 3 && (odpowiedz == odpowiedzi4[j])))
            {
                // Jeżeli pośród elementów tablicy jest taki, którego wartość została już zmieniona na j + 1, to wyświetl komunikat o próbie oszustwa
                if (odgadniete[j] != j + 1)
                {
                    int odchylenie = rand() % 4; // Wprowadzam zmienną odchylenie, tak by między rozgrywkami ilość punktów za daną odpowiedź ciągle się zmieniała
                    cout << "\x1b[38;5;11m\x1b[48;5;0m";
                    cout << "\x1b[" << j + j + 8 << ";26H" << j + 1 << ". " << odpowiedz;
                    cout << "\x1b[" << j + j + 8 << ";68H█  " << punkty[j] + odchylenie << " pkt.";
                    suma += punkty[j] + odchylenie; // Do zmiennej suma dodaje punkty za poprawną odpowiedź (nie zapominając o wartości odchylenia)
                    cout << "\x1b[22;76HTwoja suma: " << suma << endl;
                    cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
                    cout << "\n\33[2K"; // Przenoszę się do linijki terminala niżej i czyszczę cały wiersz do końca tak by nowa treść miała miejsce
                    koniec += 1;
                    odgadniete[j] = j + 1;
                    zgadnieteHaslo = true;
                }
                else
                {
                    cout << "\33[2K"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim
                    cout << "Gorzej ci? Już raz wpisałeś/aś to hasło - nie ma za nie podwójnych punktów..." << endl;
                    zgadnieteHaslo = true;
                }
            }
        }
        if (zgadnieteHaslo == false) // Jeżeli zmienna po przejściu powyższej pętli nie zmieniła wartości, to oznacza, że wprowadzonego hasła nie ma na liście odpowiedzi
        {
            cout << "\33[2K"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim
            cout << "Niestety tego hasła nie ma na liście" << endl;
            bledy += 1;
            ekranBledy(bledy);
        }
        else
        {
            zgadnieteHaslo = false; // Zmień wartość zmiennej na pierwotną, by pętla mogła poprawnie wykonać się kolejny raz
        }
        cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
    }
    // Jeżeli suma zebranych punktów jest więcej-równo 80, to sprawdź czy pogratulować graczowi wszystkich dobrych odpowiedzi, czy pogratulować zebrania wystarczającej liczby punktów do wygrania gry. W przeciwnym wypadku wyświetl komunikat o przegranej
    if (suma >= 80)
    {
        if (bledy == 3)
        {
            cout << "\33[2K\x1b[38;5;10m"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim oraz ustawiam kolor tekstu na zielony
            cout << "Mimo, że zaliczyłeś/aś trzecią (ostatnią możliwą) wpadkę, to wciąż zdołałeś/aś wygrać!\x1b[0m" << endl;
        }
        else
        {
            cout << "\33[2K\x1b[38;5;10m"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim oraz ustawiam kolor tekstu na zielony
            cout << "Wygrana!\x1b[0m" << endl;
        }
        cout << "\33[2K"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim
        cout << "Twój wynik końcowy to: " << suma << " punktów" << endl;
    }
    else
    {
        cout << "\33[2K\x1b[38;5;9m"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim oraz ustawiam kolor tekstu na czerwony
        cout << "Przegrana :(\x1b[0m" << endl;
        cout << "\33[2K"; // Czyszczę cały wiersz do końca, tak by nowy tekst nie zlał się z poprzednim
        cout << "Twój wynik końcowy to: " << suma << " punktów" << endl;
    }
    cout << "\n\33[2K"; // Przenoszę się do linijki terminala niżej i czyszczę cały wiersz do końca
    cout << "Czy chcesz zagrać jeszcze raz? Wylosuje dla ciebie nowe pytanie (1 - tak, 2 - nie): ";
    int ponownie = 0;
    while (!(cin >> ponownie)) // Z użyciem napisanej funkcji, weryfikuję czy podany arg wejścia jest liczbą całkowitą
    {
        weryfikacja();
    }
    switch (ponownie) // Na podstawie argumentu wejścia decyduję czy przerwać grę czy też może rozpocząć kolejną rundę
    {
    case 2:
        break;
    default:
        goto GRAJ;
        break;
    }
}

void ekranBledy(int bledy)
{
    if (bledy == 1)
    {
        cout << "\x1b[38;5;11m\x1b[48;5;0m";
        cout << "\x1b[4;8H██   ██";
        cout << "\x1b[5;8H ██ ██ ";
        cout << "\x1b[6;8H  ███  ";
        cout << "\x1b[7;8H ██ ██ ";
        cout << "\x1b[8;8H██   ██";
        cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
    }
    else if (bledy == 2)
    {
        cout << "\x1b[38;5;11m\x1b[48;5;0m";
        cout << "\x1b[4;8H██   ██";
        cout << "\x1b[5;8H ██ ██ ";
        cout << "\x1b[6;8H  ███  ";
        cout << "\x1b[7;8H ██ ██ ";
        cout << "\x1b[8;8H██   ██";
        cout << "\x1b[11;8H██   ██";
        cout << "\x1b[12;8H ██ ██ ";
        cout << "\x1b[13;8H  ███  ";
        cout << "\x1b[14;8H ██ ██ ";
        cout << "\x1b[15;8H██   ██";
        cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
    }
    else if (bledy == 3)
    {
        cout << "\x1b[38;5;11m\x1b[48;5;0m";
        cout << "\x1b[4;8H██   ██";
        cout << "\x1b[5;8H ██ ██ ";
        cout << "\x1b[6;8H  ███  ";
        cout << "\x1b[7;8H ██ ██ ";
        cout << "\x1b[8;8H██   ██";
        cout << "\x1b[11;8H██   ██";
        cout << "\x1b[12;8H ██ ██ ";
        cout << "\x1b[13;8H  ███  ";
        cout << "\x1b[14;8H ██ ██ ";
        cout << "\x1b[15;8H██   ██";
        cout << "\x1b[18;8H██   ██";
        cout << "\x1b[19;8H ██ ██ ";
        cout << "\x1b[20;8H  ███  ";
        cout << "\x1b[21;8H ██ ██ ";
        cout << "\x1b[22;8H██   ██";
        cout << "\x1b[0m\x1b[" << hMax + 2 << ";0H" << endl;
    }
}
