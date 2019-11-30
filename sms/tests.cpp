#include "catch.hpp"
#include "sms.hpp"
#include <cstring>



TEST_CASE("telephone1a") {
/* Telephone iphone;
 const char * isima = "0473405000";

 CHECK( "" == iphone.getNumero());
 iphone.setNumero(isima);
 CHECK( isima == iphone.getNumero()); */
}


/*
TEST_CASE("telephone1b") {
 std::string loic = "0473405042";
 Telephone   iphone(loic);

 CHECK( loic == iphone.getNumero());
}

TEST_CASE("telephone2") {
 const Telephone iphone("0473449520");

 CHECK( "0473449520" == iphone.getNumero());
}

TEST_CASE("Reseau1") {
 Reseau r;
 CHECK ("" == r.lister());

 r.ajouter("0473405000");
 CHECK ("0473405000\n" == r.lister());
 r.ajouter("0473407632");
 CHECK ("0473405000\n0473407632\n" == r.lister());
}

TEST_CASE("Reseau2") {
 Reseau r;
 CHECK ("" == r.lister());

 r.ajouter("0473405000");
 CHECK ("0473405000\n" == r.lister());
 r.ajouter("0473407632");
 CHECK ("0473405000\n0473407632\n" == r.lister());
 r.ajouter("0473405042");
 CHECK ("0473405000\n0473405042\n0473407632\n" == r.lister());
}

// C'est bien pourri mais permet d'initialiser r
#define MON_RESEAU \
Reseau r;\
r.ajouter("0473405000");\
r.ajouter("0473405033");\
r.ajouter("0473405042");\
r.ajouter("0473407632")

TEST_CASE("Reseau3") {
 MON_RESEAU;

 CHECK("0473405042" == r.trouveTel("0473405042").getNumero());
 CHECK(&r           == r.trouveTel("0473405042").getReseau());
}

TEST_CASE("Reseau4") {
 MON_RESEAU;

 CHECK_THROWS_AS("0473405070" == r.trouveTel("0473405070").getNumero(), std::invalid_argument);
}

TEST_CASE("Reseau5") {
  MauvaisNumero e;

  CHECK(strcmp("mauvais numero", e.what()) == 0 );
}

TEST_CASE("Reseau6") {
  MON_RESEAU;

  CHECK_THROWS_AS("0473405070" == r.trouveTel("0473405070").getNumero(), MauvaisNumero);
}

TEST_CASE("Telephone3") {
 const Telephone t;

 CHECK( 0 == t.getReseau());
}

TEST_CASE("SMS1") {
	SMS sms("0473405044", "0473405042", "20171207");
	sms.setTexte("Examen en cours");
	CHECK("Examen en cours" == sms.getTexte());
	CHECK("Examen en cours" == sms.afficher());
} */

/*
TEST_CASE("Message0") {
   Message m;
   // si ca compile, c'est perdu ...
} */

/*
TEST_CASE("Message1") {
 int nb = Message::getCle();
 Message * sms1 = new SMS("", "", "");
 CHECK ( nb     == sms1->getId() );
 CHECK ( (nb+1) == Message::getCle() );
 SMS sms2("", "", "");
 CHECK ( (nb+1) == sms2.getId() );
 CHECK ( (nb+2) == SMS::getCle() );

 delete sms1;
}

TEST_CASE("Telephone4") {
	const Telephone t;

  CHECK( 0 == t.getNbMessages());
}

TEST_CASE("SMS2") {
	MON_RESEAU;

  Telephone * de = & r.trouveTel("0473405042");
  Telephone * a  = & r.trouveTel("0473407632");

  CHECK(0 == de->getNbMessages());
  CHECK(0 ==  a->getNbMessages());

    // créer et envoyer un SMS à un numéro de téléphone
  de->textoter("0473407632", "Examen en cours");

  CHECK(1 == de->getNbMessages());
  CHECK(1 ==  a->getNbMessages());

}

TEST_CASE("SMS3") {
	MON_RESEAU;

  Telephone * de = & r.trouveTel("0473405042");

  CHECK(0 == de->getNbMessages());

  de->textoter("0473406666", "Info mal orientee");

  CHECK(1 == de->getNbMessages());

}

TEST_CASE("Media") {
	Media * m1 = new Image;
	CHECK( "[[image]]" == m1->afficher() );
	delete m1;
	Media * m2 = new Son;
	CHECK( "[[son]]" == m2->afficher() );
	delete m2;
	Media * m3 = new Video;
	CHECK( "[[video]]" == m3->afficher() );
	delete m3;
}

TEST_CASE("MMS1") {
	MMS * m1 = new MMS("", "", "");
  CHECK("" == m1->afficher());

  m1->joindre(new Image);
  CHECK("[[image]]" == m1->afficher());    
  m1->setTexte("essai");
  CHECK("essai[[image]]" == m1->afficher());    
  m1->joindre(new Son);
  CHECK("essai[[image]][[son]]" == m1->afficher());    
  m1->joindre(new Video);
  CHECK("essai[[image]][[son]][[video]]" == m1->afficher());  

  delete m1;  
}

TEST_CASE("MMS2") {
	MMS * m1 = new MMS("", "", "");
  CHECK("" == m1->afficher());
  m1->joindre(new Video);

  SMS * m2 = m1;
  m2->setTexte("exam");
  CHECK("exam[[video]]" == m2->afficher());    

  Message * m3 = m1;
  CHECK("exam[[video]]" == m3->afficher());    

  delete m3;
    // espace memoire correctement libere ?    
}

TEST_CASE("MMS3") {
	MON_RESEAU;

  Telephone * de = & r.trouveTel("0473405042");
  Telephone * a  = & r.trouveTel("0473407632");

  CHECK(0 == de->getNbMessages());
  CHECK(0 ==  a->getNbMessages());

  MMS* mms = new MMS("", "", "");
  mms->joindre(new Video);

  de->mmser("0473407632", mms);

  CHECK("0473405042" == mms->getDe());
  CHECK("0473407632" == mms->getA());    

  CHECK(1 == de->getNbMessages());
  CHECK(1 ==  a->getNbMessages());

} */
