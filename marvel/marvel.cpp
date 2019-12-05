#include "marvel.hpp"

// Personne //
Str Personne::afficherGenre() const {
   switch(genre) {
      case(HOMME): return "[HOMME]"; break;
      case(FEMME): return "[FEMME]"; break;
      case(INCONNU): return "[INCONNU]"; break;
      default: return "-- Error Genre --";   
   }
}