#include <iostream>
#include <string>
using namespace std;

class A{
public:
  virtual void foo(){ cout << sizeof(this) << endl; cout << "moshi moshi this is A" << endl; }
};

class B: public A{
public:
  void foo() override{ cout << sizeof(this) << endl; }
};

int main(){
  A *a = new A;
  B *b = new B;
  A *ab = new B;

  a->foo();
  b->foo();
  b->A::foo();
  ab->foo();
}
