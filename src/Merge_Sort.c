#include <stdio.h>

#define MAX 1000000
#define FLAG -9999

int A[MAX];

int MERGE(int p,int q,int r){
	int n1, n2, i, j, k,z;
	//printf("MERGE p=%d q=%d r=%d\n",p,q,r);
	n1 = q-p+1;
	n2 = r-q;
	int L[n1+1], R[n2+1];
	for(i=0; i<n1; i++){
		L[i] = A[p+i];
		//printf("L[%d]=%d\n",i,L[i]);
	}
	for(i=0; i<n2; i++){
		R[i] = A[q+i+1];
		//printf("R[%d]=%d\n",i,R[i]);
	}
	L[n1] = FLAG;
	R[n2] = FLAG;
	i=0;
	j=0;
	for(k=p; k<=r; k++){
		if((L[i]<=R[j] && i!=n1) || j==n2){
			A[k] = L[i];
			i++;
		}
		else if((L[i]>R[j] && j!=n2) || i==n1){
			A[k] = R[j];
			j++;
		}
	}
	//for(z=0; z<MAX; z++) printf("MERGE A[%d]=%d\n", z, A[z]);
}

int MERGE_SORT(int p,int r){
	int q;
	if(p<r){
		q=((p+r)/2);
		//printf("ANTES p=%d q=%d r=%d\n",p,q,r);
		MERGE_SORT(p,q);
		MERGE_SORT(q+1,r);
		MERGE(p,q,r);
	}
}

int main(void){
	int i, p=0, r=MAX-1;	
	for(i=0;i<MAX;i++) A[i]=MAX-i;
	//for(i=0; i<MAX; i++) printf("INICIO A[%d]=%d\n", i, A[i]);	
	MERGE_SORT(p,r);
	//for(i=0; i<MAX; i++) printf("FINAL A[%d]=%d\n", i, A[i]);
	return 0;
}

