#include "Groupe.hpp"

Groupe::Groupe()
{

}

int Groupe::getCompteur() {return this->compteur;}

std::string Groupe::toString()
{
   std::string retour  = "";

   for (int i = 0; i < Groupe::nb_c; i++)
   {
      retour += (formes[i]->toString() + '\n');
   }

   return retour;
}

void Groupe::ajouter(Forme * c)
{
   if(nb_c < Groupe::TAILLE - 1)
   {
      // c->ordre        = nb_c + nb_r; // nb_c + nb_r
      formes[nb_c++] = c;
   }
   else
   {
      std::cout << "Taille insuffisante" << std::endl;
   }
}
