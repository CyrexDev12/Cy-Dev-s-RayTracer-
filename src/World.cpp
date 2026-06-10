#include "World.h"
#include "LightShadeVector.h"
#include <stdexcept>

// Default World constructor 

World::World() {
    PointLight* ptLight = new PointLight({{-10, 10, -10, 1}, Color(1, 1, 1)});

    Lighting *ling = new Lighting(*ptLight); 

    lighting = ling; 
    
}


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
        throw std::runtime_error("World has no lighting configured."); // Commented out, as lighting starts of null to get configured 
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



// Find color_at the hit()
Color World::Color_at(const Ray& ray) {
    Intersections intersections = intersect_world(ray);

    // Get a pointer to the closest hit
    const Intersection* intersection = intersections.hit(); 

    // If no valid positive intersection exists, return black immediately
    if (intersection == nullptr) {
        return Color{0, 0, 0};
    }

    // Dereference the pointer safely now that we verified it exists
    Computations comp = prepareComputations(*intersection, ray);

    return shade_hit(comp);
}
