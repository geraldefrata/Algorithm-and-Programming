#include<stdio.h>

int main()
{
	int kasus, n, t;
	
	scanf("%d", &kasus);
	
	int input[kasus], jumlah_prima[kasus]={0};
	for(int i=0; i<kasus; i++)
	{
		scanf("%d", &input[i]);
		
		for(n=1; n<=input[i]; n++)
		{
			for(t=2; t<n; t++)
			{
				if(n%t==0)
				{
					break;
				}
			}if(n==t)
			{
				jumlah_prima[i]++;
			}
		}
	}
	for(int l=0; l<kasus; l++)
	{
		printf("Case #%d:\n", l+1);
		for(int m=0; m<jumlah_prima[l]; m++)
		{
			printf("I will become a good boy.\n");
		}
	}
	
	return 0;
}
