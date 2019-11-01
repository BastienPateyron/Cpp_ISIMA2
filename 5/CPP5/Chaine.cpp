#include "Chaine.hpp"
#include <cstring>

// Initialisation des Attributs de classe


// Constructeurs
Chaine::Chaine() : capacite(-1), tab(NULL) {}

Chaine::Chaine(int taille = 0) : capacite(taille) {}

Chaine::Chaine(char const * inCS) // Input_C_String
{
   tab = (char *) malloc(sizeof(char) * strlen(inCS));
   strcpy(tab, inCS);
}

Chaine::~Chaine() {if(tab) free(tab);}


// Methodes
int    Chaine::getCapacite() const { return capacite; }
char * Chaine::c_str()       const { return tab; }