
#include "body.hpp"

#include <array>

class Simulation
{

private:
    long tick_count = 0;
    
    std::array<Body, 2> bodies;

public:
    void init();

    void tick(double delta_time);
    void run();
};
