#ifndef marvel__hpp
#define marvel__hpp

#include <iostream>


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

      // std::ostream & operator<<(std::ostream & s) {return afficher(s);}
          

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

   public:
      Super(Str nom, Personne p = Personne::INCONNU) : nom(nom), anonyme(true), identite(p) {}
      Str getNom() const {return nom;}
      bool estAnonyme() const {return anonyme;}
      Personne & getIdentite() {return identite;}

};







// Operateurs //
bool operator==(Personne const & a, Personne const & b);
std::ostream & operator<<(std::ostream & s, Personne const & p);






#endif
