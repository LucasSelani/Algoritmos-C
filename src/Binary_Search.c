#include <stdio.h>
 
#define MAX 10
 
int search(int A[MAX], int x){
        int baixo = 0, alto = MAX-1, meio;
        while(baixo<=alto){
                meio=(baixo+alto)/2;
                if(x<A[meio]) alto = meio-1;
                else if(x>A[meio]) baixo = meio+1;
                else return meio;
        }
        return -1;
}
 
int main(void){
        int A[MAX], i, x;
        for(i=0;i<MAX;i++) A[i]=i;
        scanf("%d",&x);
        printf("resultado: %d\n", search(A,x));
        return 0;
}