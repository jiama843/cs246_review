class Vec{
  Vec(int i, int j);
};

Vec makeVec(){ return Vec{1, 2}; }

int main(){

  v.operator<<(cout);
  operator<<(v, cout);

  w << (v << cout);

  Vec v = makeVec(); //None of the constructors are called if copy-move ellision works
  Vec *p = new Vec[10]; //objects MUST BE INITIALIZED

  for(auto n : l){ n... }
  //for(auto &n : l){ n... }

  auto end = l.end();
  for(auto it = l.begin(); it != end; ++it){
    auto &n = *it;
    n...
  }

  ifstream file{"file.txt"}
  string s;
  file >> s;

  while(file >> i >> j)//if read on i fails, then read on j will also fail
  //Essentially what happens is that a failbit is set, in which case
  //all reads don't work
}

//explicit requires that you use the name of a class to instantiate an object
