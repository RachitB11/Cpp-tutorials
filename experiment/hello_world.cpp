// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Allows to use the methods in the namespace
// using namespace std;


// argc and argv are optional data that store the number of arguments passed to
// the program and the strings passed from the terminal
int main(int argc, char**argv)
{
  std::cout<<"Hello World\n";

  if (argc!=1)
  {
    std::cout<<"You entered "<<argc<<" arguments\n";
    for(int i=0; i<argc; i++)
    {
      std::cout<<argv[i]<<std::endl;
    }
  }

  return 0;
}
