#include <string>
#include <iostream>
using namespace std;

void foo(int n){
  return;
}

void foo2(int &n){
  return;
}

void constfoo(const int n){
  return;
}

void constfoo2(const int &n){
  return;
}

int main (){
  foo(5);
  foo(5 + 1);
  //foo2(5);
  //foo2(5 + 4);
  constfoo(5);
  constfoo(5 + 3);
  constfoo2(5);
  constfoo2(5 + 2);
}
