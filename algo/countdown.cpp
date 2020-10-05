#include<stdio.h>

int main()
{
	int kasus, detik;
	int i, j, k;
	
	scanf("%d", &kasus);
	for(i=0; i<kasus; i++)
	{
		scanf("%d", &detik);
		printf("Case #%d:\n", i+1);
		for(j=detik; j>0; j--)
		{
			if(detik==j || j==5 || j==10 || j==30 || j==60)
			{
				printf("%d SECONDS TILL NEW YEAR!!\n", j);
			}
			else
			{
				printf("%d\n", j);
			}
		}
	}
	
	
	return 0;
}
