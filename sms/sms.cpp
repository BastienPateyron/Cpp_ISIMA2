#include "sms.hpp"


int Message::cle = 0;   // Variable statique


// Telephone
std::string Telephone::getNumero() const {return num;}
void        Telephone::setNumero(std::string num) {this->num = num;}
Telephone::Telephone(std::string num, Reseau * r) : num(num), reseau(r){}
Reseau * Telephone::getReseau() const {return reseau;}
int Telephone::getNbMessages() const {return messages.size();}
void  Telephone::textoter(std::string destinataire, std::string msg)
{
   // Ajout du msg en local
   SMS * texto_local = new SMS(num, destinataire);
   texto_local->setTexte(msg);
   messages.push_back(texto_local);

   // Ajout du msg sur la cible (si elle existe)
   try {
      Telephone & cible = reseau->trouveTel(destinataire);
      SMS * texto_cible = new SMS(num, destinataire);
      texto_cible->setTexte(msg);
      cible.messages.push_back(texto_cible);
   }
   catch(MauvaisNumero const & e) {std::cout << "Mauvais numéro détecté, pas d'envoi !!" << std::endl;};
}

Telephone::~Telephone()
{
   for(
      std::vector<Message *>::iterator it = messages.begin();
      it != messages.end();
      ++it
   ) delete * it;
   
   messages.clear();
}


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

Telephone & Reseau::trouveTel(std::string num)
{
   // Telephone t;
   
   try { return telephones.at(num); }
   catch(const std::exception & e) {throw MauvaisNumero();}
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
std::string SMS::afficher() const {return getTexte();}
std::string SMS::getTexte() const {return texte;}
void          SMS::setTexte(std::string t) { texte = t;}

// Media
Media::~Media() {};
std::string Son::afficher() const {return "[[son]]";}
std::string Video::afficher() const {return "[[video]]";}
std::string Image::afficher() const {return "[[image]]";}

// MMS
MMS::MMS(std::string e, std::string dest, std::string date) : SMS(e, dest, date) {}
MMS::~MMS(){
   for(
      v_media::iterator it = medias.begin();
      it != medias.end();
      it++   
   ) delete (*it);
};

void MMS::joindre(Media const * m) {medias.push_back(m);}
std::string MMS::afficher() const
{

   return std::accumulate(
             medias.begin(),
             medias.end(),
             SMS::afficher(),
             [] (std::string s, Media const * m) { return s += m->afficher();}
          );
}