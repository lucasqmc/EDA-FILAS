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

int filaCheia(void);
void exibeFila(void);
int tamanhoFila(void);

int filaCheia(void) {
    int boolean = 0;   

    if(teste.p < teste.u){
        if(teste.u == MAX - 1 && teste.p == 0){
            boolean = 1;
        }
    }
    else if(teste.u < teste.p){
        if(teste. p - teste.u == 1){
            boolean = 1;
        }
    }

    return boolean; 
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
