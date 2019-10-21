#include <stdlib.h>
#include <stdio.h>
#define MAX 10

struct Fila
{
    int p;
    int u;
    int vetor[MAX];
};
typedef struct Fila fila;

fila teste;


int filaVazia(void);
int filaCheia(void);
void iniciaFila();
void removeItemFila(void);
void insereItemFila(int y);
void exibeFila(void);
int tamanhoFila(void);


int filaVazia(void) {
   return tamanhoFila() == 0;
}
int filaCheia(void) {
    int bool = 0;   

    if(teste.p < teste.u){
        if(teste.u == MAX - 1 && teste.p == 0){
            bool = 1;
        }
    }
    else if(teste.u < teste.p){
        if(teste. p - teste.u == 1){
            bool = 1;
        }
    }

    return bool; 
}

void iniciaFila(){
    teste.p = 0;
    teste.u = 0;
}

void removeItemFila(void) {
    // int retirado = teste.vetor[teste.p];
    // teste.p++;
    if (!filaVazia()){
     if(teste.p == MAX - 1){
        teste.vetor[teste.p] = 0; 
        teste.p = 0;
        
     }
     else{
        teste.vetor[teste.p] = 0;
        teste.p++; 
     }      
   }
   else{
       printf("Fila Vazia! Não foi possível remover mais itens da fila\n");
   }
}

void insereItemFila(int y) {
   if (!filaCheia()){
     if(teste.u == MAX - 1){
        teste.u = 0;
        teste.vetor[teste.u] = y; 
     }
     else{
        teste.u++;
        teste.vetor[teste.u] = y; 
     }      
   }
   else{
       printf("Fila Cheia! Não foi possível inserir item na fila\n");
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
                printf(" %03d |",teste.vetor[i]);
            }else{
                 printf(" XXX |");
             }
        }
        else if(teste.p > teste.u){
            if((i >= 0 && i <= teste.u) || (i >= teste.p && i <= MAX)){
                printf(" %03d |",teste.vetor[i]);
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

        for ( int i = teste.p; i <= teste.u; i++){
            count ++;
        }
    }
    else if(teste.p > teste.u){
        for ( int i = teste.p; i <= MAX; i++){
            count ++;
        }
        for ( int i = 0; i <= teste.u; i++){
            count ++;
        }
    }

    return count;
}
