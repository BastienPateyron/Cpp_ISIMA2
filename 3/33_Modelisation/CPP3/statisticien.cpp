#include "statisticien.hpp"
#include <fstream>


Statisticien::Statisticien() : calcul(0) {}

void Statisticien::acquerir(std::string nom)
{
	std::ifstream fichier;
  fichier.open(nom.c_str());

  if( !fichier.fail())
  {
    std::cout << "Fichier ouvert" << std::endl;
    int nombreLignes, lecture = 0;
    
    fichier >> nombreLignes;
    int i = 0;
    while(!fichier.eof() && i++ < nombreLignes) // I permet d'éviter le dernier passage
    {
      fichier >> lecture;
      somme += lecture;
    }

    moyenne = somme / nombreLignes;

    std::cout << somme << std::endl;
    std::cout << moyenne << std::endl;

    fichier.close();
    calcul = true;
  }

}
