#include "scene/pattern.h"
#include "geometry/Shape.h"


Color Pattern::PatternAtShape(const Shape* shape, const std::vector<double>& world_point) {
        // 1. Convert World Point to Object Local Space
        std::vector<double> object_point = shape->getTransform().inverse().multiplyTuple(world_point);
        
        // 2. Convert Object Local Point to Pattern Local Space
        std::vector<double> pattern_point = this->transform.inverse().multiplyTuple(object_point);
        
        // 3. Evaluate the actual mathematical formula
        return LocalPatternAt(pattern_point);
    }