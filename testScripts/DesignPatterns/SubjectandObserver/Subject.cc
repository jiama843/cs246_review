#include "Subject.h"
using namespace std;

void Subject::attach(Observer *ob){
  obs.push_back(ob);
}

void Subject::detach(Observer *ob){
  for(auto it = obs.begin(); it != obs.end(); ++it){
    if(*it == ob){
      obs.erase(it);
      break;
    }
  }
}

void Subject::notifyObservers(){
  for(auto o: obs){
    o->notify();
  }
}

Subject::~Subject(){}
