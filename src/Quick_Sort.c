#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int PARTITION(int A[MAX], int p, int r){
	int x, i, j, aux1, aux2, a;
	//printf("PART p=%d r=%d\n",p,r);
	x = A[r];
	i = p-1;
	for(j=p;j<r;j++){
		if(A[j]<=x){
			i++;
			aux1 = A[i];
			A[i] = A[j];
			A[j] = aux1;
		}
	}
	aux2 = A[i+1];
	A[i+1] = A[r];
	A[r] = aux2;
	//printf("\n\n");
	//printf("i=%d\n",i);
	//for(a=0; a<MAX; a++) printf("A[%d]=%d\n", a, A[a]);
	return i+1;
}

int QUICKSORT(int A[MAX], int p, int r){
	int i, q;
	
	if(p<r){
		q = PARTITION(A,p,r);
		//printf("ANTES p=%d q=%d r=%d\n",p,q,r);
		//printf("q=%d\n", q);
		QUICKSORT(A,p,q-1);
		QUICKSORT(A,q+1,r);
	}
}

int main(){
	int p, r, i, med, aux;
	int A[MAX];
	//medi mediana;
	for(i=0;i<MAX;i++) A[i]=MAX-i;
	//for(i=0; i<MAX; i++) printf("INICIO A[%d]=%d\n", i, A[i]);	
	p = 0;
	r = MAX-1;	
	/*srand(time(NULL));
	for(i=0;i<3;i++){
		mediana.pos[i]=rand()%MAX-1;
		mediana.num[i]=A[mediana.pos[i]];
	}
	if((mediana.num[0] >= mediana.num[1] && mediana.num[0] <= mediana.num[2]) || (mediana.num[0] >= mediana.num[2] && mediana.num[0] <= mediana.num[1])) med=mediana.pos[0];
	else if((mediana.num[1] >= mediana.num[0] && mediana.num[1] <= mediana.num[2]) || (mediana.num[1] >= mediana.num[2] && mediana.num[1] <= mediana.num[0])) med=mediana.pos[1];
	else if((mediana.num[2] >= mediana.num[1] && mediana.num[2] <= mediana.num[0]) || (mediana.num[2] >= mediana.num[0] && mediana.num[2] <= mediana.num[1])) med=mediana.pos[2];
	aux = A[r];
	A[r] = A[med];
	A[med] = aux;*/
	QUICKSORT(A,p,r);
	printf("\n\n");
	//for(i=0; i<MAX; i++) printf("FINAL A[%d]=%d\n", i, A[i]);
	return 0;
}
