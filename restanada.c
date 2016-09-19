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

void movePeça (int **tab, par pos, int mov ) {

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

int main() {
   
    return 0
}