#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Mere {
  protected:
    string nom;
  public: 
    Mere(string s="pas fourni"):nom(s) {
    }
    
   void methode1() {
       cout << "Nom" << nom << endl;
   }
};
 
class Fille : public Mere {
  private:
    string nom;
  public:
   
  Fille():Mere("noname") {
  }
 
  void methode2() {
      cout << "Afficher2" << nom << endl;
    }
};
 
int main(int, char**) {
   Fille f;
 
   f.methode1();
   f.methode2();
}