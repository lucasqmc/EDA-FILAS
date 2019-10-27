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

int tamanhoFila(){
    int count = 0;
    for ( int i = 0; i < fila.tamanhoVetor; i++){
        if(fila.vetor[i] != -1){
          count ++;  
        }        
    }

    return count;
}


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
   }
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

int rearranjarFila(int aumento, int vagas_disponiveis){
    if(fila.p > fila.u){
        int tamanhoP_aoFimFila = 0, j = 0, count = 0;
        int *vetor_temp;
        vetor_temp = (int *) malloc(sizeof(int)*fila.tamanhoVetor);
        if(vetor_temp == NULL){
            printf("\nNão possui memória suficiente!\n");
            return 0;
        }
        tamanhoP_aoFimFila = fila.tamanhoVetor - fila.p;

        for(int i = fila.p; i < fila.tamanhoVetor; i++,j++){
            vetor_temp[j] = fila.vetor[i];
        }
        for(int i = 0; i <= fila.u; i++,j++){
            vetor_temp[j] = fila.vetor[i];
        }
        for(int i = fila.u; i < fila.p; i++,j++){
            if(i == fila.u && fila.vetor[fila.u] >= 0){
                vetor_temp[j] = fila.vetor[fila.u]; 
            }else{
               vetor_temp[j] = -1; 
            }            
        }

        fila.p = 0;
        fila.u = tamanhoFila();

        for(int i = 0; i < fila.tamanhoVetor; i++){
            fila.vetor[i] = vetor_temp[i];
        }

        fila.tamanhoVetor = fila.tamanhoVetor + aumento;

        fila.vetor = (int *) realloc(fila.vetor, sizeof(int)*fila.tamanhoVetor);
        for(int i = fila.u;i < fila.tamanhoVetor; i++){
            fila.vetor[i] = -1;
        }

        free(vetor_temp);
    }else{
        if(fila.p != 0){
            int *vetor_temp, j = 0;
            vetor_temp = (int *) malloc(sizeof(int)*fila.tamanhoVetor);
            if(vetor_temp == NULL){
                printf("\nNão possui memória suficiente!\n");
                return 0;
            }

            for(int i = fila.p; i <= fila.u; i++, j++){
                vetor_temp[j] = fila.vetor[i]; 
            } 

            fila.p = 0;
            fila.u = tamanhoFila();

            for(int i = fila.u; i < fila.tamanhoVetor; i++,j++){
                if(i == fila.u && fila.vetor[fila.u] >= 0){
                    vetor_temp[j] = fila.vetor[fila.u]; 
                }else{
                    vetor_temp[j] = -1; 
                }            
            }

            for(int i = 0; i < fila.tamanhoVetor; i++){
                fila.vetor[i] = vetor_temp[i];
            }

            fila.tamanhoVetor = fila.tamanhoVetor + aumento;

            fila.vetor = (int *) realloc(fila.vetor, sizeof(int)*fila.tamanhoVetor);
            for(int i = fila.u;i < fila.tamanhoVetor; i++){
                fila.vetor[i] = -1;
            }

            printf("\n> Fila antes de inserir:\n");
            exibeFila();

            free(vetor_temp);

        }else{

            fila.tamanhoVetor = fila.tamanhoVetor + aumento;
            fila.vetor = (int *) realloc(fila.vetor, sizeof(int)*fila.tamanhoVetor);

            if(fila.vetor[fila.u] != -1){
                fila.u = fila.u + 1;
            }

            for(int i = fila.u;i < fila.tamanhoVetor; i++){
                fila.vetor[i] = -1;
            }
        }
    }

    return 1;
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
    int bool_rearranjar = 0;
    
    printf("\nInsira a quantidade de elementos que deseja inserir: ");
    scanf("%d", &valor);
    vagas_livre = fila.tamanhoVetor - tamanhoFila();

    if(valor > vagas_livre){
        nao_inseridos = valor - vagas_livre;
        bool_rearranjar = rearranjarFila(nao_inseridos, vagas_livre);
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
            
        insereItemFila(valorInsere_tmp);
        
        j = 0;
        valorInsere_tmp = -1;
    }

    valor = 0;   
}

void freeFila(){
    free(fila.vetor);
}
