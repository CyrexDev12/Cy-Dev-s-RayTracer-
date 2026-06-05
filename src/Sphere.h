#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <vector> 
#include "Ray.h"
#include "Material.h"
using namespace std; 



class Sphere {

private: 
double radius; 
double diamater;
vector<double> position;
Matrix transformMatrix; // Transformation matrix for the sphere (e.g., for scaling, translation, etc.)
Material material; // Struct inlcuding; ambient, diffuse, specular, and shininess. 



public:
// Default constructor 
Sphere(); 


 

vector<double> intersect(Ray ray);

Matrix getTransform() {
    return transformMatrix;
}


void settransform(Matrix m) {
    this->transformMatrix = m;

} 

void setAmbient(double& num) {
    if (num < 0 || num > 1) {
        throw invalid_argument("Must be a value between 0-1!");
    }

    material.ambient = num; 
}

void setDiffuse(double& num) {
 if (num < 0 || num > 1) {
        throw invalid_argument("Must be a value between 0-1!");
    }

    material.diffuse = num; 
}

void setSpecular(double& num) {
    if (num < 0 || num > 1) {
        throw invalid_argument("Must be a value between 0-1!");
    }

    material.specular = num; 
}

void setShininess(double& num) {
    if (num < 10 || num > 200) {
        throw invalid_argument("Must be a value between 10-200!");
    }

    material.shininess = num; 
}


};


#endif