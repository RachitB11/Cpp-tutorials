// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

// This is a global variable thats going to be used throughout
// hungarian notation : g for global i for int and then name
int g_iRandNum = 0;

// Const variable cannot be changed once set
const double PI = 3.14159;

int main()
{

  // boolean
  bool bMarried = true;
  // char
  char chMyGrade = 'A';
  // unsigned int : Never negative val (0->2^16)
  unsigned short int uAge = 43;
  // short int (Min -32k something)
  short int siWeight = 180;

  int nDays = 7;
  long lBigNum= 11000000;
  float fPi = 3.15159;
  double dBigFloat = 1.1111111111111111;
  long double ldPi= 3.141519;
  auto whatWillBe = true;

  // Min max limits of data structs
  std::cout<<"Min bool "<< std::numeric_limits<bool>::min()<<std::endl;
  std::cout<<"Max bool "<< std::numeric_limits<bool>::max()<<std::endl;

  std::cout<<"Min double "<< std::numeric_limits<double>::min()<<std::endl;
  std::cout<<"Max double "<< std::numeric_limits<double>::max()<<std::endl;


  // Size of data structs
  std::cout<<"int size "<<sizeof(int)<<std::endl;

  // Double is more precise than float
  // %f float
  // %c char
  // %d int
  // %5d 5 spaces
  // %.3f 3 decimal places float
  // %s string

  std::cout<<std::endl;

  std::cout<< "Example 1"<<std::endl;
  std::string sQuestion1("Enter number 1: ");
  std::string sNum1,sNum2;
  std::cout << sQuestion1;
  getline(std::cin, sNum1);
  std::cout<< "Enter number 2: ";
  getline(std::cin, sNum2);
  int nNum1 = std::stoi(sNum1);
  int nNum2 = std::stoi(sNum2);
  printf("Result of sum: %d\n",(nNum1+nNum2));

  std::cout<<std::endl;

  std::cout<< "Example 2"<<std::endl;
  const double dMileToKm = 1.60934;
  std::string sQuestion2("Enter miles: ");
  std::string sMile;
  std::cout << sQuestion2;
  getline(std::cin, sMile);
  double dMile = std::stod(sMile);
  printf("KiloMeters: %.4f\n",(dMile*dMileToKm));

  std::cout<<std::endl;

  return 0;
}
