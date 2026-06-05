#ifndef RAY_H
#define RAY_H
#include <iostream>
#include <vector>
#include "Operations.h"
#include "Matrix.h"


using namespace std; 


// RAY CLASS 

// RAY CASTING: Creating a ray or line, and finding the intersections of that ray with the objects within the scene

// RAY Includes; A starting point Origin, and a vector called the direction which says where it points

// We think of the rays direction vector as its speed

struct Ray {
    vector<double> origin; // POINT
    vector<double> direction; // VECTOR
    

    // Compute the point at the given distance t along the ray
    vector<double> position(double t);
    Ray transform(Matrix m);

    // Debug function
    void printRay() {
        cout << "Ray Origin: ";
        for (double value : origin) {
            cout << value << " ";
        }
        cout << "\nRay Direction: ";
        for (double value : direction) {
            cout << value << " ";
        }
        cout << endl;
    }

    
};

















#endif