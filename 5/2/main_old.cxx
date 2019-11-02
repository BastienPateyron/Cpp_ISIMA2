#include "Couple.hpp"
#include "Famille.hpp"
#include <cstdlib>

void fonction(Bavarde b)
{
  std::cout << "code de la fonction pour "<< b.getNumero() << endl;
}

void f11()
{
  Bavarde b;
  Bavarde *p = new Bavarde(3);
  fonction(b);

  std::cout << Bavarde(5).getNumero() << std::endl;

  delete p;
}

void f12()
{
  const int TAILLE = 5;
  Bavarde   tab1[TAILLE];               // Creation d'un tableau de 10 Bavarde
  Bavarde * tab2 = new Bavarde[TAILLE]; // Creation d'un tableau dynamique de 10 Bavarde

  for (int i = 0; i < TAILLE; ++i)
  {
     tab1[i].afficher();
     tab2[i].afficher();
  }

  delete[] tab2;
}

void f13()
{
  Couple * c = new Couple;
  
  c->afficher();

  delete c;
}

void f14()
{
  Famille f1(5);
  Famille f2(0);
  Famille f3(6);
}

void f15() // Malloc n'utilise pas le constructeur
{
  Bavarde * b = (Bavarde *) malloc(sizeof(Bavarde));
  cout << "Valeur: " << b->getNumero() << endl;
  free(b);
}

int main(int, char **)
{
  // f11();
  // f12();
  // f13();
  f14();
  // f15();

  return 0;
}