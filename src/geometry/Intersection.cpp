// Intersection.cpp
#include "geometry/Intersection.h"
#include <limits> // For std::numeric_limits
#include <algorithm>
using namespace std; 


// Returns the closest t
// Used in hit() function to return a valid positive intersection 
// Change the return type to a pointer so you can safely signal "no hit"
const Intersection* Intersections::hit() const {
    const Intersection* closestIntersection = nullptr;
    double closestT = std::numeric_limits<double>::infinity();

    for (const auto& intersection : intersectionList) {
        double currentT = intersection.getT();
        
        // Match the book: t >= 0 (or t > 0 depending on your epsilon approach)
        if (currentT >= 0.0 && currentT < closestT) {
            closestT = currentT;
            closestIntersection = &intersection; // Track the actual object
        }
    }

    return closestIntersection; // Returns nullptr naturally if no positive t found
}



// Sort the intersections into ascending order based off of t
// In-place Sorting Algorithm is the best choice 
// overloaded operator '>' '<' for sorting 
void Intersections::Sort() {
    std::sort(intersectionList.begin(), intersectionList.end());
}
