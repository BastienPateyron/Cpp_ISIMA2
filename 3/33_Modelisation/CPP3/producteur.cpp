#include "producteur.hpp"
#include <fstream>


bool Producteur::produire(int quantite, std::string nom)
{
  setTravail(getTravail() + 1);

  bool succes = false;

  // Ouverture du fichier en ecriture 'Ouput'
  std::ofstream fichier; // .c_str() obligatoire ?

  fichier.open(nom.c_str());
  
  // Si le fichier est ouvert on ecrit dedans
  if( !fichier.fail())
  {
    fichier << quantite << std::endl; // On le nombre de lignes au debut
    
    for (int i = 0; i < quantite; i++)
    {
      fichier << i + 1 << std::endl; // Ajoute les valeurs à chaque ligne
    }
    fichier.close();
    succes = true;
  }
  else
  {
    std::cout << "ECHEC OUVERTURE" << std::endl;
  }
  return succes;
}

int Producteur::getTravail(){return this->travail;}
void Producteur::setTravail(int x){this->travail = x;}