/*NOME: Beatriz Figueiredo Marouelli*/
/*N°USP: 9793652*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "f_matriz.h"
#include "f_pilha.h"

void preencheTabuleiro (int **tab, int n, int m, int *p_pec, int *p_bur) {

    int i, j;
    *p_pec = *p_bur = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &tab[i][j]);
            if (tab[i][j] == 1)
                *p_pec += 1;
            if (tab[i][j] == -1)
                *p_bur += 1;
        }
    }
}

void preencheResultado (int **tab, int **res, int n, int m) {

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            
            if (tab[i][j] == 1)
                res[i][j] = -1;
            
            else if (tab[i][j] == -1)
                res[i][j] = 1;
            
            else
                res[i][j] = 0;
        }
    }
}


void printResultado(pile *arm, int bur, int pec) {
    
    pile *resu;
    jog var;
    jog res;                                    

    resu = criaPilha((pec - bur) + 1);          
                                            
    while (pilhaVazia(arm) != 1) {              
        var = tiraPrimeiro(arm);
        colocaPrimeiro(var, resu);          
    }                                           

    while (pilhaVazia(resu) != 1) {                 
        var = tiraPrimeiro(resu);               
        if (var.m == 1) {                   
            res.l = var.l;                      
            res.c = var.c + 2;                      
            printf("%d:%d-%d:%d\n", var.l, var.c, res.l, res.c);                            
        }                                       

        else if (var.m == 2) {                      
            res.l = var.l;                      
            res.c = var.c - 2;                      
            printf("%d:%d-%d:%d\n", var.l, var.c, res.l, res.c);                                    
        }                                   

        else if (var.m == 3) {
            res.l = var.l + 2;                      
            res.c = var.c;                      
            printf("%d:%d-%d:%d\n", var.l, var.c, res.l, res.c);    
        }

        else {
            res.l = var.l - 2;                      
            res.c = var.c;                      
            printf("%d:%d-%d:%d\n", var.l, var.c, res.l, res.c);    
        }
    }
}

jog *varrePecas (int **tab, int n, int m, int pec, int *pt_tam) {

    int i, j, ind;
    jog var, *vetor;
    ind = 0;
    
    vetor = malloc(4*pec*sizeof(jog));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            
            if (tab[i][j] == 1) {
                var.l = i;
                var.c = j;
                var.m = 0;

                if (j < m - 2 && tab[i][j + 1] == 1 && tab[i][j + 2] == -1) {
                    var.m = 1;
                    var.i = ind;
                    vetor[ind] = var;
                    ind++;
                }

                if (j > 1 && tab[i][j - 1] == 1 && tab[i][j - 2] == -1) {
                    var.m = 2;
                    var.i = ind;
                    vetor[ind] = var;
                    ind++;
                }

                if (i < n - 2 && tab[i + 1][j] == 1 && tab[i + 2][j] == -1) {
                    var.m = 3;
                    var.i = ind;
                    vetor[ind] = var;
                    ind++;
                }

                if (i > 1 && tab[i - 1][j] == 1 && tab[i - 2][j] == -1) {
                    var.m = 4;
                    var.i = ind;
                    vetor[ind] = var;
                    ind++;
                }
            }   
        }
    }

    *pt_tam = ind;

    return(vetor);
}

void fazMovimento(int **tab, jog var) {

    switch (var.m) {

        case 1 :
            tab[var.l][var.c] -= 2;
            tab[var.l][var.c + 1] -= 2;
            tab[var.l][var.c + 2] += 2;
            break;

        case 2 :
            tab[var.l][var.c] -= 2;
            tab[var.l][var.c - 1] -= 2;
            tab[var.l][var.c - 2] += 2;
            break;

        case 3 :
            tab[var.l][var.c] -= 2;
            tab[var.l + 1][var.c] -= 2;
            tab[var.l + 2][var.c] += 2;
            break;

        case 4 :
            tab[var.l][var.c] -= 2;
            tab[var.l - 1][var.c] -= 2;
            tab[var.l - 2][var.c] += 2;
            break;
    }
}

void desfazMovimento(int **tab, jog var) {

    switch (var.m) {

        case 1 :
            tab[var.l][var.c] += 2;
            tab[var.l][var.c + 1] += 2;
            tab[var.l][var.c + 2] -= 2;
            break;

        case 2 :
            tab[var.l][var.c] += 2;
            tab[var.l][var.c - 1] += 2;
            tab[var.l][var.c - 2] -= 2;
            break;

        case 3 :
            tab[var.l][var.c] += 2;
            tab[var.l + 1][var.c] += 2;
            tab[var.l + 2][var.c] -= 2;
            break;

        case 4 :
            tab[var.l][var.c] += 2;
            tab[var.l - 1][var.c] += 2;
            tab[var.l - 2][var.c] -= 2;
            break;
    }
}

int simulaJogo (int **tab, int **res, int n, int m, int *pt_tam, jog *vet, int cond, int bur, int pec, pile *arm) {

    int ind;
    jog var;

    ind = 0;
    pec--;
    
    while (pilhaVazia(arm) != 1 || ind != cond) {

        if (comparaMatriz(tab, res, n, m))
            return 1;
        else if (pilhaVazia(arm) == 1)
            pec++;
        else {
            var = tiraPrimeiro(arm);
            desfazMovimento(tab, var);
            pec++;
            free(vet);
            vet = varrePecas(tab, n, m, pec, pt_tam);
            ind = var.i + 1;
        }

        while (bur < pec) {
            
            if (ind < *pt_tam) {
                
                var = vet[ind];
                colocaPrimeiro(var, arm);
                fazMovimento(tab, var); 
                pec--;
                free(vet);
                vet = varrePecas(tab, n, m, pec, pt_tam);
                ind = 0;
            }

            else {
                
                if (pilhaVazia(arm) == 1 && ind == cond)
                    return 0;

                var = tiraPrimeiro(arm);
                desfazMovimento(tab, var);
                pec++;
                free(vet);
                vet = varrePecas(tab, n, m, pec, pt_tam);
                ind = var.i + 1;

                while(ind >= *pt_tam) {
                    var = tiraPrimeiro(arm);
                    desfazMovimento(tab, var);
                    pec++;
                    free(vet);
                    vet = varrePecas(tab, n, m, pec, pt_tam);
                    ind = var.i + 1;
                }
            }
        }   
    }

    return 0;
}

int main () {

    int linha, coluna, pecas, buracos, tam, cond;
    int *pt_pecas, *pt_buracos, *pt_tam;
    jog *vet_joga;
    pile *arm;
    int **tabuleiro, **resultado;

    
    pt_pecas = &pecas;
    pt_buracos = &buracos;
    pt_tam = &tam;
    scanf("%d %d", &linha, &coluna);
    
    tabuleiro = criaMatriz(linha, coluna);
    resultado = criaMatriz(linha, coluna);
    
    preencheTabuleiro(tabuleiro, linha, coluna, pt_pecas, pt_buracos);
    if (pecas == 0 && buracos == 0)
        return 0;

    preencheResultado(tabuleiro, resultado, linha, coluna);
    arm = criaPilha((pecas - buracos) + 1);

    vet_joga = varrePecas(tabuleiro, linha, coluna, pecas, pt_tam);
    cond = tam;

    
    if (simulaJogo(tabuleiro, resultado, linha, coluna, pt_tam, vet_joga, cond, buracos, pecas, arm)) {
        printResultado(arm, buracos, pecas);
    }
    
    else
        printf("Impossivel\n");
    

    free(vet_joga);
    free(arm);
    return 0;
}