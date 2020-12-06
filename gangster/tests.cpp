#include "catch.hpp"
#include "gangster.hpp"
#include <stdexcept>
#include <sstream>
#include <cstring>

/*
TEST_CASE("Personne1") {
	  const char * nom = "corleone";
    Personne zz(nom);

    REQUIRE(nom == zz.getNom());
    
    zz.setNom("vito");
    
    REQUIRE("vito" == zz.getNom());
} */

/*
TEST_CASE("Personne2") {
    const char * nom = "frank";
    const Personne zz(nom);

    REQUIRE(nom     == zz.getNom());
} */

/*
TEST_CASE("Personne3") {
    REQUIRE("INCONNU" == INCONNU.getNom());
}*/

/*
TEST_CASE("Gangster") {
  const Gangster parrain;
        Gangster accolyte1;
  const Gangster accolyte2;

  CHECK  (1 == parrain.getId());
  CHECK  (1 == parrain.getInfluence());
  
  CHECK  (parrain.getId()  +1 == accolyte1.getId());
  CHECK  (1 == accolyte1.getInfluence());
  
  CHECK  (accolyte1.getId()+1 == accolyte2.getId());
  CHECK  (1 == accolyte2.getInfluence());

} */

/*
TEST_CASE("Chef") {
   Gangster soldat1; 
   Chef     lieutenant;
   Gangster soldat2;

   CHECK( 1 == lieutenant.getInfluence());

   CHECK(   soldat1.getId()+1 == lieutenant.getId());
   CHECK(lieutenant.getId()+1 == soldat2.getId());

   lieutenant.commande(&soldat1);
   CHECK( 11 == lieutenant.getInfluence());
   lieutenant.commande(&soldat2);
   CHECK( 12 == lieutenant.getInfluence());

   Chef boss;
   CHECK( 1 == boss.getInfluence());
   CHECK(soldat2.getId()+1 == boss.getId());
   boss.commande(&lieutenant);

   CHECK( 22 == boss.getInfluence());
} */

/*
TEST_CASE("Inconnu") {
  InconnuException inconnu;
  CHECK( strcmp(inconnu.what(), "personnalite inconnue")==0);
}*/


/*
TEST_CASE("Exception") {
  Gangster inconnu;
  
  REQUIRE_THROWS_AS(inconnu.getPersonne(), InconnuException);
} */

/*
TEST_CASE("Revelation") {
  Gangster parrain;
  const Personne vito("Vito Corleone");
  
  CHECK(! vito.equals(Personne("loic")));

  parrain.setPersonne(vito);
  
  CHECK(parrain.getPersonne().equals(Personne("Vito Corleone")));
} */

/*
TEST_CASE("Comparaison") {
  Gangster g1;
  Gangster g2;
  Chef     c;

  // gangster de meme influence => "age" qui compte
  CHECK( g2 < g1 );
  CHECK( c  < g1 );

  
  c.commande(&g2);
  // gangster de plus d'influence
  CHECK( g1  < c );
  CHECK( g2  < c );
} */

/*
void creerFamille(Famille & famille, Gangster*hommes[]) {
  for (int i = 0; i < 10; ++i) {
    hommes[i] = new Gangster();
    famille.ajouter(hommes[i]);
  }
  for (int i = 10; i < 13; ++i) {
    hommes[i] = new Chef();
    famille.ajouter(hommes[i]);
  }
  for (int i = 0; i < 5; ++i) {
    ((Chef*)hommes[10])->commande(hommes[2*i]);
    ((Chef*)hommes[11])->commande(hommes[2*i+1]);
  }
  ((Chef*)hommes[12])->commande(hommes[10]);
  ((Chef*)hommes[12])->commande(hommes[11]);
}

*/

/*
TEST_CASE("Famille1A") {
  Famille famille;
  std::stringstream ss;

  Gangster * hommes[13];

  creerFamille(famille, hommes);
  
  const char * tableau[13] = {"Tony", "Clemenza", "Peter", "Kay", "Lucas", 
                              "Salvatore", "Virgil", "Carlo", "Jack",
                              "Moe", "Tom Hagen", "Santino Corleone", "Vito" };
  for(int i =0; i<13; ++i) 
    if (i%4) {
      hommes[i]->setPersonne(Personne(tableau[i]));
      // std::cout << hommes[i]->getPersonne().getNom() << std::endl;
  }

  //famille.listePersonnes(std::cout);
  famille.listePersonnes(ss);

  std::stringstream attendu;
  attendu << "Carlo, Clemenza, Kay, Moe, Peter, Salvatore, Santino Corleone, Tom Hagen, Virgil";
  
  CHECK(attendu.str() == ss.str()); 
  
} */

/*
TEST_CASE("Famille1B") {
  Famille famille;
  std::stringstream ss;

  Gangster * hommes[13];

  creerFamille(famille, hommes);
  
  const char * tableau[13] = {"Tony", "Clemenza", "Peter", "Kay", "Lucas", 
                              "Salvatore", "Virgil", "Carlo", "Jack",
                              "Moe", "Tom Hagen", "Santino Corleone", "Vito" };
  for(int i =0; i<13; ++i) 
    if (i%4) {
      hommes[i]->setPersonne(Personne(tableau[i]));
  }

  ss << famille;

  std::stringstream attendu;
  attendu << "Carlo, Clemenza, Kay, Moe, Peter, Salvatore, Santino Corleone, Tom Hagen, Virgil";
  
  CHECK(attendu.str() == ss.str()); 

} */

/*
TEST_CASE("Foncteur") {
  Gangster g1;
  Gangster g2;
  Chef     c;

  c.commande(&g1);

  FoncteurInf foncteur;
  CHECK(foncteur(&g2, &g1));
  CHECK(foncteur(&g1, &c ));
} */

/*
TEST_CASE("Famille2") {
  Famille famille;
  std::stringstream ss;
  Gangster * hommes[13];
  
  creerFamille(famille, hommes);

  // std::cout << std::endl;
  // for(Gangster * homme : hommes) 
  //   std::cout << homme->getId() << "/" << homme->getInfluence() << " ";
  // std::cout << std::endl;

  // famille.listeMembres(std::cout);
  famille.listeMembres(ss);

  std::stringstream attendu;
  
  attendu << hommes[12]->getId() << " ";
  attendu << hommes[10]->getId() << " ";
  attendu << hommes[11]->getId();
  for(int i =0; i<10; ++i)
    attendu << " " << hommes[i]->getId();
  
  CHECK(attendu.str() == ss.str());
} */

// ET VALGRIND ????