#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 10 (dodatkowa)
// Zadanie 1

const int W = 800;
const int H = 800;

int R[W][H];
int G[W][H];
int B[W][H];

void clear()
{
    for (int x = 0; x < W; x++)
    {
        for (int y = 0; y < H; y++)
        {
            R[x][y] = 0;
        }
    }
}

void zbiorMandelbrota()
{
    clear();
    for (int x = 0; x < W; x++)
    {
        for (int y = 0; y < H; y++)
        {
            double x0 = 1.5;
            double y0 = 1;
            int alfa = 255;
            int iteracja = 0;
            int max_iteracji = 20;
            complex<float> point((float)2 * x / W - x0, (float)2 * y / H - y0);
            complex<float> z(0, 0);
            do
            {
                z = z * z + point;
                iteracja++;
            } while (abs(z) < 2 && iteracja <= max_iteracji);
            if (iteracja < max_iteracji)
            {
                B[x][y] = (alfa * iteracja) / max_iteracji;
            }
            else
            {
                B[x][y] = 0;
            }
        }
    }
}

void saveppm()
{
    ofstream myfile;

    myfile.open("D.1._Zbior_Mandelbrota.ppm");
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
    zbiorMandelbrota();
    saveppm();

    return 0;
}
