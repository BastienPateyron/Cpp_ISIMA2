#pragma once
#include "Cercle.hpp"
#include "Rectangle.hpp"


class Groupe : public Forme
{
   // Attributs //
   private:
      static const int TAILLE = 10;

   public:
      int         nb;
      int         compteur; // Inutile ? Statique ?
      Forme     * formes[TAILLE];     
   
   // Methodes //
   public:
                  Groupe();
                  // ~Groupe();
      int         getCompteur();
      std::string toString();
      void ajouter(Forme * c);
};

// TODO Gerer l'ordre