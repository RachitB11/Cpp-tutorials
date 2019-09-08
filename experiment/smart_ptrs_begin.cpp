// Preprocessor directives
// These things are run before compile
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
#include <stdio.h>
#include <memory>

// Smart pointers have the power of pointers while dealing with the reallocation
// of memory
int main()
{
  // C way of doing it
  int amtToStore;
  std::cout << "How many numbers do you want to store: ";
  std::cin >> amtToStore;
  int* pNums;
  pNums = (int*) malloc(amtToStore*sizeof(int));
  if(pNums != NULL)
  {
    int i = 0;
    while(i<amtToStore)
    {
      std::cout << "Enter a number: ";
      std::cin >> pNums[i];
      i++;
    }
  }
  std::cout<<"You entered these numbers\n";
  for(int i = 0; i<amtToStore; i++) std::cout<<pNums[i]<<"\n";
  // Need a delete here to avoid memory overflow
  delete pNums;

  // C++ way of doing it
  int amtToStore2;
  std::cout << "How many numbers do you want to store: ";
  std::cin >> amtToStore2;
  std::unique_ptr<int[]> pNums2(new int[amtToStore2]);
  // A unique ptr can only have one owner so the line below is illegal
  // std::unique_ptr<int[]> pNums3 = pNums2;
  // We need to use the shared pointers for doing this sort of stuff

  if(pNums2 != NULL)
  {
    int i = 0;
    while(i<amtToStore2)
    {
      std::cout << "Enter a number: ";
      std::cin >> pNums2[i];
      i++;
    }
  }
  std::cout<<"You entered these numbers\n";
  for(int i = 0; i<amtToStore2; i++) std::cout<<pNums2[i]<<"\n";
  // NO CLEANUP REQUIRED. A smart pointer was used. It can handle that.


  return 0;
}
