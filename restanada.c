#include <stdio.h>
#include <stdlib.h>


typedef struct {

    int topo;
    int *vetor;
} pile;

typedef struct {
    int lin;
    int col;
} par;




void criaPilha(int tamanho, pile *pilha) {

    pilha->topo = 0;
    pilha->vetor = malloc(tamanho*sizeof(int));
}

void colocaPrimeiro(int n, pile *pilha) {
        
    pilha->vetor[pilha->topo] = n;
    pilha->topo++;    
}

int tiraPrimeiro (pile *pilha) {

    int f;
    pilha->topo--;
    f = pilha->vetor[pilha->topo];
    
    return f;
}

int pilhaVazia (pile *pilha) {

    if (pilha->topo == 0)
        return 1;
    else
        return 0;
}

void destroiPilha (pile *pilha) {

    free(pilha->vetor);
    pilha->vetor = NULL;
    free(pilha);
    pilha = NULL;
}

int veTopo (pile *pilha) {
    return (pilha->vetor[pilha->topo]);
}

void movePeca (int **tab, par pos, int mov ) {

    switch (mov) {

        case 1 :
            tab[pos.lin][pos.col] += 2;
            tab[pos.lin][pos.col + 1] -=2;
            tab[pos.lin][pos.col + 2] -=2;
            break;

        case 2 :
            tab[pos.lin][pos.col] -=2;
            tab[pos.lin][pos.col- 1] -=2;
            tab[pos.lin][pos.col- 2] -=2;
            break;

        case 3 :
            tab[pos.lin][pos.col] -=2;
            tab[pos.lin + 1][pos.col] -=2;
            tab[pos.lin + 2][pos.col] -=2;
            break;

        case 4 :
            tab[pos.lin][pos.col] -=2;
            tab[pos.lin - 1][pos.col] -=2;
            tab[pos.lin - 2][pos.col] -=2;
            break;
    }
}

int podeMover (int **tab, par pos, int mov ) {

    switch (mov) {

        case 1 :
            if (tab[pos.lin][pos.col] == -1 && tab[pos.lin][pos.col + 1] == 1 && tab[pos.lin][pos.col + 2] == 1)
                return 1;
            else return 0;
        
        case 2 :
            if (tab[pos.lin][pos.col] == -1 && tab[pos.lin][pos.col - 1] == 1 && tab[pos.lin][pos.col - 2] == 1)
                return 1;
            else return 0;

        case 3 :
            if (tab[pos.lin][pos.col] == -1 && tab[pos.lin + 1][pos.col] == 1 && tab[pos.lin + 2][pos.col] == 1)
                return 1;
            else return 0;

        case 4 :
            if (tab[pos.lin][pos.col] == -1 && tab[pos.lin - 1][pos.col] == 1 && tab[pos.lin - 2][pos.col] == 1)
                return 1;
            else return 0;
    
    }
}

int** criaResultado (int **tab, int n, int m) {

    int **res, i, j;
    
    res = malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        res[i] = malloc(m*sizeof(int));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            
            if (tab[i][j] == 1)
                res[i][j] = -1;

            if (tab[i][j] == -1)
                res[i][j] = 1;

            else
                res[i][j] = 0;
        }
    }

    return (res);
}


int confereMatriz (int **tab, int **res, int n, int m) {

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (tab[i][j] != res[i][j])
                return 0;
        }
    }

    return 1;

}

par procuraBuraco (int **tab, int n, int m) {
    
    
}


int procuraGanhar (int **tab, int **res, int n, int m) {

}





int main() {

    int n, m;
     
     n = 2;
     m = 3;
   
    return 0;
}