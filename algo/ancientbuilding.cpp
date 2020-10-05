#include<stdio.h>

int main()
{
	int kasus, state, M;
	M=1000000007;
	
	scanf("%d", &kasus);
	
	int pow=50;
	long long int a=1;
	while(pow>0)
	{
		a*=2;
		a%=M;
		pow--;
	}
	pow=33;
	long long int b=1;
	while(pow>0)
	{
		b*=3;
		b%=M;
		pow--;
	}
	
	while(kasus)
	{
		int pow_A, pow_B;
		scanf("%d %d", &pow_A, &pow_B);
		long long int hasil=1;
		while(pow_A>50)
		{
			hasil=(hasil*a)%M;
			pow_A-=50;
		}
		while(pow_A>0)
		{
			hasil=(hasil*2)%M;
			pow_A--;
		}
		while(pow_B>33)
		{
			hasil=(hasil*b)%M;
			pow_B-=33;
		}
		while(pow_B>0)
		{
			hasil=(hasil*3)%M;
			pow_B--;
		}
		printf("%d\n", hasil);
		state++;
		kasus--;
		
		
	}
	
	return 0;
}
