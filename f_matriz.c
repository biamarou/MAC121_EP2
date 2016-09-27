#include <stdio.h>
#include <stdlib.h>

int **criaMatriz (int n, int m) {

    int **matriz, k;

    matriz = malloc(n*(sizeof(int *)));
    for (k = 0; k < n; k++)
        matriz[k] = malloc(m*(sizeof(int)));

    return(matriz);
}

void printMatriz(int **tab, int n, int m){

    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int comparaMatriz (int **tab, int **res, int n, int m) {

    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (tab[i][j] != res[i][j])
                return 0;
        }
    }

    return 1;
}