#include "Forme.hpp"

int Forme::nbFormes = 0; // Initialisation unique de la variable de classe

Forme::Forme() : Forme(0, 0) {}

Forme::Forme(double w, double h) : Forme(w, h, 0, 0) {}

Forme::Forme(Point p, COULEURS c) : Forme(0, 0)
{
   couleur = c;
   point = p;
}

Forme::Forme(double w, double h, double x, double y) : Forme(w, h, Point(x, y)) {}

Forme::Forme(double w, double h, Point p) : couleur(COULEURS::BLEU),
                                            id(Forme::nbFormes++),
                                            point(p),
                                            w(w),
                                            h(h)
{
}

Forme::~Forme() {}

std::string Forme::toString() const
{
   return std::to_string(point.getX()) + " " +
          std::to_string(point.getY()) + " " +
          std::to_string(getLargeur()) + " " +
          std::to_string(getHauteur());
}

// Methodes statiques / de classe
int Forme::getId() const { return id; }
int Forme::prochainId() { return nbFormes; }

// Methodes const
COULEURS Forme::getCouleur() const { return couleur; }
double Forme::getLargeur() const { return w; }
double Forme::getHauteur() const { return h; }

// Methodes avec effet de bord
Point &Forme::getPoint() { return point; } // TODO: Réussir à retourner la référence du point
void Forme::setCouleur(COULEURS c) { couleur = c; }
void Forme::setX(double x) { point.setX(x); }
void Forme::setY(double y) { point.setY(y); }