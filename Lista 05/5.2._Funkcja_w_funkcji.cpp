#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 5
// Zadanie 2

float readHeight()
{
    float height;
    cout << "Podaj wzrost (w metrach): ";
    cin >> height;
    return height;
}

int readMass()
{
    float mass;
    cout << "Podaj wagę (w kg): ";
    cin >> mass;
    return mass;
}

float BMI(float height, float mass)
{
    return mass / (height * height);
}

void BMIprint(float BMI) // fu
{
    cout << "Twoje BMI to: " << BMI << endl;
    if (BMI < 18.5)
    {
        cout << "niedowaga" << endl;
    }
    else if (BMI < 25)
    {
        cout << "optimum" << endl;
    }
    else if (BMI < 30)
    {
        cout << "nadwaga" << endl;
    }
    else
    {
        cout << "otyłość" << endl;
    }
}

int main()
{
    BMIprint(BMI(readHeight(), readMass()));
    return 0;
}
