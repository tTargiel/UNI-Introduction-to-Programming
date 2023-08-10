#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 6

int main()
{
    cout << "\x1b[0m      " << "\x1b[48;5;1m          \x1b[0m" << endl;
    cout << "\x1b[0m    " << "\x1b[48;5;1m                  \x1b[0m" << endl;
    cout << "\x1b[0m    " << "\x1b[48;5;94m      \x1b[48;5;215m    \x1b[48;5;0m  \x1b[48;5;215m  \x1b[0m" << endl;
    cout << "\x1b[0m  " << "\x1b[48;5;94m  \x1b[48;5;215m  \x1b[48;5;94m  \x1b[48;5;215m      \x1b[48;5;0m  \x1b[48;5;215m      \x1b[0m" << endl;
    cout << "\x1b[0m  " << "\x1b[48;5;94m  \x1b[48;5;215m  \x1b[48;5;94m    \x1b[48;5;215m      \x1b[48;5;94m  \x1b[48;5;215m      \x1b[0m" << endl;
    cout << "\x1b[0m  " << "\x1b[48;5;94m    \x1b[48;5;215m        \x1b[48;5;94m        \x1b[0m" << endl;
    cout << "\x1b[0m      " << "\x1b[48;5;215m              \x1b[0m" << endl;
    cout << "\x1b[0m    " << "\x1b[48;5;1m    \x1b[48;5;4m  \x1b[48;5;1m      \x1b[0m" << endl;
    cout << "\x1b[0m  " << "\x1b[48;5;1m      \x1b[48;5;4m  \x1b[48;5;1m    \x1b[48;5;4m  \x1b[48;5;1m      \x1b[0m" << endl;
    cout << "\x1b[0m" << "\x1b[48;5;1m        \x1b[48;5;4m        \x1b[48;5;1m        \x1b[0m" << endl;
    cout << "\x1b[0m" << "\x1b[48;5;215m    \x1b[48;5;1m  \x1b[48;5;4m  \x1b[48;5;11m  \x1b[48;5;4m    \x1b[48;5;11m  \x1b[48;5;4m  \x1b[48;5;1m  \x1b[48;5;215m    \x1b[0m" << endl;
    cout << "\x1b[0m" << "\x1b[48;5;215m      \x1b[48;5;4m            \x1b[48;5;215m      \x1b[0m" << endl;
    cout << "\x1b[0m" << "\x1b[48;5;215m    \x1b[48;5;4m                \x1b[48;5;215m    \x1b[0m" << endl;
    cout << "\x1b[0m    " << "\x1b[48;5;4m      " << "\x1b[0m    " << "\x1b[48;5;4m      \x1b[0m" << endl;
    cout << "\x1b[0m  " << "\x1b[48;5;94m      " << "\x1b[0m        " << "\x1b[48;5;94m      \x1b[0m" << endl;
    cout << "\x1b[0m" << "\x1b[48;5;94m        " << "\x1b[0m        " << "\x1b[48;5;94m        \x1b[0m" << endl;

    cout << endl; 

    cout << "\x1b[0m                  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m                \x1b[48;5;1m  \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m              \x1b[48;5;1m    \x1b[48;5;210m    \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m            \x1b[48;5;1m    \x1b[48;5;0m  \x1b[48;5;1m  \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m          \x1b[48;5;1m          \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m        \x1b[48;5;1m      \x1b[48;5;0m  \x1b[48;5;1m    \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m      \x1b[48;5;1m              \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m    \x1b[48;5;1m      \x1b[48;5;0m  \x1b[48;5;1m      \x1b[48;5;210m    \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[0m  \x1b[48;5;1m                \x1b[48;5;210m  \x1b[48;5;10m  \x1b[48;5;2m  \x1b[0m\n";
    cout << "\x1b[48;5;10m  \x1b[48;5;210m    \x1b[48;5;1m        \x1b[48;5;210m    \x1b[48;5;10m  \x1b[48;5;2m    \x1b[0m\n";
    cout << "\x1b[48;5;2m  \x1b[48;5;10m  \x1b[48;5;210m            \x1b[48;5;10m  \x1b[48;5;2m    \x1b[0m\n";
    cout << "\x1b[0m  \x1b[48;5;2m  \x1b[48;5;10m            \x1b[48;5;2m    \x1b[0m\n";
    cout << "\x1b[0m    \x1b[48;5;2m            \x1b[0m\n";
    return 0;
}
