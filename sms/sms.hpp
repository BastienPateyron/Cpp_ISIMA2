#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

class Reseau;
class Message;
// class Telephone;


class Telephone
{
   private:
      std::string             num;
      Reseau *                reseau;
      std::vector<Message *>  messages;
      
   public:
      Telephone(std::string = "", Reseau * r = nullptr);
      ~Telephone();
      std::string getNumero() const;
      void        setNumero(std::string);
      Reseau *    getReseau() const;
      int         getNbMessages() const;
      void        textoter(std::string destinataire, std::string msg);

      // bool operator<(Telephone const &);
};



class Reseau
{
   private:
      std::map<std::string, Telephone> telephones;
      typedef std::pair<std::string, Telephone> paire;     
   
   public:
      void        ajouter(std::string);
      std::string lister() const;
      Telephone & trouveTel(std::string);    

};

class MauvaisNumero : public std::invalid_argument
{
   public:
      MauvaisNumero();
};


class Message
{
   private:
      std::string expediteur;      
      std::string destinataire;
      std::string date;
      int         id;
      static int  cle;

   public:
      Message(std::string = "", std::string = "", std::string = "");
      virtual ~Message();
      virtual std::string afficher() const = 0;
      int        getId()  const;
      static int getCle();      
};

class SMS : public Message
{
   private:
      std::string texte;
   
   public:
      SMS(std::string = "", std::string = "", std::string = "");
      ~SMS();
      std::string afficher() const;
      std::string getTexte() const;
      void        setTexte(std::string);
   
};

class Media {

   public:
      virtual std::string afficher() const = 0;
      virtual ~Media();
};

class Son : public Media {

   public:
      virtual std::string afficher() const;   
};

class Video : public Media {

   public:
      virtual std::string afficher() const;
};

class Image : public Media {

   public:
      virtual std::string afficher() const;
};

class MMS : public SMS
{
   typedef std::vector<Media const *> v_media;

   private:
      v_media medias;

   public:
      MMS(std::string e, std::string dest, std::string date);
      ~MMS();
      void joindre(Media const *);
      std::string afficher() const;
};

#endif