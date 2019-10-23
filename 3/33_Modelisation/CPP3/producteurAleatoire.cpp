#include "producteurAleatoire.hpp"

producteurAleatoire::producteurAleatoire() : Producteur(){};

bool produire(std::string nom)
{
  int quantite = 0;

  bool b = Producteur::produire(quantite, nom);
  
  // Appeler fonction produire de la mere
  return  b;
}