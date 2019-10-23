#include <iostream>
#include <string>


class Mere {
  protected:
    std::string nom;
  public:
    Mere(std::string s="pas fourni"):nom(s) {
    }

   virtual void methode1() {
       std::cout << "Nom: " << nom << std::endl;
   }
};

class Fille : public Mere {
  private:
    std::string nom;
  public:

    Fille():Mere("noname") {
    }

    void methode2() {
        std::cout << "Afficher2" << nom << std::endl;
    }
    
    virtual void methode1() {
        std::cout << "Nom: " << nom << std::endl;
    } // DAFUK ? Question 1.2 fin
};

int main(int, char**) {
   Fille f;

   f.methode1();
   f.methode2();
}