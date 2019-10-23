#include "Bavarde.hpp"

// Bavarde globale(2);
int Bavarde::compteur = 0;

Bavarde::Bavarde() : Bavarde(0)
{
  // cout << "Construction anonyme" << endl;
}

Bavarde::Bavarde(int x)
{
  numero = x;
  compteur++;
  cout << "Construction de " << numero << endl;
}

Bavarde::Bavarde(const Bavarde  &  b) : Bavarde(b.numero) {}

Bavarde::~Bavarde()
{
  cout << "Tais toi " << numero << endl;
}

int Bavarde::getNumero() { return numero; }

void Bavarde::afficher()
{
  cout << "Affichage de " << getNumero() << endl;
}

