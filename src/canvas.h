#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <cstdint>
#include "Operations.h"

struct Canvas {
    int width; 
    int height; 
    std::vector<Color> pixels; 

     Canvas(int w, int h)
        : width(w), height(h), pixels(w * h, Color{0, 0, 0}) // all black
    {}

      // Access pixel at (x, y)
    Color& at(int x, int y) {
        return pixels[y * width + x];
    }

    const Color& at(int x, int y) const {
        return pixels[y * width + x];
    }

    void writePixel(int x, int y, const Color& C);
    void canvasOut(); 
    std::string convertToPpm();
    std::string constructPixelData();
    int getMaxColorVal();
};

// PPM FILE 
// (IDENTIFIER)
// (WIDTH) (HEIGHT)
// (MAX COLOR VALUE)






#endif