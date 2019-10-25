#include "vetor_circular.h"




int main(){

    int activity_bool = 1,option = -1, j = 0;
    int valor = 0,vagas_livre = 0,nao_inseridos = 0, valorInsere_tmp = -1;
    int tamanhoFila_tmp = 0, nao_removidos = 0, qnt_remover = 0; 

    while(activity_bool){
        printf("\n -------------------------------------------");
        printf("\n");
        printf("|                 Main Menu                 |");
        printf("\n");
        printf(" -------------------------------------------\n");
        printf("(1) Inserir Elemento\n");
        printf("(2) Remover Elemento\n");
        printf("(3) Exibir Fila\n");
        printf("(4) Reiniciar Fila\n");
        printf("(5) Sair\n");
       // printf("(6) Tamanho fila\n");
        
        while(option > 6 || option < 1){
            printf("> ");
            scanf("%d", &option);
            if(option > 6 || option < 1){
                printf("Digite uma opção válida entre 1 - 5, por favor\n");
            }
        }        

        switch (option)
        {
            case 1:                
                printf("\nInsira a quantidade de elementos que deseja inserir: ");
                scanf("%d", &valor);
                if(teste.u == MAX){
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
                else if(teste.u == MAX){
                    printf("\n%d elemento(s) foi(ram) inserido(s) na fila, mas %d não coube(ram).", vagas_livre,nao_inseridos); 
                }   
                valor = 0;     
            break;

            case 2:
                printf("\nInsira a quantidade de elementos que deseja remover: ");
                scanf("%d", &valor);
                tamanhoFila_tmp = tamanhoFila();
                if(valor > tamanhoFila_tmp){
                    nao_removidos = valor - tamanhoFila_tmp;
                    qnt_remover = teste.u;
                }
                else{
                    qnt_remover = valor + teste.p;
                }

                
                printf(" ----------------------- \n");
                for(int i = teste.p;i < qnt_remover;i++){
                    printf("| Elemento removido: %03d |\n", teste.vetor[i]);
                    removeItemFila();
                }
                if(valor > tamanhoFila_tmp){
                    printf("\n > A lista está vazia! %d foi(ram) removido(s) da lista\n", tamanhoFila_tmp);
                    printf(" > %d elemento(s) deixou(ram) de ser removido(s) pois a lista já está vazia!\n", nao_removidos);
                }
                printf(" ----------------------- \n");
            break;

            case 3:
                exibeFila();
            break;

            case 4:
                iniciaFila();
            break;

            case 5:
                activity_bool = 0;
            break;

            case 6:
                printf("\nTamanho Fila: %d", tamanhoFila());
            break;
        }

        option = 10;
    }


    return 0;
}






