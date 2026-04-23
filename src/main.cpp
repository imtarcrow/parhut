#include <print>
#include <spdlog/spdlog.h>

#include "simulation.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::println("Usage: {} <length>", argv[0]);
        return 1;
    }

    spdlog::info("Starting...");
    auto* simulation = new Simulation();

    simulation->init();
    simulation->run();

    delete simulation;

    spdlog::info("Exiting...");
    return 0;
}
