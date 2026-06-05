#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include <iostream>
#include <vector>
#include "Operations.h"
#include "Light.h"
using namespace std;


// No size or shape, exists at a single point in space, defined by intensity (how bright it is), the intensity also describes the light source.



// Your updated PointLight class inheriting from Light
class PointLight : public Light {
private:
    std::vector<double> position;
    Color intensity;

public:
    PointLight();

    PointLight(const std::vector<double>& pos, const Color& col);

    Color getIntensity() const override { return intensity; }
    std::vector<double> getPosition() const override { return position; }
};







#endif