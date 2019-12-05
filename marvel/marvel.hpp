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
          

   private:
      Str nom;
      Str prenom;
      Personne::Genre genre;


};







#endif
