#include "sms.hpp"


int Message::cle = 0;   // Variable statique


// Telephone
std::string Telephone::getNumero() const {return num;}
void        Telephone::setNumero(std::string num) {this->num = num;}
Telephone::Telephone(std::string num, Reseau * r) : num(num), reseau(r){}
Reseau * Telephone::getReseau() const {return reseau;}
int Telephone::getNbMessages() const {return messages.size();}


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

// Message
Message::Message(std::string e, std::string dest, std::string date) :
   expediteur(e),
   destinataire(dest),
   date(date),
   id(Message::cle++)
   {}

Message::~Message() {Message::cle--;}

int Message::getId()  const {return id;}
int Message::getCle()       {return Message::cle;}


// SMS
SMS::SMS(std::string e, std::string dest, std::string date) : Message(e, dest, date) {} // Devrait appeler moman ??
SMS::~SMS() {}
std::string & SMS::afficher() {return getTexte();}
std::string & SMS::getTexte() {return texte;}
void          SMS::setTexte(std::string t) { texte = t;}