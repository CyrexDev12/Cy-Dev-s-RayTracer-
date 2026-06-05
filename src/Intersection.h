// Intersection.h
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>

// Forward declaration of Shape so compiler knows it exists
class Shape; 

class Intersection {
private: 
    double t;  
    const Shape* object; 

public:
    Intersection(double t, const Shape* object) : t(t), object(object) {}

    double getT() const { return t; }
    const Shape* getObject() const { return object; }

    // Operator overloading to easily sort intersections by distance
    bool operator<(const Intersection& other) const {
        return this->t < other.t;
    }
};

class Intersections {
private:
    std::vector<Intersection> intersectionList;

public:
    // Add an intersection to our collection
    void addIntersection(const Intersection& intersection) {
        intersectionList.push_back(intersection);
    }

    // Retrieve all intersections found
    const std::vector<Intersection>& getIntersections() const {
        return intersectionList;
    }

    // Clear list between rays
    void clear() {
        intersectionList.clear();
    }

    // Returns the closest valid intersection point (t > 0)
    // Returns -1.0 if there is no valid hit in front of the ray
    double hit() const; 

    // Helper to get the actual object pointer of the closest hit
    const Shape* hitObject() const;
};

#endif
