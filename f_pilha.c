#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

pile *criaPilha(int tamanho) {
    
    pile *pilha;
    pilha = malloc(sizeof(pile));
    pilha->top = 0;
    pilha->vet = malloc(sizeof(jog));
    pilha->vet = malloc(tamanho*sizeof(jog));

    return(pilha);
}

void colocaPrimeiro(jog n, pile *pilha) {
       
    pilha->vet[pilha->top] = n;
    pilha->top += 1;    
}

jog tiraPrimeiro (pile *pilha) {

    jog f;
    pilha->top--;
    f = pilha->vet[pilha->top];
    
    return f;
}

int pilhaVazia (pile *pilha) {

    if (pilha->top == 0)
        return 1;
    else
        return 0;
}

void destroiPilha (pile *pilha) {

    free(pilha->vet);
    pilha->vet = NULL;
    free(pilha);
    pilha = NULL;
}

jog veTopo (pile *pilha) {
    
    return (pilha->vet[pilha->top]);
}