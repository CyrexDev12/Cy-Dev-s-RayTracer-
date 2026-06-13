#include "scene/Camera.h"
#include <iostream>
#include <iomanip>
#include <cmath>


// Constructor 
Camera::Camera(double h, double v, double f) {
    hSize = h; 
    vSize = v;
    fov = f; 

    halfView = tan(fov / 2); // The width of half the canvas 
    aspect = hSize / vSize;  // Aspect ratio of the horizontal size of the canvas to its vertical size
    
    if (aspect >= 1) {
        // Horizontally dominated 
        // half view is half the width of the canvas, and half view / aspect is half of the canvas's height
        halfWidth = halfView; 
        halfHeight = halfView / aspect; 

    } else {
        // Vertically dominated 
        // half view is instead half the height of the canvas, and half the canvas's width is halfview * aspect
        halfWidth = halfView * aspect; 
        halfHeight = halfView; 
    }

    pixelSize = (halfWidth * 2) / hSize; 

}


void Camera::print() {
     // Set floating-point formatting for clean reading
    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "========================================\n";
    std::cout << "             CAMERA STATUS              \n";
    std::cout << "========================================\n";
    
    // Canvas Dimensions & Field of View
    std::cout << "  Canvas Width (hSize) : " << hSize << " px\n";
    std::cout << "  Canvas Height (vSize): " << vSize << " px\n";
    std::cout << "  Field of View (fov)  : " << fov << " rad\n";
    std::cout << "  Aspect Ratio (aspect): " << aspect << "\n";
    std::cout << "----------------------------------------\n";
    
    // Internal Ray Generation Variables
    std::cout << "  Pixel Size           : " << pixelSize << "\n";
    std::cout << "  Half View            : " << halfView << "\n";
    std::cout << "  Half Width           : " << halfWidth << "\n";
    std::cout << "  Half Height          : " << halfHeight << "\n";
    std::cout << "----------------------------------------\n";
    
    // Transformation Matrix
    std::cout << "  Transformation Matrix:\n";
    
    transform.printMatrix(); 
    
    std::cout << "========================================\n" << std::endl;
}

// Must compute the world coordinates at the center of a given pixel, and then construct a ray that passes through that point 
Ray ray_for_pixel(Camera cam, double x, double y) {
    // The offset from the edge of the canvas to the pixels center 
    double pixelSize = cam.getPixelSize(); 
    double halfWidth = cam.getHalfWidth(); 
    double halfHeight = cam.getHalfHeight(); 
    Matrix trans = cam.getTransformM(); 

    double xOffset = (x + 0.5) * pixelSize; 
    double yOffset = (y + 0.5) * pixelSize; 

    // The untransformed coordinates of the pixel in world space
    // (recall that the camera looks towards -z), so +x is to the *left)
    double world_x = halfWidth - xOffset; 
    double world_y = halfHeight - yOffset; 

    // Using the camera matrix, transform the canvas point and the origin. 
    // And then compute the rays direction vector
    // (Canvas is at z = -1)
    Matrix inv = trans.inverse(); 
    vector<double> pixel = inv.multiplyTuple({world_x, world_y, -1, 1}); 
    vector<double> origin = inv.multiplyTuple({0, 0, 0, 1}); 
    vector<double> direction = NormalizeTuple(SubtractTuples(pixel, origin)); 

    return Ray(origin, direction); 
}

std::string dashes(int count) {
    return std::string(count, '-');
}

std::string GreenHashes(int count) {
    return "\033[32m" + std::string(count, '#') + "\033[0m";
}

void updateProgress(int completedSlots) {
    const int maxSlots = 20;

    double percentage = (static_cast<double>(completedSlots) / maxSlots) * 100.0;

    std::cout << "\r"
              << GreenHashes(completedSlots)
              << dashes(maxSlots - completedSlots)
              << " (" << static_cast<int>(percentage) << "%)"
              << std::flush;
}

// Params; Camera, world
// Renders the canvas  
// NEW: Added a percentage completion timer for render
Canvas render(Camera cam, World& world) {
    int width = cam.gethSize();
    int height = cam.getvSize();

    Canvas canvas(width, height);

    int totalPixels = canvas.width * canvas.height;
    int pixCount = 0;

    int maxSlots = 20;
    int lastSlots = -1;

    for (int y = 0; y < canvas.height; y++) {
        for (int x = 0; x < canvas.width; x++) {
            Ray r = ray_for_pixel(cam, x, y);
            Color c = world.Color_at(r);
            canvas.writePixel(x, y, c);

            pixCount++;

            int completedSlots = (pixCount * maxSlots) / totalPixels;

            if (completedSlots != lastSlots) {
                updateProgress(completedSlots);
                lastSlots = completedSlots;
            }
        }
    }

    std::cout << std::endl;

    return canvas;
}