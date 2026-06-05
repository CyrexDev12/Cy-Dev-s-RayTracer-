#include "Intersection.h"
#include <iostream>
#include <limits>



double Intersections::hit() const {
    double closestT = std::numeric_limits<double>::infinity();

    for (const Intersection& intersection : intersections) {
        double t = intersection.getT();
        if (t > 0 && t < closestT) {
            closestT = t;
        }
    }

    std::cout << "Closest hit t value: " << closestT << std::endl;

    return closestT;
}