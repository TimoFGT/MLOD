#include <stdio.h>
#include <stdlib.h>

int* repeat(int values[], int coeffs[], int tailleCommuneDesTableaux) {

    int tailleTableauFinale=0;

    // Calcul de la taille du tableau final
    for(int k=0;k<tailleCommuneDesTableaux+1;k++) {
        tailleTableauFinale = tailleTableauFinale + coeffs[k];
    }

    int* resultat = (int*)malloc(tailleTableauFinale * sizeof(int));

    // Construction du tableau final
    for(int i=0;i<tailleCommuneDesTableaux;i++) {
        for(int j=0; j<coeffs[i];j++) {
            resultat[i+j]=values[i];
        }
    }
    return resultat;
}

int main() {
    int t1[] = {1,2,4};
    int t2[] = {10,3,8};
    int taille = 3;
    int* testFonction = repeat(t1, t2, taille);
    free(testFonction);
}