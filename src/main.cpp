#include <print>
#include "simulation.hpp"

int main() {
    std::print("Starting...");
    auto* simulation = new Simulation();

    simulation->init();
    simulation->run();

    delete simulation;

    std::print("Exiting...");
    return 0;
}
