#ifndef __SMS
#define __SMS
#include <iostream>
#include <map>
// #include <algorithm>
#include <numeric>

class Reseau;

class Telephone {
   private:
      std::string num;
      Reseau * r;

   public:
      Telephone();
      Telephone(std::string, Reseau * r = nullptr);
      std::string getNumero() const;
      void setNumero(std::string);
      Reseau * getReseau() const;
};



class Reseau {
   
   typedef std::pair<std::string, Telephone> paire;

   private:
      std::map<std::string, Telephone> telephones;

   public:
      std::string lister() const;
      void ajouter(std::string);
      Telephone & trouveTel(std::string);
};




#endif