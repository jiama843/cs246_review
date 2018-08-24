#include <iostream>
using namespace std;

class AddText{
  string s;
public:
  AddText(string s): s{s}{}
  string operator()(string s){ return this->s + s; }
  friend ostream &operator<<(ostream &out, AddText &t){
    out << t.s << endl;
    return out;
  }
};

int main(){
  AddText t{"hi,"};
  cout << t("I'm a person") << endl;
  cout << t << endl;
}
