#include "Bavarde.hpp"

// Bavarde globale(2);
int Bavarde::compteur = 0;

Bavarde::Bavarde() : Bavarde(0)
{
  // cout << "Construction anonyme" << endl;
}

Bavarde::Bavarde(int x)
{
  numero = compteur++;
  std::cout << "Construction de " << numero << std::endl;
}

Bavarde::Bavarde(const Bavarde  &  b) : Bavarde(b.numero) {}

Bavarde::~Bavarde()
{
  std::cout << "Tais toi " << numero << std::endl;
}

int Bavarde::getNumero() { return numero; }

void Bavarde::afficher()
{
  std::cout << "Affichage de " << getNumero() << std::endl;
}

