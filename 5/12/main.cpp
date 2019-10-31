#include "Forme.hpp"
#include "Cercle.hpp"

void afficher1(Forme f) {
   f.afficher();
}

void afficher2(Forme &f) {
   f.afficher();
}

void afficher3(Forme * f) {
   f->afficher();
}

int main(int, char**) {
   Cercle cercle;

   // std::cout << cercle.toString() << std::endl;
   
   afficher1(cercle);         // Troncature  -> Forme
   afficher2(cercle);         // OK          -> Cercle
   afficher3(&cercle);        // OK          -> Cercle

   return 0;
}