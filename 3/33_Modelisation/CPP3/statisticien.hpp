#ifndef __CPP3_STATISTICIEN_HPP__
#define __CPP3_STATISTICIEN_HPP__

#include <iostream>

class Statisticien {
	
  public:
    bool calcul;
    double somme;
    double moyenne;
    
  public:
    Statisticien();
    void acquerir(std::string nom);

};

#endif