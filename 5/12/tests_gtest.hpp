#ifndef __TESTS_TESTS_HPP__
#define __TESTS_TESTS_HPP__

/* tests avec google test */
/* COULEURS est une énumération classique */


#include <fstream>
#include <iostream>
#include <gtest/gtest.h>
#include "Point.hpp"
#include "Rectangle.hpp"

TEST(Point, Instanciation) {
	Point p1;
	ASSERT_EQ(p1.getX(), 0);
	ASSERT_EQ(p1.getY(), 0);
	
    p1.setX(11);
    p1.setY(21);

    ASSERT_EQ(p1.getX(), 11);
	ASSERT_EQ(p1.getY(), 21);

	Point p2(12, 22);

	ASSERT_EQ(p2.getX(), 12);
	ASSERT_EQ(p2.getY(),  0);  // :-)
}
/*
TEST(Point, Origine) {
	ASSERT_EQ(ORIGINE.getX(), 0);
	ASSERT_EQ(ORIGINE.getY(), 0);
} */

/*
TEST(Forme, Compteur) {
   // Pour être correct, ce test doit etre le premier sur Forme
   ASSERT_EQ(0, Forme::prochainId());
   Forme f1;
   ASSERT_EQ(0, f1.getId());
   ASSERT_EQ(1, Forme::prochainId());	
   // Verification que la valeur n'est pas decrementee accidentellement.
   Forme *p = new Forme;
   ASSERT_EQ(1, p->getId());
   delete p;
   ASSERT_EQ(2, Forme::prochainId());	
}*/
/*

TEST(Forme, Instanciation1) {
	Forme f1;
	ASSERT_EQ(f1.getPoint().getX(), 0);
	ASSERT_EQ(f1.getPoint().getY(), 0);
	ASSERT_EQ(f1.getCouleur(), BLEU);
}
*/
/*
TEST(Forme, Instanciation2) {	
	Forme f2;
	
	f2.setX(15); // pas une erreur
	f2.setY(25);
	f2.setCouleur(VERT);
	ASSERT_EQ (f2.getPoint().getX(), 15);
	ASSERT_EQ (f2.getPoint().getY(), 25);
	ASSERT_EQ (f2.getCouleur(), VERT);
	ASSERT_NE (f2.getCouleur(), BLEU);
	ASSERT_NE (f2.getCouleur(), ROUGE);
	ASSERT_NE (f2.getCouleur(), JAUNE);
}
*/
/*
TEST(Forme, Instanciation3) {
    // IL N'Y A PAS D'ERREUR DANS LE TEST, CELA DOIT MARCHER	
	Forme f2(Point(10,20), ROUGE);
	ASSERT_EQ (f2.getPoint().getX(), 10);
	ASSERT_EQ (f2.getPoint().getY(), 20);
	ASSERT_EQ (f2.getCouleur(), ROUGE);
	ASSERT_NE (f2.getCouleur(), BLEU);

	f2.getPoint().setX(15);
	f2.getPoint().setY(25);
	f2.setCouleur(JAUNE);
	ASSERT_EQ (f2.getPoint().getX(), 15);
	ASSERT_EQ (f2.getPoint().getY(), 25);
	ASSERT_EQ (f2.getCouleur(), JAUNE);
	ASSERT_NE (f2.getCouleur(), BLEU);
	ASSERT_NE (f2.getCouleur(), ROUGE);
}
*/
/*
TEST(Forme, BoiteEnglobante) {
	Forme f;
	ASSERT_EQ (f.getLargeur(), 0);
	ASSERT_EQ (f.getHauteur(), 0);
}

*/

#endif
