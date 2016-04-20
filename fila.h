# fila-Estrutura-de-Dados-

#ifndef _H_FILA_

#define _H_FILA_

#define FILA_VERSAO   0.1

#include "lista.h"

typedef struct _fila {
    lista *itens;
    lista *pri;
    lista *ult;
    int tamanho;
} fila;

/* Cria uma fila vazia */
fila *fila_cria();

/* Libera memória removendo a fila e seus elementos */
void fila_elimina(fila **F);

/* Retorna se a fila eh vazia ou nao */
int fila_ehVazia(fila *F);

/* Retorna se a fila eh cheia ou nao - apenas por compatibilidade */
int fila_ehCheia(fila *F);

/* Insere um elemento no topo da fila */
void fila_insere(fila *F, void *info);

/* Remove o elemento do topo da fila */
void *fila_remove(fila *F);

/* Retorna o primeiro elemento da fila */
void *fila_primeiro(fila *F);

/* Retorna o ultimo elemento da fila */
void *fila_ultimo(fila *F);

/* Retorna o tamanho da fila */
int fila_tamanho(fila *F);

#endif // _H_FILA_
