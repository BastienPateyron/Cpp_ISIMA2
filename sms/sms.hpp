#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
// #include <algorithm>
#include <numeric>
#include <vector>

class Reseau;
class Message;
class Media;
class MMS;

typedef std::string Str; // Adieu std::string


class Telephone {
   private:
      Str num;
      Reseau * r;
      std::vector<Message *> messages;

   public:
      Telephone(Str = "", Reseau * r = nullptr);
      ~Telephone();
      Str getNumero() const;
      void setNumero(Str);
      Reseau * getReseau() const;
      int getNbMessages() const;
      void textoter(Str, Str);
      void mmser(Str, MMS *);
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
      friend Telephone;

   public:
      Message(Str = "", Str = "", Str = "");
      Message(Message const *);
      virtual ~Message();
      virtual Str afficher() const = 0;
      int getId() const;
      static int getCle();

};


class SMS : public Message {
   private:
      Str texte;

   public:
      SMS(Str = "", Str = "", Str = "");
      SMS(SMS const *);
      Str getTexte() const;
      void setTexte(Str);
      virtual Str afficher() const;
};


class MMS : public SMS {
   private:
      std::vector<Media *> medias;

   public:
      MMS(Str = "", Str = "", Str = "");
      MMS(MMS const *);
      ~MMS();
      Str afficher() const;
      void joindre(Media *);
};



class Media {
   public:
   virtual ~Media();
      virtual Str afficher() const = 0;
};


class Son : public Media {
   public:
      Str afficher() const;
};


class Image : public Media {
   public:
      Str afficher() const;
};


class Video : public Media {
   public:
      Str afficher() const;
};



#endif