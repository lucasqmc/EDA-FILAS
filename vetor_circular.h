#ifndef _fila_circular_h
#define _fila_circular_h

#include <stdlib.h>
#include <stdio.h>
#include "vetor_circular.c"

int tamanhoFila(void);
int filaVazia(void);
int filaCheia(void);
void iniciaFila(void);
void removeItemFila(void);
void insereItemFila(int);
void exibeFila(void);
void prepareRemove();
void prepareInserir();
void freeFila();
int rearranjarFila(int, int);
#endif