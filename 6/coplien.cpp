#include <iostream>

class M
{
  public:
    M() { std::cout << "M::M()" << std::endl; }
    ~M() { std::cout << "M::~M()" << std::endl; }
    M(const M &) { std::cout << "M::M(const M&)" << std::endl; }

    M & operator=(M const &o)
    {
      puts("Hello M");
        if (&o != this) // Pour éviter un crash avec s1 = s1
        {
          
        }
        return *this;
    }
};

class F : public M
{

  public:
    F() { std::cout << "F::F()" << std::endl; }
    ~F() { std::cout << "F::~F()" << std::endl; }
    F(const F &f) : M(f) { std::cout << "F::F(const F&)" << std::endl; }
    F & operator=(F const &o)
    {
      M::operator=(o);

      return *this;
    //   puts("Hello F");
    //     if (&o != this) // Pour éviter un crash avec s1 = s1
    //     {
          
    //     }
    //     return *this;
    // }
    }
};

class A
{
  private:
    M m;
  public:
    A() { std::cout << "A::A()" << std::endl; }
    ~A() { std::cout << "A::~A()" << std::endl; }
    A(const A &) { std::cout << "A::A(const A&)" << std::endl; }

    A & operator=(A const &o)
    {
      puts("Hello A");
        if (&o != this) // Pour éviter un crash avec s1 = s1
        {
          
        }
        return *this;
    }
};

int main(int, char **)
{
  // F f1;      // Mere puis Fille
  // F f2 = f1; // Copie de M

  // std::cout << "f1 = f2" << std::endl;
  // f1 = f2;
  A a1;
  puts("Copie");
  A a2 = a1;

  return 0;
}