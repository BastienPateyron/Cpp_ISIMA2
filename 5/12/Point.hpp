#ifndef __CPP4__POINT_HPP__
#define __CPP4__POINT_HPP__

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
      Point(Point * p);
      ~Point();
      int getX() const;
      int getY() const;
      static int getCompteur();
      void setX(double);
      void setY(double);
      void deplacerDe(int x, int y);	  // Definit nombre de pas dans chaque axe
      void deplacerVers(int x, int y);	  // Definit une nouvelle position 

}; 

// declaration d'un point ORIGINE
// il ne faudra pas oublier de l'instancier quelque part
// extern
// Globale à l'ENSEMBLE des unités de compilation (pas juste Point.cpp)
extern Point ORIGINE;

#endif