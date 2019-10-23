#ifndef _fila_fixo_h
#define _fila_fixo_h

#include <stdlib.h>
#include <stdio.h>
#define MAX 3


int filaVazia(void);
int filaCheia(void);
void reiniciaFila();
void removeItemFila(void);
void insereItemFila(int y);
void exibeFila(void);
int tamanhoFila(void);

#endif