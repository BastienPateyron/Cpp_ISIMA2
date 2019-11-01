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
      Chaine(Chaine * c);
      ~Chaine();

      // Constantes
      int    getCapacite() const;
      char * c_str()       const;

      // Effet de Bord



   // Elements de classe

};

#endif
