#include <stdlib.h>
#include <stdio.h>

typedef struct BOX{
	char letra;
	struct BOX *proximo;
}box;

typedef struct TAG{
	box *inicio;
	box *fim;
}tag;

void enqueue(char A, tag* tag){
	box *node = (box*) malloc(sizeof(box));

	node->letra = A;
	node->proximo = NULL;

	if(tag->fim == NULL) tag->inicio = node;
	if(tag->fim != NULL) (tag->fim)->proximo = node;
	
	tag->fim = node;
}

void push(char A, tag* tag){
	box *node = (box*) malloc(sizeof(box));

	node->letra = A;	
	if(tag->inicio == NULL){
		tag->fim = NULL;
		node->proximo = NULL;
	}	
	if(tag->inicio != NULL) node->proximo = tag->inicio;
	tag->inicio = node;
}

void search(char A, tag* tag){
	box *aux = tag->inicio;
	int i = 1;
	
	if(tag->inicio){
		do{		
			if(aux->letra == A){
				printf("A letra '%c' é a %dº letra da palavra ", A, i);
				break;
			}
			else aux = aux->proximo;
			i++;
		}while(aux != NULL);
		if(aux == NULL) printf("A letra '%c' não foi encontrada ", A);
	}
	else printf("Não tem nenhuma palavra para buscar ");
}

char delete(tag* tag){
	char A;
	box* aux;
	
	if(tag->inicio){
		aux = tag->inicio;
		tag->inicio = aux->proximo;
		A = aux->letra;
		free(aux);
		if(!tag->inicio) tag->fim = NULL;
	}
	return A;
}

void limpaMemoria(tag* tag){
	box *aux;

	if(tag->inicio){	
		while(tag->inicio != NULL){
			aux = tag->inicio;
			tag->inicio = (tag->inicio)->proximo;
			free(aux);
			if(!tag->inicio) tag->fim = NULL;
		}
	}
}

int main(){
	
	char letra;
	int op;

	//Criando nós		
	tag fila;
	tag pilha;

	//Setando nós
	fila.inicio = NULL;
	fila.fim = NULL;
	pilha.inicio = NULL;
	pilha.fim = NULL;

	//Lendo palavra	
	__fpurge(stdin);
	printf("Digite uma palavra: ");
	while(scanf("%c", &letra) && letra != '\n'){
		enqueue(letra, &fila);
		push(letra, &pilha);
	}
	printf("\n");

	//Buscando letra
	__fpurge(stdin);	
	printf("Qual letra deseja buscar?\nLetra: ");
	scanf("%c", &letra);			
	search(letra, &fila);
	printf("na fila\n");
	search(letra, &pilha);
	printf("na pilha\n");
	printf("\n");

	//Imprime a string
	printf("Seu nome é: ");
	while(fila.inicio != NULL)	printf("%c", delete(&fila));
	printf("\n");
		
	printf("Seu nome ao contrário é: ");
	while(pilha.inicio != NULL)	printf("%c", delete(&pilha));
	printf("\n");
	

	
	//Limpa memória
	limpaMemoria(&fila);
	limpaMemoria(&pilha);

	return 0;
}
