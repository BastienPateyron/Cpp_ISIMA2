#ifndef __CPP4__FORME_HPP__
#define __CPP4__FORME_HPP__

#include "Point.hpp"
#include <iostream>

// enum COULEURS { BLANC, NOIR};
enum class COULEURS {BLANC, NOIR, BLEU, VERT, JAUNE, ROUGE};

class Forme
{
   // Attributs //
   private:

   protected:
      COULEURS couleur;
      int      id;
      Point    point;
      double   w;
      double   h;

   public:

   
   // Methodes //
   public:
      Forme();
      Forme(double w, double h);
      Forme(Point p, COULEURS c);
      Forme(double w, double h, Point p);
      Forme(double w, double h, double x, double y);
      
      
      virtual ~Forme();

      // Methodes const
      int                 getId()      const;
      COULEURS            getCouleur() const;
      double              getLargeur() const;
      double              getHauteur() const;
      void                afficher()   const;
      virtual std::string toString()   const;

      // Methodes a effet de bord
      Point & getPoint() ;
      void    setCouleur(COULEURS c);
      void    setX(double x);
      void    setY(double y);
      
   // Elements statiques
   private:
      static int nbFormes;

   public:
      static int prochainId();
};

#endif