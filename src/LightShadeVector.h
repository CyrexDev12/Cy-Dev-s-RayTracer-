#ifndef LIGHTSHADEVECTOR_H
#define LIGHTSHADEVECTOR_H
#include <iostream>
#include "Sphere.h"
#include <vector>
using namespace std;

/* We define this as a class that represents vectors from the point p 

- E is the eye vector, pointing from p to the origin of the ray.
- L is the light vector, poiting from p to the position of the light source.
- N is the surface normal, a vector that is perpendicular to the surface at P. 
- R is the reflection vector, poiting in the direction that incoming light would bounce, or reflect. 

*/


struct LightShadeVector {
    vector<double> E; // Eye vector
    vector<double> L; // Light vector
    vector<double> N; // Surface normal
    vector<double> R; // Reflection vector

    void printVectors() {
        cout << "Eye Vector (E): ";
        for (double value : E) {
            cout << value << " ";
        }
        cout << "\nLight Vector (L): ";
        for (double value : L) {
            cout << value << " ";
        }
        cout << "\nSurface Normal (N): ";
        for (double value : N) {
            cout << value << " ";
        }
        cout << "\nReflection Vector (R): ";
        for (double value : R) {
            cout << value << " ";
        }
        cout << endl;
    }


    void CalculateEyeVector(const vector<double>& rayOrigin); 

    void CalculateLightVector(const vector<double> lightPosition, const vector<double>& pointP);

    void CalculateNormalVector(const vector<double>& pointP, Sphere& s);

    void CalculateReflectionVector();

};






#endif