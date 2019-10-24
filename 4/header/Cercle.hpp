#ifndef __CPP4__CERCLE_HPP__
#define __CPP4__CERCLE_HPP__

#include "Forme.hpp"
#include <string>

class Cercle : public Forme
{
  private:
    // int x, y, w, h;
  
  public:
    // int ordre; 

  public:
    Cercle();
    Cercle(int x, int y, int w, int h);
    Cercle(int x, int y, int rayon);
    
    double      getRayon()          const;
    std::string toString()          const override;
    void        setRayon(double r);
};

#endif
