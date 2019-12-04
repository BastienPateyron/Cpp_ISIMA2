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
Personne::Personne() {};
Personne::Personne(std::string prenom, std::string nom, Personne::Genre genre) : nom(nom), prenom(prenom), genre(genre) {}
// Personne::Personne(Personne const & p) : nom(p.nom), prenom(p.prenom), genre(p.genre) {};
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
Super::Super(Super const & s) : nom(s.nom), personne(s.getIdentite()), anonyme(s.anonyme)
{
   for (
      v_capa::const_iterator it = s.capacites.begin();
      it != s.capacites.end();
      it++
   ) capacites.push_back( (*it)->clone());
}

Super::~Super()
{
   std::cout << "Kill " << nom << std::endl;
   for(
      v_capa::iterator it = capacites.begin();
       it != capacites.end();
       it++
   ) 
   {
      std::cout << "  Kill " << (*it)->getNom() << std::endl;
      delete *it;
   }
   capacites.clear();
}

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


// Capacite::Capacite(Capacite const & c) : nom(c.getNom()), niveau(c.getNiveau()) {}

Materiel * Materiel::clone() const {return new Materiel(*this);}
Physique * Physique::clone() const {return new Physique(*this);}
Psychique * Psychique::clone() const {return new Psychique(*this);}


