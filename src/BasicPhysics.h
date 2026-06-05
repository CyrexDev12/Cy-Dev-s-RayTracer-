#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>


class Projectile {
private:
    std::vector<double> position;
    std::vector<double> velocity;
    double gravity;
    double windSpeed;
    double dt;          // time step

public:
    Projectile(std::vector<double> initPos,
               std::vector<double> vel,
               double grav,
               double windS,
               double timestep)
        : position(initPos),
          velocity(vel),
          gravity(grav),
          windSpeed(windS),
          dt(timestep) {}

    std::vector<double> Tick();
};









#endif