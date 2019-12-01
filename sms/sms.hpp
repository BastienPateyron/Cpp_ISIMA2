#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
#include <numeric>

class Reseau;
// class Telephone;


class Telephone
{
   private:
      std::string num;
      Reseau * reseau;
   
   public:
      Telephone(std::string = "", Reseau * r = nullptr);
      std::string getNumero() const;
      void        setNumero(std::string);
      Reseau *    getReseau() const;

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
      Telephone   trouveTel(std::string);    

};

class MauvaisNumero : public std::invalid_argument
{
   public:
      MauvaisNumero();
};



#endif