#ifndef INTERSECTION_H
#define INTERSECTION_H
#include <vector>


class Intersection {
    private: 
        double t;  // distance along the ray to the intersection
        void* object;  // pointer to the intersected object (e.g., Sphere)

    public:
        // Constructor
        Intersection(double t, void* object) : t(t), object(object) {}

        double getT() const {
            return t;
        }

        void* getObject() const {
            return object;
        }




};


class Intersections {
    private:
        std::vector<Intersection> intersections;

    public:
        void addIntersection(const Intersection& intersection) {
            intersections.push_back(intersection);
        }

        const std::vector<Intersection>& getIntersections() const {
            return intersections;
        }

        double hit() const; // Returns the t value of the closest intersection that is in front of the ray (t > 0)
};





#endif