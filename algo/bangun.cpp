#include<stdio.h>

int main()
{
	int a, b, c;
	int j,i;
	
	scanf("%d", &a);
	for(i=1; i<=a; i++)
	{	
		for(j=1; j<=a; j++)
		{
			if (j==1 || j==a || i==1 || i==a)
			printf("#");
			else 
			printf(" ");
		}
		printf("\n");
	}
	

	
	return 0;
}
