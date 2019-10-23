#include "Mere.hpp"

using std::cout;
using std::endl;

int Mere::compteur = 0;

Mere::Mere()
{
  Mere::compteur++;
  cout << "Mere n° " << Mere::getCompteur() << endl;
}

Mere::Mere(std::string nom) : Mere()
{
  this->nom = nom;
  cout << "Maman " << getNom() << endl;
}

Mere::~Mere()
{
  cout << "Kill Mere" << endl;
  Mere::compteur--;
}

int Mere::getCompteur()
{
  return compteur;
}

std::string Mere::getNom()
{
  return nom;
}

void Mere::afficher()
{
  cout << "Je suis Maman" << endl;
}