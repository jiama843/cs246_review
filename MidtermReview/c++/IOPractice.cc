#include <string>
#include <iostream>
using namespace std;

int main () {
  int i;
  while (true) {
    if (cin >> i) {
      cout << i << endl;
    }
    else {
      if (cin.eof()) break;
      else {
        cin.clear(); //comment out and see what happens!
        cin.ignore(); //comment out and see what happens!
      }
    }
  }
}
