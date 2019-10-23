#include <cstdio>


/* on peut utiliser le mot clé const pour définir la taille d'un tableau statique en C++ */
const int TAILLE = 10;

int main(int, char **) {
  int tab[TAILLE];

  for (int i=0; i < TAILLE; ++i) {
    tab[i] = i %2;
    printf(" %d ", tab[i]);
  }

  printf("\n");

  return TAILLE;
}