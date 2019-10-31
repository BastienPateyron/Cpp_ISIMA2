#include <fstream>
#include <iostream>

#include "catch.hpp"
#include "Bavarde.hpp"


// NOTE : ce test utilise des enum "class"
// il faut donc utiliser un compilateur g++ >= 6.1
// ou activer l'option c++11 du compilateur
// -std=c++11 ou -std=c++0x sur les tres vieux compilateurs

// Les tests ne sont pas exhaustifs, loin de là


/// MES TESTS /////

void test1(Bavarde b) {
  		std::cout << "appel de fonction avec parametre objet et copie" << std::endl;
}

Bavarde test2a() {
  std::cout << "appel de fonction avec retour" << std::endl;
  return Bavarde(5); // creation d'un objet local
} // plus de copie - voir ZZ3

Bavarde test2b() {
  Bavarde b(5); // creation d'un objet local
  std::cout << "appel de fonction avec retour" << std::endl;
  return b;
} // plus de copie - ZZ3

void test3(Bavarde & b) {
  std::cout << "appel de fonction avec référence " << std::endl;
}

void test4(Bavarde *b) {
  std::cout << "appel de fonction avec un pointeur sur un objet" << std::endl;
}

TEST_CASE("Copie", "[Bavarde]")
{
	Bavarde b;
	test1(b);
	test2a();
	test2b();
	test3(b);
  test4(&b);
}


// TEST_CASE("Instanciation", "[Point]")
// {

// 	Point p1;
// 	REQUIRE(p1.getX() == 0);
// 	REQUIRE(p1.getY() == 0);

// 	p1.setX(11);
// 	p1.setY(21);

// 	REQUIRE(p1.getX() == 11);
// 	REQUIRE(p1.getY() == 21);

// 	Point p2(12, 22);

// 	REQUIRE(p2.getX() == 12);
// 	REQUIRE(p2.getY() == 22); // :-)
// }

// TEST_CASE("Origine", "[Point]") {
// 	REQUIRE(ORIGINE.getX() == 0);
// 	REQUIRE(ORIGINE.getY() == 0);
// }


// TEST_CASE("Compteur", "[Forme]") {
//    // Pour être correct, ce test doit etre le premier sur Forme
//    REQUIRE(0 == Forme::prochainId());
//    Forme f1;
//    REQUIRE(0 == f1.getId());
//    REQUIRE(1 ==  Forme::prochainId());	
//    // Verification que la valeur n'est pas decrementee accidentellement.
//    Forme *p = new Forme;
//    REQUIRE(1 == p->getId());
//    delete p;
//    REQUIRE(2 == Forme::prochainId());	
// }

// TEST_CASE("Instanciation1", "[Forme]") {
// 	Forme f1;
// 	REQUIRE(f1.getPoint().getX() == 0);
// 	REQUIRE(f1.getPoint().getY() == 0);
// 	REQUIRE(f1.getCouleur() ==  COULEURS::BLEU);
// }

// TEST_CASE("Instanciation2", "[Forme]") {
// 	Forme f2;
	
// 	f2.setX(15);
// 	f2.setY(25);
// 	f2.setCouleur(COULEURS::VERT);
// 	REQUIRE (f2.getPoint().getX() == 15);
// 	REQUIRE (f2.getPoint().getY() == 25);
// 	REQUIRE (f2.getCouleur() == COULEURS::VERT);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::BLEU);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::ROUGE);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::JAUNE);
// }

// TEST_CASE("Instanciation3", "[Forme]") {
//     // IL N'Y A PAS D'ERREUR DANS LE TEST, CELA DOIT MARCHER	
// 	Forme f2(Point(10,20), COULEURS::ROUGE);
// 	REQUIRE (f2.getPoint().getX() == 10);
// 	REQUIRE (f2.getPoint().getY() == 20);
// 	REQUIRE (f2.getCouleur() == COULEURS::ROUGE);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::BLEU);

// 	f2.getPoint().setX(15);
// 	f2.getPoint().setY(25);
// 	f2.setCouleur(COULEURS::JAUNE);
// 	REQUIRE (f2.getPoint().getX() == 15);
// 	REQUIRE (f2.getPoint().getY() == 25);
// 	REQUIRE (f2.getCouleur() == COULEURS::JAUNE);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::BLEU);
// 	REQUIRE_FALSE (f2.getCouleur() == COULEURS::ROUGE);
// }

// TEST_CASE("BoiteEnglobante", "[Forme]") {
// 	Forme f;
// 	REQUIRE (f.getLargeur() == 0);
// 	REQUIRE (f.getHauteur() == 0);
// }

// TEST_CASE("Cercle", "[Cercle]") {
//    int compteur = Forme::prochainId();
//    Cercle c1;
//    Cercle c2(1, 2, 3);

//    REQUIRE(c1.toString() == "CERCLE 0 0 0.000000 0.000000");
//    REQUIRE(c2.toString() == "CERCLE 1 2 6.000000 6.000000");

//    c2.setRayon(30);
//    REQUIRE(c2.getRayon()   == 30  );
//    REQUIRE(c2.toString()   == "CERCLE 1 2 60.000000 60.000000");
//    REQUIRE(c2.getLargeur() == 60);
//    REQUIRE(c2.getHauteur() == 60);

//    REQUIRE(Forme::prochainId() == (compteur+2) );
// }

// TEST_CASE("Polymorphisme", "[Forme]") {
//    Forme * f1 = new Cercle;
//    Forme * f2 = new Rectangle;

//    REQUIRE(f1->toString() == "CERCLE 0 0 0.000000 0.000000");
//    REQUIRE(f2->toString() == "RECTANGLE 0 0 0.000000 0.000000");

//    delete f1;
//    delete f2;
// }