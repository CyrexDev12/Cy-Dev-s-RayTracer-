#include "LightShadeVector.h"
#include "Operations.h"


// Negate the rays direction vector, turning it around to point back at its origin. 
 void LightShadeVector::CalculateEyeVector(const vector<double>& rayOrigin) {
     vector<double> rawDog = NegateTuple(rayOrigin);

     E = NormalizeTuple(rawDog); 
 }

 // Subtract p from the position of the light source, giving you the vector poiting toward the light. 
void LightShadeVector::CalculateLightVector(const vector<double> lightPosition, const vector<double>& pointP) {
    vector<double> rawDog = SubtractTuples(lightPosition, pointP);

    L = NormalizeTuple(rawDog);
} 

void LightShadeVector::CalculateNormalVector(const vector<double>& pointP, const Shape& s) {
    Matrix inverseTransform = s.getTransform().inverse();
    vector<double> objectPoint = inverseTransform.multiplyTuple(pointP);
    
    // Explicitly enforce that the normal is a VECTOR (w = 0)
    vector<double> objectNormal = SubtractTuples(objectPoint, {0, 0, 0, 1}); 
    objectNormal[3] = 0.0; 

    N = inverseTransform.transpose().multiplyTuple(objectNormal);
    N[3] = 0.0; // Ensure the output remains a clean vector
    N = NormalizeTuple(N); // Normals must be unit vectors
}

void LightShadeVector::CalculateReflectionVector() {
    double dotProductParam = 2.0 * CalculateDotProd(L, N);
    vector<double> scaledNormal = ScaleTuple(N, dotProductParam);
    
    R = SubtractTuples(scaledNormal, L); 
    R[3] = 0.0; 
    R = NormalizeTuple(R); // Add this to guarantee a perfect unit vector!
}