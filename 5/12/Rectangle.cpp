#include <iostream>
#include "Rectangle.hpp"
#include <math.h>


Rectangle::Rectangle() : Rectangle(0, 0, 0, 0) {}
/*
 * Trace le Rectangle a partir d'un point de coordonnes 'x' et 'y'
 * d'une hauteur 'h' et d'une largeur 'w'
 */
Rectangle::Rectangle(int x, int y, int w, int h) : Forme(w, h, x, y) {}

/* 
 * Trace le Rectangle a partir de deux points diagonnaux 
 * en calculant la hauteur et la largeur
 */
Rectangle::Rectangle(int x1, int y1, int x2, int y2, DIAGONALE)
: // Liste d'initialisation 
  Rectangle(x1, y1, abs(x1 - x2), abs(y1 - y2)) // Delegation de constructeur
{
  std::cout << "By Diagonale" << std::endl;  
}

std::string Rectangle::toString() const
{
  return "RECTANGLE " + Forme::toString();
}
