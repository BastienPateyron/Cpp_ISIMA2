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
const Personne & Super::getIdentite() const
{
   if(anonyme) throw AnonymeException();
   return personne;
}

int Super::getNiveau() const
{
   return std::accumulate(
      capacites.begin(), 
      capacites.end(), 
      0, 
      [] (int i,  Capacite const * c) { return c->getNiveau() + i; } ); // Lambda qui accumule dans i la valeur des niveaux de la liste
}
