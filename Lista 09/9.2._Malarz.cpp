#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Tomasz Targiel
// Lista 9
// Zadanie 2

const int W = 800;
const int H = 800;

int R[W][H];
int G[W][H];
int B[W][H];

void circle(int start_x, int start_y, double d)
{
    double r = 0;
    for (int i = start_x; i <= (start_x + d); i++)
    {
        for (int j = start_y; j <= (start_y + d); j++)
        {
            r = sqrt(pow(i - (start_x + (d / 2)), 2) + pow(j - (start_y + (d / 2)), 2));
            if (r <= d / 2)
            {
                R[i][j] = (j / (start_x + d)) * 255;
                G[i][j] = (i / (start_y + d)) * 155;
                B[i][j] = (j / (start_x + d)) * 55;
            }
            r = 0;
        }
    }
}

void saveppm()
{
    ofstream myfile;

    myfile.open("9.2._Malarz.ppm");
    myfile << "P3" << endl << W << " " << H << endl << 255 << endl;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            myfile << R[x][y] << " " << G[x][y] << " " << B[x][y] << " ";
        }
        myfile << endl;
    }
    myfile.close();
}

int main()
{
    srand(time(NULL));
    int diameter = 100;
    for (int k = 0; k < 16; k++)
    {
        circle((rand() % (W - diameter)), (rand() % (H - diameter)), rand() % diameter);
    }
    saveppm();

    return 0;
}
