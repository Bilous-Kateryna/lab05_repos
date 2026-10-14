#define UNIT_TEST
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Lab_05_2.cpp"

TEST_CASE("A: наступний доданок ряду e^(-x)")
{
    double a = 1;
    A(2, 1, a);                      // a1 = 1 * (-2/1) = -2
    CHECK(a == doctest::Approx(-2));
    A(2, 2, a);                      // a2 = -2 * (-2/2) = 2
    CHECK(a == doctest::Approx(2));
}

TEST_CASE("S: сума ряду для e^(-x)")
{
    double s;
    int n;

    S(0, 0.0001, n, s);
    CHECK(s == doctest::Approx(1));
    CHECK(n == 1);

    S(1, 0.000001, n, s);
    CHECK(s == doctest::Approx(exp(-1.0)).epsilon(0.00001));

    S(-1, 0.000001, n, s);
    CHECK(s == doctest::Approx(exp(1.0)).epsilon(0.00001));

    S(0.5, 0.001, n, s);
    CHECK(s == doctest::Approx(exp(-0.5)).epsilon(0.001));
}