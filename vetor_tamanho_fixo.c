#include "vetor_tamanho_fixo.h"

fila teste;

int filavazia (void) {
   return teste.p >= teste.u;
}
int filacheia (void) {
   return teste.u == MAX - 1;
}

void iniciaFila(){
    teste.p = 0;
    teste.u = 0;
}

int tiradafila (void) {
   return teste.vetor[teste.p++];
}

void colocanafila (int y) {
   teste.vetor[teste.u++] = y;
}

int main(){

    teste.p = 3;

    printf("%d\n",teste.p);
    return 0;
}






