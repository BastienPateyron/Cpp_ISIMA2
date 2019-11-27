#ifndef marvel__hpp
#define marvel__hpp
#include <iostream>
#include <exception>


// Classes
class Personne
{
   public:
   
      static Personne INCONNU;
      enum Genre {HOMME, FEMME, INDETERMINE};
      
      Personne();
      // ~Personne();
      // Personne(Personne const & p);
      Personne(std::string , std::string , Personne::Genre);
      
      std::string    getNom()                   const { return nom; }
      std::string    getPrenom()                const { return prenom; }    
      Genre          getGenre()                 const { return genre; }
      std::string    afficherGenre()            const;
      std::ostream & afficher(std::ostream & s) const { return s << prenom << " " << nom << " " << afficherGenre(); }

   private:
      std::string nom, prenom;
      Genre genre; // Personne::Genre

};


class Super {
   public:
      Super(std::string nom, Personne p) : nom(nom), personne(p), anonyme(true) {}

      std::string getNom()     const { return nom; }      
      bool        estAnonyme() const { return anonyme; }

      
      
      void        enregistrer() { anonyme = false; }
      Personne &  getIdentite();

   private:
      std::string nom;
      Personne    personne;
      bool        anonyme;


   public:
};


// Fonctions
bool operator==(Personne const & a, Personne const & b);
std::ostream & operator<<(std::ostream & s, Personne const & p);

// Exceptions
class AnonymeException : public std::exception { 
   public: 
      const char * what() { return "identite anonyme"; }
};

#endif
