#include<iostream>
#include<memory>
#include<vector>
#include<string>

struct object_t;
using obj_ptr = object_t*;
using document_t = std::vector<obj_ptr>;

template<typename T> void draw(const T&);

struct object_t
{
  virtual void draw() = 0;
  virtual ~object_t() {};
};

template<typename U> struct model_t : object_t
{
  std::unique_ptr<U> m_data;
  
  model_t(const U& data)
  : m_data{std::make_unique<U>(data)}
  {}
  
  void draw() override final
  {
    ::draw(*m_data);
  }
  
  ~model_t()
  {}
};

// fully specialize the template function "template<typename T> void draw(const T&)" above
// to handle any type you want.

// for the object_t*
template<> void draw(const obj_ptr& obj)
{
    obj->draw();
}

// for int
template<> void draw(const int& i)
{
  std::cout << " drawing int = " << i << '\n';
}
// for double
template<> void draw(const double& d)
{
  std::cout << " drawing double = " << d << '\n';
}
// for string
template<> void draw(const std::string& s)
{
  std::cout << "drawing string = " << s << '\n';
}

// for the container document_t
template<> void draw(const document_t& doc)
{
  std::cout << "<document>\n";
  for (const auto& elmnt: doc)
    draw(elmnt);
  std::cout << "</document>\n";
}
