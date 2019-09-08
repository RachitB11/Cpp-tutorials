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

// NOTE: the find, replace, append, erase, substr options are pretty useful for string manipulation qns'
// NOTE: the getline(ss,indivstring,separator) is also pretty cool to get words from the string

void SolveForX(std::string equation);
std::vector<std::string> StringToVector(std::string theString, char separator);

// Doing the dumbest solution first more complex one later
bool IsPrime(int num);
std::vector<int> GetPrimes(int maxPrime);

// Generating random vecs
std::vector<int> GenerateRandVec(int vecSize, int start, int end);

int main()
{
  // PROBLEM 1
  // std::cout<<"Enter an equation to solve ";
  // std::string equation = "";
  // getline(std::cin,equation);
  // SolveForX(equation);

  // PROBLEM 2
  int num;
  std::cout << "Number to check: ";
  std::cin>>num;
  std::cout << "Is "<< num << " Prime "<<IsPrime(num)<<"\n";
  std::cout << "Generate Primes upto ";
  int maxPrime;
  std::cin >> maxPrime;
  std::vector<int> primeList = GetPrimes(maxPrime);
  for(auto x: primeList) std::cout << x << "\n";

  // PROBLEM 3
  std::vector<int> vecVals = GenerateRandVec(10,5,50);
  std::cout<<"Random vector"<<"\n";
  for(auto x: vecVals) std::cout << x << "\n";

  return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator)
{
  std::vector<std::string> vecsWords;
  std::stringstream ss(theString);
  std::string sIndivStr;

  // String stream and getline combo helps us get words on the basis of the separator
  while(getline(ss, sIndivStr, separator))
  {
    vecsWords.push_back(sIndivStr);
  }

  return vecsWords;
}

// Format X + 4 = 9
void SolveForX(std::string equation)
{
  std::vector<std::string> vecEquation = StringToVector(equation,' ');
  int num1 = std::stoi(vecEquation[2]);
  int num2 = std::stoi(vecEquation[4]);
  int xVal = num2-num1;
  std::cout<<"x = "<< xVal << "\n";
}

bool IsPrime(int num)
{
  if(1<=num && num<=3)
  {
    return true;
  }
  for(int i=2; i<=num/2 ; i++)
  {
    if(num%i==0)
    {
      return false;
    }
  }
  return true;
}

std::vector<int> GetPrimes(int maxPrime)
{
  std::vector<int> v;
  for(int i=1;i<=maxPrime;i++)
  {
    if(IsPrime(i))
    {
      v.push_back(i);
    }
  }
  return v;
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
