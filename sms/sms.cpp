#include "sms.hpp"

// Telephone
std::string Telephone::getNumero() const {return num;}
void        Telephone::setNumero(std::string num) {this->num = num;}
Telephone::Telephone() {}
Telephone::Telephone(std::string num) : num(num) {}
Telephone::Telephone(std::string num, Reseau * r) : num(num), reseau(r) {}
// bool     Telephone::operator<(Telephone const & n) { return num < n.getNumero();}
Reseau * Telephone::getReseau() const {return reseau;}


// Reseau
void Reseau::ajouter(std::string num)
{
   telephones.insert( paire(num, Telephone(num, this)));
   // telephones.sort();
}

std::string Reseau::lister() const
{  
   return std::accumulate(
      telephones.begin(),
      telephones.end(),
      std::string(""),
      [] (std::string s, paire p) { return s += p.second.getNumero() + '\n' ;}
   );
}

Telephone Reseau::trouveTel(std::string num)
{
   Telephone t;
   
   try {t = telephones.at(num);}
   catch(const std::exception & e) {throw MauvaisNumero();}
   return t;
}

// Exception
MauvaisNumero::MauvaisNumero() : std::invalid_argument("mauvais numero") {}