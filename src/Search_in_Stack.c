#include <stdlib.h>
#include <stdio.h>

typedef struct BOX{
	int num;
	struct BOX *proximo;
}box;

typedef struct TAG{
	box *inicio;
	box *fim;
}tag;

void push(int A, tag* tag){
	box *node = (box*) malloc(sizeof(box));

	node->num = A;	
	if(tag->inicio == NULL){
		tag->fim = NULL;
		node->proximo = NULL;
	}	
	if(tag->inicio != NULL) node->proximo = tag->inicio;
	tag->inicio = node;
}

void search(int A, tag* tag){
	box *aux = tag->inicio;
	int i = 1;
	
	if(tag->inicio){
		do{		
			if(aux->num == A){
				printf("\nO valor '%d' é o %dº numero da lista (lido a partir do final)\n", A, i);
				break;
			}
			else aux = aux->proximo;
			i++;
		}while(aux != NULL);
		if(aux == NULL) printf("\nO valor '%d' não foi encontrado\n", A);
	}
	else printf("\nA lista está vazia!\n");
}

int pop(tag* tag){
	int A;
	box* aux;
	
	if(tag->inicio){
		aux = tag->inicio;
		tag->inicio = aux->proximo;
		A = aux->num;
		free(aux);
		if(!tag->inicio) tag->fim = NULL;
	}
	return A;
}

void limpaMemoria(tag* tag){
	box *aux;

	while(tag->inicio != NULL){
		aux = tag->inicio;
		tag->inicio = (tag->inicio)->proximo;
		free(aux);
	}
	free(tag->fim);
}

int main(){
	tag pilha; //Criando a lista ligada chamada pilha
	pilha.inicio = NULL; //Setando os valores iniciais
	pilha.fim = NULL;    //da lista ligada para nulo

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
			push(num, &pilha); //Empilhando os valores lidos
		}				
		__fpurge(stdin);
		printf("\nDigite o número que deseja buscar\n");
		scanf("%d", &num);
		search(num, &pilha); //Chamando a função que buscará o número lido
		__fpurge(stdin);
		printf("\nDeseja sair?\n1- Sim\n2- Nao\n");
		scanf("%d", &op);
		if(op == 1){
			limpaMemoria(&pilha);
			break;	
		}
		else if(op == 2){
			__fpurge(stdin);
			printf("Deseja começar uma lista nova?\n1- Sim\n2- Não\n");
			scanf("%d", &op);
			if(op == 1)	limpaMemoria(&pilha);
			else if(op > 2 || op < 1) 
				printf("Opção inválida, reiniciando algoritmo com a mesma lista\n");
		}
		else printf("Opção inválida, reiniciando algoritmo com a mesma lista\n");
		printf("\n\n\n\n");
	}
	return 0;
}