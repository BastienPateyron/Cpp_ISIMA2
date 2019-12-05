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



// Super //
Personne & Super::getIdentite() {
   if(anonyme) throw AnonymeException();
   else        return identite;
}





// Operateurs //
bool operator==(Personne const & a, Personne const & b) {
   return (
      a.getNom() == b.getNom() &&
      a.getPrenom() == b.getPrenom() &&
      a.getGenre() == b.getGenre()
   );
}

std::ostream & operator<<(std::ostream & s, Personne const & p) {return p.afficher(s);}