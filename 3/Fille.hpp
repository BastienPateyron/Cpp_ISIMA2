#pragma once
#include "Mere.hpp"

class Fille : public Mere
{
  private:
    std::string cheese;

  public:
    Fille();
    Fille(std::string);
    ~Fille();
    void afficher() override; // Virtual et override sont optionnels
    void fromage();
};
