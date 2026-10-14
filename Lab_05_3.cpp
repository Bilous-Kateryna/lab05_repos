// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double s(const double x);

int main()
{
    double tp, tk, z;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    double dt = (tk - tp) / n;

    double t = tp;

    cout << "-----------------------------" << endl;
    cout << "|     t     |       z       |" << endl;
    cout << "-----------------------------" << endl;

    cout << fixed << setprecision(4);

    while (t <= tk)
    {
        z = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(1));
        cout << "| " << setw(9) << t << " | " << setw(13) << z << " |" << endl;
        t += dt;
    }

    cout << "-----------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1 || x == 0)
        return (pow(cos(x), 2) + 1) / exp(x);
    else
    {
        double S = 0;
        int k = 0;
        double a = 2 * x;       // перший доданок
        S = a;
        do
        {
            k++;
            double R = 4 * x * x / ((2 * k) * (2 * k + 1));   // рекурентне співвідношення
            a *= R;
            S += a;
        } while (k < 4);
        return S / sin(2 * x);
    }
}