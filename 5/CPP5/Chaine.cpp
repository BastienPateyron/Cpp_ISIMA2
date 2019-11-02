#include "Chaine.hpp"
#include <cstring>

// Initialisation des Attributs de classe


// Constructeurs
Chaine::Chaine() : capacite(0), tab(NULL) {}

Chaine::Chaine(char const * inCS) : capacite(strlen(inCS)+ 1) // Input_C_String
{

   tab = (char *) malloc(sizeof(char) * capacite);
   strcpy(tab, inCS);
}

Chaine::Chaine(int inCapacite = 0) : capacite(inCapacite + 1) // +1 Pour le \0 géré en interne
{
   tab = (char *) malloc(sizeof(char) * capacite);
   memset(tab, 0, capacite);
}

Chaine::Chaine(Chaine const & c) : Chaine(c.getCapacite())
{
   strcpy(this->tab, c.tab);
   std::cerr << "Constructeur de copie" << std::endl;
}

Chaine::~Chaine() { free(tab); }


// Methodes
int    Chaine::getCapacite()                           const { return capacite - 1; } // -1 car la capacité interne compte aussi le \0
char * Chaine::c_str()                                 const { return tab; }
void   Chaine::afficher(std::ostream & flux)           const { flux << c_str(); }
void   Chaine::afficherParValeur(Chaine const  c)      const { c.afficher(); }
void   Chaine::afficherParReference(Chaine const  & c) const { c.afficher(); }