// Preprocessor directives
// These things are run before compile
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

#include <iterator>

// Macro directives
#define PI 3.14159

// Macro functions
#define AREA_CIRCLE(radius) (PI*std::pow(radius,2))

// Template functions
// Remember that wherever T is used needs to be the same class
// typename T means its a changable datatype
template<typename T> void Times2(T val)
{
  std::cout<<val<<" * 2 = " << val*2<<"\n";
}

template<typename T> T Add(T val, T val2)
{
  return val + val2;
}

template<typename T> T Max(T val, T val2)
{
  return val<val2 ? val2 : val;
}


// Template classes
template<typename T, typename U>
class Person
{
public:
  T height;
  U weight;
  static int numOfPeople;
  Person(T h, U w)
  {
    height=h,weight=w;
    numOfPeople++;
  }
  void GetData()
  {
    std::cout << "Height: "<<height<<" and Weight: "<<weight<<"\n";
  }
};

// For the static variable the following has to be done
template<typename T, typename U> int Person<T,U>::numOfPeople;

int main()
{
  // Macros
  std::cout<<"Area of circle 5: "<< AREA_CIRCLE(5)<<"\n";
  Times2(5);
  Times2(5.3);

  // Templeate methods
  std::cout<<"5 + 4: "<< Add(5,4) <<"\n";
  std::cout<<"5.4 + 4.6: "<< Add(5.4,4.6) <<"\n";
  std::cout<<"Max(4,8): "<< Max(4,8) <<"\n";
  std::cout<<"Max(A,B): "<< Max('A','B') <<"\n";
  std::cout<<"Max(Cat,Dog): "<< Max("Cat","Dog") <<"\n";

  // Template class
  Person<double, int> mikeTyson(5.83,216);
  mikeTyson.GetData();
  std::cout<<"Number of People: "<<mikeTyson.numOfPeople<<"\n";

  // Iterators
  std::vector<int> num2 = {1,2,3,4};
  std::vector<int>::iterator itr;
  for(itr=num2.begin(); itr<num2.end(); itr++) std::cout<<*itr << "\n";

  std::vector<int>::iterator itr2 = num2.begin();
  advance(itr2,2);
  std::cout<<*itr2<<"\n";

  auto itr3 = next(itr2,1);
  std::cout<<*itr3<<"\n";

  auto itr4 = prev(itr2,1);
  std::cout<<*itr4<<"\n";

  std::vector<int> num3 = {1,4,5,6};
  std::vector<int> num4 = {2,3};
  auto itr5 = num3.begin();
  advance(itr5,1);
  copy(num4.begin(), num4.end(), inserter(num3, itr5));
  for(int &i:num3) std::cout<< i << "\n";
  
  return 0;
}
