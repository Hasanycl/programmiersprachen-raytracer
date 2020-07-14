#include "sphere.hpp"
#define _USE_MATH_DEFINES
#include <cmath>



Sphere::Sphere(glm::vec3 center, float radius):

    center_{center},
    radius_{radius}{}


float Sphere::area() const {

    return 4 * M_PI * std::pow(radius_,2);

}

float Sphere::volume() const {

    return (4.0f / 3.0f)* M_PI * std::pow(radius_, 3);
}