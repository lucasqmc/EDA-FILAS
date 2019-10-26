#include "vetor_circular.h"
#define MAX 5

struct Fila
{
    int p;
    int u;
    int *vetor;
    int tamanhoVetor;
};
typedef struct Fila Fila;

Fila fila;

int filaVazia(void) {
   return tamanhoFila() == 0;
}

int filaCheia(void) {
    int bool = 0;   

    if(fila.p == 0 && fila.u == fila.tamanhoVetor - 1){
        bool = 1;
    }
    else if(fila.p > fila.u && fila.p - fila.u == 1){
        bool = 1;
    }
     
    return bool; 
}

void iniciaFila (void) {
   fila.p = fila.u = 0;
   fila.tamanhoVetor = MAX;
   free(fila.vetor);
   fila.vetor = (int *) malloc(sizeof(int)*MAX);

   for(int i = 0; i < fila.tamanhoVetor; i++){
       fila.vetor[i] = -1;
   }
}

void removeItemFila(void) {
    // int retirado = fila.vetor[fila.p];
    // fila.p++;
    if (!filaVazia()){
        if(fila.p == fila.u){
            if(fila.vetor[fila.p] != -1){
                fila.vetor[fila.p] = -1;
            }else{
                printf("Fila Vazia! Não foi possível remover mais itens da fila\n");
            }
        }
        else if(fila.p > fila.u && fila.p == fila.tamanhoVetor -1){
           fila.vetor[fila.p] = -1; 
           fila.p = 0;  
        }else{
            fila.vetor[fila.p] = -1; 
            fila.p++;  
        }
   }
   else{
       printf("Fila Vazia! Não foi possível remover mais itens da fila\n");
   }
}

void insereItemFila(int y) {
   if (!filaCheia()){
       if(fila.u == fila.tamanhoVetor - 1){
           if(fila.vetor[fila.u] != -1){
               if(fila.p == 1){
                   fila.u = 0;
                   fila.vetor[fila.u] = y; 
               }else if(fila.p > 1){
                   fila.u = 1;
                   fila.vetor[fila.u - 1] = y; 
               }
            }else{
                fila.vetor[fila.u] = y; 
                fila.u = 0;  
            }            
       }else if(fila.vetor[fila.u] != -1){
           if(fila.p - fila.u == 1){
                fila.u++;
                fila.vetor[fila.u] = y; 
            }else if(fila.p - fila.u > 1){
                fila.u = fila.u + 2;
                fila.vetor[fila.u - 1] = y; 
            }

       }else{
           fila.vetor[fila.u] = y; 
           fila.u++;  
       }
   }
   else{
        if(fila.vetor[fila.u] == -1){
            fila.vetor[fila.u] = y; 
        }
        //printf("\nFila Cheia! Não foi possível inserir item na fila\n");
   }
}


int tamanhoFila(){
    int count = 0;
    for ( int i = 0; i < fila.tamanhoVetor; i++){
        if(fila.vetor[i] != -1){
          count ++;  
        }        
    }

    return count;
}

void exibeFila(){

    int tamanho_fila = tamanhoFila();
    
    printf(" ");

    for ( int i = 0; i < fila.tamanhoVetor; i++){
        if(i == (fila.tamanhoVetor - 1)){
            printf("----- \n");
        }else{
            printf("------");
        }
    }

    printf("|");

    for ( int i = 0; i < fila.tamanhoVetor; i++){
        // if(fila.p <= fila.u){
        //     if((i >= fila.p && i <= fila.u)){
        //         if(i != fila.u){
        //             printf(" %03d |",fila.vetor[i]);
        //         }else{
        //          printf(" XXX |");
        //         }                
        //     }else{
        //          printf(" XXX |");   
        //      }
        // }else{
        //     if(i == fila.u){
        //         printf(" %03d |",fila.vetor[i]);
        //     }else{
        //         printf(" XXX |");
        //     }        
        // }
        if(fila.vetor[i] != -1){
            printf(" %03d |", fila.vetor[i]);
        }else{
            printf(" XXX |");
        }     
                
        
    }
    printf("\n");
    printf(" ");

    for ( int i = 0; i < fila.tamanhoVetor; i++){
        if(i == (fila.tamanhoVetor - 1)){
            printf("-----");
        }else{
            printf("------");
        }
    }

    printf("\n");
    printf(">");

    for ( int i = 0; i < fila.tamanhoVetor; i++){
        if(i == fila.p || i == fila.u){
            if(i == fila.p && i != fila.u){
                printf("  p   ");
            }
            else if(fila.p == fila.u){
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
    int localizar_p = fila.p, contador = 0;
    
    printf("\nInsira a quantidade de elementos que deseja remover: ");
    scanf("%d", &valor);
    tamanhoFila_tmp = tamanhoFila();
    localizar_p = (fila.tamanhoVetor - 1) - (fila.p  + valor);

    if(valor > tamanhoFila_tmp){
        nao_removidos = valor - tamanhoFila_tmp;
        if( localizar_p < 0 ){
            qnt_remover = fila.tamanhoVetor;
        }else{
           qnt_remover = valor + fila.p; 
        }
    }
    else{
        if( localizar_p < 0 ){
            qnt_remover = fila.tamanhoVetor;
        }else{
           qnt_remover = valor + fila.p; 
        }
    }

    
    printf(" ----------------------- \n");
    for(int i = fila.p;i < qnt_remover;i++){
        printf("| Elemento removido: %03d |\n", fila.vetor[i]);
        removeItemFila();
        contador++;
    }

    if( localizar_p < 0 && fila.p != fila.u ){
        qnt_remover = valor - contador;
        for(int i = fila.p;i < qnt_remover;i++){
            printf("| Elemento removido: %03d |\n", fila.vetor[i]);
            removeItemFila();
        }
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
    if(fila.u == fila.tamanhoVetor){
        vagas_livre = 0;    
    }else{
        vagas_livre = fila.tamanhoVetor - tamanhoFila();
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
    else if(fila.u == fila.tamanhoVetor){
        printf("\n%d elemento(s) foi(ram) inserido(s) na fila, mas %d não coube(ram).", vagas_livre,nao_inseridos); 
    }   
    valor = 0;   
}

void freeFila(){
    free(fila.vetor);
}