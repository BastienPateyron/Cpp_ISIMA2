#ifndef __CPP3_TESTS_HPP__
#define __CPP3_TESTS_HPP__


#include <gtest/gtest.h>
#include "producteur.hpp"
#include "statisticien.hpp"
#include <fstream>
#include <iostream>

/* Instanciation d'un Producteur et vérification que travail est nulle */
TEST(Producteur, Initialisation) {
	Producteur p;
	ASSERT_EQ(0, p.getTravail());
}

/* Verification de travail après quelques appels à produire() */
/*
TEST(Producteur, Travail) {
	Producteur p;
	p.produire(10, "test01.txt");
	ASSERT_EQ( 1, p.getTravail());
}
*/
/* Verification du contenu de la production */
/*
TEST(Producteur, Travail2) {
	Producteur p;
	p.produire(10, "test01.txt");
	p.produire(10, "test01.txt");
	p.produire(10, "test01.txt");
	ASSERT_EQ(3, p.getTravail());
}
*/
/*
TEST(Producteur, Travail3) {

    const int         DEMANDE    = 10;
    const std::string NOM_FICHIER("test01.txt");
    int               lecture, i;
    Producteur        p; 


	p.produire(DEMANDE, NOM_FICHIER.c_str());

    std::ifstream fichier(NOM_FICHIER.c_str());

    ASSERT_TRUE(fichier.is_open());

    if (!fichier.eof()) {
		fichier >> lecture; 
		EXPECT_EQ(DEMANDE, lecture);
		for (i = 0; i < DEMANDE; ++i) {
			fichier >> lecture;
            EXPECT_EQ(i+1, lecture);
		}
    
    EXPECT_EQ(i, DEMANDE);
    
    fichier.close();

	ASSERT_EQ(p.getTravail(), 1);
}
}
*/
/*
TEST(Statisticien, Initialisation) {
  Statisticien p;
  ASSERT_FALSE(p.aCalcule());
}
*/
#endif