#include "sms.hpp"

// Telephone
std::string Telephone::getNumero() const {return num;}
void        Telephone::setNumero(std::string num) {this->num = num;}
Telephone::Telephone() {}
Telephone::Telephone(std::string num) : num(num) {}
bool Telephone::operator<(Telephone const & n) { return num < n.getNumero();}


// Reseau
void Reseau::ajouter(std::string const & num)
{
   telephones.push_back(Telephone(num));
   telephones.sort();
}

std::string Reseau::lister() const
{  
   return std::accumulate(
      telephones.begin(),
      telephones.end(),
      std::string(""),
      [] (std::string s, Telephone const & t) { return s += t.getNumero() + '\n' ;}
   );
}