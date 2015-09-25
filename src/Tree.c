#include <stdlib.h>
#include <stdio.h>

typedef struct TREE{
	char nome[20];
	int id;
	struct TREE *right;
	struct TREE *left;
	struct TREE *pai;
}tree;

tree *node;

typedef struct TAG{
	struct TREE *root;
	struct TREE *aux;
}tag;

void strcopy(char *str1, char *str2){
	int i = 0;	
	while(str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

int strcomp(char *str1, char *str2){
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] < str2[i]) return -1;
		else if(str1[i] > str2[i]) return 1;
		i++; 
	}
	if(str1[i] == '\0' && str2[i] == '\0') return 0;
	else if(str1[i] == '\0' && str2[i] != '\0') return -1;	
	else if(str1[i] != '\0' && str2[i] == '\0') return 1;
}

int busca(char *nome){
	
}

/*void listagem(tree *buffer){
	if(buffer->left != NULL) listagem(buffer->left);
	printf("%s - %d\n", buffer->nome, buffer->id);
	if(buffer->right != NULL) listagem(buffer->right);
}*/

void arvorizar(char *A, int id, tag *arvore){
	node = (tree*) malloc(sizeof(tree));

	strcopy(node->nome, A);
	node->id = id;
	node->right = NULL;
	node->left = NULL;

	if(arvore->root == NULL) arvore->root = node;	
	else{
		arvore->aux = arvore->root;		
		while(1){
			if(strcomp(arvore->aux->nome, node->nome) > 0){
				if(arvore->aux->left == NULL){
					arvore->aux->left = node;
					break;
				}
				else arvore->aux = arvore->aux->right;
			}
			else{
				if(arvore->aux->right == NULL){
					arvore->aux->right = node;
					break;
				}
				else arvore->aux = arvore->aux->left;
			}
		}
	}
	arvore->aux = NULL;
	return;
}

int main(){
	tag arvre;
	arvre.root = NULL;
	arvre.aux = NULL;

	while(1){
		int id, op = 0;
		char nome[20];

		scanf("%s", nome);
		scanf("%d", &id);		
		arvorizar(&nome[20], id, &arvre);

		printf("Aperte 1 para sair");
		scanf("%d", &op);
		if(op == 1) break;
	}
	//listagem(&arvre);


	return 0;
}








