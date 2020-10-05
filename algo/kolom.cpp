#include<stdio.h>

int main()
{
	int kasus;
	long num1, num2;
	
	scanf("%d", &kasus);
	
	for(int i=0; i<kasus; i++)
	{
		scanf("%1d %1d", &num1, &num2);
		long number[100000] = {0};
		 
		for(int j=0; j<num1; j++)
		{
			scanf("&1d", &number[j]);
		}
		
		int temp = 0;
		
		for(int j=0; j<num1-1; j++)
		{
			for(int k=j+1; k<num1; k++)
			{
				if(number[k] < number[j])
				{
					temp = number[k];
					number[k] = number[j];
					number[j] = temp;
				}
			}
		}
		printf("Case #%d:\n", i+1);
		
		for(int j=0; j<num2; j++)
		{
			int x = j;
			for(int k=x; k<num1; k++)
			{
				if(k == x)
				{
					printf("%1d", number[k]);
					k += num2-1;
				}
				else
				{
					printf("%1d", number[k]);
					k += num2-1;
				}
				if(k < num1 && k !=num1-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		
	}
	
	
	return 0;
}
