#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector <int> v){
  for(int i = 0; i < v.size(); i++){
    cout << v.at(i) << ", ";
  }
  cout << endl;
}

void printIfEven(int i){
  if(i % 2 == 0){ cout << i << ", "; }
}

int main(){ //vector is implemented with an iterator, so it has begin() and end() etc.

  ostream_iterator <int> out{cout, ", "};

  //initialize vector
  vector <int> v;
  for(int i = 0; i < 20; i++){
    v.push_back(i);
  }
  printVec(v);

  cout << "before out" << endl;
  copy(v.begin(), v.end(), out);
  cout << endl;
  cout << "after out" << endl;

  //for_each()
  for_each(v.begin(), v.end(), printIfEven);
  cout << endl;

  //find()
  for_each(find(v.begin(), v.end(), 5), v.end(), printIfEven);
  cout << endl;

  //copy()
  vector <int> w (v.size());
  copy(v.begin(), v.end(), w.begin());
  printVec(w);

  //transform()
  vector <int> z (v.size());
  transform(v.begin(), v.end(), z.begin(),
  [](int i){
     if(i % 2 == 0){ return i; }
      return 0;
    });
  printVec(z);
}
