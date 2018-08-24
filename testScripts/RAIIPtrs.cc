#include <iostream>
#include <string>
#include <memory>
using namespace std;

class realObject{
  int id;
  string s;
public:
  realObject(int id, string s): id{id}, s{s}{}
  int getId(){
    return id;
  }
  string getS(){
    return s;
  }
};

class Obj{
public:
  int id;
  string *p;
};

class uniqueObj{
public:
  unique_ptr<Obj> unique_obj = make_unique<Obj>();
  virtual void print(){
    cout << "unique_obj id: " << unique_obj->id << endl;
  }
};

class sharedObj{
public:
  shared_ptr<Obj> shared_obj = make_shared<Obj>();
  virtual void print(){
    cout << "shared_obj id: " << shared_obj->id << endl;
  }
};

int main(){
  uniqueObj u;
  //unique_ptr<Obj> cannotCopy = u.unique_obj; //Cannot copy unique_ptrs

  sharedObj s;
  //shared_ptr<Obj> canMoveShared = s.shared_obj;

  u.print();
  s.print();

  unique_ptr<Obj> canMoveUnique = std::move(u.unique_obj); //You can move unique_ptrs
  cout << canMoveUnique->id << endl;

  unique_ptr<realObject> realPtr = make_unique<realObject>(1, "Hello");
  cout << realPtr->getS() << endl;
}
