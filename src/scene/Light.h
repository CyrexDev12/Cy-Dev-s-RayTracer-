#ifndef LIGHT_H
#define LIGHT_H
#include "scene/LightShadeVector.h"
#include "scene/PointLight.h"
#include "math/Operations.h"
#include "scene/Material.h"

// Base Class for all light types 
class Light {
    public:
    virtual ~Light() = default; 

    // Pure virtual functions that every light must provide
    virtual Color getIntensity() const = 0; 
    virtual vector<double> getPosition() const = 0; 

};













#endif