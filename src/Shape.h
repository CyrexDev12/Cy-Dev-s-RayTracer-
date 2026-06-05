// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <stdexcept>
#include "Ray.h"
#include "Material.h"
#include "Matrix.h" // Assuming Matrix is defined here
#include "Intersection.h"

class Shape {
protected:
    std::vector<double> position;
    Matrix transformMatrix; 
    Material material; 

public:
    virtual ~Shape() = default;

    // Pure virtual function: Every shape must implement its own math
    virtual void intersect(Ray ray, Intersections& intersectionsList) = 0;

    // --- Common Getters & Setters ---
    Matrix getTransform() const { return transformMatrix; }
    void setTransform(const Matrix& m) { this->transformMatrix = m; } 

    std::vector<double> getPosition() const { return position; }
    void setPosition(const std::vector<double>& pos) { this->position = pos; }

    Material getMaterial() const { return material; }
    Color getMaterialColor() const { return material.color; }
    void setMaterialColor(const Color& color) { material.color = color; }

    void setAmbient(double num) {
        if (num < 0.0 || num > 1.0) throw std::invalid_argument("Must be a value between 0-1!");
        material.ambient = num; 
    }

    void setDiffuse(double num) {
        if (num < 0.0 || num > 1.0) throw std::invalid_argument("Must be a value between 0-1!");
        material.diffuse = num; 
    }

    void setSpecular(double num) {
        if (num < 0.0 || num > 1.0) throw std::invalid_argument("Must be a value between 0-1!");
        material.specular = num; 
    }

    void setShininess(double num) {
        if (num < 10.0 || num > 200.0) throw std::invalid_argument("Must be a value between 10-200!");
        material.shininess = num; 
    }
};

#endif
