#ifndef MATERIAL_H
#define MATERIAL_H
#include "Operations.h"


// MATERIAL STRUCT 
// INCLUDE AMBIENT, DIFFUSE, SPECULAR, SHININESS
// MUST BE UNSIGNED NEGATIVE FLOATING POINTS BETWEEN 0-1, SHININESS VALUES 10-200


struct Material {
    double ambient; 
    double diffuse; 
    double specular; 
    double shininess; 
    Color color;

     Material() : ambient(0.1), diffuse(0.9), specular(0.9), shininess(200.0), color(1.0, 1.0, 1.0) {}

};




#endif