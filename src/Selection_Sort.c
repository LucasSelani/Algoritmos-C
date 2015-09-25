#include <stdio.h>
#define MAX 10 

int main()
{
	int teste[MAX] = {62, 89, 71, 12, 16, 14, 3, 1, 23, 8};
	int aux, min, i, j;
	
	printf("Desordenado:\n");
	for(i=0; i<MAX; i++) printf("T[%d] = %d\n", i, teste[i]);
	
	//Selection Sort
	for(i=0; i<MAX;i++)
	{
		min = i;
		for(j=i+1; j<MAX; j++) if(teste[j] < teste[min]) min = j;
		aux = teste[i];
		teste[i] = teste[min];
		teste[min] = aux;
	}
		
	printf("Ordenado:\n");
	for(i=0; i<MAX; i++) printf("T[%d] = %d\n", i, teste[i]);

	return 0;	
}
