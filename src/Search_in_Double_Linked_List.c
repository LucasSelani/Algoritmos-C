#include <stdlib.h>
#include <stdio.h>

typedef struct DUALBOX{
	int letra;
	struct DUALBOX *proximo;
	struct DUALBOX *anterior;
}dualbox;

typedef struct TAG{
	dualbox *inicio;
	dualbox *fim;
}tag;

void listadupla(int A, tag* tag){
	dualbox *node = (dualbox*) malloc(sizeof(dualbox));

	node->letra = A;
	node->proximo = NULL;

	if(tag->inicio == NULL){
		node->anterior = NULL;
		tag->inicio = node;	
	}
	if(tag->fim != NULL){
		(tag->fim)->proximo = node;
		node->anterior = tag->fim;


	}
	tag->fim = node;
}	

void searchinicio(int A, tag* tag){
	dualbox *aux = tag->inicio;
	int i = 1;
	
	if(tag->inicio){
		do{		
			if(aux->letra == A){
				printf("O valor '%d' é a %dº elemento da lista olhando a partir do inicio\n", A, i);
				break;
			}
			else aux = aux->proximo;
			i++;
		}while(aux != NULL);
		if(aux == NULL) printf("O valor '%d' não foi encontrada\n", A);
	}
	else printf("Não tem nenhum elemento para buscar\n");
}

void searchfim(int A, tag* tag){
	dualbox *aux = tag->fim;
	int i = 1;
	
	if(tag->fim){
		do{		
			if(aux->letra == A){
				printf("O valor '%d' é a %dº elemento da lista olhando a partir do fim\n", A, i);
				break;
			}
			else aux = aux->anterior;
			i++;
		}while(aux != NULL);
		if(aux == NULL) printf("O valor '%d' não foi encontrada\n", A);
	}
	else printf("Não tem nenhum elemento para buscar\n");
}

int delete(tag* tag){
	int A;
	dualbox* aux;
	
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
	dualbox *aux;

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
	tag lista; //Criando a lista ligada chamada lista
	lista.inicio = NULL; //Setando os valores iniciais
	lista.fim = NULL;    //da lista ligada para nulo

	int num = 0; //Variável que irá receber os valores lidos
	int op = 0, i = 0; //Variável de navegação no algoritmo e variavel de controle
	int qtd = 0; //Variável que irá receber a quantidade de valores que serão lidos
	while(1){
		__fpurge(stdin);
		printf("Deseja encadear quantos números?\n");
		scanf("%d", &qtd);
		__fpurge(stdin);
		printf("\nDigite os números que serão encadeados\n");		
		for(i=0; i<qtd; i++){ //Lendo até a quantidade que o usuario escolheu
			scanf("%d", &num);
			listadupla(num, &lista); //Listando os valores lidos
		}				
		__fpurge(stdin);
		printf("\nDigite o número que deseja buscar\n");
		scanf("%d", &num);
		searchinicio(num, &lista); //Chamando a função que buscará o número lido do inicio
		searchfim(num, &lista); //Chamando a função que buscará o número lido do fim
		__fpurge(stdin);
		printf("\nDeseja sair?\n1- Sim\n2- Nao\n");
		scanf("%d", &op);
		if(op == 1){
			limpaMemoria(&lista);
			break;	
		}
		else if(op == 2){
			__fpurge(stdin);
			printf("Deseja começar uma lista nova?\n1- Sim\n2- Não\n");
			scanf("%d", &op);
			if(op == 1)	limpaMemoria(&lista);
			else if(op > 2 || op < 1) 
				printf("Opção inválida, reiniciando algoritmo com a mesma lista\n");
		}
		else printf("Opção inválida, reiniciando algoritmo com a mesma lista\n");
		printf("\n\n\n\n");
	}
	return 0;
}