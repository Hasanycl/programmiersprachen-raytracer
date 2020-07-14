#ifndef SHAPE_HPP 
#define SHAPE_HPP
#include"color.hpp"
#include<string>

class Shape {

  public:

      Shape(std::string name , Color color);
      //pure virtual methods
      virtual float area() const = 0;
      virtual float volume() const = 0;
   
  protected:
      
      std::string name_;
      Color color_;


};


#endif