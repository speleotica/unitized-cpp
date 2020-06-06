#ifndef UNITIZED_LENGTH_H
#define UNITIZED_LENGTH_H

#import <cmath>

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

    inline Length(double value, Unit unit): unit(unit), value(value) {};

    inline double get(Unit unit) const {
        return convert(value, Length::unit, unit);
    }

    inline Length inUnit(Unit unit) const {
        return Length(get(unit), unit);
    }

    inline Length add(Length addend) const {
        return Length(value + addend.get(unit), unit);
    }
    inline Length sub(Length subtrahend) const {
        return Length(value - subtrahend.get(unit), unit);
    }
    inline Length mul(double multiplicand) const {
        return Length(value * multiplicand, unit);
    }
    inline Length div(double denominator) const {
        return Length(value / denominator, unit);
    }
    inline double divUnitless(Length denominator) const {
        return value / denominator.get(unit);
    }
    inline Length mod(Length modulus) const {
        return Length(fmod(value, modulus.get(unit)), unit);
    }

    inline Length abs() const {
        return Length(fabs(value), unit);
    }
    inline Length negate() const {
        return Length(-value, unit);
    }

    inline bool isFinite() const {
        return isfinite(value);
    }
    inline bool isInfinite() const {
        return isinf(value);
    }
    inline bool isNaN() const {
        return isnan(value);
    }
    inline bool isNegative() const {
        return value < 0;
    }
    inline bool isPositive() const {
        return value > 0;
    }
    inline bool isZero() const {
        return value == 0;
    }
    inline bool isNonzero() const {
        return value != 0;
    }

    inline bool equals(Length other) const {
        return value == other.get(unit);
    }

    inline int compareTo(Length other) const {
        double otherValue = other.get(unit);
        return value > otherValue ? 1 : value < otherValue ? -1 : 0;
    }

    const Unit unit;

private:
    const double value;

    inline double convert(double value, Unit from, Unit to) const {
        if (from == to) return value;
        return fromBase(toBase(value, from), to);
    };

    inline double fromBase(double value, Unit to) const {
        switch (to) {
        case Meters: return value;
        case Centimeters: return value * 100;
        case Kilometers: return value * 0.001;
        case Feet: return value / 0.3048;
        case Miles: return value / (5280 * 0.3048);
        case Yards: return value / (3 * 0.3048);
        case Inches: return value * 12 / 0.3048;
        }
    }
    inline double toBase(double value, Unit from) const {
        switch (from) {
        case Meters: return value;
        case Centimeters: return value * 0.01;
        case Kilometers: return value * 1000;
        case Feet: return value * 0.3048;
        case Miles: return value * 5280 * 0.3048;
        case Yards: return value * 3 * 0.3048;
        case Inches: return value * 0.3048 / 12;
        }
    }
};

} // namespace dewalls

#endif // UNITIZED_LENGTH_H
