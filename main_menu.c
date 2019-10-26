#include "vetor_circular.h"




int main(){

    int activity_bool = 1,option = -1, j = 0;
    iniciaFila();

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
                prepareInserir();  
            break;

            case 2:
                prepareRemove();
            break;

            case 3:
                exibeFila();
            break;

            case 4:
                iniciaFila();
            break;

            case 5:
                freeFila();
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






