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

int main()
{
  ////////////// STRINGS/////////////////

  // Character arrays which are basically strings in C
  char cString[] = {'A',' ','S','t','r','i','n','g','\0'};
  std::cout<<"Array Size: "<<sizeof(cString)/sizeof(*cString)<<"\n";

  // String vector
  std::vector<std::string> strVec(10);
  std::string str("I'm a string");
  strVec[0] = str;

  // String ops
  std::cout<<str.at(2)<<"\n";
  std::cout<<str.front()<<"\n";
  std::cout<<str.back()<<"\n";
  std::cout<<str.length()<<"\n";

  // Copy string
  std::string str2(str);
  strVec[1] = str2;

  // Copy from first space to the end
  std::string str3(str,4);
  strVec[2] = str3;

  std::string str4(5,'x');
  strVec[3] = str4;

  strVec[4] = str.append(" and your not"); // Or us the +=
  str+=" and your not";

  str.append(str, 34, 37);
  strVec[5] = str;

  // Erase from 13 to end
  str.erase(13,str.length()-1);
  strVec[6] = str;

  // Substring (start at 6 and length 6)
  std::cout<<"Substr: "<<str.substr(6,6)<<"\n";

  // Reverse a string
  reverse(str.begin(),str.end());
  std::cout << "Reverse: "<< str << "\n";

  // Change the case of the string
  transform(str2.begin(),str2.end(),str2.begin(),::toupper);
  std::cout << "Upper case: "<< str2 << "\n";

  // a-z: 97-122
  // A-Z: 65-90
  char aChar = 'Z';
  int aInt = aChar;
  std::cout << "A code: " << (int)'a' << "\n";

  // Convert int to string
  std::string strNum = std::to_string(1+2);
  std::cout << "to string: " << strNum << "\n";

  // Find a subsctring in there
  if(str.find("string") != std::string::npos)
  {
    std::cout<<"1st index "<<str.find("string")<<"\n";
  }

  for(auto y: strVec)
    std::cout<<y<<"\n";

///////////////////////MATH//////////////////////
std::cout << "abs(-10) = " << std::abs(-10) << "\n";

 std::cout << "max(5,4) = " << std::max(5,4) << "\n";

 std::cout << "min(5,4) = " << std::min(5,4) << "\n";

 std::cout << "fmax(5.3,4.3) = " << std::fmax(5.3,4.3) << "\n";

 std::cout << "fmin(5.3,4.3) = " << std::fmin(5.3,4.3) << "\n";

 // e ^ x
 std::cout << "exp(1) = " << std::exp(1) << "\n";

 // 2 ^ x
 std::cout << "exp2(1) = " << std::exp2(1) << "\n";

 // e * e * e ~= 20 so log(20.079) ~= 3
 std::cout << "log(20.079) = " << std::log(20.079) << "\n";

 // 10 * 10 * 10 = 1000, so log10(1000) = 3
 std::cout << "log10(1000) = " << std::log10(1000)
         << "\n";

 // 2 * 2 * 2 = 8
 std::cout << "log2(8) = " << std::log2(8)
         << "\n";

 // 2 ^ 3
 std::cout << "pow(2,3) = " << std::pow(2,3)
         << "\n";

 // Returns what times itself equals the provided value
 std::cout << "sqrt(100) = " << std::sqrt(100)
         << "\n";

 // What cubed equals the provided
 std::cout << "cbrt(1000) = " << std::cbrt(1000)
         << "\n";

 // Hypotenuse : SQRT(A^2 + B^2)
 std::cout << "hypot(2,3) = " << std::hypot(2,3)
         << "\n";

 std::cout << "ceil(10.45) = " << std::ceil(10.45)
         << "\n";

 std::cout << "floor(10.45) = " << std::floor(10.45)
         << "\n";

 std::cout << "round(10.45) = " << std::round(10.45)
         << "\n";

 // Also sin, cos, tan, asin, acos, atan, atan2,
 // sinh, cosh, tanh, asinh, acosh, atanh

  return 0;
}
