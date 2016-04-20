# fila-Estrutura-de-Dados-

#ifndef _H_PILHA_

#define _H_PILHA_

#define PILHA_VERSAO   0.1

#include "lista.h"

typedef struct _pilha {
    lista *itens;
    int tamanho;
} pilha;

/* Cria uma pilha vazia */
pilha *pilha_cria();

/* Libera memória removendo a pilha e seus elementos */
void pilha_elimina(pilha **P);

/* Retorna se a pilha eh vazia ou nao */
int pilha_ehVazia(pilha *P);

/* Retorna se a pilha eh cheia ou nao - apenas por compatibilidade */
int pilha_ehCheia(pilha *P);

/* Retorna o elemento no topo da pilha */
void *pilha_topo(pilha *P);

/* Insere um elemento no topo da pilha */
void pilha_insere(pilha *P, void *info);

/* Remove o elemento do topo da pilha */
void *pilha_remove(pilha *P);

/* Retorna o tamanho da Pilha */
int pilha_tamanho(pilha *P);

#endif // _H_PILHA_
