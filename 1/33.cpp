#include <iostream>

void fonction1(int a) {
  std::cout << &a << std::endl;
}

void fonction1(int& a) {
  std::cout << &a << std::endl;
}

void swap(int a, int b)
{
    int tmp = a;
    a       = b;
    b       = tmp;
}

int main(int, char **) {
   /*
   int age = 41;
   std::cout << &age << std::endl;
   fonction1(age);
   fonction2(age);
    */

   // 3.4 //
    int  a = 3;
    int  b = a;
    int& c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    // c = 5;
    // std::cout << a << " " << b << " " << c << std::endl;
    // a = 6;
    // std::cout << a << " " << b << " " << c << std::endl;
   
    return 0;
}