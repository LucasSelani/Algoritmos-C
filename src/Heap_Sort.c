#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
int size = MAX;

int LEFT(int i){
	return 2*(i+1)-1;
}

int RIGHT(int i){
	return 2*(i+1);
}

int MAX_HEAPIFY(int A[size], int i){
	int maior, aux, l, r, k;
	bool passou=false;
	do{
		if(passou) i=maior;
		l = LEFT(i);
		r = RIGHT(i);
		if(l<size && A[l]>A[i]) maior = l;
        else maior = i;
		if(r<size && A[r]>A[maior]) maior = r;
		if(maior!=i){
			aux = A[i];
			A[i] = A[maior];
			A[maior] = aux;
			passou = true;
			printf("maior=%d l=%d r=%d\n",maior,l,r);
			for(k=0; k<MAX; k++) printf("MAX A[%d]=%d\n", k, A[k]);
		}
	}while(i!=maior);
	return;
}

int HEAPSORT(int A[MAX]){
	int i,j, aux;
	for(i=MAX-1; i>=1; i--){
		aux = A[0];
		A[0] = A[i];
		A[i] = aux;
		size--;
		MAX_HEAPIFY(A,0);
		}
}

int BUILD_MAX_HEAP(int A[MAX]){
	int i, j;
	size = MAX;
	for(i=(MAX/2)-1; i>=0; i--) MAX_HEAPIFY(A,i);
}

int main(){
	int i;
	int A[MAX];
	for(i=0;i<MAX;i++) A[i]=rand()%MAX;
	for(i=0; i<MAX; i++) printf("INICIO A[%d]=%d\n", i, A[i]);
	BUILD_MAX_HEAP(A);
	HEAPSORT(A);
	for(i=0; i<MAX; i++) printf("FINAL A[%d]=%d\n", i, A[i]);
	return 0;
}


