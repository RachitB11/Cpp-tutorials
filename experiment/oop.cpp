// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
#include <math.h>
#include <ctime>

class Animal
{
  // Variables that are only accessible within the class
  private:
    std::string name;
    double height;
    double weight;

    // static variables are those which are shared among all objects of the class
    static int numOfAnimals;

  // Accessible wherever the object is accessible
  // Acessible outside the class
  public:
    // Gets the name but protects the data since the name is private
    std::string GetName(){return name;}
    void SetName(std::string name){ this->name = name;}
    double GetHeight(){return height;}
    void SetHeight(double height){ this->height = height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight){ this->weight = weight;}

    void SetAll(std::string, double, double);

    // Constructor called when the object is created
    Animal(std::string, double, double);
    // COnstructor overloaded
    Animal();

    // Deconstructor called when the object is deleted
    ~Animal();

    // Static methods can only access static fields (static things belong to the class not the object)
    static int GetNumOfAnimals(){return numOfAnimals;}

    // Specifically created to override later
    void ToString();

};

int Animal::numOfAnimals = 0;

void Animal::SetAll(std::string name, double height, double weight)
{
  this->name = name;
  this->height = height;
  this->weight = weight;
  Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight)
{
  this->name = name;
  this->height = height;
  this->weight = weight;
  Animal::numOfAnimals++;
}

Animal::Animal()
{
  this->name = "";
  this->height = 0;
  this->weight = 0;
  Animal::numOfAnimals++;
}

Animal::~Animal()
{
  std::cout<<"Animal "<<this->name<<" destroyed\n";
}

void Animal::ToString()
{
  std::cout<<this->name<<" is "<< this->height << " cms tall and " <<
    this->weight << " kgs in weight\n";
}

// This class inherits the Animal class
class Dog: public Animal
{
  private:
    std::string sound = "Woof";
  public:
    void MakeSound()
    {
      std::cout<< "The dog "<<this->GetName() << " says "<<
      this->sound << "\n";
    }
    Dog(std::string, double, double, std::string);
    // NOTE: The Dog constructor initialized using the Animal constructor
    Dog():Animal(){};
    void ToString();
};

//NOTE: Here we write the dog constructor and initialize it using the Animal constructor
Dog::Dog(std::string name, double height, double weight, std::string sound):
  Animal(name, height, weight)
{
  this->sound = sound;
}

// This method was overriden from the parent class
void Dog::ToString()
{
  // NOTE: IMPORTANT!!!!! This will not work because inherited class cannot access the private
  // variables of the parent class. This would have worked if those variables were protected!!!!!
  // std::cout<<this->name<<" is "<< this->height << " cms tall and " <<
  //   this->weight << " kgs in weight\n";

  // To circumvent the problem of not being able to access the private variables either
  // 1. Convert the private variables to protected in the parent class definition
  // OR
  // 2. Use the get methods from the parent class
  std::cout<<this->GetName()<<" is "<< this->GetHeight() << " cms tall and " <<
    this->GetWeight() << " kgs in weight and says " << this->sound  << "\n";
}


int main()
{
  Animal fred;
  fred.ToString();
  fred.SetWeight(33);
  fred.SetHeight(10);
  fred.SetName("Fred");
  fred.ToString();

  Animal tom("Tom", 36, 15);
  tom.ToString();

  Dog spot("Spot", 38, 16, "Woooof");
  spot.ToString();

  // No need to create the instance of a class when using static methods 
  std::cout << "Number of Animals "<< Animal::GetNumOfAnimals()<<"\n";

  return 0;
}
