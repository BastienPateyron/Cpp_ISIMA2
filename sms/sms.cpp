#include "sms.hpp"


// Téléphone //
Str Telephone::getNumero() const {return num;}
void Telephone::setNumero(Str n) {num = n;}
Telephone::Telephone(Str n, Reseau * reseau) : num(n), r(reseau) {}
Telephone::~Telephone() {
   for(
      std::vector<Message *>::iterator it = messages.begin();
      it != messages.end();
      it++
   ) delete *it;
   messages.clear();
}
Reseau * Telephone::getReseau() const {return r;}
int Telephone::getNbMessages() const {return messages.size();}
void Telephone::textoter(Str a, Str txt) {
   // Stocker msg en local
   
   SMS * local = new SMS(num, a);
   local->setTexte(txt);
   messages.push_back(local);
   
   // Stocker msg à distance
   try {r->trouveTel(a).messages.push_back(new SMS(local));} // Copie du SMS local
   catch(MauvaisNumero const & e) {}
}

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
int Message::cle = 0;
Message::Message(Str de, Str a, Str date) : de(de), a(a), date(date), id(Message::cle++) {}
Message::Message(Message const * m) : Message(m->de, m->a, m->date) {}
Message::~Message() {};
int Message::getId() const {return id;}
int Message::getCle()  {return Message::cle;}


// SMS //
SMS::SMS(Str de , Str a, Str date) : Message(de, a, date) {}
SMS::SMS(SMS const * sms) : Message(sms) {texte = sms->texte;}
Str SMS::getTexte() const {return texte;}
void SMS::setTexte(Str t) {texte = t;}
Str SMS::afficher() const {return getTexte();}


// MMS //
MMS::MMS(Str de , Str a, Str date) : SMS(de, a, date) {}
MMS::~MMS() {
   for(
      std::vector<Media *>::iterator it = medias.begin();
      it != medias.end();
      it++
   ) delete *it;

   medias.clear();
}
Str MMS::afficher() const {
   return std::accumulate(
      medias.begin(),
      medias.end(),
      getTexte(),
      [] (Str s, Media * m) { return s += m->afficher();}
   );
}
void MMS::joindre(Media * m) {medias.push_back(m);}


// Media //
Media::~Media() {}

// Son //
Str Son::afficher() const {return "[[son]]";}

// Image //
Str Image::afficher() const {return "[[image]]";}

// Video //
Str Video::afficher() const {return "[[video]]";}
