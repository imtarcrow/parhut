#include "simulation.hpp"

#include <spdlog/spdlog.h>
#include <unistd.h>

void Simulation::init()
{
    spdlog::info("Initializing Simulation...");
}

void Simulation::tick(double delta_time)
{
    spdlog::info("{}. tick {}", this->tick_count, delta_time);
    this->tick_count++;
}

void Simulation::run()
{
    while (true) {
        this->tick(0.02);
        usleep(20000);
    }
}
