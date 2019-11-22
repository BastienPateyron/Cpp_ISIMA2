#include "Vecteur.hpp"

Vecteur::Vecteur(int const capacite = 10) : capacite(capacite), size(0)
{
   tab = new double[capacite];
}

Vecteur::~Vecteur()
{
}

Vecteur & Vecteur::operator=(Vecteur const & v)
{
   if(this != &v)
   {
      delete [] tab;
      capacite = v.capacite;
      size = v.size;

      if(size)
      {
         tab = new double[capacite];
         std::copy(v.tab[0], v.tab[size], tab);
      }
      else tab = nullptr;
   }
   return * this;
}

double & Vecteur::operator[](int const index)             { return tab[index]; }
double const & Vecteur::operator[](int const index) const { return tab[index]; }

Vecteur operator+(Vecteur const & a, Vecteur const & b)
{

   int size = a.size + b.size;

   Vecteur v(size * 2);

   std::copy(a.tab[0], a.tab[a.size], v.tab[0]);
   std::copy(b.tab[0], b.tab[b.size], v.tab[v.size]);

   return v;
}
// std::ostream & operator<<(std::ostream const & flux, Vecteur const & v)
// {

// }