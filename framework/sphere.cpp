#include "sphere.hpp"
#define _USE_MATH_DEFINES
#include <math.h>



Sphere::Sphere(glm::vec3 center, float radius,std::string name , Color color):

    Shape(name,color),
    center_{center},
    radius_{radius}{}


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