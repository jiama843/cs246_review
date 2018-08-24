#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Person{
  string name;
public:
  Person(string name)
    : name{name}{}

  virtual ~Person(){};

  void printName(){
    cout << name << endl;
  }
};


class Student: public Person{
  int assn;
  int exams;
public:
  Student(string name, int assn, int exams)
    : Person{name}, assn{assn}, exams{exams}{}

  void printCourseGrade(){
    cout << assn * 0.4 + exams * 0.6 << endl;
  }
};


int main(){
  const Person *jerry = new Person{"Jerry"};
  Person *bill = new Person{"Bill"};
  Student *billy = new Student{"Billy", 98, 75};
  shared_ptr <Student> sharedBilly = make_shared<Student>("Billy", 98, 75);

  bill->printName();
  billy->printName();
  billy->printCourseGrade();

  //1. static_cast
  Person *staticBill = static_cast<Person *>(billy); //UPCAST?!!!
  Student *staticBilly = static_cast<Student *>(bill); //Downcast Compiles
  //string *staticIntBilly = static_cast<string *>(billy); //Compiler trusts you X(won't compile)

  staticBill->printName();
  staticBilly->printName();
  staticBilly->printCourseGrade();

  //2. reinterpret_cast
  Person *reBill = reinterpret_cast<Person *>(billy);
  Student *reBilly = reinterpret_cast<Student *>(bill);
  string *reIntBilly = reinterpret_cast<string *>(billy);

  reBill->printName();
  reBilly->printName();
  reBilly->printCourseGrade();

  //3. const_cast
  Person *p1 = bill;
  //Person *p2 = jerry; //won't compile, p2 is not const
  Person *constAwayP2 = const_cast<Person *>(jerry);

  constAwayP2->printName();

  //4. dynamic_cast
  Person *dynamicBill = dynamic_cast<Person *>(billy); // Subclass to Superclass
  Student *dynamicBilly = dynamic_cast<Student *>(bill); // Superclass to Subclass X (WON'T COMPILE)

  Person *dynamicBillDecorator = reinterpret_cast<Person *>(static_cast<Student *>(dynamic_cast<Person *>(billy)));

  dynamicBillDecorator->printName();
  dynamicBill->printName();
  //dynamicBilly->printName();
  //dynamicBilly->printCourseGrade();

  shared_ptr <Person> staticSharedBilly = static_pointer_cast<Person>(sharedBilly);
  staticSharedBilly->printName();

  shared_ptr <Person> dynamicSharedBilly = dynamic_pointer_cast<Person>(sharedBilly);
  dynamicSharedBilly->printName();
}
