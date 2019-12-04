#include "sms.hpp"


// Téléphone //
std::string Telephone::getNumero() const {return num;}
void Telephone::setNumero(std::string n) {num = n;}
Telephone::Telephone() {}
Telephone::Telephone(std::string n) : num(n) {}


// Réseau //
std::string Reseau::lister() const {
   return std::accumulate(
      telephones.begin(),
      telephones.end(),
      std::string(""),
      [] (std::string s, paire p) {return s + p.first + '\n';}
   );
}

void Reseau::ajouter(std::string num) {telephones.insert(paire(num, Telephone(num)));}