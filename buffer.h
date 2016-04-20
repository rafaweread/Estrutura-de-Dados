# fila-Estrutura-de-Dados-

#ifndef _H_BUFFER_

#define _H_BUFFER_

#define BUFFER_VERSAO   0.1

#include "lista.h"

typedef struct _buffer {
    void **itens;
    int pri;
    int ult;
    int tamanho;
    int tamMax;
} buffer;

/* Cria uma buffer vazia */
buffer *buffer_cria(int tamMaximo);

/* Libera memória removendo a buffer e seus elementos */
void buffer_elimina(buffer **F);

/* Retorna se a buffer eh vazia ou nao */
int buffer_ehVazia(buffer *F);

/* Retorna se a buffer eh cheia ou nao - apenas por compatibilidade */
int buffer_ehCheia(buffer *F);

/* Insere um elemento no topo da buffer */
void buffer_insere(buffer *F, void *info);

/* Remove o elemento do topo da buffer */
void *buffer_remove(buffer *F);

/* Retorna o primeiro elemento da buffer */
void *buffer_primeiro(buffer *F);

/* Retorna o ultimo elemento da buffer */
void *buffer_ultimo(buffer *F);

/* Retorna o tamanho da buffer */
int buffer_tamanho(buffer *F);

#endif // _H_BUFFER_
