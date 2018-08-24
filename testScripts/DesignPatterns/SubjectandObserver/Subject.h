#include <iostream>
#include <vector>
#include <string>

class Subject{
  std::vector<Observer *> obs;
public:
  virtual void attach(Observer *ob);
  virtual void detach(Observer *ob);
  virtual void notifyObservers();
  virtual ~Subject() = 0;
};
