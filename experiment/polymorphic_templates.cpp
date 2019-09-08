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

class Pizza
{
public:
  virtual void MakePizza() = 0;
};

class NYStyleCrust
{
public:
  std::string AddIngredient()
  {
    return "Crust so thin you can see through it\n\n";
  }
};

class DeepDishCrust
{
public:
  std::string AddIngredient()
  {
    return "Super Awesome Chicago Deep Dish\n\n";
  }
};

template<typename T> class LotsOfMeat: public T
{
public:
  std::string AddIngredient()
  {
    return "Lots of Random Meat," + T::AddIngredient();
  }
};

template<typename T> class Vegan: public T
{
public:
  std::string AddIngredient()
  {
    return "Vegan cheese, veggies, " + T::AddIngredient();
  }
};

template <typename T>
class MeatNYStyle: public T, public Pizza
{
public:
  void MakePizza()
  {
    std::cout<<"Meat NY style pizza: "<< T::AddIngredient();
  }
};

template <typename T>
class VeganDeepDish: public T, public Pizza
{
public:
  void MakePizza()
  {
    std::cout<<"Vegan Deep Dish: "<< T::AddIngredient();
  }
};

int main()
{
  std::vector<std::unique_ptr<Pizza>> pizzaOrders;
  // You stacked templates within templates and were able to mix and match toppings  and crust to create new pizzas
  // We create a new unique pointer using the new tag
  // https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
  pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
  pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

  // https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
  // Mainly because a unique pointer cannot transfer ownership
  std::unique_ptr<Pizza> pizza3 = std::unique_ptr<Pizza>(new VeganDeepDish<Vegan<DeepDishCrust>>());
  pizzaOrders.push_back(std::move(pizza3));

  for(auto& pizza:pizzaOrders)pizza->MakePizza();

  return 0;
}
