#include <iostream>

class M {
 public:  
  M() {
    std::cout << "M::M()" << std::endl;
  }
   ~M() {
    std::cout << "M::~M()" << std::endl;
  }
    M(const M&) {
    std::cout << "M::M(const M&)" << std::endl;
  }
  
};

class F : public M {
 public:
  F() {
    std::cout << "F::F()" << std::endl;
  }  
~F() {
    std::cout << "F::~F()" << std::endl;
  }
  /*  
  F(const F& f) {
    std::cout << "F::F(const F&)" << std::endl;
  } 
  */
};

int main(int, char**) {

  F f1;
  F f2 = f1;
  
  f1 = f2;

  return 0;
}class M {
 public:  
  M() {
    std::cout << "M::M()" << std::endl;
  }
   ~M() {
    std::cout << "M::~M()" << std::endl;
  }
    M(const M&) {
    std::cout << "M::M(const M&)" << std::endl;
  }
  
};

class F : public M {
 public:
  F() {
    std::cout << "F::F()" << std::endl;
  }  
~F() {
    std::cout << "F::~F()" << std::endl;
  }
  /*  
  F(const F& f) {
    std::cout << "F::F(const F&)" << std::endl;
  } 
  */
};

int main(int, char**) {

  F f1;
  F f2 = f1;
  
  f1 = f2;

  return 0;
}class M {
 public:  
  M() {
    std::cout << "M::M()" << std::endl;
  }
   ~M() {
    std::cout << "M::~M()" << std::endl;
  }
    M(const M&) {
    std::cout << "M::M(const M&)" << std::endl;
  }
  
};

class F : public M {
 public:
  F() {
    std::cout << "F::F()" << std::endl;
  }  
~F() {
    std::cout << "F::~F()" << std::endl;
  }
  /*  
  F(const F& f) {
    std::cout << "F::F(const F&)" << std::endl;
  } 
  */
};

int main(int, char**) {

  F f1;
  F f2 = f1;
  
  f1 = f2;

  return 0;
}