#include "geometry/Plane.h"
#include <cmath>

// - Local Intersect: If the ray is parallel to the plane (ray.direction.y is close to 0), it misses completeley. Otherwise, t = -rayorigin.y  ray.direction.y 
void Plane::intersect(Ray ray, Intersections& intersectionsList) {

    const double EPSILON = 1e-5; // Small epsilon product to protect against floating pt issues 
    double local_ray_originY = ray.origin[1];
    double local_ray_directionY = ray.direction[1]; 

    // If the ray is moving parallel to the XZ plane, it misses
    if (abs(ray.direction[1]) < EPSILON) {
        return; // We return nothing no intersection exists 
    }

    // calculate the distance t to the intersection pt
    double t = -(local_ray_originY) / local_ray_directionY; 

    // Append to list

    intersectionsList.addIntersection(Intersection(t, this)); 

    return; 
}