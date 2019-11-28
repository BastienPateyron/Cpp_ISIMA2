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
      Personne(std::string , std::string , Personne::Genre = Personne::INDETERMINE);
      
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

      std::string       getNom()      const { return nom; }      
      bool              estAnonyme()  const { return anonyme; }
      const Personne &  getIdentite() const;

      
      
      void enregistrer() { anonyme = false; }
      void setIdentite(Personne const & p) {anonyme = true; personne = p;}

   private:
      std::string nom;
      Personne    personne;
      bool        anonyme;


   public:
};

// Capacites
class Capacite
{
   private:

   protected:
      std::string nom;
      int         niveau;

   public:
      Capacite(std::string const & n, int const & lvl) : nom(n), niveau(lvl) {};
      virtual ~Capacite() {};
      virtual void utiliser(std::ostream & log) = 0;
};

// Materiel
class Materiel : public Capacite
{
   public:
      Materiel(std::string const & n, int const & lvl) : Capacite(n, lvl) {};
      // Redéfinitions
      void utiliser(std::ostream & log) { actionner(log); }
      void actionner(std::ostream & log) { log << nom << " [" << niveau << "]" << " en action"; }
};

// Physique
class Physique : public Capacite
{
   public:
      Physique(std::string const & n, int const & lvl) : Capacite(n, lvl) {};
      void utiliser(std::ostream & log) { exercer(log); }
      void exercer(std::ostream & log) { log << nom << " [" << niveau << "]"; }

};

// Psychique
class Psychique : public Capacite
{
   public:
      Psychique(std::string const & n, int const & lvl) : Capacite(n, lvl) {};
      void utiliser(std::ostream & log) { penser(log); }
      void penser(std::ostream & log) { log << nom << " [" << niveau << "]"; }

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
