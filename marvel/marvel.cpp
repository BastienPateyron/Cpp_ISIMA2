#include "marvel.hpp"

// Instanciations //
Personne Personne::INCONNU("Inconnu", "Inconnu", Personne::INDETERMINE);


// Operateurs //
bool operator==(Personne const & a, Personne const & b)
{
   return (
      a.getNom()    == b.getNom() &&
      a.getPrenom() == b.getPrenom() &&
      a.getGenre()  == b.getGenre());
}

std::ostream & operator<<(std::ostream & s, Personne const & p) { return p.afficher(s); }

// Personne //
Personne::Personne(std::string prenom, std::string nom, Personne::Genre genre) : nom(nom), prenom(prenom), genre(genre) {}

std::string Personne::afficherGenre() const
{
   switch(genre)
   {
      case(Personne::HOMME):       return "[HOMME]";
      case(Personne::FEMME):       return "[FEMME]";
      case(Personne::INDETERMINE): return "[INDETERMINE]";
      default:                     return "-Erreur_switch-";
   } 
}



// Super //
Personne & Super::getIdentite()
{
   if(anonyme) throw new Super::AnonymeException;
   return personne;
}



