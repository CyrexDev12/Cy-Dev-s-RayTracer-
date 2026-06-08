#ifndef LIGHTING_H
#define LIGHTING_H
#include "Operations.h"
#include "Material.h"
#include "LightShadeVector.h"
#include "PointLight.h"
#include "Light.h"

class Lighting { 
private: 
    // Hold a reference or pointer to the abstract base class
    const Light& sceneLight; 

public: 
    // Default Constructor 
    Lighting() = default; 
    // Constructor accepts any light type that inherits from Light
    Lighting(const Light& lightSource) : sceneLight(lightSource) {}

    // Destructor 
    ~Lighting() {
        delete &sceneLight; 
    }

    // Pass the LightShadeVector dynamically by reference
    Color ProcessLighting(Material mat, 
                           LightShadeVector& lsv, 
                           const std::vector<double>& point);

};









#endif