#include <stdio.h>

int jo_number(int num)
{
	int initial_num = num;
	int remainder, base = 1, binary = 0;
	while (num > 0)
	{
		remainder = num % 2;
		if (remainder == 1)
			binary = binary + 8 * base;
		else
			binary = binary + 7 * base;
		num = num / 2;
		base = base * 10;
	}
	binary -= base * 8/10;

	return binary;
}



int main()
{
	long long int a;
	int t;

	scanf("%d", &t);
	for(int i=1 ; i<=t ;i++)
	{
		scanf("%lld", &a);

		printf("Case #%d: ",i);
		int nth = 1;
		int flag = 0;
		do
		{
			nth++;
			if (a%jo_number(nth) == 0)
			{
				flag = 1;
				break;
			}
		} while (a>jo_number(nth));

		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	getchar();
	return 0;
}
