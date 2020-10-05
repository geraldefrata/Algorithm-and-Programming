#include<stdio.h>
#include<math.h>

int jo(int a)
{
	int in_a = a;
	int jumlah=0, base=1, n; 
	
	while (a > 0)
	{
		n = a % 2;
		if(n == 1)
		{
			jumlah = jumlah + 8 * base;
		}
		else
		{
			jumlah = jumlah +7 * base;
		}
			a = a/2;
			base=base * 10;
	}
		jumlah -= base*8/10;
		
		return jumlah;
}


int main()
{
	long long int x; 
	int kasus;
	int count, temp;
	
	scanf("%d", &kasus); getchar();
	for(int i=0; i<kasus; i++)
	{
		scanf("%11d", &x); getchar();
		printf("Case #%d: ", i+1);
		
		int count=1;
		int temp=0;
		
		do
		{
			count++;
			if(x % jo(count)==0)
			{
				temp=1;
				break;
			}
		}while(x > jo(count));
		
		if(temp == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	getchar();
	return 0;
}
