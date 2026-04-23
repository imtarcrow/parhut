#include "body.hpp"

#include <glm/ext/vector_double2.hpp>

Body::Body(double mass, double radius, glm::dvec2 position, glm::dvec2 initial_velocity)
    : mass(mass)
    , radius(radius)
    , position(position)
    , velocity(initial_velocity)
{
}

auto Body::get_mass() const noexcept -> double
{
    return this->mass;
}

auto Body::get_radius() const noexcept -> double
{
    return this->radius;
}

auto Body::get_position() const noexcept -> glm::dvec2
{
    return this->position;
}

auto Body::get_velocity() const noexcept -> glm::dvec2
{
    return this->velocity;
}

auto Body::get_acceleration() const noexcept -> glm::dvec2
{
    return this->acceleration;
}

void Body::set_mass(double mass) noexcept
{
    this->mass = mass;
}

void Body::set_radius(double radius) noexcept
{
    this->radius = radius;
}

void Body::set_position(glm::dvec2 position) noexcept
{
    this->position = position;
}

void Body::set_velocity(glm::dvec2 velocity) noexcept
{
    this->velocity = velocity;
}

void Body::set_acceleration(glm::dvec2 acceleration) noexcept
{
    this->acceleration = acceleration;
}
