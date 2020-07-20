#ifndef SPHERE_HPP 
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include"ray.hpp"
#include"hitpoint.hpp"

class Sphere : public Shape {

  public:

    Sphere(glm::vec3 center, float radius, std::string name, Color color);
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
    ~Sphere();
    HitPoint intersect(Ray const& r) const;

  private:

    glm::vec3 center_;
    float radius_;
};

#endif
