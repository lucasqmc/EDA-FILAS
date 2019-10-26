
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

int detroi_fila(){
    int elem;
    while(desenfileira(&elem));
    free(fila);
    return 1;
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
        qnt_remover = fila.u;
    }
    else{
        qnt_remover = valor + fila.p;
    }

    
    printf(" ----------------------- \n");
    for(int i = fila.p;i < qnt_remover;i++){
        printf("| Elemento removido: %03d |\n", fila.vetor[i]);
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
    if(fila.u == MAX){
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
    else if(fila.u == MAX){
        printf("\n%d elemento(s) foi(ram) inserido(s) na fila, mas %d não coube(ram).", vagas_livre,nao_inseridos); 
    }   
    valor = 0;   
}