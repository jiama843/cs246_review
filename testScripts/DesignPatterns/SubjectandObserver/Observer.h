#include <iostream>
#include <vector>
#include <string>

class Observer{
public:
  virtual void notify() = 0;
  virtual ~Observer();
};
