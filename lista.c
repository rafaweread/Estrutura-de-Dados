# fila-Estrutura-de-Dados-

/* *****************************
	Compilar usando:
	gcc -c lista.c
***************************** */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Cria uma lista com um elemento */
lista *lista_criaNo(void * info) {
    lista *aux;

    aux = (lista *) malloc (sizeof(lista));
    if (aux != NULL) {
        aux->info = info;
        aux->prox = NULL;
    }
    return aux;
}

/* Retorna se a lista eh vazia ou nao */
int lista_ehVazia(lista *L) {
    return (L == NULL);
}

/* Insere L2 no final de L */
void lista_insereFim(lista **L, lista *L2) {
	if (L != NULL) {
		if (lista_ehVazia(*L)) {
			*L = L2;
		} else {
			lista_insereFim(&((*L)->prox), L2);
		}
	}
}

/* Insere L2 no inicio de L */
void lista_insereInicio(lista **L, lista *L2) {
	if (L != NULL) {
		lista_insereFim(&L2, (*L));
		*L = L2;
	}
}

/* Insere L2 na i-esima posicao de L */
void lista_inserePos(lista **L, lista *L2, int i) {
    if (i <= 1) {
        lista_insereInicio(L, L2);
    } else if (L != NULL) {
		if (lista_ehVazia(*L)) {
			/* lista_insereFim(L, L2); */
			*L = L2;
		} else {
			lista_inserePos(&((*L)->prox), L2, i-1);
		}
	}
}

/* Remove o primeiro elemento da lista */
lista *lista_removeInicio(lista **L) {
	lista *aux;

	if (L != NULL) {
		if (lista_ehVazia(*L)) {
				return NULL;
		} else {
			aux = *L;
			*L = (*L)->prox;
			aux->prox = NULL;
			return aux;
		}
	}
}

/* Remove o último elemento da lista */
lista *lista_removeFim(lista **L){
	lista *aux;

	if (L != NULL) {
		if (lista_ehVazia(*L)) {
			return NULL;
		} else if (lista_ehVazia((*L)->prox)) {
			aux = (*L);
			*L = NULL;
			return aux;
		} else {
			aux = lista_removeFim(&((*L)->prox));
			return aux;
		}
	}
}

/* Remove o i-ésimo elemento da lista */
lista *lista_removePos(lista **L, int i){
	lista *aux;

	if (L != NULL) {
		if (lista_ehVazia(*L)) {
			return NULL;
		} else if (i <= 1) {
			aux = lista_removeInicio(L);
			return aux;
		} else {
			aux = lista_removePos(&(*L)->prox, i-1);
			return aux;
		}
	}
}

/* Retorna o número de elementos na lista*/
int lista_numElementos(lista *L){
	if (lista_ehVazia(L)) {
	    return 0;
	} else {
		return (lista_numElementos(L->prox) + 1);
	}
}

/* Retorna a posição de um elemento se existir na lista */
int lista_busca(lista *L, void * info, int (*comp)(void *, void *)) {
	int res;
	
	if (lista_ehVazia(L)) {
		return 0;
	} else {
		if (comp(L->info, info)==0) {
			return 1;
		} else {
			res = lista_busca(L->prox, info, comp);
			if (res != 0) {
				res = res + 1;
			}
			return res;
		}
	}
}

/* Libera memória removendo todos os elementos da lista */
void lista_libera(lista **L) {
	if (L != NULL) {
		if (!lista_ehVazia(*L)) {
			lista_libera(&((*L)->prox));
			free(*L);
			*L = NULL;
		}
	}
}
