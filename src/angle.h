#ifndef UNITIZED_ANGLE_H
#define UNITIZED_ANGLE_H

namespace unitized {

class Angle
{
public:
    enum Unit {
        Degrees = 1,
        Gradians = 2,
        Radians = 3,
        MilsNATO = 4,
        PercentGrade = 5
    };

    Angle(double value, Unit unit);

    static Angle degrees(double value);
    static Angle gradians(double value);
    static Angle radians(double value);
    static Angle milsNATO(double value);
    static Angle percentGrade(double value);

    static double sin(Angle angle);
    static double cos(Angle angle);
    static double tan(Angle angle);
    static Angle asin(double value);
    static Angle acos(double value);
    static Angle atan(double value);
    static Angle atan2(double y, double x);

    double convertTo(Unit unit) const;
    double toDegrees() const;
    double toGradians() const;
    double toRadians() const;
    double toMilsNATO() const;
    double toPercentGrade() const;

    Angle as(Unit unit) const;
    Angle asDegrees() const;
    Angle asGradians() const;
    Angle asRadians() const;
    Angle asMilsNATO() const;
    Angle asPercentGrade() const;

    Angle add(Angle addend) const;
    Angle sub(Angle subtrahend) const;
    Angle mul(double multiplicand) const;
    Angle div(double denominator) const;
    double divUnitless(Angle denominator) const;
    Angle mod(Angle modulus) const;
    Angle abs() const;
    Angle negate() const;
    bool isFinite() const;
    bool isInfinite() const;
    bool isNaN() const;
    bool isNegative() const;
    bool isPositive() const;
    bool isZero() const;
    bool isNonzero() const;
    bool equals(Angle other) const;
    int compareTo(Angle other) const;

    const Unit unit;

private:
    const double value;

    static double convert(double value, Unit from, Unit to);
    static double fromBase(double value, Unit to);
    static double toBase(double value, Unit from);
};

} // namespace unitized

#endif // UNITIZED_ANGLE_H
