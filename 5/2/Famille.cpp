#include "Famille.hpp"

Famille::Famille(int taille) : membres()
{
  std::cout << "Famille de " << taille << " membres" << std::endl;
  membres = new Bavarde[taille];
}

Famille::~Famille()
{
  delete[] membres;
}