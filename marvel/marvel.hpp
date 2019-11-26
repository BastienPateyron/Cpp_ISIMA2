#ifndef marvel__hpp
#define marvel__hpp
#include <iostream>

class Personne
{
   public:
   
      enum Genre {HOMME, FEMME, INDETERMINE};
      
      Personne();
      // ~Personne();
      Personne(Personne const & p);
      Personne(const char * , const char * , Personne::Genre);
      
      std::string getNom()    const { return nom; };
      std::string getPrenom() const { return prenom; };      
      Genre       getGenre()  const { return genre; };

   private:
      std::string nom, prenom;
      Genre genre; // Personne::Genre


      
};

#endif
