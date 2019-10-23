#include "Bavarde.hpp"

// Bavarde globale(2);

Bavarde::Bavarde() : Bavarde(0)
{
  // cout << "Construction anonyme" << endl;
}

Bavarde::Bavarde(int x)
{
  numero = x;
  cout << "Construction de " << numero << endl;
}

Bavarde::~Bavarde()
{
  cout << "Tais toi " << numero << endl;
}

int Bavarde::getNumero() { return numero; }

void Bavarde::afficher()
{
  cout << "Affichage de " << getNumero() << endl;
}

