#include <stdio.h>
#define MAX 100

int main()
{
	int teste[MAX];
	int eleito, i, j,a;
	
	for(i=0; i<MAX; i++) teste[i] = MAX-i;
	
	for(i=1; i<MAX; i++)
	{
		eleito = teste[i];	
		j = i-1;
		while((j>=0) && (eleito < teste[j]))
		{
			teste[j+1] = teste[j];
			j--;
		}
		teste[j+1] = eleito;
		//for(a=0; a<MAX; a++) printf("T[%d] = %d\n", a, teste[a]);
	}
	
	//printf("Ordenado:\n");
	//for(i=0; i<MAX; i++) printf("T[%d] = %d\n", i, teste[i]);

	return 0;	
}
