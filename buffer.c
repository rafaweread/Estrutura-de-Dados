# fila-Estrutura-de-Dados-

/* *****************************
	Compilar usando:
	gcc -c buffer.c
***************************** */
#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

/* Cria uma buffer vazia */
buffer *buffer_cria(int tamMax) {
    if(tamMax > 0){
        buffer *aux     = (buffer *) malloc( sizeof(buffer) );
        aux->tamMax     = tamMax;
        aux->tamanho    = 0;
        aux->pri        = 0;
        aux->ult        = 0;
        aux->itens      = (void **) malloc( tamMax * sizeof(void *) );
        return aux;
    }else{
        return NULL;
    }
}

/* Libera memória removendo a buffer e seus elementos */
void buffer_elimina(buffer **B){
    if( B != NULL ){
        free((*B)->itens);
        free(*B);
        B = NULL;
    }
}

/* Retorna se a buffer eh vazia ou nao */
int buffer_ehVazia(buffer *B) {
	if( B != NULL ){
        return B->tamanho == 0;
    }else{
        return 1;
    }
}

/* Retorna se a buffer eh cheia ou nao */
int buffer_ehCheia(buffer *B) {
    if( B != NULL ){
        return B->tamanho == B->tamMax;
    }else{
        return 1;
    }
}

/* Insere um elemento no topo da buffer */
void buffer_insere(buffer *B, void *info) {
    if( B != NULL ){
        if(B->tamanho != B->tamMax){
            B->tamanho += 1;
            B->ult += 1;
            if(B->ult == B->tamMax){
                B->ult = 0;
            }
            *(B->itens + B->ult) = info;
        }
    }
}

/* Remove o elemento do topo da buffer */
void *buffer_remove(buffer *B) {
    if( B != NULL ){
        if(B->tamanho > 0){
            void *aux = *(B->itens + B->pri);
            B->tamanho -= 1;
            B->pri += 1;
            if(B->pri == B->tamMax){
                B->pri = 0;
            }
            return aux;
        }    
    }
}

/* Retorna o primeiro elemento da buffer */
void *buffer_primeiro(buffer *B) {
	if( B != NULL ){
        return *(B->itens + B->pri);
    }else{
        return NULL;
    }
}

/* Retorna o ultimo elemento da buffer */
void *buffer_ultimo(buffer *B) {
	if( B != NULL ){
        return *(B->itens + B->ult);
    }else{
        return NULL;
    }
}

/* Retorna o tamanho da buffer */
int buffer_tamanho(buffer *B) {
	if( B != NULL ){
        return B->tamanho;
    }else{
        return 0;
    }
}
