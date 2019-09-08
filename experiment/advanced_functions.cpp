// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
// This is for the random number generator
#include <ctime>
// For transform and reverse
#include <algorithm>
//  For the math stuff
#include <cmath>

// For std::function
#include <functional>

double MultBy2(double num)
{
  return num*2;
}

// Takes in the function as the argument with syntax return_type(arg)
double DoMath(std::function<double(double)> func,double number)
{
  return func(number);
}

double MultBy3(double num)
{
  return num*3;
}

bool IsItOdd(int num)
{
  return num%2==1;
}

// Takes in the function as the argument with syntax return_type(arg)
std::vector<int> ChangeList(std::vector<int> listOfNums, std::function<bool(int)> func)
{
  std::vector<int> resultVec;
  for(auto x: listOfNums)
  {
    if(func(x))
    {
      resultVec.push_back(x);
    }
  }
  return resultVec;
}

int main()
{
  auto times2 = MultBy2;
  std::cout << "5 * 2  = "<< times2(5)<<"\n";
  std::cout << "6 * 2  = "<< DoMath(times2, 6)<<"\n";

  std::vector<std::function<double(double)>> funcs(2);
  funcs[0] = MultBy2;
  funcs[1] = MultBy3;
  std::cout << "2 * 10 = " <<funcs[0](10)<<"\n";
  std::cout << "3 * 10 = " <<funcs[1](10)<<"\n";

  std::vector<int> listOfNums = {1,2,3,4};
  std::vector<int> oddList = ChangeList(listOfNums, IsItOdd);

  std::cout<<"List of Odds\n";
  for(auto i: oddList)
  {
    std::cout<<i<<"\n";
  }

  return 0;
}
