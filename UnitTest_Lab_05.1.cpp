// Unit test для функції k(x, y)
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"

// підключаємо програму; її main перейменовуємо, щоб не було двох main
#define main program_main
#include "Lab_05_1.cpp"
#undef main

// k(1, 1) = 1/|2| + 1/|2| = 1
TEST_CASE("TestMethod1")
{
    double t;
    t = k(1, 1);
    CHECK(t == doctest::Approx(1.0));
}

// k(2, 0) = 2/8 + 0 = 0.25
TEST_CASE("TestMethod2")
{
    double t;
    t = k(2, 0);
    CHECK(t == doctest::Approx(0.25));
}

// k(4, -2) = 4/56 + (-2)/2 = -13/14
TEST_CASE("TestMethod3")
{
    double t;
    t = k(4, -2);
    CHECK(t == doctest::Approx(-13.0 / 14.0));
}
