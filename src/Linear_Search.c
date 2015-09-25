#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
 
#define MAX 10
 
using namespace std;
   
int search(int A[MAX], int x){
        bool achou=false;
        int i=0, j, aux;
       
        printf("\n");
       
        while(i<MAX && achou==false){
                if(A[i]==x) achou=true;
                i++;
        }
	i--;
	if(achou) return i;           
        else return -1;       
}
 
int main(void){
        int A[MAX], x, i;
        for(i=0; i<MAX; i++) A[i]=rand()%MAX;
        scanf("%d", &x);
        printf("posicao: %d\n", search(A,x));          
}