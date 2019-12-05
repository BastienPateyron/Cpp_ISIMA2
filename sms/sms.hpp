#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
// #include <algorithm>
#include <numeric>

class Reseau;

typedef std::string Str; // Adieu std::string


class Telephone {
   private:
      Str num;
      Reseau * r;
      std::vector<Message> messages;

   public:
      Telephone(Str = "", Reseau * r = nullptr);
      Str getNumero() const;
      void setNumero(Str);
      Reseau * getReseau() const;
      int getNbMessages() const;
};


class Reseau {
   
   typedef std::pair<Str, Telephone> paire;

   private:
      std::map<Str, Telephone> telephones;

   public:
      Str lister() const;
      void ajouter(Str);
      Telephone & trouveTel(Str);
};


// Exception //
class MauvaisNumero : public std::invalid_argument {
   public:
      MauvaisNumero();
      // const char * what();
};



class Message {
   private:
      Str de;
      Str a;
      Str date;
      int id;
      static int cle;

   public:
      Message(Str = "", Str = "", Str = "");
      virtual ~Message();
      virtual Str afficher() const = 0;
      int getId() const;
      static int getCle();

};


class SMS : public Message {
   private:
      Str texte;

   public:
      SMS(Str, Str, Str);
      Str getTexte() const;
      void setTexte(Str);
      virtual Str afficher() const;
};

#endif