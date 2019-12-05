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
Super::Super(Super const & super) : 
   nom(super.nom),
   anonyme(super.anonyme),
   identite(super.identite) {
   for(
      std::vector<Capacite *>::const_iterator it = super.capacites.begin();
      it != super.capacites.end(); it++
   ) capacites.push_back( (*it)->clone() );
}

Super::~Super() {
   for(
      std::vector<Capacite *>::iterator it = capacites.begin();
      it != capacites.end();
      it++
   ) delete *it;
   capacites.clear();
}

Personne & Super::getIdentite() {
   if(anonyme) throw AnonymeException();
   else        return identite;
}

int Super::getNiveau() const {
   return std::accumulate (
      capacites.begin(),
      capacites.end(),
      0,
      [] (int i, Capacite * c) { return i += c->niveau;}
   );
}



// Equipe //
int Equipe::getNiveau() const {
   return std::accumulate(
      membres.begin(), membres.end(),
      0,
      [] (int i, Super * s) {return i += s->getNiveau();}
   );
}

Equipe::~Equipe() {
   for(
      std::vector<Super *>::iterator it = membres.begin();
      it != membres.end();
      it++
   ) delete *it;
   membres.clear();
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