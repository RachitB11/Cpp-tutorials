// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
#include <cmath>
#include <ctime>

// Polymorphism

class Shape
{
// This basically means that the inheirted classes will be able to access these variables.
protected:
  double height;
  double width;
public:
  Shape(double length)
  {
    height = length;
    width = length;
  }
  Shape(double h, double w)
  {
    height = h;
    width = w;
  }
  // NOTE:This needs to be overriden in  each class. Its virtual.
  // Being virtual is the reason the polymorphism works
  virtual double Area()
  {
    return height*width;
  }
};


class Circle : public Shape
{
public:
  Circle(double w):Shape(w){

  }
  double Area()
  {
    return 3.14159*std::pow((width/2),2);
  }
};

// NOTE: So what polymorphism means is that even though the method is defined with the
// parent class as the argument it knows to use the overriden method when the child
// class is passed.
void ShowArea(Shape& shape)
{
  std::cout<<"Area : "<<shape.Area()<<"\n";
}

int main()
{
  Shape rectangle(10,5);
  Circle circle(10);
  ShowArea(rectangle);
  ShowArea(circle);

  return 0;
}
