#include <fstream>
#include <iostream>

#include "producteur.hpp"
#include "statisticien.hpp"
#include "catch.hpp"

int NB_LIGNES = 10;
std::string LE_FICHIER = "test01.txt";

TEST_CASE("Producteur_Initialisation") {
  Producteur p;
  REQUIRE( p.getTravail() == 0);
}

TEST_CASE("Producteur_travail2") {
  Producteur p;
  p.produire(NB_LIGNES, LE_FICHIER);
  p.produire(NB_LIGNES, LE_FICHIER);
  p.produire(NB_LIGNES, LE_FICHIER);
  REQUIRE ( p.getTravail() == 3);
}

TEST_CASE("Producteur_Travail3") {

    const int         DEMANDE    = NB_LIGNES;
    const std::string NOM_FICHIER(LE_FICHIER);
    int               lecture, i;
    Producteur        p; 


    p.produire(DEMANDE, NOM_FICHIER.c_str());

    std::ifstream fichier(NOM_FICHIER.c_str());

    REQUIRE(fichier.is_open());

    if (!fichier.eof()) {
      fichier >> lecture; 
      REQUIRE(DEMANDE == lecture);
      for (i = 0; i < DEMANDE; ++i) {
        fichier >> lecture;
        REQUIRE( lecture == (i+1) );
      }
    
    REQUIRE(i == DEMANDE);
    // CHECK(fichier.eof());
    fichier.close();

    REQUIRE(p.getTravail() == 1);
  }
}

TEST_CASE("Statisticien_Initialisation") {
  Statisticien p;
  REQUIRE_FALSE(p.calcul);
}

TEST_CASE("Statisticien_Acquerir")
{
  Statisticien p;
  p.acquerir(LE_FICHIER);
  REQUIRE(p.calcul == true);
  REQUIRE(p.somme == NB_LIGNES * (NB_LIGNES + 1) / 2);
  REQUIRE(p.moyenne == 5.5);
}

// TODO TEST Probabilités (Fin 3.3)