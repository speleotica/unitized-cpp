%module unitized

namespace unitized {

class Angle;
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
};

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
};

} // namespace unitized