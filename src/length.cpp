#include "length.h"
#include "angle.h"
#include <cmath>

namespace unitized {

Length::Length(double value, Unit unit): unit(unit), value(value)  {}

Length Length::meters(double value) {
    return Length(value, Length::Meters);
}
Length Length::centimeters(double value) {
    return Length(value, Length::Centimeters);
}
Length Length::kilometers(double value) {
    return Length(value, Length::Kilometers);
}
Length Length::feet(double value) {
    return Length(value, Length::Feet);
}
Length Length::yards(double value) {
    return Length(value, Length::Yards);
}
Length Length::inches(double value) {
    return Length(value, Length::Inches);
}
Length Length::miles(double value) {
    return Length(value, Length::Miles);
}

Angle Length::atan2(Length y, Length x) {
    return Angle::atan2(y.convertTo(y.unit), x.convertTo(y.unit));
}

double Length::convertTo(Unit unit) const {
    return convert(value, Length::unit, unit);
}
double Length::toMeters() const {
    return convertTo(Length::Meters);
}
double Length::toCentimeters() const {
    return convertTo(Length::Centimeters);
}
double Length::toKilometers() const {
    return convertTo(Length::Kilometers);
}
double Length::toFeet() const {
    return convertTo(Length::Feet);
}
double Length::toYards() const {
    return convertTo(Length::Yards);
}
double Length::toInches() const {
    return convertTo(Length::Inches);
}
double Length::toMiles() const {
    return convertTo(Length::Miles);
}

Length Length::as(Unit unit) const {
    return Length(convertTo(unit), unit);
}
Length Length::asMeters() const {
    return as(Length::Meters);
}
Length Length::asCentimeters() const {
    return as(Length::Centimeters);
}
Length Length::asKilometers() const {
    return as(Length::Kilometers);
}
Length Length::asFeet() const {
    return as(Length::Feet);
}
Length Length::asYards() const {
    return as(Length::Yards);
}
Length Length::asInches() const {
    return as(Length::Inches);
}
Length Length::asMiles() const {
    return as(Length::Miles);
}

Length Length::add(Length addend) const {
    return Length(value + addend.convertTo(unit), unit);
}
Length Length::sub(Length subtrahend) const {
    return Length(value - subtrahend.convertTo(unit), unit);
}
Length Length::mul(double multiplicand) const {
    return Length(value * multiplicand, unit);
}
Length Length::div(double denominator) const {
    return Length(value / denominator, unit);
}
double Length::divUnitless(Length denominator) const {
    return value / denominator.convertTo(unit);
}
Length Length::mod(Length modulus) const {
    return Length(fmod(value, modulus.convertTo(unit)), unit);
}

Length Length::abs() const {
    return Length(fabs(value), unit);
}
Length Length::negate() const {
    return Length(-value, unit);
}

bool Length::isFinite() const {
    return isfinite(value);
}
bool Length::isInfinite() const {
    return isinf(value);
}
bool Length::isNaN() const {
    return isnan(value);
}
bool Length::isNegative() const {
    return value < 0;
}
bool Length::isPositive() const {
    return value > 0;
}
bool Length::isZero() const {
    return value == 0;
}
bool Length::isNonzero() const {
    return value != 0;
}

bool Length::equals(Length other) const {
    return value == other.convertTo(unit);
}

int Length::compareTo(Length other) const {
    double otherValue = other.convertTo(unit);
    return value > otherValue ? 1 : value < otherValue ? -1 : 0;
}


double Length::convert(double value, Unit from, Unit to) {
    if (from == to) return value;
    return fromBase(toBase(value, from), to);
};

double Length::fromBase(double value, Unit to) {
    switch (to) {
    case Meters: return value;
    case Centimeters: return value * 100;
    case Kilometers: return value * 0.001;
    case Feet: return value / 0.3048;
    case Miles: return value / (5280 * 0.3048);
    case Yards: return value / (3 * 0.3048);
    case Inches: return value * 12 / 0.3048;
    }
    return NAN;
}
double Length::toBase(double value, Unit from) {
    switch (from) {
    case Meters: return value;
    case Centimeters: return value * 0.01;
    case Kilometers: return value * 1000;
    case Feet: return value * 0.3048;
    case Miles: return value * 5280 * 0.3048;
    case Yards: return value * 3 * 0.3048;
    case Inches: return value * 0.3048 / 12;
    }
    return NAN;
}

}
