#pragma once
#include "Bavarde.hpp"

class Couple
{
  // Attributs
  Bavarde a;
  Bavarde b;

  // Methodes 
  public:
    Couple();
    Couple(int, int);
    ~Couple();
    int getNumeroA();
    int getNumeroB();
    void afficher();



};