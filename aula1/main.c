#include <stdio.h>
#include <stdlib.h>

/*
 * @author: Lucas Gomes Santana
 * Exercício de aula 1. 
 */
typedef struct N{
    char *valor;
    struct N *anterior;
} node;

void imprimir(node *ultimo) {
    printf("\n\nNomes digitados:\n");
    node *atual = ultimo;
    while(atual != NULL) {
        printf("%s\n", atual->valor);
        atual = atual->anterior;
    }
}

int main(){
    node *ultimo = NULL;
    node *n;

    int numeroNomes;
    printf("Digite o numero de nomes a ser digitado: ");
    scanf("%d", &numeroNomes);

	int i;
    printf("\n\nDigite os nomes separados por ENTER: \n");
	for(i = 0; i < numeroNomes; i++) {
        char *nome = malloc(50*sizeof(char));
		scanf("%s", nome); 
	    
	    n = (node *)malloc(sizeof(node));
        n->valor = nome;
        n->anterior = ultimo;
	    ultimo = n;
	}

    imprimir(ultimo);

    // Limpando
    node *atual = ultimo;
    while(atual != NULL) {
        node *temp = atual->anterior;
        free(atual->valor);
        free(atual);
        atual = temp;
    }

    return 0;
}