#include "scene/PointLight.h"



PointLight::PointLight() {
  position = {0, 0, 0}; 
  Color white(1, 1, 1); // Pure white

  intensity = white; 
}


// Constructor for PointLight, initializes position and intensity
// White Color default 
  PointLight::PointLight(const std::vector<double>& pos, const Color& col) {
    if (!isPoint(pos)) {
        throw invalid_argument("Must be a point tuple!");
    }

    position = pos; 
    intensity = col; 
  }


