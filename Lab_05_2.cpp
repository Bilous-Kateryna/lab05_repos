#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x"       << "     |"
                << setw(10) << "exp(-x)" << "   |"
                << setw(7) << "S"       << "      |"
                << setw(5) << "n"       << "   |"
                << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x       << "   |"
                    << setw(10) << setprecision(5) << exp(-x) << "   |"
                    << setw(10) << setprecision(5) << s       << "   |"
                    << setw(5)                     << n       << "   |"
                    << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}
#endif

// Обчислює суму ряду s з точністю eps та кількість доданків n
void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1;      // перший доданок: a0 = 1
    s = a;
    do
    {
        n++;
        A(x, n, a);    // наступний доданок через попередній
        s += a;
    } while (fabs(a) >= eps);
}

// Обчислює n-й доданок a через (n-1)-й: a(n) = a(n-1) * R, R = -x/n
void A(const double x, const int n, double &a)
{
    double R = -x / n;
    a *= R;
}