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