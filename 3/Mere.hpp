#pragma once

#include <iostream>
#include <string>

class Mere
{
  // Attributs //
  private:
    static int compteur;
    std::string nom;

  protected:
  
  public:

  // Methodes //
  public:
    Mere();
    Mere(std::string nom);
    virtual ~Mere();
    static int getCompteur();
    std::string getNom();
    virtual void afficher();
    
};