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

// Abstract class
// This is the ideal way you should be designing your code


// NOTE: The purpose of the abstract class is to be a base class that is inherited.
// Here shape is that abstract class that is going to be inherited to make any shape.
//  It just needs to have purely virtual functions that need to be overridden by each
// inherited class
class Shape
{
public:
  // NOTE:This needs to be overriden in  each class. Its virtual.
  // Being virtual is the reason the polymorphism works
  virtual double Area() = 0;
};


class Circle : public Shape
{
protected:
  double width;
public:
  Circle(double w){
    width = w;
  }
  // NOTE: Add the override tag just so that the compiler checks that the overrided method
  // exists in the base class
  double Area() override
  {
    return 3.14159*std::pow((width/2),2);
  }
};

class Rectangle : public Shape
{
protected:
  double width;
  double height;
public:
  Rectangle(double h, double w){
    height = h;
    width = w;
  }
  // NOTE: Add the override tag just so that the compiler checks that the overrided method
  // exists in the base class
  // NOTE: Add the final to say that any subclass of Rectangle should not be able to
  // override this class
  double Area() override final
  {
    return height*width;
  }
};

// This will throw an error because we were trying to override the area class
// which is alread marked as final
// class Square : public Rectangle
// {
// public:
//   Square(double h, double w):
//   Rectangle(h,w)
//   {
//
//   }
//   double Area() override
//   {
//     return height*2;
//   }
// };

// NOTE: So what polymorphism means is that even though the method is defined with the
// parent class as the argument it knows to use the overriden method when the child
// class is passed.
void ShowArea(Shape& shape)
{
  std::cout<<"Area : "<<shape.Area()<<"\n";
}

int main()
{
  Rectangle rectangle(10,5);
  Circle circle(10);
  ShowArea(rectangle);
  ShowArea(circle);
  return 0;
}
