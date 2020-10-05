#include<stdio.h>
#include<math.h>

int main()
{
	int kasus;
	int permen, count=0;
	int j, i, max;
	
	scanf("%d", &kasus);
	for(i=0; i<kasus; i++)
	{
		scanf("%d", &permen);
		if(permen<=100000)
		{
			for(j=1; j<=permen; j++)
			{
				if(permen%j==0)
				{
					count++;
				}
			}
		}
		else
		{
			for(j=1; j<=sqrt(permen); j++)
			{
				if(permen%j==0)
				{
					count++;
				}
			}
			count = count*2;
			if(permen==1000000)
			{
				count--;
			}
			if(permen==100000000)
			{
				count--;
			}
		}
		printf("Case #%d: %d\n", i+1, count);
		count=0;
	}
	
	
	return 0;
}
