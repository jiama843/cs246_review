#include <iostream>
#include <string>
using namespace std;

template <typename T>

class Type{
  T t;

public:
  Type(int i): t{i} {}
  virtual ~Type(){} //Destructor is likely unable to handle
                    //the destruction of a type T, so user
                    //must manually deallocate memory
  bool print(){
    cout << this->t;
  }
};

int main(){
  Type <int> t{2};
  t.print();
}
