#include "Couple.hpp"

// Liste d'initialisation pour eviter l'appel du constructeur par defaut au debut
Couple::Couple() : a(Bavarde(1)), b(Bavarde(2)) 
{
  cout << "New Couple" << endl;
}

// Couple::Couple(int, int)
// {
//   // TODO  
// }

Couple::~Couple()
{
    cout << "Delete Couple" << endl;
}


int Couple::getNumeroA() { return a.getNumero();}

int Couple::getNumeroB() { return b.getNumero();}

void Couple::afficher()
{
  cout << "Couple: " << getNumeroA() << " - " << getNumeroB() << endl;
}
