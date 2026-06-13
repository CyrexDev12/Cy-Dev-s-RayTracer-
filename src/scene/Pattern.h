// Pattern.h
#ifndef PATTERN_H
#define PATTERN_H

#include "math/Matrix.h"
#include "math/Operations.h"
#include <cmath>

// Current Patterns: Stripe, Checkers 
// NOTE: Checkers cause issues, render distortion 

class Shape; // FORWARD DECLERATION 

class Pattern {
public:
    Matrix transform; 

    Pattern() = default; 
    virtual ~Pattern() = default;

    Color PatternAtShape(const Shape* shape, const std::vector<double>& world_point);
    virtual Color LocalPatternAt(const std::vector<double>& pattern_point) = 0;
};

class StripePattern : public Pattern {
private:
    Color colorA;
    Color colorB;

public:
    StripePattern(Color a, Color b) : colorA(a), colorB(b) {}

    Color LocalPatternAt(const std::vector<double>& pattern_point) override {
        if (static_cast<int>(std::floor(pattern_point[0])) % 2 == 0) {
            return colorA;
        }
        return colorB;
    }
};

class CheckersPattern : public Pattern {
private:
    Color colorA;
    Color colorB;

public:
    CheckersPattern(Color a, Color b) : colorA(a), colorB(b) {}

    Color LocalPatternAt(const std::vector<double>& pattern_point) override {
        double sum = std::floor(pattern_point[0]) + 
                     std::floor(pattern_point[1]) + 
                     std::floor(pattern_point[2]);
                     
        if (static_cast<int>(sum) % 2 == 0) {
            return colorA;
        }
        return colorB;
    }
};

#endif
