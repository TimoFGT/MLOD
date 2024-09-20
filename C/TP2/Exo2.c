#include <stdint.h>
#include <stdlib.h>
#define SIZE 5

 int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);
    return EXIT_SUCCESS;
}

void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]) {
    for (int i=0;i<SIZE+1;i++) {
        for (int j=0;j<SIZE+1;j++) {
            for (int k=0;k<SIZE+1; k++) {
                matriceResultat[i][j] += matrice1[i][k]*matrice2[k][j];
            }
        }
    }
}


 void matrix_print(int64_t matriceResultat[][SIZE]) {
    for (int i=0;i<SIZE+1;i++) {
        for (int j=0;j<SIZE+1;j++) {
            (matriceResultat[i][j]);
        }
    }
 }
