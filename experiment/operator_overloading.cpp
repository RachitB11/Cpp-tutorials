// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
// For transform and reverse
#include <algorithm>
//  For the math stuff
#include <cmath>
// For random nos.
#include <ctime>

class Box
{
public:
  double length, width, breadth;
  std::string boxString;
  Box()
  {
    length = 1, width = 1, breadth = 0;
  }
  Box(double l, double w, double b)
  {
    length =  l, width = w, breadth = b;
  }
  // Other unary ops: --,*,->,&,+,-,*,/,++

  // Basically do return_type operator actual_operator(args_if_required)

  // Since we're returning the reference to the same box
  void operator ++ ()
  {
    length++;
    breadth++;
    width++;
  }

  // Create a c string representation (pointer to an array)
  operator const char*()
  {
    std::ostringstream boxStream;
    boxStream<<"Box: "<<length<<","<<width<<","<<breadth;
    boxString = boxStream.str(); // This is a regular c++ string
    return boxString.c_str(); //Returns a c style string
  }

  Box operator + (const Box& box2)
  {
    Box boxSum;
    boxSum.length = length + box2.length;
    boxSum.width = width + box2.width;
    boxSum.breadth = breadth + box2.breadth;
    return boxSum;
  }

  double operator [] (int x)
  {
    if(x==0) return length;
    else if(x==1) return width;
    else if(x==2) return breadth;
    else return 0;
  }

  bool operator == (const Box& box2)
  {
    return((length==box2.length)&&(width==box2.width)&&(breadth==box2.breadth));
  }

  bool operator < (const Box& box2)
  {
    double thisSize = length + width + breadth;
    double box2Size = box2.length + box2.width + box2.breadth;
    return (thisSize<box2Size);
  }

  void operator = (const Box& boxToCopy)
  {
    length = boxToCopy.length;
    width = boxToCopy.width;
    breadth = boxToCopy.breadth;
  }
};

int main()
{
  Box box(10,10,10);
  ++box;
  std::cout<<box<<"\n";

  Box box2(5,5,5);
  std::cout<<"Box sum "<<box+box2<<"\n";
  std::cout<<"Box length "<<box[0]<<"\n";
  std::cout<<std::boolalpha;
  std::cout<<"Boxes equal "<< (box==box2) <<"\n";
  std::cout<<"Boxes comparison "<< (box<box2) <<"\n";

  box = box2;
  std::cout<<"New box"<< box <<"\n";

  return 0;
}
