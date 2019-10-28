#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *fila;

int inicializa_fila(){
    fila = malloc(sizeof(celula));
    if(fila == NULL) return 0;
    fila->prox = fila;
    return 1;
}

/* Essa função irá fazer as mudanças na memória e retornar se deu certo ou não */
int desenfileira(int *y){
    if(fila->prox == fila) return 0;
    celula *lixo = fila->prox;
    *y = lixo->dado;
    fila->prox = lixo->prox;
    free(lixo); //Retirar da memória sobre o cara que o pronteiro "lixo" aponta
    return 1;
}

int enfileira(int y){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return 0;
    novo->prox = fila->prox;
    fila->prox = novo;
    fila->dado = y;
    fila=novo;
    return 1;
}

int destroi_fila(){
    int elem;
    while(desenfileira(&elem));
    free(fila);
    return 1;
}

void exibe_fila(){

    celula *tmp = fila->prox;
    int u = 0;
    for (int i = 0; i < tamanhoFila() ; i++){
        printf("------");
    }
    printf("\n");
    printf("| ");
    while (tmp->dado != NULL){
        printf("%03d | ",tmp->dado);
        tmp = tmp->prox;
        u++;
    }
    printf("\n");
    for (int i = 0; i < tamanhoFila() ; i++){
        printf("------");
    }
    printf("\n");
    printf("   p");
    for (int i = 0; i < (tamanhoFila()*6) - 2; i++)
    {
        printf(" ");
    }
    printf("u\n");

    printf("\n\n");
}

int tamanhoFila(void){
    celula *tmp = fila->prox;
    int u = 0;
    while (tmp->dado != NULL){
        tmp = tmp->prox;
        u++;
    }

    return u;
}

int main(){

    int p = 1000;

    inicializa_fila();

    exibe_fila();


    printf("Tamanho da fila: %d\n\n", tamanhoFila());

    return 0;
}