#include "simulation.hpp"
#include <print>
#include <unistd.h>

void Simulation::init() {
    std::println("Initializing Simulation...");
}

void Simulation::tick(double delta_time) {
    std::println("{}. tick {}", this->tick_count, delta_time);
    this->tick_count++;
}

void Simulation::run() {
    while(true) {
        this->tick(0.02);
        usleep(20000);
    }
}
