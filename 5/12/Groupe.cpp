#include "Groupe.hpp"

Groupe::Groupe()
{

}

int Groupe::getCompteur() {return this->compteur;}

std::string Groupe::toString()
{
   std::string retour  = "";

   for (int i = 0; i < Groupe::nb; i++)
   {
      retour += (formes[i]->toString() + '\n');
   }

   return retour;
}

void Groupe::ajouter(Forme * c)
{
   if(nb < Groupe::TAILLE - 1) { formes[nb++] = c; }
   else                        { std::cout << "Taille insuffisante" << std::endl; }
}
