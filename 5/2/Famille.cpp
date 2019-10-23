#include "Famille.hpp"

Famille::Famille(int taille) : membres()
{
  cout << "Famille de " << taille << " membres" << endl;
  membres = new Bavarde[taille];
}

Famille::~Famille()
{
  delete[] membres;
}