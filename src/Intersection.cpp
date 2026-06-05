// Intersection.cpp
#include "Intersection.h"
#include <limits> // For std::numeric_limits

double Intersections::hit() const {
    double closestT = std::numeric_limits<double>::infinity();
    bool foundHit = false;

    // Loop through all recorded intersections
    for (const auto& intersection : intersectionList) {
        double currentT = intersection.getT();
        
        // A valid hit must be in front of the ray (t > 0) 
        // and closer than any previous valid hit we've found
        if (currentT > 0.0 && currentT < closestT) {
            closestT = currentT;
            foundHit = true;
        }
    }

    // If we found a valid positive intersection, return it. Otherwise return -1.0
    return foundHit ? closestT : -1.0;
}

const Shape* Intersections::hitObject() const {
    double closestT = std::numeric_limits<double>::infinity();
    const Shape* closestShape = nullptr;

    for (const auto& intersection : intersectionList) {
        double currentT = intersection.getT();
        if (currentT > 0.0 && currentT < closestT) {
            closestT = currentT;
            closestShape = intersection.getObject();
        }
    }

    return closestShape; // Returns nullptr if nothing was hit
}
