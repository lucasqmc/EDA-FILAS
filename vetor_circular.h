#ifndef _fila_circular_h
#define _fila_circular_h

#include <stdlib.h>
#include <stdio.h>
#include "vetor_circular.c"


int filaVazia(void);
int filaCheia(void);
void iniciaFila(void);
void removeItemFila(void);
void insereItemFila(int y);
void exibeFila(void);
int tamanhoFila(void);
void prepareRemove();
void prepareInserir();
void freeFila();
#endif