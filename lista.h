# fila-Estrutura-de-Dados-

#ifndef _H_LISTA_

#define _H_LISTA_

#define LISTA_VERSAO   0.5

typedef struct _lista lista;

typedef struct _lista {
    void *info;
    lista *prox;
} lista;

/* Cria uma lista com um elemento */
lista *lista_criaNo(void * info);

/* Retorna se a lista eh vazia ou nao */
int lista_ehVazia(lista *L);

/* Insere L2 no final de L */
void lista_insereFim(lista **L, lista *L2);

/* Insere L2 no inicio de L */
void lista_insereInicio(lista **L, lista *L2);

/* Insere L2 na i-esima posicao de L */
void lista_inserePos(lista **L, lista *L2, int i);

/* Remove o primeiro elemento da lista */
lista *lista_removeInicio(lista **L);

/* Remove o último elemento da lista */
lista *lista_removeFim(lista **L);

/* Remove o i-ésimo elemento da lista */
lista *lista_removePos(lista **L, int i);

/* Retorna o número de elementos na lista*/
int lista_numElementos(lista *L);

/* Retorna a posição de um elemento se existir na lista */
int lista_busca(lista *L, void *info, int (*comp)(void *, void *));

/* Libera memória removendo todos os elementos da lista */
void lista_libera(lista **L);


#endif // _H_LISTA_
