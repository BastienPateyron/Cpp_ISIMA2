#include <iostream>
#include "Point.hpp"

using namespace std;

int main(int, char **)
{
   Point p;
   
   // p.setX(15);
   // p.setY(15);
   // p.deplacerDe(5, 10);
   // cout << p.getX() << " , " << p.getY() << endl; // 20 , 25

   // p.deplacerVers(10,10);
   // cout << p.getX() << " , " << p.getY() << endl; // 10 , 10

   Point point;
   // cout << point.getX() << " , " << point.getY() << endl;
   cout << "Taille: " << sizeof(point) << endl;

   Point * point2 = new Point(0., 3);
   // cout << point2->getX() << " , " << point2->getY() << endl;
   cout << "Taille: " << sizeof(point2) << endl;
   Point point3(3, 5);
   // cout << point3.getX() << " , " << point3.getY() << endl;
   cout << "Taille: " << sizeof(point3) << endl;
   
      
   // delete point;
   delete point2;

   cout << "Il existe " << Point::getCompteur() << " points " << endl;
   
   return 0;

}

// Initialisation de la variable statique
// Mais pourquoi l'initialisation se fait-elle avant l'entree dans le main ???
int Point::compteur = 0; 

Point::Point()
{
   x = y = 0;
   Point::compteur ++;
}

Point::Point(double x, double y) 
{
   this->x  = x; 
   this->y  = y;
   Point::compteur++;
}

Point::~Point() 
{
   cout << "destructeur" << endl;
   compteur--;
}

int Point::getX()	               {return x;}
int Point::getY()	               {return y;}
int Point::getCompteur()         {return compteur;}

void Point::setX(int val)        {x = val;}
void Point::setY(int val)        {y = val;}

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
