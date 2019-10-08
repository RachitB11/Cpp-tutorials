#include <limits>
#include <iostream>

int main()
{
  float a = std::numeric_limits<float>::quiet_NaN();
  float b = std::numeric_limits<float>::quiet_NaN();

  std::cout<<a-b<<std::endl;
  std::cout<<(a>b)<<std::endl;
  std::cout<<(a<1)<<std::endl;
  std::cout<<(a>1)<<std::endl;
  std::cout<<(a!=1)<<std::endl;
  std::cout<<(a!=b)<<std::endl;
  std::cout<<(a-1)<<std::endl;
}
