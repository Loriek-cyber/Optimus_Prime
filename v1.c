#include <stdio.h>
#include <stdlib.h>

// Funzione per stampare la matrice
void printMatrix(int **vettore, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            printf("%d ", vettore[i][k]);
        }
        printf("\n");
    }
}

void printNumbers() {
    int k = 1;
    while (1) {
        int num = 6 * k - 1;
        printf("%d ", num);
        k++;
    }
}


int main(void){
    
}