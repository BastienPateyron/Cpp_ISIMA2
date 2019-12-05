#ifndef marvel__hpp
#define marvel__hpp

#include <iostream>
#include <exception>
#include <vector>
#include <numeric>
class Capacite;


typedef std::string Str;

class Personne {
   public:
      enum Genre{HOMME,FEMME, INDETERMINE};
      Personne(Str prenom = "Inconnu", Str nom = "Inconnu", Genre genre = Personne::INDETERMINE) : nom(nom), prenom(prenom), genre(genre) {}
      Str getNom() const {return nom;}
      Str getPrenom() const {return prenom;}
      Genre getGenre() const {return genre;}
      std::ostream & afficher(std::ostream & s) const {return s << prenom << " " << nom << " " << afficherGenre();}
      Str afficherGenre() const;
      static Personne INCONNU;

   private:
      Str nom;
      Str prenom;
      Personne::Genre genre;


};


class Super {
   private:
      Str nom;
      bool anonyme;
      Personne identite;
      std::vector<Capacite *> capacites;

   public:
      Super(Str nom, Personne p = Personne::INCONNU) : nom(nom), anonyme(true), identite(p) {}
      Super(Super const &);
      ~Super();
      Str getNom() const {return nom;}
      bool estAnonyme() const {return anonyme;}
      Personne & getIdentite();
      void enregistrer() {anonyme = false;}
      void setIdentite(Personne p) {identite = p; anonyme = true;}
      void ajouter(Capacite * c) {capacites.push_back(c);}
      int getNiveau() const;

};



class Capacite {
   protected:
      Str nom;
      int niveau;
      friend Super;

   public:
      Capacite(Str nom, int niveau) : nom(nom), niveau(niveau) {}
      virtual Capacite * clone() const = 0;
      virtual ~Capacite() {};
      virtual void utiliser(std::ostream & s) const = 0; 
};


class Materiel : public Capacite {
   public:
      Materiel(Str nom, int niveau) : Capacite(nom, niveau) {}
      virtual Materiel * clone() const {return new Materiel(*this);}
      void actionner(std::ostream & s) const { utiliser(s);}
      virtual void utiliser(std::ostream & s) const {s << nom + " [" +  std::to_string(niveau) + "] en action";}
};

class Physique : public Capacite {
   public:
      Physique(Str nom, int niveau) : Capacite(nom, niveau) {}
      virtual Physique * clone() const {return new Physique(*this);}
      void exercer(std::ostream & s) const {utiliser(s);}
      virtual void utiliser(std::ostream & s) const {s << nom + " [" + std::to_string(niveau) + "]";}
};

class Psychique : public Capacite {
   public:
      Psychique(Str nom, int niveau) : Capacite(nom, niveau) {}
      virtual Psychique * clone() const {return new Psychique(*this);}
      void penser(std::ostream & s) const {utiliser(s);}
      virtual void utiliser(std::ostream & s) const {s << nom + " [" + std::to_string(niveau) + "]";}
};







// Exception //
class AnonymeException : public std::exception {
   public:
      const char * what() {return "identite anonyme";}
};

// Operateurs //
bool operator==(Personne const & a, Personne const & b);
std::ostream & operator<<(std::ostream & s, Personne const & p);






#endif
