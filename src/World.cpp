#include "World.h"

// Intersect World Function 
// Iterate over all of the objects that have been added to the world, intersecting them with the ray. 
// Aggregate the intersections into a single collection 
Intersections World::intersect_world(const Ray& ray) {
    Intersections intersectionList; 

    for (auto& s : shapesList) {
        s->intersect(ray, intersectionList); // Call intersect on each shape in the list, and add the intersections to the intersection list
    }


    return intersectionList; 
}