#include<stdio.h>

int main()
{
	int kasus;
	int panjang, lebar;
	int i, j, k;
	
	scanf("%d", &kasus); getchar();
	for(i=0; i<kasus; i++)
	{
		scanf("%d %d", &panjang, &lebar); getchar();
		printf("Case #%d:\n", i+1);
		for(j=panjang; j>0; j--)
		{
			printf("#");
		}
	}
	
	return 0;
}
