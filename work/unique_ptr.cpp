#include <iostream>
#include <memory>
#include <string>

class Base {
    public:
        virtual ~Base() = 0;
};

Base::~Base(){}

class D1 : public Base {
    public:
        ~D1(){std::cout<<"D1 des"<<std::endl;}
        // D1(){throw "D1 Exit";}
};


class D2 {
    public:
        std::unique_ptr<D1> d1_ptr;
        ~D2(){std::cout<<"D2 des"<<std::endl;}
        D2(){d1_ptr.reset(new D1());}
};


int main()
{
  try{
    std::unique_ptr<D2> a;
    // throw "Main exit";
    a.reset(new D2());
  }
  catch (char const* e) {
    std::cout<<"Exception "<< e << std::endl;
  }

  return 0;
}
