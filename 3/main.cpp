#include "Fille.hpp"

int main()
{
  // Mere  * m = new Mere("Françoise");
  // Fille * f = new Fille("Nicole");
  Mere  * t = new Fille("Fille vue comme mere");

  // m->afficher();
  // f->afficher();  
  t->afficher();
  // t->fromage(); // Ne marche pas

  // delete m;
  // delete f;
  
  delete t;

  return 0;
}