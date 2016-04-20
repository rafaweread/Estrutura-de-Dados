# fila-Estrutura-de-Dados-

/*          
 * listaLig.c
 * Autor: Nielsen Cassiano Simoes
 * Comentarios:
 *	Este arquivo nao deve ser alterado. Para compilar este programa,
 *	utilize a seguinte linha de comando (Linux): *	
 *	gcc usaLista.c listas.o -o usaLista
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "listas.h"

void imprimir(lista *lstInt) {      
	if (lstInt != NULL) {
		printf("%d --> ", lstInt->info);
		imprimir(lstInt->prox);
	} else {
		printf("NULL\n");
	}
}

int comparaNohs(tdado a, tdado b) {
	if (a == b)
		return 0;
	else if (a > b)
		return -1;
	else
		return 1;
}

//Funcao principal
int main() {
	//-------------------------------------------------------
	//Para saber a memoria dinamica foi desalocada - Ignore
	#ifdef __linux__
	struct mallinfo info = mallinfo ();
	int MemDinInicial = info.uordblks, MemDinFinal;
	#endif
	//-------------------------------------------------------
	 
	lista *lstNo  = NULL;
	lista *lstInt = NULL; 
	
	int op = 0; //controle do menu
	int valor, pos;
	
	do {
		printf("\n=====================================\n");
		if (!lstNo) {
			printf("1 - CriaNo\t\t");
			printf("(nao pode inserir)\t");
			printf("(nao pode inserir)\n");
			printf("(nao pode inserir)\t");
		} else {
			printf("(Noh criado)\t\t");
			printf("2 - Inserir Fim\t\t");
			printf("3 - Inserir Inicio\n");
			printf("4 - Inserir Posicao\t");
		}
		printf("5 - Remover Primeiro\t");
		printf("6 - Remover Ultimo\n");
		printf("7 - Remover Pos\t\t");
		printf("8 - Buscar Elemento\t");
		printf("9 - Qtdade de Elementos\n");			 
		printf("10- Imprimir Lista\t");
		printf("0 - Sair\n");
		printf("Escomodelo para lha a opcao: ");
		scanf("%d", &op);
		printf("=====================================\n");
		switch(op) {
			case 0:
				break;
			case 1:
				if (lstNo) break; /* Jah existe um noh criado */
				printf("Digite o valor do novo elemento:\n");
				scanf("%d", &valor);
				lstNo = lista_criaNo(valor);
				if (!lista_ehVazia(lstNo))
					printf("Noh de valor %d criado.\n", valor);
				else
					printf("Erro ao criar noh.\n");
				break;
			case 2:
				if (!lstNo) break; /* Nao existe um noh criado */
				lista_insereFim(&lstInt, lstNo);
				printf("Noh Inserido.\n");
				lstNo = NULL;
				break;
			case 3:
				if (!lstNo) break; /* Nao existe um noh criado */
				lista_insereInicio(&lstInt, lstNo);
				printf("Noh Inserido.\n");
				lstNo = NULL;
				break;
			case 4:
				if (!lstNo) break; /* Nao existe um noh criado */
				printf("Digite a posicao para insercao:\n");
				scanf("%d", &pos);
				lista_inserePos(&lstInt, lstNo, pos);
				printf("Noh Inserido.\n");
				lstNo = NULL;
				break;
			case 5:
				lstNo = lista_removeInicio(&lstInt);
				if (!lista_ehVazia(lstNo)) {
					printf("Removido %d da lista.\n", lstNo->info);
					lista_libera(&lstNo);
				}
				break;
			case 6:
				lstNo = lista_removeFim(&lstInt);
				if (!lista_ehVazia(lstNo)) {
					printf("Removido %d da lista.\n", lstNo->info);
					lista_libera(&lstNo);
				}
				break;
			case 7:
				printf("Digite a posicao para remocao:\n");
				scanf("%d", &pos);
				lstNo = lista_removePos(&lstInt, pos);
				if (!lista_ehVazia(lstNo)) {
					printf("Removido %d da lista.\n", lstNo->info);
					lista_libera(&lstNo);
				} else
					printf("Elemento nao encontrado.\n");
				break;
			case 8:
				printf("Digite o valor do elemento a ser procurado:\n");
				scanf("%d", &valor);
				if (!lista_ehVazia(lstInt)) {
					pos = lista_busca(lstInt, valor, &comparaNohs);
					if (pos)
						printf("Elemento de valor %d encontrado na posicao %d\n", valor, pos);
					else
						printf("Elemento de valor %d nao encontrado na lista\n", valor);
				} else
					printf("Elemento nao encontrado.\n");
				break;
			case 9:
				if (!lista_ehVazia(lstInt))
					printf("A lista possui %d elemento(s)\n", lista_numElementos(lstInt));
				else
					printf("Lista Vazia!\n");
				break;
			case 10:
				if (!lista_ehVazia(lstInt))
					imprimir(lstInt);
				else
					printf("Lista Vazia!\n");
				break;
			default:
				printf("Opcao invalida.\n");
		}
	} while (op != 0);

	lista_libera(&lstNo); //Desalocando a memoria
	lista_libera(&lstInt); //Desalocando a memoria
	printf("\n");

	//--------------------------------------------------------------------
	//Codito para verificar se toda memoria alocada foi desalocada - Ignore
	#ifdef __linux__
	info = mallinfo ();
	MemDinFinal = info.uordblks;
	if (MemDinInicial!=MemDinFinal)
	 printf("\n\nMemoria dinamica nao foi totalmente liberada (%d, %d)\n", MemDinInicial,MemDinFinal);
	#endif	 
	//---------------------------------------------------------------------	
	  
	return 0;
}
