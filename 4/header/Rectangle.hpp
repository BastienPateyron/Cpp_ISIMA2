#ifndef __CPP4__RECTANGLE_HPP__
#define __CPP4__RECTANGLE_HPP__

#include "Forme.hpp"

enum class DIAGONALE {};

class Rectangle : public Forme
{
  private:
    // int x, y, w, h;

  public:
    // int ordre; // Initialisé par la LISTE quand on y ajoute cet objet

  public:
    Rectangle();
    Rectangle(int, int, int, int);
    Rectangle(int, int, int, int, DIAGONALE);
    std::string toString() const override;
};


#endif