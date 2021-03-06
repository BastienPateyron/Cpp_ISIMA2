#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>
#include <vector>

class Chaine  {

   // Elements de l'Objet
   private:
      int    capacite;
      char * tab;

   protected:
   
   public:
      // Constructeurs
      Chaine();
      Chaine(char const * inCS); // Input_C_Strin
      Chaine(int capacite);
      Chaine(Chaine const & c);
      ~Chaine();

      // Constantes
      int    getCapacite()                           const;
      char * c_str()                                 const;
      void   afficher(std::ostream & flux=std::cout) const;
      void   afficherParValeur(Chaine const  c)      const;
      void   afficherParReference(Chaine const & c)  const;

      // Effet de Bord
      Chaine     & operator=(Chaine const & c);
      const char & operator[](int const index) const;
      char       & operator[](int const index);

   // Elements de classe

};

std::ostream & operator<<(std::ostream & flux, Chaine const & c);    

#endif
