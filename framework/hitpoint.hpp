#ifndef HITPOINT_HPP
#define HITPOINT_HPP
#include <string>
#include <glm/vec3.hpp>

struct HitPoint {

    bool intersected = false;
    float t = 0.0f;
    std::string name = "";
    Color color{ 0.0f, 0.0f, 0.0f };
    glm::vec3 intersection_point = { 0.0f, 0.0f, 0.0f };
    glm::vec3 direction = { 0.0f, 0.0f, 0.0f };
};

#endif