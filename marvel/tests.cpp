#include <sstream>
#include <cstring>
#include "catch.hpp"
#include "marvel.hpp"

/*
TEST_CASE("Personne1") {
    const char * prenom   = "Bruce";
    const char * nom      = "Wayne";
    Personne::Genre genre = Personne::HOMME;
    Personne p(prenom, nom, genre);

    REQUIRE( prenom    == p.getPrenom());
    REQUIRE( nom       == p.getNom());
    REQUIRE( genre     == p.getGenre());
}*/

/*
TEST_CASE("Personne2") {
    const Personne p("Diana", "Prince", Personne::FEMME);

    REQUIRE( "Diana"          == p.getPrenom());
    REQUIRE( "Prince"         == p.getNom());
    REQUIRE( Personne::FEMME  == p.getGenre());
}

TEST_CASE("Personne3") {
    Personne sorciere("Wanda", "Maximof", Personne::FEMME);
    std::stringstream ss;
    sorciere.afficher(ss);
    REQUIRE("Wanda Maximof [FEMME]" == ss.str() );
} 

TEST_CASE("Inconnu1") {
    REQUIRE("Inconnu"             == Personne::INCONNU.getNom());
    REQUIRE("Inconnu"             == Personne::INCONNU.getPrenom());
    REQUIRE(Personne::INDETERMINE == Personne::INCONNU.getGenre());
}  

TEST_CASE("Inconnu2") {
    REQUIRE(   Personne::INCONNU  == Personne("Inconnu", "Inconnu", Personne::INDETERMINE));
    REQUIRE( !(Personne::INCONNU  == Personne("", "", Personne::HOMME)));
}  

TEST_CASE("Inconnu3") {
    std::stringstream ss;
    ss << Personne::INCONNU;
    REQUIRE("Inconnu Inconnu [INDETERMINE]" == ss.str() );
} 

TEST_CASE("Super1") {
    Super heros("Superman", Personne("Clark", "Kent", Personne::HOMME));

    REQUIRE ("Superman" == heros.getNom());
    REQUIRE ( true      == heros.estAnonyme()); // C'est le pouvoir des lunettes
    // ça marche, même pour mon avatar !!!
}

TEST_CASE("Anonyme1") {
    Super spider("Spiderman", Personne("Peter", "Parker", Personne::HOMME));
    REQUIRE (true == spider.estAnonyme());
    spider.enregistrer();
    REQUIRE (false == spider.estAnonyme());
    REQUIRE ("Peter"  == spider.getIdentite().getPrenom());
    REQUIRE ("Parker" == spider.getIdentite().getNom());
}

TEST_CASE("Anonyme2") {
    const char * msg = "identite anonyme";
    AnonymeException ie;
    REQUIRE( strcmp(msg, ie.what() );
} 

TEST_CASE("Anonyme3") {
    Super spider("Spiderman", Personne("Peter", "Parker", Personne::HOMME));
    CHECK_THROWS_AS  ( spider.getIdentite(), AnonymeException);
    REQUIRE_THROWS_AS( spider.getIdentite(), std::exception);

}

TEST_CASE("Super2") {
    Super venom("Venom", Personne("Peter", "Parker", Personne::HOMME));
    venom.enregistrer();
    venom.setIdentite(Personne("Eddie", "Brock"));
    CHECK_THROWS_AS( venom.getIdentite(), std::exception);
    venom.enregistrer();
    CHECK( "Brock"  == venom.getIdentite().getNom() );
    CHECK( "Parker" != venom.getIdentite().getNom() );
}
*/


/*
// Test qui ne doit pas compiler
// Sera testé si les tests sur les capacités sont réussis
TEST_CASE("Capacite0") {
    Capacite c("aucune", 0);
} 
*/

/*
TEST_CASE("Materiel") {
    Materiel armure("MarkI", 5);
    std::stringstream log;
    armure.actionner(log); 
    REQUIRE ( "MarkI [5] en action" == log.str()); 
} 

TEST_CASE("Physique") {
    Physique force("force", 3);
    std::stringstream log;
    force.exercer(log); 
    REQUIRE ( "force [3]" == log.str()); 
} 

TEST_CASE("Psychique") {
    Psychique tp("telepathie", 7);
    std::stringstream log;
    tp.penser(log); 
    REQUIRE ( "telepathie [7]" == log.str()); 
}

TEST_CASE("Capacite1") {
    std::stringstream log;
    // pas taper ...
    Capacite * capa = new Materiel("Mjolnir", 70);
    capa->utiliser(log);
    REQUIRE ( "Mjolnir [70] en action" == log.str());
    delete capa;

    log.str(""); // vide le buffer log
    capa = new Psychique("telekinesie", 12);
    capa->utiliser(log);
    REQUIRE ( "telekinesie [12]" == log.str()); 
    delete capa;
} 

TEST_CASE("Capacite2") {
    Super wolf("wolferine", Personne("James", "Howlett")); // Le vrai nom de Logan
    wolf.ajouter(new Physique("regeneration", 50));
    wolf.ajouter(new Materiel("squelette adamantium", 50));
    REQUIRE(100 == wolf.getNiveau());

    Super rien = wolf;
    wolf.ajouter(new Physique("force", 10));

    REQUIRE(110 == wolf.getNiveau());
    REQUIRE(100 == rien.getNiveau());
}

TEST_CASE("Capacite3") {
    Capacite * m1 = new Materiel("Anneau", 5);
    Capacite * m2 = m1->clone();
    Materiel * m3 = ((Materiel *)m1)->clone();

    REQUIRE( m1->getNom() == m2->getNom() );
    REQUIRE( m1->getNom() == m3->getNom() );
    
    delete m1;
    delete m2;
    delete m3;
}

TEST_CASE("Super3") {
    Super iron("Iron Man", Personne("Tony", "Starck"));
    iron.enregistrer();
    iron.ajouter(new Materiel("armure", 10));

    Super warm   = iron;
    REQUIRE ( false == warm.estAnonyme() );    

    warm.setNom("War Machine");    
    warm.setIdentite(Personne("James Rupert", "Rhodes"));
    warm.enregistrer();

    REQUIRE ( iron.getNom() != warm.getNom() );
    REQUIRE ( iron.getIdentite().getNom   () != warm.getIdentite().getNom   () );
    REQUIRE ( iron.getIdentite().getPrenom() != warm.getIdentite().getPrenom() );
    REQUIRE ( iron.getIdentite().getGenre () == warm.getIdentite().getGenre () );
    REQUIRE ( 10 == warm.getNiveau());
}

TEST_CASE("Equipe") {
    Equipe vengeurs("vengeurs");
    REQUIRE ( 0 == vengeurs.getNombre());

    Super * antz = new Super("Homme-Fourmi", Personne("Hank", "Pym"));
    
    antz->ajouter(new Physique ("changement taille",  10));
    antz->ajouter(new Psychique("telepathie insecte", 10));
    antz->ajouter(new Physique ("flux energie",       10));

    vengeurs.ajouter(antz);
    REQUIRE ( 1 == vengeurs.getNombre());

    Super * wasp = new Super(*antz);
    wasp->setNom("La guepe");
    wasp->setIdentite(Personne("Janet", "Van Dyne", Personne::FEMME));
    wasp->ajouter(new Physique("vol", 20));
    
    vengeurs.ajouter(wasp);
    REQUIRE ( 2 == vengeurs.getNombre());

    REQUIRE( 30 == antz->getNiveau());
    REQUIRE( 50 == wasp->getNiveau());

    Super * hulk = new Super("Hulk", Personne("Robert Bruce", "Banner"));
    hulk->ajouter(new Physique("force", 500));
    vengeurs.ajouter(hulk);
    REQUIRE ( 3 == vengeurs.getNombre());


    Super * iron = new Super ("Iron Man", Personne("Tony", "Starck"));
    iron->ajouter(new Materiel("MarkIV", 300));
    vengeurs.ajouter(iron);
    REQUIRE (   4 == vengeurs.getNombre());
    REQUIRE ( 880 == vengeurs.getNiveau());
    // Il manque Thor Odinsen et Steve Rogers pour l'équipe originelle :-)
}
*/
