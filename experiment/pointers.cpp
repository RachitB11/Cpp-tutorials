// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>

// A global variable is available everywhere (Best to avoid it generally)
// Pointers are used for accessing the heap. The objects are by default added to the stack.
// To access the heap or any other external resources you need pointers.
// Malloc helps allocate memory in the heap
// The memory is divided into main code, stack and heap

// These are creating pointers to data created dynamically in the heap
// int *p; p=(int*)malloc(5*sizeof(int)); in C
// int *p; p=new int[5]; in C++
// Create arrays dynamically in methods since they wont be wiped once it goes out of scope
// This also means that you need to delete the data once you're done with it.

// This is pointing to static data in the stack. This gets deleted automatically once out of stack.
// int a[] = {1,2,3};
// int *p; p=&a;

// Reference
// int a = 10; int &r=a; //References need to initialized on declaration

// Function prototype so that main knows what is to come
double AddNumbers(double num1, double num2);
void AssignAge3(int *pAge);
void DoubleArray(int* arr, int size);
std::vector<int> Range(int start, int end, int step);

int main()
{

  ////////////RANDOM////////////////
  std::vector<int> myVec(10);
  // std::begein points to the first element of the vector. Similar for end
  // std::iota populates the vector from 1->10
  std::iota(std::begin(myVec),std::end(myVec),1);
  for(auto i:myVec)
  {
    if(i%2==0)
    {
      std::cout<<i<<std::endl;
    }
  }

  /////////////////SIMPLE FUNCTIONS///////////////////////
  double num1=2,num2=3;
  std::cout<<"Result of 2+3: "<<AddNumbers(num1,num2)<<std::endl;

  /////////POINTERS///////////////////////////////////
  // It stores the address in memory
  // Pointers store the address which can be accessed using the reference op
  int age = 43;
  int* pAge = NULL;
  pAge = &age; // Reference operator
  // The addresses are Hexadecimal stuff

  std::cout<<"Address of age var: "<< pAge << std::endl;
  std::cout<<"Value age var: "<< *pAge << std::endl; //This is called dereferencing

  int intArray[] = {1,2,3,4};
  int *pIntArray = intArray; //The array name contains thee first address in the array

  // You can go through all the addresses in the arrays using the ++ operator
  std::cout<<"1st: "<<*pIntArray<<" Address: "<<pIntArray++ << std::endl;
  std::cout<<"2nd: "<<*pIntArray<<" Address: "<<pIntArray++ << std::endl;
  std::cout<<"3rd: "<<*pIntArray<<" Address: "<<pIntArray++ << std::endl;
  std::cout<<"4th: "<<*pIntArray<<" Address: "<<pIntArray-- << std::endl;
  std::cout<<"3rd: "<<*pIntArray<<" Address: "<<pIntArray-- << std::endl;
  std::cout<<"2nd: "<<*pIntArray<<" Address: "<<pIntArray << std::endl;

  ///////////////////////POINTERS TO FUNCTIONS/////////////////////////
  AssignAge3(pAge); // Instead of copying the entire structure you access by memory
  std::cout<<"Value age var: "<< *pAge << std::endl; //This is called dereferencing

  DoubleArray(intArray,4);
  for(int i=0; i<4; i++)
  {
    std::cout<<intArray[i]<<std::endl;
  }


  ////////////////// PROBLEMS /////////////////////////////////////
  std::vector<int> vRange = Range(1, 10, 2);
  std::cout<<"Range"<<std::endl;
  for(auto j: vRange)
  {
    std::cout<<j<<std::endl;
  }

  return 0;
}

// FUNCTIONS

// Variables in a function are local to it.
double AddNumbers(double num1, double num2)
{
  return num1 + num2;
}

void AssignAge3(int* pAge)
{
  *pAge=22;
}

void DoubleArray(int* arr, int size)
{
  for(int i=0; i<size; i++)
  {
    arr[i] = arr[i]*2;
  }
}

std::vector<int> Range(int start, int end, int step)
{
  std::vector<int> vResult;
  for(int i=start; i<=end; i+=step)
  {
    vResult.push_back(i);
  }
  return vResult;
}
// END FUNCTIONS
