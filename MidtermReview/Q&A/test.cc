class Test{
  int *p;
  explicit Test(int i); // good practice to use explicit on SINGLE PARAMETER
  //constructors to negate implicit conversions

  Test &operator=(const Test &other){
    int *tmp = p;
    p = new int{*other.p};
    delete tmp;

    //For safety, delete what p is pointing to first
    delete p;
    p = new int{*other.p};
  } // It is possible for new to fail
  // In the case that new fails, the methods stops executing and
  // p becomes a dangling pointer
};

void test(Test t){}

void foo(){
  test(1); // This works because of implicit conversion
}
