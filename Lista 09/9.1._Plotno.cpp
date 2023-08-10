#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Tomasz Targiel
// Lista 9
// Zadanie 1

const int W = 600;
const int H = 600;

int R[W][H];
int G[W][H];
int B[W][H];

void gradient()
{
    srand(time(NULL));
    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
        {
            R[i][j] = (j / float(W)) * (rand() % 255);
            G[i][j] = (i / float(H)) * (rand() % 155);
            B[i][j] = (j / float(W)) * (rand() % 55);
        }
}

void saveppm()
{
    ofstream myfile;

    myfile.open("9.1._Plotno.ppm");
    myfile << "P3" << endl << W << " " << H << " " << endl << 255 << endl;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            myfile << R[x][y] << " " << G[x][y] << " " << B[x][y] << " " << endl;
        }
        myfile << endl;
    }
    myfile.close();
}

int main()
{
    gradient();
    saveppm();

    return 0;
}
