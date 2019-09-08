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

// Generating random vecs
std::vector<int> GenerateRandVec(int vecSize, int start, int end);
void BubbleSort(std::vector<int>& theVec);
int Factorial(int number);
void PrintHorzVector(std::vector<int>& theVec);
int Fibonacci(int number);

// Overloaded functions
double Area(double radius);
double Area(double height, double width);

int main()
{

  // Bubble sort
  std::vector<int> randVec = GenerateRandVec(10,1,50);
  BubbleSort(randVec);
  for(auto x: randVec) std::cout<<x<<"\n";

  // Recursion for factorials
  // A recursive function is when it calls itself
  // Rules for Recursion
  // 1. Have a base case
  // 2. Have a ending criteria
  // 3. Define the recursive function
  std::cout << "Factorial 5 = "<<Factorial(5)<<"\n";

  // Pretty print vector
  std::vector<int> theVec = {10,8,2,5,9,11,6,14};
  PrintHorzVector(theVec);

  // Fibonacci nos
  int index;
  std::cout << "Get the Fibonacci Index: ";
  std::cin >> index;
  printf("Fib(%d) = %d\n", index, Fibonacci(index));

  // Overloaded functions
  std::cout<<"Area circle (c) or Rectangle (r): ";
  char areaType;
  std::cin >> areaType;

  switch(areaType)
  {
    case 'c':
      std::cout << "Enter radius: ";
      double radius;
      std::cin>>radius;
      std::cout<<"Area: "<<Area(radius)<<"\n";
      break;
    case 'r':
      std::cout << "Enter height: ";
      double height;
      std::cin>>height;
      std::cout << "Enter width: ";
      double width;
      std::cin>>width;
      std::cout<<"Area: "<<Area(height, width)<<"\n";
      break;
    default: std::cout<<"ERROR: Please enter c or r \n";
  }

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

// Passed the vector by reference
// BUbble sort in each round the top number comes to the top
void BubbleSort(std::vector<int>& theVec)
{
  int i = theVec.size()-1;

  while(i>=1)
  {
    int j=0;
    while(j<i)
    {
      printf("\n Is %d > %d\n", theVec[j], theVec[j+1]);

      if(theVec[j]>=theVec[j+1])
      {
        int temp = theVec[j];
        theVec[j] = theVec[j+1];
        theVec[j+1] = temp;
      }
      else
      {
        std::cout<<"Don't switch\n";
      }
      j++;
      for(auto k:theVec) std::cout<<k<<",";
    }
    std::cout<<"\nEnd of round\n";
    i-=1;
  }
}

int Factorial(int number)
{
  if(number==1)
  {
    return 1;
  }
  else
  {
    return number*Factorial(number-1);
  }
}

void PrintHorzVector(std::vector<int>& theVec)
{
  int dashes = theVec.size()*5;
  for(int n=0;n<dashes;n++) std::cout<<"-";
  std::cout<<"\n";
  for(int n=0;n<theVec.size();n++) printf("| %2d ",n);
  std::cout<<"|\n";
  for(int n=0;n<dashes;n++) std::cout<<"-";
  std::cout<<"\n";
  for(int n=0;n<theVec.size();n++) printf("| %2d ",theVec[n]);
  std::cout<<"|\n";
  for(int n=0;n<dashes;n++) std::cout<<"-";
  std::cout<<"\n";
}

int Fibonacci(int number)
{
  if(number == 0) return 0;
  if(number == 1) return 1;
  else return Fibonacci(number-1) + Fibonacci(number-2);
}

double Area(double radius)
{
  return 3.1415* std::pow(radius,2);
}


double Area(double height, double width)
{
  return height * width;
}
