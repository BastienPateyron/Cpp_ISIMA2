#include "Chaine.hpp"
#include <cstring>

// Initialisation des Attributs de classe


// Constructeurs
Chaine::Chaine() : capacite(0), tab(NULL) {}

Chaine::Chaine(char const * inCS) : capacite(strlen(inCS)+ 1) // Input_C_String
{
   tab = new char[capacite];
   strcpy(tab, inCS);
}

Chaine::Chaine(int inCapacite = 0) : capacite(inCapacite + 1) // +1 Pour le \0 géré en interne
{
   tab = new char[capacite];
   memset(tab, 0, capacite);
}

Chaine::Chaine(Chaine const & c) : Chaine(c.getCapacite())
{
   strcpy(this->tab, c.tab);
   std::cerr << "Constructeur de copie" << std::endl;
}

Chaine::~Chaine() { delete [] tab; }


// Methodes Constantes
int    Chaine::getCapacite()                           const { return capacite - 1; } // -1 car la capacité interne compte aussi le \0
char * Chaine::c_str()                                 const { return tab; }
void   Chaine::afficher(std::ostream & flux)           const { flux << c_str(); }
void   Chaine::afficherParValeur(Chaine const  c)      const { c.afficher(); }
void   Chaine::afficherParReference(Chaine const  & c) const { c.afficher(); }

// Effets de bord
Chaine & Chaine::operator=(const Chaine &c)
{
   if (&c != this)   // Pour éviter un crash avec s1 = s1
   {
      delete [] tab;
      capacite = c.capacite;
      
      if(capacite)
      {
         tab = new char[capacite];
         strcpy(tab, c.tab);
      }
      else
      {
         tab = nullptr;
      }
   }

   return * this;
}

// Fonctions
std::ostream & operator<<(std::ostream & flux, Chaine const & c)
{
   if(c.c_str())
   {
      // for(int i = 0; i < (int) strlen(c.c_str()); i++) std::cout << c[i] << std::endl;
      c.afficher(flux);
   }
   return flux;
}

const char & Chaine::operator[](int const index) const
{
   if((index < 0) || (index >= capacite) || !tab) // Tests à recopier ailleurs
   {
      std::cerr << "Erreur d'index" << std::endl;
      // std::exit(1); // moisi
   }

   return tab[index];
}
 
char & Chaine::operator[](int const index)
{
   
   if((index < 0) || (index >= capacite) || !tab) // Tests à recopier ailleurs
   {
      std::cerr << "Erreur d'index" << std::endl;
      // std::exit(1); // moisi
   }

   return tab[index];

}