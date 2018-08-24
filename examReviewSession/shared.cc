struct Test{
  shared_ptr<Test> other;
};

struct Node{
  unique_ptr<Node> next;
  Node *previous;
};

int main(){
  shared_ptr<Test> t1 = make_shared<Test>(); //t1.count = 1
  shared_ptr<Test> t2 = make_shared<Test>(); //t2.count = 1

  t1.other = t2; //t1.count = 2
  t2.other = t1; //t2.count = 2
}
//t1.count = 1
//t2.count = 1
