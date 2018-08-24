#include <iostream>
#include <string>
using namespace std;

void foo(int a, int b){
  cout << a << b << endl;
}

void foo2(int a, int b = 0){
  cout << a << b << endl;
}

void foo3(string s = "hi", int a = 0, int b = 0){
  cout << a << b << endl;
}

//invalid
/*void foo4(int a = 0, int b){
  cout << a << b << endl;
}*/

int main(){
  foo(1, 2);
  //foo(2); //invalid

  foo2(1);
  //foo2(,1); //invalid

  foo3("hi");
  foo3(0, 9); //invalid - compiles but segmentation fault
}
