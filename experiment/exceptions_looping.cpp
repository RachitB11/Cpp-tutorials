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

// Function prototype so that main knows what is to come
std::vector<int> Range(int start, int end, int step);
void DrawTree(int height);
void DrawTreeLine(int position, int height, int base);

int main()
{
  int i=1;


//////////////// SIMPLE LOOPING/////////
  while(i<=20)
  {
    if(i%2==0)
    {
      i+=1;
      continue;
    }

    if(i==15) break;

    std::cout<<i<<"\n";
    i+=1;
  }

//////////// TREE PROBLEM //////////////
  int iTreeHeight;
  std::cout<<"How tall is the tree:";
  std::cin>>iTreeHeight;
  DrawTree(iTreeHeight);

////////////// EXCEPTIONS////////////////
  // Handling errors on behalf of the user
  double dNum1,dNum2;
  std::cout<<"Enter num1: ";
  std::cin>>dNum1;
  std::cout<<"Enter num2: ";
  std::cin>>dNum2;

  try
  {
    if(dNum2==0)
    {
      throw "Division by 0 is not possible";
    }
    else
    {
      printf("Result: %.1f\n",dNum1/dNum2);
    }
  }

  catch(const char* exp)
  {
    std::cout << "Error : " << exp << "\n";
  }

  ////////////// EXCEPTIONS 2////////////////

    // Everytime you try a catch (atleast one) is required below it
    // NOTE: In a try block if an exception occurs everything in the try block is ignored
    try
    {
      std::cout<<"Throwing exception"<<std::endl;
      throw std::runtime_error("Error occured");
      std::cout<<"Can you print me??"<<std::endl;
    }

    // std:exception from which all exceptions arise
    catch(std::exception &exp)
    {
      std::cout << "Handled exception : " << exp.what() << "\n";
    }

    // Catch all (Never try to do this bad practice)
    // catch(...)
    // {
    //   std::cout << "Default exception"< < "\n";
    // }

  ////////////////// DO-WHILE ////////////////////////////
  // A do while loop will execute atleast once

  // Create a seed and give it something that always changes
  srand(time(NULL));
  int secretNum = std::rand()%11;
  int guess = 0;

  do
  {
    std::cout << "Guess the number between 0-10  : ";
    std::cin >> guess;
    if(guess>secretNum) std::cout<<"Too big"<<std::endl;
    if(guess<secretNum) std::cout<<"Too small"<<std::endl;
  }
  while(secretNum!=guess);

  std::cout<<"You guessed it"<<std::endl;

  return 0;
}

// FUNCTIONS
std::vector<int> Range(int start, int end, int step)
{
  std::vector<int> vResult;
  for(int i=start; i<=end; i+=step)
  {
    vResult.push_back(i);
  }
  return vResult;
}

void DrawTree(int height)
{
  int iBase = 2*(height-1)+1;
  for(auto i: Range(1,height+1,1))
  {
    if(i==height+1)
    {
      DrawTreeLine(1, height, iBase);
    }
    else
    {
      DrawTreeLine(i, height, iBase);
    }
  }
}

void DrawTreeLine(int position, int height, int base)
{
  for(auto i:Range(1,base,1))
  {
    if(i>(height-position)&&i<(height+position))
    {
      std::cout<<"#";
    }
    else
    {
      std::cout<<" ";
    }
  }
  std::cout<<std::endl;
}
// END FUNCTIONS
