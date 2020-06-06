#include "catch.hpp"
#include "../src/length.h"
#include <initializer_list>

using namespace unitized;

void checkConversions(std::initializer_list<Length> values, double epsilon) {
    for (Length i : values) {
        for (Length j : values) {
            if (epsilon == 0) {
                REQUIRE(i.get(j.unit) == j.get(j.unit));
                REQUIRE(i.get(i.unit) == j.get(i.unit));
            } else {
                REQUIRE(i.get(j.unit) == Approx(j.get(j.unit)).epsilon(epsilon));
                REQUIRE(i.get(i.unit) == Approx(j.get(i.unit)).epsilon(epsilon));
            }
        }
    }
}

TEST_CASE( "Length" , "[unitized, length]" ) {
    SECTION("imperial conversions") {
        checkConversions({
                             Length(2, Length::Yards),
                             Length(6, Length::Feet),
                             Length(72, Length::Inches)
                         }, 0);
    }
    SECTION( "metric conversions" ) {
        checkConversions({
                             Length(1.6, Length::Kilometers),
                             Length(1600, Length::Meters),
                             Length(160000, Length::Centimeters)
                         }, 0);
    }
    SECTION( "other conversions" ) {
        checkConversions({
                             Length(0.0003048, Length::Kilometers),
                             Length(0.3048, Length::Meters),
                             Length(30.48, Length::Centimeters),
                             Length(1.0 / 5280, Length::Miles),
                             Length(1.0 / 3, Length::Yards),
                             Length(1, Length::Feet),
                             Length(12, Length::Inches)
                         }, 1e-8);
    }
}
