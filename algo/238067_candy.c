#include <stdio.h>
#include <math.h>
int main()
{
	int k,kasus;
	int permen,count=0;
	int i,f,max;
	
	scanf("%d",&kasus);
	for(k=1;k<=kasus;k++)
	{			
		scanf("%d", &permen);
		if(permen<=100000)
		{
			for(i=1;i<=permen;i++)
			{
				if(permen%i == 0)
				{
					count++;
				}
    		}
    	}
    	else
    	{
    		for(i=1;i<=sqrt(permen);i++)
			{
				if(permen%i == 0)
				{
					count++;
				}
    		}
    		count = count*2;
    		if(permen == 1000000)
    		{
    			count--;
			}
			if(permen == 100000000)
    		{
    			count--;
			}
		}
		printf("Case #%d: %d\n",k,count);
		count=0;
	}
	return 0;
}
