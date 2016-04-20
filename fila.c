#include <stdio.h>
#include "fila.h"
#include "lista.h"

/* Cria uma fila vazia */
fila *fila_cria() {
	fila *aux = (fila *) malloc(sizeof(fila));
	if (aux != NULL) {
		aux->itens = aux->pri = aux->ult = NULL;
		aux->tamanho = 0;
	}
	
	return aux;
}

/* Libera memória removendo a fila e seus elementos */
void fila_elimina(fila **F) {
	if (F != NULL && *F != NULL) {
		lista_libera( &((*F)->itens) );
		free(*F);
		*F = NULL;
	}
	return;
}

/* Retorna se a fila eh vazia ou nao */
int fila_ehVazia(fila *F) {
	return 0;
}

/* Retorna se a fila eh cheia ou nao - apenas por compatibilidade */
int fila_ehCheia(fila *F) {
	return 0;
}

/* Insere um elemento na fila */
void fila_insere(fila *F, void *info) {
	lista *aux;
	
	if (F != NULL) {
	  aux = lista_criaNo(info);
	  if (aux == NULL)
	      return;
	  
	  if (fila_ehVazia(F)) {
		  F->itens = F->pri = F->ult = aux;
	  } else {
		  lista_insereFim(&(F->ult), aux);
		  F->ult = aux;
	  }

	  F->tamanho = F->tamanho + 1;
	}
	
	return;
}

/* Remove um elemento da fila */
void *fila_remove(fila *F) {
	lista *aux;
	void *info = NULL;

	if (F != NULL && !fila_ehVazia(F)) {		
        aux = lista_removeInicio(&(F->itens));
        info = aux->info;
        lista_libera(&aux);
        F->pri = F->itens;
		F->tamanho = F->tamanho - 1;
		if (F->pri == NULL)
		    F->ult = NULL;
    }
	
	return info;
}

/* Retorna o primeiro elemento da fila */
void *fila_primeiro(fila *F) {
	return NULL;
}

/* Retorna o ultimo elemento da fila */
void *fila_ultimo(fila *F) {
	void *info = NULL;
	
	if (F != NULL && !fila_ehVazia(F))
	    info = F->ult->info;
	    
    return info;
}

/* Retorna o tamanho da fila */
int fila_tamanho(fila *F) {
	return 0;
}

