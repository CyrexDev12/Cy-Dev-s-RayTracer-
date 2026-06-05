#include "Lighting.h"
#include <cmath>

 Color Lighting::ProcessLighting(Material mat, LightShadeVector& lsv, const std::vector<double>& point) {

     Color black(0, 0, 0);
        Color diffuse = black;
        Color specular = black;
        Color Intensity = sceneLight.getIntensity();

        Color effectiveColor = multiplyColors(mat.color, Intensity);

        // Uses the local lsv reference safely across any single pixel execution
        lsv.CalculateLightVector(sceneLight.getPosition(), point);

        Color ambient = multiplyByScalar(effectiveColor, mat.ambient);
        double lightDotNorm = CalculateDotProd(lsv.L, lsv.N); 
        
        if (lightDotNorm >= 0.0) {
            diffuse = multiplyByScalar(effectiveColor, mat.diffuse * lightDotNorm);

            lsv.CalculateReflectionVector();
            double reflectDotProd = CalculateDotProd(lsv.R, lsv.E); 

            if (reflectDotProd > 0.0) {
                double factor = pow(reflectDotProd, mat.shininess);
                double overallSpecularFactor = mat.specular * factor;
                specular = multiplyByScalar(Intensity, overallSpecularFactor); 
            }
        }

        Color result = addColors(ambient, diffuse);
        return addColors(result, specular);

 }