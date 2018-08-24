#include <iostream>

class Element;

class factory{
public:
  virtual Element createElem() = 0;
}
