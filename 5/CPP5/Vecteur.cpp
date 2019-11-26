#include "Vecteur.hpp"

Vecteur::Vecteur(int const capacite = 10) : v_capacite(capacite), v_size(0)
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
      capacity(v.capacity());
      size(v.size());

      if(size())
      {
         tab = new double[capacity()];
         std::copy( &(v[0]), &(v[0]) + v.size(), tab);
         memcpy(tab, v.tab, v.size());
      }
      else tab = nullptr;
   }
   return * this;
}

double & Vecteur::operator[](int const index) 
{
   // item;
   if(index < 0
   || index > size() - 1
   || !tab)
      throw Vecteur::OutOfRangeException();
   
   double &item = tab[index];
   
   return item; 
}

double const & Vecteur::operator[](int const index) const 
{
   if(index < 0
   || index > size() - 1
   || !tab)
      throw Vecteur::OutOfRangeException();
   
   double &item = tab[index];
   
   return item; 
}

Vecteur & Vecteur::operator+(Vecteur const & v)
{
   capacity(capacity() + v.capacity());
   std::copy(v.tab, v.tab + v.size(), tab + size() + 1);
   return * this;
}

// std::ostream & operator<<(std::ostream const & flux, Vecteur const & v)
// {

// }

// Ajoute un element en fin de tableau et double sa taille s'il n'y en a plus
void Vecteur::push_back(double const x)
{
   std::cout << "I push back" << std::endl;

   if(size() == capacity())   // On double l'espace memoire
   {
      Vecteur v(capacity() * 2);
      memcpy(v.tab, tab, size());
      delete this; // peut être spécifier dans le destructeur de delete tab ??
      *this = v;
   }

   tab[size()] = x;
   size(size() + 1); // size++
}

