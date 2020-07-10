#ifndef SHAPE_HPP 
#define SHAPE_HPP

class Shape {

  public:
      //pure virtual methods
      virtual float area() const = 0;
      virtual float volume() const = 0;


};


#endif