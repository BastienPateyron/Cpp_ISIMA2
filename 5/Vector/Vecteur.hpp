#include <iostream>

class Vecteur
{
private:
   /* data */

   

public:
   int capacite;
   int size;
   double * tab;

   // Vecteur(/* args */);
   Vecteur(int const size);
   ~Vecteur();
   Vecteur      & operator=(Vecteur const &);
   double       & operator[](int const index);
   double const & operator[](int const index) const;
};

Vecteur operator+(Vecteur const & a, Vecteur const & b);
// std::ostream & operator<<(std::ostream const & flux, Vecteur const & v);