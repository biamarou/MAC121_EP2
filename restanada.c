#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lin;
    int col;
} par;


typedef struct {
   par coord;
   int mov;    
} joga;

typedef struct {

    int topo;
    joga *vetor;
} pile;


void criaPilha(int tamanho, pile *pilha) {

    pilha->topo = 0;
    pilha->vetor = malloc(tamanho*sizeof(joga));
}

void colocaPrimeiro(joga n, pile *pilha) {
        
    pilha->vetor[pilha->topo] = n;
    pilha->topo++;    
}

joga tiraPrimeiro (pile *pilha) {

    joga f;
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

joga veTopo (pile *pilha) {
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

void guardaJogadas (int **tab, par pos, pile *pilha, int n, int m) {

    joga entries; 
    
    if (pos.col < n && tab[pos.lin][pos.col] == -1 && tab[pos.lin][pos.col + 1] == 1 && tab[pos.lin][pos.col + 2] == 1) {
        entries.coord.lin = pos.lin;
        entries.coord.col = pos.col;
        entries.mov = 1;
        colocaPrimeiro(entries, pilha);

    }

    if (pos.col > 1 && tab[pos.lin][pos.col] == -1 && tab[pos.lin][pos.col - 1] == 1 && tab[pos.lin][pos.col - 2] == 1) {
        entries.coord.lin = pos.lin;
        entries.coord.col = pos.col;
        entries.mov = 2;
        colocaPrimeiro(entries, pilha); 
    }
                

    if (pos.lin < m && tab[pos.lin][pos.col] == -1 && tab[pos.lin + 1][pos.col] == 1 && tab[pos.lin + 2][pos.col] == 1) {
        entries.coord.lin = pos.lin;
        entries.coord.col = pos.col;
        entries.mov = 3;
        colocaPrimeiro(entries, pilha);
    }

    
    if (pos.lin > 1 && tab[pos.lin][pos.col] == -1 && tab[pos.lin - 1][pos.col] == 1 && tab[pos.lin - 2][pos.col] == 1) {
        entries.coord.lin = pos.lin;
        entries.coord.col = pos.col;
        entries.mov = 4;
        colocaPrimeiro(entries, pilha); 
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