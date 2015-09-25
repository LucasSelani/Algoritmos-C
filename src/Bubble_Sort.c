#include <stdlib.h>

int main()
{
	int teste[10];
	int i, j, aux;
	
	for(i=0; i<10; i++) scanf("%d",&teste[i]);
	
	printf("Desordenado:\n");
	
	for(i=0; i<10; i++)	printf("T[%d] = %d\n", i, teste[i]);
	
	for(j=9; j>=0; j--)
	{
		for(i=0; i<j; i++)
		{	
			if(teste[i] < teste[i+1])
			{
				aux = teste[i];
				teste[i] = teste[i+1];
				teste[i+1] = aux;
			}
		}
	}
	
	printf("Ordenado:\n");
	
	for(i=0; i<10; i++)	printf("T[%d] = %d\n", i, teste[i]);
	
	return 0;
}
