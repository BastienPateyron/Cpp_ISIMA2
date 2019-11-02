#include "catch.hpp"
#include <cstring>
#include <sstream> // a mettre en commentaire 
#include "Chaine.hpp"

TEST_CASE("defaut","Constructeur par defaut") {
   Chaine c;
   CHECK( -1 == c.getCapacite());
   CHECK(  0 == c.c_str()); // 0, NULL, ou nullptr
}

TEST_CASE("Verification des const sur les accesseurs") {
   const Chaine c;   // Echec compilation sinon
   CHECK( -1 == c.getCapacite());
   CHECK(  0 == c.c_str()); // 0, NULL, ou nullptr
}

TEST_CASE("Constructeur par chaine C") {
	char  source []= "rien";
    Chaine c1(source);
    CHECK( (signed)strlen(source) == c1.getCapacite() );
    CHECK( 0 == strcmp(source, c1.c_str()) ); 

    Chaine c2 = "";
    CHECK( 0 == c2.getCapacite() );
    CHECK( 0 == strcmp("", c2.c_str())); 

    // Verifier que la liberation memoire est bien faite
}

TEST_CASE("Constructeur avec capacite") {
    Chaine c1(6);
    CHECK( 6 == c1.getCapacite());
    CHECK( 0 == strlen(c1.c_str())); 

    // Verifier que la liberation memoire est bien faite
}

TEST_CASE("Constructeur de copie") {
    Chaine s1(10);   // une chaine vide
    Chaine s2 = s1;  // une autre chaine vide
    
    CHECK( s1.getCapacite() == s2.getCapacite());
    // tous les problemes vont venir de la
    // j'ai converti en void * uniquement pour l'affichage de catch
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));
}

TEST_CASE("methode afficher") {
	const char * original = "une chaine a tester";
    const char * copie    = "chaine d'affichage par copie et reference -- ";
    const Chaine c1(original);
    const Chaine c2(copie);

    std::stringstream ss;
    
    c1.afficher(); // on verifie juste que ca compile
    c1.afficher(ss);
    c1.afficherParValeur(c2);
    c1.afficherParReference(c2);

    std::cout << ss.str() << std::endl;
    CHECK( ss.str() == original); // test de std::string :-)
}

/*
TEST_CASE("operateur d'affectation") {
	Chaine s1("une premiere chaine");
    Chaine s2("une deuxieme chaine plus longue que la premiere");
    
    s1 = s2;

    CHECK( s1.getCapacite() == s2.getCapacite()); 
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));

    s1 = s1; // est ce que cela va survivre a l execution ?
}*/

/*
TEST_CASE("Surcharge <<") {
	const char * chaine = "une nouvelle surcharge";
	Chaine s(chaine);
    std::stringstream ss;
    // ss << s;  // :-)

    CHECK( ss.str() == chaine ); //  test de std::string, again :-))
}
*/