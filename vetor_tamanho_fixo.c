#include "vetor_tamanho_fixo.h"
// #define MAX 3

// struct Fila
// {
//     int p;
//     int u;
//     int vetor[MAX];
// };
// typedef struct Fila fila;

// fila teste;

int main(){

    int activity_bool = 1,option = -1, j = 0;
    int valor = 0,vagas_livre = 0,nao_inseridos = 0, valorInsere_tmp = -1;

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
        //printf("(6) Tamanho fila\n");
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
                vagas_livre = MAX - tamanhoFila();
                if(valor > vagas_livre){
                    nao_inseridos = valor - vagas_livre;
                }

                for(int i = 0; i < valor; i++){
                    printf("Insira o %d º: ", i);
                    while(valorInsere_tmp < 0 || valorInsere_tmp > 999){
                        if(j > 0){
                            printf("Por favor, digite um valor entre 0 e 999: ");
                        }
                        scanf("%d", &valorInsere_tmp);
                        j++;
                    }
                    if(valor > vagas_livre){
                        if(i < vagas_livre){
                            insereItemFila(valorInsere_tmp);
                        }                        
                    }else{
                        insereItemFila(valorInsere_tmp);
                    }
                    j = 0;
                    valorInsere_tmp = -1;
                }
                if(valor > vagas_livre){                  
                    printf("\n%d elementos foram inseridos na fila, mas %d não couberam.", vagas_livre,nao_inseridos);  
                }            
            break;

            case 2:
                removeItemFila();
            break;

            case 3:
                exibeFila();
            break;

            case 4:
                reiniciaFila();
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






