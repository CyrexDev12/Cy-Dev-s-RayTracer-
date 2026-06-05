#include "Sphere.h"
#include <cmath>


// Default constructor
Sphere::Sphere() {
    radius = 1.0;
    diamater = 2.0;
    position = {0.0, 0.0, 0.0}; // Center of the sphere at the origin
}



// Return t values of the interesection points 
// Transform the ray before calculating the intersection to account for any transformations applied to the sphere
vector<double> Sphere::intersect(Ray ray) {

    // Apply the inverse of the sphere's transformation to the ray
    Ray transformedRay = ray.transform(transformMatrix.inverse());

  //  transformMatrix.inverse().printMatrix();


  // cout << "Ray Origin: " << transformedRay.origin[0] << ", " << transformedRay.origin[1] << ", " << transformedRay.origin[2] << " w: " << transformedRay.origin[3] << endl;
  // cout << "Ray Direction: " << transformedRay.direction[0] << ", " << transformedRay.direction[1] << ", " << transformedRay.direction[2] << " w: " << transformedRay.direction[3] << endl;


    vector<double> intersections;
    // Using Object space for intersection calculations, so we can treat the sphere as if it's centered at the origin with radius 1
    // Compute the coefficients of the quadratic equation
    double a = CalculateDotProd(transformedRay.direction, transformedRay.direction);
    double b = 2 * CalculateDotProd(transformedRay.direction, transformedRay.origin);
    double c = CalculateDotProd(transformedRay.origin, transformedRay.origin) - 1; // Radius is 1 in object space 
    

    // Compute the discriminant
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        // No intersection
        cout << "No intersection" << endl;
        return intersections;
    } else {
        // Compute the two intersection points
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
        intersections.push_back(t1);
        intersections.push_back(t2);
        return intersections;
    }

   
}





