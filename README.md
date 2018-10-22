# PolyMorphism
Some thaughts following Sean Parent's talk about runtime polymorphism

Sean Parent in his talk about Runtime Polymorphism, he walked throug a technic to simulate runtime polymorphism without the constraints and the cons of the latter.
see this on youTube here: https://www.youtube.com/watch?v=QGcVXgEVMJg

my notes about this technic are the following:
1- the technic adds two layers of indirection, which makes it difficult to maintain and follow
2- it eliminates the possibility of inheriting from the class object_t in case we want to derive a class that implenents the virtual interface of our model (class concept_t).

Goal of my method:
    given a class object_t, that has a virtual interface to be implemented in all its derived classes. 
    1-is it possible to create a container object: class document_t, that can be agnostic to the type of elements it contain while at the same time uses a common interface on them all?
    2-is it possible to keep the abilty for our clients to derive a class from our "object_t" class, and implement the virtual interface in his own way?
    3-is it possible if we import a third party library that doesn't implement the virtual interface of the class object_t, yet can be expanded to implement it without knowing its source code, and thus could be included into our container class document_t?

roughly this is the kind of classes I'm talking about:
class object_t
{
  virtual draw()=0;
  virtual ~object_t();
};
using document_t = std::vector<object_t>;
void draw(const document_t& doc)
{
  for(const auto& elmnt: doc)
    draw(elmnt);
}
