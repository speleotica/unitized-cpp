#include "catch.hpp"
#include "../src/angle.h"
#include <cmath>
#include <initializer_list>

using namespace unitized;

void checkConversions(std::initializer_list<Angle> values, double epsilon) {
    for (Angle i : values) {
        for (Angle j : values) {
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

TEST_CASE( "Angle" , "[unitized, angle]" ) {
    SECTION("basic conversions") {
        checkConversions({
                             Angle::degrees(90),
                             Angle::gradians(100),
                             Angle::milsNATO(1600)
                         }, 0);
    }
    SECTION( "other conversions" ) {
        checkConversions({
                             Angle::radians(M_PI / 4),
                             Angle::degrees(45),
                             Angle::gradians(50),
                             Angle::milsNATO(800),
                             Angle::percentGrade(100)
                         }, 1e-12);
    }
    SECTION("trig functions") {
        CHECK(Angle::sin(Angle::degrees(90)) == 1.0);
        CHECK(Angle::cos(Angle::degrees(90)) == 0.0);
        CHECK(Angle::tan(Angle::gradians(50)) == Approx(1).epsilon(1e-12));
        CHECK(Angle::asin(1).toRadians() == Approx(M_PI_2));
        CHECK(Angle::acos(1).toRadians() == 0.0);
        CHECK(Angle::atan(1).toRadians() == M_PI_4);
        CHECK(Angle::atan2(2, 1).toRadians() == atan2(2, 1));
    }
}
