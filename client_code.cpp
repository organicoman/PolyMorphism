#include "Runtime_Polymorphism.h"
struct my_class
{};

template<> void draw(const my_class& cls)
{
  std::cout << " drawing my_class \n";
}

int main()
{
  model_t<int> x{1};
  model_t<double> y{3.14};
  model_t<std::string> z{"hello"};
  
  document_t d;
  d.push_back(&x);
  d.push_back(&y);
  
  model_t<document_t> doc{d}; // adding the document itself as an object at the time of its previous definition.
  d.push_back(&doc);
  d.push_back(&z);
  
  draw(d);
  
  return 0;
}
