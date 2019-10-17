#include <stdlib.h>
#include <stdio.h>
#define MAX 40

struct Fila
{
    int p;
    int u;
    int vetor[MAX];
};
typedef struct Fila fila;

int filavazia(void);
int filacheia(void);
void iniciaFila();
int tiradafila(void);
void colocanafila(int y);
void exibeFila(void);