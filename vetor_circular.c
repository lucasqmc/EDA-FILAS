#include "vetor_circular.h"
#define MAX 3 

struct Fila
{
    int p;
    int u;
    int vetor[MAX];
};
typedef struct Fila Fila;

Fila *fila;


int filaVazia(void) {
   return tamanhoFila() == 0;
}

int filaCheia(void) {
    int bool = 0;   

    if(fila->u == MAX){
        bool = 1;
    }
     
    return bool; 
}

void iniciaFila (void) {
   fila->p = fila->u = 0;
}

void removeItemFila(void) {
    // int retirado = fila->vetor[fila->p];
    // fila->p++;
    if (!filaVazia()){
        if(fila->p < MAX){
            fila->vetor[fila->p] = -1;
            fila->p++; 
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
        fila->vetor[fila->u] = y; 
        fila->u++;      
   }
   else{
       //printf("\nFila Cheia! Não foi possível inserir item na fila\n");
   }
}

int tamanhoFila(){
    int count = 0;
    if(fila->p < fila->u){

        for ( int i = fila->p; i < fila->u; i++){
            count ++;
        }
    }
    else if(fila->p > fila->u){
        for ( int i = fila->p; i < MAX; i++){
            count ++;
        }
        for ( int i = 0; i < fila->u; i++){
            count ++;
        }
    }

    return count;
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
        if(fila->p <= fila->u){
            if((i >= fila->p && i <= fila->u)){
                if(i != fila->u){
                    printf(" %03d |",fila->vetor[i]);
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
        if(i == fila->p || i == fila->u){
            if(i == fila->p && i != fila->u){
                printf("  p   ");
            }
            else if(fila->p == fila->u){
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

void prepareRemove(){
    int activity_bool = 1,option = -1, j = 0;
    int valor = 0,vagas_livre = 0,nao_inseridos = 0, valorInsere_tmp = -1;
    int tamanhoFila_tmp = 0, nao_removidos = 0, qnt_remover = 0; 

    
    printf("\nInsira a quantidade de elementos que deseja remover: ");
    scanf("%d", &valor);
    tamanhoFila_tmp = tamanhoFila();
    if(valor > tamanhoFila_tmp){
        nao_removidos = valor - tamanhoFila_tmp;
        qnt_remover = fila->u;
    }
    else{
        qnt_remover = valor + fila->p;
    }

    
    printf(" ----------------------- \n");
    for(int i = fila->p;i < qnt_remover;i++){
        printf("| Elemento removido: %03d |\n", fila->vetor[i]);
        removeItemFila();
    }
    if(valor > tamanhoFila_tmp){
        printf("\n > A lista está vazia! %d foi(ram) removido(s) da lista\n", tamanhoFila_tmp);
        printf(" > %d elemento(s) deixou(ram) de ser removido(s) pois a lista já está vazia!\n", nao_removidos);
    }
    printf(" ----------------------- \n");
}

void prepareInserir(){
    int activity_bool = 1,option = -1, j = 0;
    int valor = 0,vagas_livre = 0,nao_inseridos = 0, valorInsere_tmp = -1;
    int tamanhoFila_tmp = 0, nao_removidos = 0, qnt_remover = 0; 
    
    printf("\nInsira a quantidade de elementos que deseja inserir: ");
    scanf("%d", &valor);
    if(fila->u == MAX){
        vagas_livre = 0;    
    }else{
        vagas_livre = MAX - tamanhoFila();
    }
    if(valor > vagas_livre){
        nao_inseridos = valor - vagas_livre;
    }

    for(int i = 0; i < valor; i++){
        printf("Insira o %d º: ", i + 1);
        while(valorInsere_tmp < 0 || valorInsere_tmp > 999){
            if(j > 0){
                printf("Por favor, digite um valor entre 0 e 999: ");
            }
            scanf("%d", &valorInsere_tmp);
            j++;
        }
        if(valor > vagas_livre){
            if(i <= vagas_livre){
                insereItemFila(valorInsere_tmp);
            }                        
        }else{
            insereItemFila(valorInsere_tmp);
        }
        j = 0;
        valorInsere_tmp = -1;
    }
    if(valor > vagas_livre){                  
        printf("\n%d elemento(s) foi(ram) inserido(s) na fila, mas %d não coube(ram).", vagas_livre,nao_inseridos);  
    } 
    else if(fila->u == MAX){
        printf("\n%d elemento(s) foi(ram) inserido(s) na fila, mas %d não coube(ram).", vagas_livre,nao_inseridos); 
    }   
    valor = 0;   
}