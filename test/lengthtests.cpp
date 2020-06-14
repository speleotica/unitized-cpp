#include "catch.hpp"
#include "../src/length.h"
#include <initializer_list>

using namespace unitized;

void checkConversions(std::initializer_list<Length> values, double epsilon) {
    for (Length i : values) {
        for (Length j : values) {
            if (epsilon == 0) {
                CHECK(i.convertTo(j.unit) == j.convertTo(j.unit));
                CHECK(i.convertTo(i.unit) == j.convertTo(i.unit));
            } else {
                CHECK(i.convertTo(j.unit) == Approx(j.convertTo(j.unit)).epsilon(epsilon));
                CHECK(i.convertTo(i.unit) == Approx(j.convertTo(i.unit)).epsilon(epsilon));
            }
        }
    }
}

TEST_CASE( "Length" , "[unitized, length]" ) {
    SECTION("imperial conversions") {
        checkConversions({
                             Length::yards(2),
                             Length::feet(6),
                             Length::inches(72)
                         }, 0);
    }
    SECTION( "metric conversions" ) {
        checkConversions({
                             Length::kilometers(1.6),
                             Length::meters(1600),
                             Length::centimeters(160000)
                         }, 0);
    }
    SECTION( "other conversions" ) {
        checkConversions({
                             Length::kilometers(0.0003048),
                             Length::meters(0.3048),
                             Length::centimeters(30.48),
                             Length::miles(1.0 / 5280),
                             Length::yards(1.0 / 3),
                             Length::feet(1),
                             Length::inches(12)
                         }, 1e-8);
    }
}
