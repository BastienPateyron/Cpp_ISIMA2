#include "marvel.hpp"

// Personne //
Personne Personne::INCONNU;

Str Personne::afficherGenre() const {
   switch(genre) {
      case(HOMME): return "[HOMME]"; break;
      case(FEMME): return "[FEMME]"; break;
      case(INDETERMINE): return "[INDETERMINE]"; break;
      default: return "-- Error Genre --";   
   }
}



// Operateurs //
bool operator==(Personne const & a, Personne const & b) {
   return (
      a.getNom() == b.getNom() &&
      a.getPrenom() == b.getPrenom() &&
      a.getGenre() == b.getGenre()
   );
}