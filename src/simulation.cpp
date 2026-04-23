#include "simulation.hpp"

#include <cstddef>
#include <glm/ext/vector_double2.hpp>
#include <glm/geometric.hpp>
#include <random>
#include <spdlog/spdlog.h>
#include <unistd.h>

constexpr double GRAVITATIONAL_CONSTANT = 6.671e-11;

void Simulation::init()
{
    spdlog::info("Initializing Simulation...");

    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    this->bodies[0] = Body(10e22, 2, { 1.469e11, 0 }, { dist(rng), dist(rng) });
    this->bodies[1] = Body(10e22, 2, { -1.469e11, 0 }, { dist(rng), dist(rng) });
}

void Simulation::tick(double delta_time)
{
    spdlog::trace("{}. tick {}", this->tick_count, delta_time);

    if (this->tick_count % 10000 == 0) {
        spdlog::info("{}. Tick", this->tick_count);

        glm::dvec2 pos1 = this->bodies[0].get_position();
        spdlog::info("b1 {} {}", pos1.x, pos1.y);

        glm::dvec2 pos2 = this->bodies[1].get_position();
        spdlog::info("b2 {} {}", pos2.x, pos2.y);
    }

    for (std::size_t i = 0; i < bodies.size(); i++) {
        for (std::size_t j = i + 1; j < bodies.size(); j++) {
            auto& b1 = bodies[i];
            auto& b2 = bodies[j];

            glm::dvec2 direction = b2.get_position() - b1.get_position();
            double distance = glm::length(direction);

            if (distance < b1.get_radius() + b2.get_radius()) {
                continue;
            }

            double acceleration_b1 = GRAVITATIONAL_CONSTANT * (b2.get_mass() / (distance * distance));
            double acceleration_b2 = GRAVITATIONAL_CONSTANT * (b1.get_mass() / (distance * distance));

            b1.set_acceleration((glm::normalize(direction) * acceleration_b1) + b1.get_acceleration());
            b2.set_acceleration((glm::normalize(-direction) * acceleration_b2) + b2.get_acceleration());
        }
    }

    for (auto& body : bodies) {
        body.tick(delta_time);
    }

    this->tick_count++;
}

void Simulation::run()
{
    while (true) {
        usleep(10);
        this->tick(0.000001);
    }
}
