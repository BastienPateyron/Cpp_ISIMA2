//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <fstream>
#include <cstdlib>

int main( int argc, char* argv[] ) {
  std::string s;
  std::stringstream ss;
  ss << getenv("HOME") << "/" << ".identite";
  std::ifstream f1(ss.str().c_str());
  if (!f1.good()) {
  	std::ofstream f2(ss.str().c_str());
  	std::cout << "Saisir votre NOM :";
    std::cin >> s;
    f2 << s << std::endl;
  	std::cout << "Saisir  votre PRENOM:";
  	std::cin >> s;
    f2 << s;
  } else f1.close();

  int result = Catch::Session().run( argc, argv );
  
  return result;
}