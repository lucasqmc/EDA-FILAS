#ifndef _fila_fixo_h
#define _fila_fixo_h
#define FIXO 0
#define CIRCULAR 0
#define LISTA 1

    int inicializa_fila();
    int enfileira(int y);
    int desenfileira(int *y);
    int destroi_fila();
    void prepareRemove();
    void prepareInserir();

#endif
