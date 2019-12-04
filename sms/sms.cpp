#include "sms.hpp"


// Téléphone //
Str Telephone::getNumero() const {return num;}
void Telephone::setNumero(Str n) {num = n;}
Telephone::Telephone(Str n, Reseau * reseau) : num(n), r(reseau) {}
Reseau * Telephone::getReseau() const {return r;}


// Réseau //
Str Reseau::lister() const {
   return std::accumulate(
      telephones.begin(),
      telephones.end(),
      Str(""),
      [] (Str s, paire p) {return s + p.first + '\n';}
   );
}

void Reseau::ajouter(Str num) {telephones.insert(paire(num, Telephone(num, this)));}
Telephone & Reseau::trouveTel(Str num) {
   try {return telephones.at(num);}
   catch(std::exception const & e) {throw MauvaisNumero();}
}

// Exception //
MauvaisNumero::MauvaisNumero() : std::invalid_argument("mauvais numero") {}
// const char * MauvaisNumero::what() { return "mauvais numero"; }


// Message //
Message::Message(Str de, Str a, Str date) : de(de), a(a), date(date) {}
Message::~Message() {};

// SMS //
SMS::SMS(Str de , Str a, Str date) : Message(de, a, date) {}
Str SMS::getTexte() const {return texte;}
void SMS::setTexte(Str t) {texte = t;}
Str SMS::afficher() const {return getTexte();}