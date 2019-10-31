#include "Point.hpp"


Point        ORIGINE  = Point(0,0);  // (Globale à l'ensemble des unités de compilation car déclarée 'externe')
int   Point::compteur = 0;           // On initialise la variable de classe

Point::Point() : Point(ORIGINE) {}

Point::Point(double x, double y)
{
   this->x  = x; 
   this->y  = y;
   Point::compteur++;
}

Point::Point(Point * p) : Point(p->getX(), p->getY()) {}
Point::~Point() {compteur--;}

int Point::getX()  const {return x;}
int Point::getY()  const {return y;}
int Point::getCompteur() {return compteur;}

void Point::setX(double val)   {x = val;}
void Point::setY(double val)   {y = val;}

void Point::deplacerDe(int x, int y)
{
   this->x += x;
   this->y += y;
}

void Point::deplacerVers(int x, int y)
{
   this->x = x;
   this->y = y;
}
