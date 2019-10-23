#pragma once

// Fichier point.hpp

class Point
{
   // Tout est prive par defaut

   // Attributs //
   int        x;
   int        y;
   static int compteur;
   
   // Methodes //
   public:
      Point();
      Point(double, double);
      ~Point();
      int getX();
      int getY();
      static int getCompteur();
      void setX(int);
      void setY(int);
      void deplacerDe(int x, int y);	  // Definit nombre de pas dans chaque axe
      void deplacerVers(int x, int y);	  // Definit une nouvelle position 

}; 
