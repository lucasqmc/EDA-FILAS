#ifndef _fila_fixo_h
#define _fila_fixo_h

#include <stdlib.h>
#include <stdio.h>
#include "vetor_tamanho_fixo.c"
#define MAX 3

int filaVazia(void);
int filaCheia(void);
void iniciaFila(void);
void removeItemFila(void);
void insereItemFila(int y);
void prepareRemove();
void prepareInserir();
void exibeFila(void);
int tamanhoFila(void);

#endif