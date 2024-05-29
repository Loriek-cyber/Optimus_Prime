#include <stdio.h>
#include <stdlib.h>


//Definizioni Globali di Matrici

int **Matrix;
int **Matrix2;
int **Matrix3;

int Calculate(int x, int y,int rule){
    x++;
    y++;
    switch (rule)
    {
    case 1:
        return (6*x*y)+x-y;
    case 2:
        return (6*x*y)+x+y;
    case 3:
        return (6*x*y)+x+y;
    }
}

void GenMatrix(int k,int rule){
    Matrix = ( int **)malloc(k * sizeof(int *));
    int value;
    for (int i = 0; i < k; i++) {
        Matrix[i] = calloc(sizeof(int) , (k - i)+1);
        for (int j = 0; j < k - i; j++) {
            value =Calculate(i, j, rule);
            if(value<k){
            Matrix[i][j] =value;
            }
            else    
                break;
        }
    }
}


// Funzione per stampare la matrice
void printMatrix(int **vettore, int n, int m) {
    int control;
    for (int i = 0; i < n; i++) {
        control=0;
        for (int k = 0; k < m; k++) {
            control=1;
            if(vettore[i][k]==0)
                break;
            printf("%d ", vettore[i][k]);
        }
        if(control==0)
            break;
        else
            printf("\n");
    }
}



void merge(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;

    // Unisci i due vettori ordinati
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Copia i rimanenti elementi di a[], se ce ne sono
    while (i < n) {
        c[k++] = a[i++];
    }

    // Copia i rimanenti elementi di b[], se ce ne sono
    while (j < m) {
        c[k++] = b[j++];
    }
}


int *SIXkMinus1(int n) {
    int *vettore = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        vettore[i] = (6*(i+1))-1;
    }
    return vettore;
}

int *SIXkPlus1(int n){
    int *vettore = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        vettore[i] = (6*(i+1))+1;
    }
    return vettore;
}

void print_vector(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int *GenPrimes(int n){
    int *primes = malloc(sizeof(int)*n);
    int *kp1 = SIXkPlus1(n/2);
    int *km1 = SIXkMinus1(n/2);
    merge(kp1,n/2, km1,n/2 ,primes);
    free(kp1);
    free(km1);
    return primes;
}



int main(void){
    GenMatrix(100,1);
}