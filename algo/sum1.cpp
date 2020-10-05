#include<stdio.h>

int main()
{
	int kasus, hasil=0, count;
	int i, x;
	long long int a, b, c, d;
	
	scanf("%d", &kasus);
	
	for(i=0; i<kasus; i++)
	{
		count = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		
		for(x=0; x<=100001; x++)
		{	
			hasil = (((a*x)+b)%d);
			
			if(hasil == c)
			{
				count++;
			}
		}
		if(count>0)
		{
			printf("Case #%d: YES\n", i+1);
		}
		else
		{
			printf("Case #%d: NO\n", i+1);
		}
	}
	
	
	return 0;
}
