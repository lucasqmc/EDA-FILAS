#include "vetor_tamanho_fixo.h"
#define MAX 3

struct Fila
{
    int p;
    int u;
    int vetor[MAX];
};
typedef struct Fila fila;

fila teste;


int filaVazia(void) {
   return tamanhoFila() == 0;
}

int filaCheia(void) {
    int bool = 0;   

    if(teste.u == MAX){
        bool = 1;
    }
     
    return bool; 
}

void iniciaFila(){
    teste.p = 0;
    teste.u = 0;
    for( int i = 0; i < MAX; i++){
        teste.vetor[i] = -1;
    }

    teste.vetor[0] = -1;
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

    for ( int i = teste.p; i < teste.u; i++){
        count ++;
    }
    
    return count;
}


