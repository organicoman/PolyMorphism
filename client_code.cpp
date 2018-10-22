#include "runtime_polymorphism.h"
struct my_class
{};

template<> void draw(const my_class& cls)
{
  std::cout << " drawing my_class \n";
}
struct derived : object_t
{
  void draw() override final
  {
    std::cout << " drawing derived class\n";
  }
  ~derived()
  {}
};

int main()
{
  model_t<int> x{1};
  model_t<double> y{3.14};
  model_t<std::string> z{"hello"};
  model_t<my_class> cls{my_class{}};
  derived Drv;
  
  document_t d;
  d.push_back(&x);
  d.push_back(&y);
  d.push_back(&Drv); // adding a derived class from class object_t
  
  model_t<document_t> doc{d}; // adding the document itself as an object at the time of its previous definition.
  d.push_back(&doc);
  d.push_back(&cls); // adding a custom class that doesn't inherit from clas object_t.
  d.push_back(&z);
  
  draw(d); // draw all the elements of the container.
  
  return 0;
}
