# fila-Estrutura-de-Dados-


#include <stdio.h>
#include "fila.h"
#include "lista.h"
#include <malloc.h>

/* Cria uma fila vazia */
fila *fila_cria() {

    fila *aux =(fila*) malloc(sizeof(*f));
    f->pri = 0;
    f->ult = 0;
    f->itens = 0;
    f->tamanho = 0;

	return f;
}

/* Libera memória removendo a fila e seus elementos */
void fila_elimina(fila **F) {
    if(F!=NULL){
        lista_libera(&((*F)->itens));
        free(*F);
        *F = NULL;

}}

/* Retorna se a fila eh vazia ou nao */
int fila_ehVazia(fila *F) {

//    lista_ehVazia(*F);
    return (F == NULL);

}

/* Retorna se a fila eh cheia ou nao - apenas por compatibilidade */
int fila_ehCheia(fila *F) {
	return (F->tamanho == F->ult);
}

/* Insere um elemento na fila (resolução está em uma foto no celular)*/
void fila_insere(fila *F, void *info) {
	return;
}

/* Remove um elemento da fila */
void *fila_remove(fila *F) {
	return NULL;
}

/* Retorna o primeiro elemento da fila */
void *fila_primeiro(fila *F) {
	return NULL;
}

/* Retorna o ultimo elemento da fila */
void *fila_ultimo(fila *F) {
	return NULL;
}

/* Retorna o tamanho da fila */
int fila_tamanho(fila *F) {
	return 0;
}
