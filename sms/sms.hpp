#ifndef __SMS
#define __SMS
#include <iostream>
#include <list>
#include <numeric>

class Telephone
{
   private:
      std::string num;
   
   public:
      Telephone();
      Telephone(std::string);
      std::string getNumero() const;
      void        setNumero(std::string);

      bool operator<(Telephone const &);
};



class Reseau
{
   private:
      std::list<Telephone> telephones;
   
   public:
      void        ajouter(std::string const &);
      std::string lister() const;         
};



#endif