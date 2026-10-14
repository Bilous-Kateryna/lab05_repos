#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// main з програми перейменовуємо, щоб не було двох main
#define main program_main
#include "Lab_05_3.cpp"
#undef main

TEST_CASE("s(x), |x| >= 1 or x = 0")
{
    CHECK(s(0) == doctest::Approx(2.0));
    CHECK(s(1) == doctest::Approx(0.4752732289200504));
    CHECK(s(-1) == doctest::Approx(3.511820550810161));
    CHECK(s(2) == doctest::Approx(0.15877240257222805));
}

TEST_CASE("s(x), |x| < 1, x != 0")
{
    CHECK(s(0.5) == doctest::Approx(1.3966033168673397));
    CHECK(s(0.1) == doctest::Approx(1.0134226643607267));
    CHECK(s(0.9) == doctest::Approx(3.0211685633331973));
    CHECK(s(-0.5) == doctest::Approx(1.3966033168673397));
}