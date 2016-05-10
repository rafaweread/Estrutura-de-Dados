#include <stdio.h>
#include "buffer.h"

/* Cria uma buffer vazia */
buffer *buffer_cria(int tamMaximo) {
	buffer *aux;
	
	if (tamMaximo <= 0)
		return NULL;
		
	aux = (buffer *) malloc(sizeof(buffer));
	if (aux != NULL) {
		aux->pri = aux->tamanho = 0;
		aux->ult = -1;
		aux->tamMax = tamMaximo;
		aux->itens = (void *) malloc(sizeof(void *)*tamMaximo);
	}
	return aux;
}

/* Libera memória removendo a buffer e seus elementos */
void buffer_elimina(buffer **B) {
	if (B != NULL && *B != NULL) {
		free((*B)->itens);
		free(*B);
		*B = NULL;
	}
	return;
}

/* Retorna se a buffer eh vazia ou nao */
int buffer_ehVazia(buffer *B) {
	if (B != NULL) {
		return (B->tamanho == 0);
	}
	
	return 0;
}

/* Retorna se a buffer eh cheia ou nao - apenas por compatibilidade */
int buffer_ehCheia(buffer *B) {
	if (B != NULL) {
		return (B->tamanho == B->tamMax);
	}
	
	return 0;
}

/* Insere um elemento no topo da buffer */
void buffer_insere(buffer *B, void *info) {
	if (B != NULL && !buffer_ehCheia(B)) {
		B->itens[(B->ult + 1) % B->tamMax] = info;
		B->ult = (B->ult + 1) % B->tamMax;
		B->tamanho = B->tamanho + 1;
	}
	return;
}

/* Remove o elemento do topo da buffer */
void *buffer_remove(buffer *B) {
	void *info = NULL;
	
	if (B != NULL && !buffer_ehVazia(B)) {
		info = B->itens[B->pri];
		B->pri = (B->pri + 1) % B->tamMax;
		B->tamanho = B->tamanho - 1;
    }
	return info;
}

/* Retorna o primeiro elemento da buffer */
void *buffer_primeiro(buffer *B) {
	return NULL;
}

/* Retorna o ultimo elemento da buffer */
void *buffer_ultimo(buffer *B) {
	void *info = null;
	if(B!=null && !buffer_ehVazia(B))
		info = B ->itens(B->ult);
	return NULL;
}

/* Retorna o tamanho da buffer */
int buffer_tamanho(buffer *B) {
	if(B!=null && !)
	return 0;
}

