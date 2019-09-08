#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>

template<typename T>
class Base
{
public:

  Base(T val);
  void addMapData(T number, std::string name);

  T getVal() const;
  std::string getMapData(T number) const;

private:
  T val_;
  std::unordered_map<T,std::string> names_;
};

template<typename T> Base<T>::Base(T val)
{
  val_  = val;
}

template<typename T> T Base<T>::getVal() const
{
  return val_;
}

template<typename T> void Base<T>::addMapData(T number, std::string name)
{
  names_[number] = name;
}


template<typename T> std::string Base<T>::getMapData(T number) const
{
  return names_.at(number);
}


int main()
{
  Base<int> *p3 = new Base<int>(50);
  std::cout<<p3->getVal()<<std::endl;

  /*This will copy the naked pointer to the unique pointer and once it goes out of scope delete the allocated memory
  This will cause a segmentation fault when trying to make the shared pointer below*/
  // {
  //   std::unique_ptr<Base<int>> p1(p3);
  //   std::unique_ptr<Base<int>> p5(std::move(p1));
  // }
  //
  // std::cout<<p3->getVal()<<std::endl;

  // Making a new unique pointer (to an array) that goes out of scope
  {
    std::unique_ptr<int> p1(new int[50]);
    std::unique_ptr<int> p5(std::move(p1));
  }

  std::shared_ptr<Base<int>>  p2(p3);
  std::cout<<p2.use_count()<<std::endl; // 1 ref count
  {
    std::shared_ptr<Base<int>> p4(p2); // 2 ref count
    std::cout<<p2.use_count()<<std::endl;
  }
  std::cout<<p2.use_count()<<std::endl; // 1 ref count

  std::cout<<p2->getVal()<<std::endl;

  p2->addMapData(1,"Rachit");
  p2->addMapData(2,"Ria");
  p2->addMapData(3,"Reena");
  p2->addMapData(4,"Raj");

  std::cout<<p2->getMapData(4)<<std::endl;
  // std::cout<<p2->names_.at(4)<<std::endl; //ERROR: Trying to access private

  return 0;
}
