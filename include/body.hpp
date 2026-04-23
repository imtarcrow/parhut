#include <glm/ext/vector_double2.hpp>

class Body
{

private:
    double mass = 1;
    double radius = 1;

    glm::dvec2 position = {0.0, 0.0};
    glm::dvec2 velocity = {0.0, 0.0};
    glm::dvec2 acceleration = {0.0, 0.0};

public:
    explicit Body(double mass = 1, double radius = 1, glm::dvec2 position = {0.0, 0.0}, glm::dvec2 initial_velocity = {0.0, 0.0});

    [[nodiscard]] auto get_mass() const noexcept -> double;
    [[nodiscard]] auto get_radius() const noexcept -> double;
    [[nodiscard]] auto get_position() const noexcept -> glm::dvec2;
    [[nodiscard]] auto get_velocity() const noexcept -> glm::dvec2;
    [[nodiscard]] auto get_acceleration() const noexcept -> glm::dvec2;

    void set_mass(double mass) noexcept;
    void set_radius(double radius) noexcept;
    void set_position(glm::dvec2 position) noexcept;
    void set_velocity(glm::dvec2 velocity) noexcept;
    void set_acceleration(glm::dvec2 acceleration) noexcept;
};
