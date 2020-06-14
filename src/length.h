#ifndef UNITIZED_LENGTH_H
#define UNITIZED_LENGTH_H

#include "angle.h"

namespace unitized {

class Length
{
public:
    enum Unit {
        Meters = 1,
        Centimeters = 2,
        Kilometers = 3,
        Feet = 4,
        Yards = 5,
        Inches = 6,
        Miles = 7
    };

    Length(double value, Unit unit);

    static Length meters(double value);
    static Length centimeters(double value);
    static Length kilometers(double value);
    static Length feet(double value);
    static Length yards(double value);
    static Length inches(double value);
    static Length miles(double value);

    static Angle atan2(Length y, Length x);

    double convertTo(Unit unit) const;
    double toMeters() const;
    double toCentimeters() const;
    double toKilometers() const;
    double toFeet() const;
    double toYards() const;
    double toInches() const;
    double toMiles() const;

    Length as(Unit unit) const;
    Length asMeters() const;
    Length asCentimeters() const;
    Length asKilometers() const;
    Length asFeet() const;
    Length asYards() const;
    Length asInches() const;
    Length asMiles() const;

    Length add(Length addend) const;
    Length sub(Length subtrahend) const;
    Length mul(double multiplicand) const;
    Length div(double denominator) const;
    double divUnitless(Length denominator) const;
    Length mod(Length modulus) const;
    Length abs() const;
    Length negate() const;
    bool isFinite() const;
    bool isInfinite() const;
    bool isNaN() const;
    bool isNegative() const;
    bool isPositive() const;
    bool isZero() const;
    bool isNonzero() const;
    bool equals(Length other) const;
    int compareTo(Length other) const;

    const Unit unit;

private:
    const double value;

    static double convert(double value, Unit from, Unit to);
    static double fromBase(double value, Unit to);
    static double toBase(double value, Unit from);
};

} // namespace unitized

#endif // UNITIZED_LENGTH_H
