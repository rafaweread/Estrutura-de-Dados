# fila-Estrutura-de-Dados-

/* *****************************
	Compilar usando:
	gcc -c pilha.c
***************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

/* Cria uma pilha vazia */
pilha *pilha_cria() {
	pilha *aux = (pilha *) malloc(sizeof(pilha));
    if( aux != NULL ){
        aux->itens = NULL;
        aux->tamanho = 0;
    }
    return aux;
}

/* Libera memória removendo a pilha e seus elementos */
void pilha_elimina(pilha **P) {
	if( P!= NULL ){
        lista_libera(&(*P)->itens);
        free(*P);
        *P=NULL;
    }
}

/* Retorna se a pilha eh vazia ou nao */
int pilha_ehVazia(pilha *P) {
	return P->tamanho == 0;
}

/* Retorna se a pilha eh cheia ou nao - apenas por compatibilidade */
int pilha_ehCheia(pilha *P) {
	return 0;
}

/* Retorna o elemento no topo da pilha */
void *pilha_topo(pilha *P) {
    if( P != NULL && P->tamanho != 0){
        return P->itens->info;
    }else{
        return NULL;
    }
	
}

/* Insere um elemento no topo da pilha */
void pilha_insere(pilha *P, void *info) {
    if( P != NULL ){
        lista *aux = lista_criaNo(info);
        lista_insereInicio(&(P->itens),aux);
        P->tamanho += 1;
    }
	return;
}

/* Remove o elemento do topo da pilha */
void *pilha_remove(pilha *P) {
    if( P != NULL && P->tamanho != 0){
        lista *aux = lista_removeInicio(&(P->itens));
        P->tamanho -= 1;
        return aux->info;
    }else {
        return NULL;
    }
}

/* Retorna o tamanho da Pilha */
int pilha_tamanho(pilha *P) {
    if( P != NULL ){
        return P->tamanho;
    }else{
        return 0;
    }
}
