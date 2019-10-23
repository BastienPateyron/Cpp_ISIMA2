#pragma once

#include <iostream>

using namespace std;


class Bavarde 
{
    // Attributs prives
    int numero;

    // Methodes
    public:
        Bavarde();
        Bavarde(const Bavarde &);
        Bavarde(int);
        ~Bavarde();
        void fonction(Bavarde b);
        int getNumero();
        void afficher();
        static int compteur;
    

}; // On cree une instance nommee 'bizarre' a la volee