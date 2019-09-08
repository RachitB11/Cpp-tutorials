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
// This is for the std::function
#include <functional>
// Generating random vecs
std::vector<int> GenerateRandVec(int vecSize, int start, int end);

int main()
{

  std::vector<int> randVec = GenerateRandVec(10,1,50);
  for(auto x: randVec) std::cout<<x<<" ";
  std::cout<<"\n";

  // SORT USING LAMBDA FUNC
  // The [] define the lambda function. This is saying sort using the lambda function
  // for comparision
  std::sort(randVec.begin(),randVec.end(), [](int x, int y){return x<y;});

  for(auto x: randVec) std::cout<<x<<" ";
  std::cout<<"\n";

  // COPY IF
  // copy from one vector to another if they meet a condition
  std::vector<int> evenVecVals;
  std::copy_if(randVec.begin(), randVec.end(),
    std::back_inserter(evenVecVals),[](int x){return (x%2)==0;});

  for(auto x: evenVecVals) std::cout<<x<<" ";
  std::cout<<"\n";

  // FOR EACH
  int sum = 0;
  // The & in the lambda function desriptor allows us to capture sum by reference
  std::for_each(randVec.begin(),randVec.end(),[&](int x){sum+=x;});
  std::cout<<"Sum: "<<sum<<"\n";

  // PROBLEM
  int divisor;
  std::vector<int> randVecDivisor;
  std::cout<<"List of values divisible by: ";
  std::cin>>divisor;
  // So add the name of the variable you want to be used in the lambda function
  std::copy_if(randVec.begin(), randVec.end(),
    std::back_inserter(randVecDivisor),[divisor](int x){return (x%divisor)==0;});
  for(auto x: randVecDivisor) std::cout<<x<<" ";
  std::cout<<"\n";

  // Doubling the vector
  std::vector<int> doubleVec;
  std::for_each(randVec.begin(),randVec.end(),[&](int x){doubleVec.push_back(x*2);});
  for(auto x: doubleVec) std::cout<<x<<" ";
  std::cout<<"\n";

  // Use lambda funcs to store in the 3rd
  std::vector<int> vec1 = {1,2,3,4,5};
  std::vector<int> vec2 = {5,6,7,8,9};
  std::vector<int> vec3(5);

  // This transform method takes in the begin and end of the vector1
  // Takes the beginning of vector2 and assumes as many elements as in vector1
  // will be used.
  // Same for vector3 which is the result will have the same size
  // Remember we did not use the vec2 when we were using this method to change
  // from lower to upper case in math_strings.cpp .
  // In that case the third argument was automatically the result.
  transform(vec1.begin(),vec1.end(),vec2.begin(),vec3.begin(),
    [](int x, int y){return x+y;});
  for(auto x: vec3) std::cout<<x<<" ";
  std::cout<<"\n";

  // TERNARY OPERATOR
  // Its like a shorter if else statement
  int age = 43;
  bool canIvote = (age>=18) ? true : false;
  // Just to print out true/false instead of 1/0
  std::cout.setf(std::ios::boolalpha);
  std::cout<<"Can I vote: "<<canIvote<<"\n";


  // USEFUL LINK: https://stackoverflow.com/questions/15853665/c11-lambda-function-how-to-pass-parameter
  // RECURSIVE LAMBDA FUNCTION
  // The LHS is defining a function which will return int and take an (int) as
  // argument and will be called Fib
  // In the RHS we define the Lambda function. Since this is recursive we need to
  // pass the method name in the [] brackets
  std::function<int(int)> Fib =
    [&Fib](int n){return n<2 ? n : Fib(n-1)+Fib(n-2);};

  std::cout<<"Fib 4: "<<Fib(4)<<"\n";

  return 0;
}

std::vector<int> GenerateRandVec(int vecSize, int start, int end)
{
  std::vector<int> resultVec;
  srand(time(NULL));
  int i = 0, randVal = 0;
  while(i < vecSize)
  {
    randVal = start + std::rand() % ((end+1)-start);
    resultVec.push_back(randVal);
    i++;
  }
  return resultVec;
}
