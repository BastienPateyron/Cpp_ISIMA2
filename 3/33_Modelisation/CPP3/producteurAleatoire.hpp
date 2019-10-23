#pragma once
#include "producteur.hpp"

class producteurAleatoire : public Producteur
{

  public:
    producteurAleatoire();
    bool produire(std::string nom);
    bool produire(int, std::string);
};

