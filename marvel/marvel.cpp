#include "marvel.hpp"

Personne::Personne(const char * prenom, const char * nom, Personne::Genre genre) : nom(nom), prenom(prenom), genre(genre) 
{

}

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

Personne Personne::INCONNU("Inconnu", "Inconnu", Personne::INDETERMINE);

bool operator==(Personne const & a, Personne const & b)
{
   return (
      a.getNom()    == b.getNom() &&
      a.getPrenom() == b.getPrenom() &&
      a.getGenre()  == b.getGenre());
}