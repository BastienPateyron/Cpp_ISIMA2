#include "sms.hpp"


// Téléphone //
std::string Telephone::getNumero() const {return num;}
void Telephone::setNumero(std::string n) {num = n;}
Telephone::Telephone(std::string n, Reseau * reseau) : num(n), r(reseau) {}
Reseau * Telephone::getReseau() const {return r;}


// Réseau //
std::string Reseau::lister() const {
   return std::accumulate(
      telephones.begin(),
      telephones.end(),
      std::string(""),
      [] (std::string s, paire p) {return s + p.first + '\n';}
   );
}

void Reseau::ajouter(std::string num) {telephones.insert(paire(num, Telephone(num, this)));}
Telephone & Reseau::trouveTel(std::string num) {
   try {return telephones.at(num);}
   catch(std::exception const & e) {throw MauvaisNumero();}
}

// Exception //
MauvaisNumero::MauvaisNumero() : std::invalid_argument("mauvais numero") {}
// const char * MauvaisNumero::what() { return "mauvais numero"; }