#include "vetor_tamanho_fixo.h"

int main(){
    // iniciaFila();
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());
    // insereItemFila(2);
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());
    // insereItemFila(3);
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());
    // insereItemFila(4);
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());
    // removeItemFila();
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());
    // insereItemFila(5);
    // exibeFila();
    // printf("Tamanho da fila: %d\n",tamanhoFila());

    int activity_bool = 1,option = 6, j = 0;

    while(activity_bool){
        while(option > 5 || option < 1){
            scanf("%d", &option);
            if(option > 5 || option < 1){
                printf("Digite uma opção válida entre 1 - 5, por favor\n");
            }
        }
        switch (option)
        {
            case 1:
                insereItemFila(2);
            break;

            case 2:
                removeItemFila();
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
        }

        option = 10;
    }


    return 0;
}






