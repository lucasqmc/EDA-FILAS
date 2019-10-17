#include "vetor_tamanho_fixo.h"

fila teste;

int filavazia(void) {
   return teste.p >= teste.u;
}
int filacheia(void) {
   return teste.u == MAX - 1;
}

void iniciaFila(){
    teste.p = 0;
    teste.u = 0;
}

int tiradafila(void) {
    int retirado = teste.vetor[teste.p];
    teste.p++;
    
   return retirado;
}

void colocanafila(int y) {
   if (!filacheia()){
     teste.vetor[teste.u++] = y;  
   }
   else{
       exit(1);
   }
}

void exibeFila(){
    for ( int i = teste.p; i < teste.u; i++){
        printf("%d ",teste.vetor[i]);
    }
    printf("\n");
}

int tamanhoFila(){
    int count = 0;
    for ( int i = teste.p; i < teste.u; i++){
        count ++;
    }

    return count;
}

int main(){
    iniciaFila();
    colocanafila(2);
    colocanafila(3);
    colocanafila(4);
    exibeFila();
    printf("Tamanho da fila: %d\n",tamanhoFila());
    tiradafila();
    exibeFila();
    printf("Tamanho da fila: %d\n",tamanhoFila());
    colocanafila(5);
    exibeFila();
    printf("Tamanho da fila: %d\n",tamanhoFila());

    return 0;
}






