#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
// #include <algorithm>
#include <numeric>



class Telephone {
   private:
      std::string num;

   public:
      Telephone();
      Telephone(std::string);
      std::string getNumero() const;
      void setNumero(std::string);
};



class Reseau {
   
   typedef std::pair<std::string, Telephone> paire;

   private:
      std::map<std::string, Telephone> telephones;

   public:
      std::string lister() const;
      void ajouter(std::string);
};




#endif