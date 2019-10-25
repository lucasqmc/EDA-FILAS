#ifndef _fila_circular_h
#define _fila_circular_h

#include <stdlib.h>
#include <stdio.h>
#define MAX 10
#define FIXO 0
#define CIRCULAR 1
#define LISTA 0


int filaVazia(void);
int filaCheia(void);
void iniciaFila(void);
void removeItemFila(void);
void insereItemFila(int y);
void exibeFila(void);
int tamanhoFila(void);

#endif