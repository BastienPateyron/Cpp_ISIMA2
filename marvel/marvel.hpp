#ifndef marvel__hpp
#define marvel__hpp

#include <iostream>


typedef std::string Str;

class Personne {
   public:
      enum Genre{HOMME,FEMME, INCONNU};
      Personne(Str prenom = "", Str nom = "", Genre genre = Personne::INCONNU) : nom(nom), prenom(prenom), genre(genre) {}
      Str getNom() const {return nom;}
      Str getPrenom() const {return prenom;}
      Genre getGenre() const {return genre;}    

   private:
      Str nom;
      Str prenom;
      Personne::Genre genre;


};







#endif
