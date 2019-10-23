#include "Fille.hpp"

using std::cout;
using std::endl;

Fille::Fille() : Fille("")
{
  // Delegation avec nom vide
}

Fille::Fille(std::string nom) : Mere(nom)
{
  cout << "New Fille n° " << Fille::getCompteur() << endl;
}

Fille::~Fille()
{
  cout << "Kill Fille" << endl;
}

void Fille::afficher()
{
  cout << "Je suis Fille" << endl;
}

void Fille::fromage() { std::cout << "FROMAGE" << std::endl;}