#include "angle.h"
#include <cmath>

namespace unitized {

Angle::Angle(double value, Unit unit): unit(unit), value(value)  {}

Angle Angle::degrees(double value) {
    return Angle(value, Angle::Degrees);
}
Angle Angle::gradians(double value) {
    return Angle(value, Angle::Gradians);
}
Angle Angle::radians(double value) {
    return Angle(value, Angle::Radians);
}
Angle Angle::milsNATO(double value) {
    return Angle(value, Angle::MilsNATO);
}
Angle Angle::percentGrade(double value) {
    return Angle(value, Angle::PercentGrade);
}

double Angle::sin(Angle angle) {
    return ::sin(angle.toRadians());
}
double Angle::cos(Angle angle) {
    return ::cos(angle.toRadians());
}
double Angle::tan(Angle angle) {
    return ::tan(angle.toRadians());
}
Angle Angle::asin(double value) {
    return Angle::radians(::asin(value));
}
Angle Angle::acos(double value) {
    return Angle::radians(::acos(value));
}
Angle Angle::atan(double value) {
    return Angle::radians(::atan(value));
}
Angle Angle::atan2(double y, double x) {
    return Angle::radians(::atan2(y, x));
}

double Angle::convertTo(Unit unit) const {
    return convert(value, Angle::unit, unit);
}
double Angle::toDegrees() const {
    return convertTo(Angle::Degrees);
}
double Angle::toGradians() const {
    return convertTo(Angle::Gradians);
}
double Angle::toRadians() const {
    return convertTo(Angle::Radians);
}
double Angle::toMilsNATO() const {
    return convertTo(Angle::MilsNATO);
}
double Angle::toPercentGrade() const {
    return convertTo(Angle::PercentGrade);
}

Angle Angle::as(Unit unit) const {
    return Angle(convertTo(unit), unit);
}
Angle Angle::asDegrees() const {
    return as(Angle::Degrees);
}
Angle Angle::asGradians() const {
    return as(Angle::Gradians);
}
Angle Angle::asRadians() const {
    return as(Angle::Radians);
}
Angle Angle::asMilsNATO() const {
    return as(Angle::MilsNATO);
}
Angle Angle::asPercentGrade() const {
    return as(Angle::PercentGrade);
}

Angle Angle::add(Angle addend) const {
    return Angle(value + addend.convertTo(unit), unit);
}
Angle Angle::sub(Angle subtrahend) const {
    return Angle(value - subtrahend.convertTo(unit), unit);
}
Angle Angle::mul(double multiplicand) const {
    return Angle(value * multiplicand, unit);
}
Angle Angle::div(double denominator) const {
    return Angle(value / denominator, unit);
}
double Angle::divUnitless(Angle denominator) const {
    return value / denominator.convertTo(unit);
}
Angle Angle::mod(Angle modulus) const {
    return Angle(fmod(value, modulus.convertTo(unit)), unit);
}

Angle Angle::abs() const {
    return Angle(fabs(value), unit);
}
Angle Angle::negate() const {
    return Angle(-value, unit);
}

bool Angle::isFinite() const {
    return isfinite(value);
}
bool Angle::isInfinite() const {
    return isinf(value);
}
bool Angle::isNaN() const {
    return isnan(value);
}
bool Angle::isNegative() const {
    return value < 0;
}
bool Angle::isPositive() const {
    return value > 0;
}
bool Angle::isZero() const {
    return value == 0;
}
bool Angle::isNonzero() const {
    return value != 0;
}

bool Angle::equals(Angle other) const {
    return value == other.convertTo(unit);
}

int Angle::compareTo(Angle other) const {
    double otherValue = other.convertTo(unit);
    return value > otherValue ? 1 : value < otherValue ? -1 : 0;
}


double Angle::convert(double value, Unit from, Unit to) {
    if (from == to) return value;
    return fromBase(toBase(value, from), to);
};

double Angle::fromBase(double value, Unit to) {
    switch (to) {
    case Degrees: return value;
    case Gradians: return value * 200 / 180;
    case Radians: return value * M_PI / 180;
    case MilsNATO: return value * 3200 / 180;
    case PercentGrade: return ::tan(value * M_PI / 180) * 100;
    }
    return NAN;
}
double Angle::toBase(double value, Unit from) {
    switch (from) {
    case Degrees: return value;
    case Gradians: return value * 180 / 200;
    case Radians: return value * 180 / M_PI;
    case MilsNATO: return value * 180 / 3200;
    case PercentGrade: return ::atan(value * 0.01) * 180 / M_PI;
    }
    return NAN;
}

}
