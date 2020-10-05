#include<stdio.h>

int main()
{
	int kasus;
	scanf("%ld", &kasus);
	
	for(int i=1; i<=kasus; i++)
	{
		while(kasus--)
		{
			long long int a, b, c, d, remainder1, remainder2;
			long long int reverse1, reverse2=0;
			scanf("%ld", &a);
			printf("Case #%d: ", i++);
			b=a;
			for(reverse1=0; a>0; a=a/10)
			{
				reverse1=reverse1*10;
				reverse1=reverse1+a%10;
			}
			d=reverse1 + b;
			for(reverse2=0; d>0; d=d/10)
			{
				reverse2=reverse2*10;
				reverse2=reverse2+d%10;
			}
			c = reverse1 + b;
			printf("%ld %ld %ld %ld\n", b, reverse1, c, reverse2);
		}

	}
	
	return 0;
}
