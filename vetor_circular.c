#include "vetor_circular.h"
#define MAX 10

struct Fila
{
    int p;
    int u;
    int vetor[MAX];
};
typedef struct Fila fila;

fila teste;

int filaCheia(void) {
    return (teste.u+1) % MAX == teste.p; 
}

int filaVazia(){
    return teste.u == teste.p;
}

void iniciaFila (void) {
   teste.p = teste.u = 0;
}

void removeItemFila(void) {
    // int retirado = teste.vetor[teste.p];
    // teste.p++;
    if (!filaVazia()){
        if(teste.p < MAX){
            teste.vetor[teste.p] = -1;
            teste.p++; 
        }else{
            printf("Fila Vazia! Não foi possível remover mais itens da fila\n");
        }
   }
   else{
       printf("Fila Vazia! Não foi possível remover mais itens da fila\n");
   }
}

void insereItemFila(int y) {
   if (!filaCheia()){
        teste.vetor[teste.u] = y; 
        teste.u++;      
   }
   else{
       //printf("\nFila Cheia! Não foi possível inserir item na fila\n");
   }
}


void exibeFila(){

    int tamanho_fila = tamanhoFila();
    
    printf(" ");

    for ( int i = 0; i < MAX; i++){
        if(i == (MAX - 1)){
            printf("----- \n");
        }else{
            printf("------");
        }
    }

    printf("|");

    for ( int i = 0; i < MAX; i++){
        if(teste.p <= teste.u){
            if((i >= teste.p && i <= teste.u)){
                if(i != teste.u){
                    printf(" %03d |",teste.vetor[i]);
                }else{
                 printf(" XXX |");
                }                
            }else{
                 printf(" XXX |");
             }
        }else{
            printf(" XXX |");
        }
        
    }
    printf("\n");
    printf(" ");

    for ( int i = 0; i < MAX; i++){
        if(i == (MAX - 1)){
            printf("-----");
        }else{
            printf("------");
        }
    }

    printf("\n");
    printf(">");

    for ( int i = 0; i < MAX; i++){
        if(i == teste.p || i == teste.u){
            if(i == teste.p && i != teste.u){
                printf("  p   ");
            }
            else if(teste.p == teste.u){
                printf(" p-u  ");
            }
            else{
                printf("  u   ");
            }
        }else{
            printf("      ");
        }
    }
    printf("\n");
}

int tamanhoFila(){
    int count = 0;
    if(teste.p < teste.u){

        for ( int i = teste.p; i < teste.u; i++){
            count ++;
        }
    }
    else if(teste.p > teste.u){
        for ( int i = teste.p; i < MAX; i++){
            count ++;
        }
        for ( int i = 0; i < teste.u; i++){
            count ++;
        }
    }

    return count;
}
