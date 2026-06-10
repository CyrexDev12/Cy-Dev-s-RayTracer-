#ifndef WORLD_H
#define WORLD_H

#include <vector>  // Added: explicitly include vector
#include "Shape.h"
#include "Lighting.h"
#include "Computations.h"

class World {
private: 
    std::vector<Shape*> shapesList; // List holding all shapes
    Lighting* lighting = nullptr;   // Initialized to nullptr to avoid dangling pointers 


public: 
    // Default constructor
    World();

    // DESTRUCTOR: Cleans up heap memory allocated for shapes
    ~World() {
        for (Shape* shape : shapesList) {
            delete shape; // Safely deletes each shape object
        }
        shapesList.clear(); // Empties the vector container

        // Note: We DO NOT delete 'lighting' here because your addLighting() 
        // function takes a reference to an object managed outside this class.
    }

    // Disable Copy Constructor and Copy Assignment to prevent double-deletion crashes
    World(const World&) = delete;
    World& operator=(const World&) = delete;

    void AddShape(Shape* shape) {
        shapesList.push_back(shape);
    }

    void addLighting(Lighting& ling) {
        lighting = &ling; 
    }

    Intersections intersect_world(const Ray& ray); 


    // hehe 
    Color shade_hit(const Computations& comps);

    Color Color_at(const Ray& ray);
};

#endif
