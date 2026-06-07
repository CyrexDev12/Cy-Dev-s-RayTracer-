#include "World.h"
#include "LightShadeVector.h"
#include <stdexcept>

// Intersect World Function 
// Iterate over all of the objects that have been added to the world, intersecting them with the ray. 
// Aggregate the intersections into a single collection 
Intersections World::intersect_world(const Ray& ray) {
    Intersections intersectionList; 

    for (auto& s : shapesList) {
        s->intersect(ray, intersectionList); // Call intersect on each shape in the list, and add the intersections to the intersection list
    }

    intersectionList.Sort(); // Sort, then return in ascending order
    return intersectionList; 
}


Color World::shade_hit(const Computations& comps) {
    if (lighting == nullptr) {
        throw std::runtime_error("World has no lighting configured.");
    }

    LightShadeVector lsv;
    lsv.E = comps.eyev;
    lsv.N = comps.normalv;

    return lighting->ProcessLighting(
        comps.object->getMaterial(),
        lsv,
        comps.point
    );
}