#include <iostream>
#include <string>
using namespace std;

template <typename T, typename iter>
class AbsIterator{
public:
  virtual T &operator*() = 0;
  virtual iter operator++() = 0;
  bool operator!=(const AbsIterator &other) = 0;
  virtual ~AbsIterator(){}
};

class Node{
  int data;
  Node *next;
public:

  class Iterator: public AbsIterator{
    Node *curr;
  public:
    explicit Iterator(Node &other): curr{other}{}
    ~Iterator(){ delete curr; }

    int &operator*() const override{
      return curr->data;
    }

    Iterator operator++() override{
      curr = curr->next;
      return *this;
    }

    bool operator!=(const Iterator &other) const override{
      return curr != other.curr;
    }

    friend class Node;
  };

  Iterator begin(){
    return Iterator{this};
  }

  Iterator end(){
    return Iterator{nullptr};
  }

  void print(){
    for(auto n: this){
      cout << data << ", ";
    }
    cout << endl;
  }
};
