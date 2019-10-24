#include "Cercle.hpp"

Cercle::Cercle() : Cercle(0, 0, 0) {}

Cercle::Cercle(int x, int y, int w, int h) : Forme(w, h, x, y) {}

Cercle::Cercle(int x, int y, int rayon) : Cercle(x, y, rayon * 2, rayon * 2) {}


std::string Cercle::toString() const { return "CERCLE " + Forme::toString(); }

double Cercle::getRayon()      const { return getLargeur() / 2; }

void Cercle::setRayon(double r) { w = h = r * 2; }
