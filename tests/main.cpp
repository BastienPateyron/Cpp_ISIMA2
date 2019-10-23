#include <iostream>

using namespace std; 
int main(int , char ** )
{
   std::string variable;

   /* je suis un comment */

   cout << "Hello les ZZ" << 2 << std::endl;
   cin >> variable;
   cout << "Variable: " << variable << endl;

   return 0;
}

void swipe(int a, int b)
{
   int tmp;

   cout << "A: " << a << "B: " << b << endl;
   tmp	 = a;
   a	 = b;
   b	 = tmp;

   cout << "A: " << a << "B: " << b << endl;
}
