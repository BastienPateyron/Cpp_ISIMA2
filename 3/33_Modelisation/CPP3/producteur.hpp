#ifndef __CPP3_PRODUCTEUR_HPP__
#define __CPP3_PRODUCTEUR_HPP__

#include <iostream>

class Producteur {
  private:
    int travail;

  public:
    virtual int  getTravail();
    virtual void setTravail(int);
    bool produire(int quantite, std::string nom);
};

#endif
