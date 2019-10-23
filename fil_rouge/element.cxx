/* nom de fichier un peu bizarre pour ne pas entrer dans un eventuel makefile*/
/* renommer en cpp*/

#include<iostream>
#include<cmath>
#include<cstdlib>

class Element {
   double x, y;
   bool ajour;
   double distance;

   void calculerDistance();

 public:
   Element();
   Element(double, double);  
   void setX(double);
   void setY(double);
   double getDistance();
   double getDistance2();
};

Element::Element():x(.0), y(.0), ajour(true), distance(.0){
} 

Element::Element(double px, double py):x(px), y(py), ajour(false), distance(.0) {
}

void Element::calculerDistance() {
	distance = sqrt(x*x+y*y);
	ajour = true;
}

void Element::setX(double px) {
	x = px;
	ajour = false;
}

void Element::setY(double py) {
	y = py;
	ajour = false;
}

double Element::getDistance() {
   if (!ajour)
   	calculerDistance();
   return distance;
} 

double Element::getDistance2() {
   calculerDistance();
   return distance;
} 

int main(int, char**) {
    Element e(10.0, 100.0);

    for(int i=0;i<100000; ++i) {

       if (!(random() % 7) ) {
          e.setX((double)rand());
          e.setY((double)rand());
       }
       std::cout << e.getDistance() << " "; 
       std::cout << e.getDistance2() << std::endl; 
    }
	return 0;
} 
