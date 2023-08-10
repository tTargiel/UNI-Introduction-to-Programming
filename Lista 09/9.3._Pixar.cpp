#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 9
// Zadanie 3

const int W = 1280;
const int H = 720;

int R[W][H];
int G[W][H];
int B[W][H];

void saveppm(int k)
{
    char workbuf[25];
    sprintf(workbuf, "klatka_%d.ppm", k);

    ofstream myfile(workbuf);

    myfile << "P3" << endl << W << " " << H << endl << 255 << endl;
    for (int j = 0; j < H; j++)
    {
        for (int i = 0; i < W; i++)
        {
            myfile << R[i][j] << " " << G[i][j] << " " << B[i][j] << " ";
        }
        myfile << endl;
    }
    myfile.close();
}

void pixel(int x, int y)
{
    R[x][y] = G[x][y] = B[x][y] = 255;
}

float h(float x)
{
    float a = 0.5;
    return a * x + (2 * (1 - a) * x * x) / (1 + x * x);
}

void iteracja(float &xn, float &yn, float a)
{
    float xn_poprzednie = xn;
    xn = yn + h(xn);
    yn = -xn_poprzednie + h(xn);
}

void clearpic()
{
    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
            R[i][j] = G[i][j] = B[i][j] = 0;
}

int main()
{
    const int NK = 100;
    for (int k = 1; k < NK; k++)
    {
        clearpic();
        float xn = W * (sin(3.1415 * k / float(NK))) * 0.1, yn = H * (sin(3.1415 * (k) / float(NK))) * 0.1;

        float ar = W / float(W);
        float amin = -0.3;
        float amax = -0.1;
        float a = (k / float(NK) - 0.5) * (amax - amin) + amin;
        // yn *= W / float(H);
        for (int i = 0; i < 1500; i++)
        {
            iteracja(xn, yn, a);
            const int S = 5;

            int xe = xn * S + W / 2.0;      // W
            int ye = yn * S * ar + H / 2.0; // H
            if (xe > 0 && xe < W && ye > 0 && ye < H)
                pixel(xe, ye);

            // cout << i << " " << xn << " " << yn << endl;
        }
        saveppm(k);
        cout << "Zapisano: " << k << "; a = " << a << endl;
    }
    return 0;
}
