#include "sphere.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


Sphere::Sphere(glm::vec3 center, float radius,std::string name , Color color):

    Shape(name,color),
    center_{center},
    radius_{radius}{

    std::cout << "Sphere constructor called"<< "\n";
}



Sphere::~Sphere() {
    std::cout << "Sphere destructor called" << "\n";
}

float Sphere::area() const {

    return 4 * M_PI * std::pow(radius_,2);

}

float Sphere::volume() const {

    return (4.0f / 3.0f)* M_PI * std::pow(radius_, 3);
}


std::ostream& Sphere::print(std::ostream& os) const {

    Shape::print(os);
    os << "Center : "<<"x: " << center_.x << ", " << "y: "<< center_.y << ", "<<"z: " << center_.z << std::endl;
    os << "Radius : " << radius_ << std::endl;
    os << "Area : " << this->area() << std::endl;
    os << "Volume : " << this->volume() << std::endl;
    return os;
}



HitPoint Sphere::intersect(Ray const& r) const {

    float t = 0.0f;
    auto ray_direction = glm::normalize(r.direction); //normalized direction
    auto result = glm::intersectRaySphere(r.origin , ray_direction , center_ , std::pow(radius_, 2) , t);
    return HitPoint{ result , t , name_ , color_ , r.origin + (t * ray_direction) , ray_direction };
}