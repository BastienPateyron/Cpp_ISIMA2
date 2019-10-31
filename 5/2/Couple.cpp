#include "Couple.hpp"

// Liste d'initialisation pour eviter l'appel du constructeur par defaut au debut
Couple::Couple() : a(Bavarde(1)), b(Bavarde(2)) 
{
  std::cout << "New Couple" << std::endl;
}

// Couple::Couple(int, int)
// {
//   // TODO  
// }

Couple::~Couple()
{
    std::cout << "Delete Couple" << std::endl;
}


int Couple::getNumeroA() { return a.getNumero();}

int Couple::getNumeroB() { return b.getNumero();}

void Couple::afficher()
{
  std::cout << "Couple: " << getNumeroA() << " - " << getNumeroB() << std::endl;
}
