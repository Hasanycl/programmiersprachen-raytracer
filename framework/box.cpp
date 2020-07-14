#include "box.hpp"


Box::Box(glm::vec3 min, glm::vec3 max,std::string name , Color color):

    Shape(name,color),
    min_{min},
    max_{max}{}

float Box::area() const {

    float l = max_.x - min_.x; //length
    float h = max_.y - min_.y; //height
    float w = max_.z - min_.z; //width

    return (2*l*w) + (2*l*h) + (2*w*h);
}

float Box::volume() const {
   
    float l = max_.x - min_.x;
    float h = max_.y - min_.y;
    float w = max_.z - min_.z;

    return l*h*w;
}


std::ostream& Box::print(std::ostream& os) const {

    Shape::print(os);
    os << "Min x: "<< min_.x << ", " << "Min y: "<<min_.y << ", " << "Min z: "<<min_.z << std::endl;
    os << "Max x: "<< max_.x << ", " <<"Max y: " <<max_.y << ", " <<"Max z: "<<max_.z << std::endl;
    os << "Area : "  <<  this->area() << std::endl;
    os << "Volume : "<< this->volume() << std::endl;
    return os;
}