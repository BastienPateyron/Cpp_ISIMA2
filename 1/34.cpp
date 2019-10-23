#include <iostream>

void swap(int& a, int& b)
{
    // Reference //
    std::cout << "Reference -- ";
    int tmp = a;
    a       = b;
    b       = tmp;
}

void swap(int * a, int * b)
{
    // Pointeur //
    std::cout << "Pointeurs -- ";
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}

int main(int, char **) {

   // 3.4 //
    int  a = 3;
    int  b = a;
    int& c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    swap(a, b);
    std::cout << a << " " << b << " " << c << std::endl;

    // c = 5;
    // std::cout << a << " " << b << " " << c << std::endl;
    // a = 6;
    // std::cout << a << " " << b << " " << c << std::endl;
   
    return 0;
}