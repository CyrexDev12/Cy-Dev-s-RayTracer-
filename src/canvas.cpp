#include "canvas.h"
#include <vector>
#include <iostream>
#include <string> 
#include <sstream>
#include <cmath> // Required for std::round
#include <fstream>

using namespace std; 

void Canvas::writePixel(int x, int y, const Color& C) {
    int index = y * width + x; 
    pixels[index] = C;
}

string Canvas::convertToPpm() {
    string identifier = "P3"; 
    string widthStr = to_string(width);
    string heightStr = to_string(height); 

    // The max color value in a standard PPM is hardcoded to 255 because
    // we clamp and scale our internal floating-point values down to 0-255 bytes.
    return identifier + "\n" + widthStr + " " + heightStr + "\n" + "255" + "\n" + constructPixelData() + "\n";
}

std::string Canvas::constructPixelData() {
    std::ostringstream oss;

    for (int y = 0; y < height; ++y) {
        int lineLength = 0; 

        for (int x = 0; x < width; ++x) {
            const Color& c = at(x, y);

            // Helper function to safely convert a floating-point color component (0.0 to 1.0+) 
            // into a standard PPM integer byte (0 to 255).
            auto clampAndScale = [](double v) -> int {
                if (v < 0.0) v = 0.0;
                if (v > 1.0) v = 1.0; // Clamps HDR values like 1.9 down to maximum white (1.0)
                return static_cast<int>(std::round(v * 255.0));
            };

            // Lambda to handle individual integer component writing while respecting the 70-character PPM line rule
            auto writeComponent = [&](int value) {
                std::string s = std::to_string(value);
                int needed = (lineLength == 0 ? 0 : 1) + static_cast<int>(s.size());

                if (lineLength + needed > 70) {
                    oss << "\n";
                    lineLength = 0;
                }

                if (lineLength > 0) {
                    oss << " ";
                    lineLength += 1;
                }

                oss << s;
                lineLength += static_cast<int>(s.size());
            };

            // Process and write the transformed color channels
            writeComponent(clampAndScale(c.r));
            writeComponent(clampAndScale(c.g));
            writeComponent(clampAndScale(c.b));
        }

        oss << "\n"; 
    }

    return oss.str();
}

// You can completely remove or deprecate getMaxColorVal()!
// Because we clamp all float colors to the 0.0 - 1.0 range and scale them to 255, 
// your PPM's max color value will always safely be 255.
int Canvas::getMaxColorVal() {
    return 255;
}

// Outputs the PPM file 
void Canvas::canvasOut() {
     ofstream out("raySphereCanvas.ppm");
    if (!out) {
        cerr << "Could not create raySphereCanvas.ppm" << endl;
        return;
    }

    string ppm = convertToPpm(); 
    out << ppm;
    out.close();
    cout << "Render complete! raySphereCanvas.ppm\n";
}
