#ifndef F_PILHA_H
#define F_PILHA_H

pile *criaPilha(int tamanho);

void colocaPrimeiro(jog n, pile *pilha);

jog tiraPrimeiro (pile *pilha);

int pilhaVazia (pile *pilha);

void destroiPilha (pile *pilha);

jog veTopo (pile *pilha);

#endif