#pragma once
#include <iostream>
#include <cstring>

class Vecteur
{
private:
   /* data */
   int v_capacite;
   int v_size;
   double * tab;

   

public:

   // Vecteur(/* args */);
   ~Vecteur();
   Vecteur(int const size);
   Vecteur      & operator=(Vecteur const &);
   double       & operator[](int const index);
   double const & operator[](int const index) const;
   Vecteur      & operator+(Vecteur const & v);

   int   capacity() const      { return v_capacite; }   
   void  capacity(int const c) { v_capacite = c; }

   int   size() const          { return v_size; }   
   void  size(int const s)     { v_size = s; }

   void push_back(double const x);

   
   // Exceptions
   class OutOfRangeException : public std::exception {};
   

 
};

// std::ostream & operator<<(std::ostream const & flux, Vecteur const & v);