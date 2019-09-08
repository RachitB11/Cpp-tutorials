// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <ctime>

// Private variables cannot be accessed in classes unless you mark a class as friendly

class Customer
{
private:
  friend class GetCustomerData;
  std::string name;

public:
  Customer(std::string name)
  {
    this->name = name;
  }
};

class GetCustomerData
{
public:
  static std::string GetName(Customer& customer)
  {
    return customer.name;
  }
};

int main()
{
  Customer tom("tom");
  GetCustomerData getName;
  // Because we had a friendly class in the private variables you can use the
  // friendly class to access the private variables of that class.
  std::cout<< "Name: "<< getName.GetName(tom)<<"\n";
  return 0;
}
