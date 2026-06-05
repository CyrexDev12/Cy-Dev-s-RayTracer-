#include <vector>
#include "BasicPhysics.h"
#include "Operations.h"
using namespace std; 


std::vector<double> Projectile::Tick() {
    // Position update: p += v * dt
    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt;

    // Velocity update: v += a * dt
    velocity[0] += windSpeed * dt;  // ax
    velocity[1] += gravity * dt;    // ay

    return position;
}