#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    int l, c, m, i;
}jog;

typedef struct {
    int top;
    jog *vet;
} pile;

#endif