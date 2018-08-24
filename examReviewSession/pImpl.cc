//test.h
struct Impl;

class MyClass{
  std::unique_ptr<Impl> pImpl;
public:
  MyClass();
  void foo();
};


//test.cc
struct Impl{
  int a;
  vector <int> c;
};

Myclass::Myclass(): pImpl{make_unique<Impl>(0, vector<int>{})}{}
