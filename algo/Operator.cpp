#include<stdio.h>

int main()
{
	int kasus;
	scanf("%d", &kasus);
	
	char input[5], temp;
	for(int i=0; i<kasus; i++)
	{
		scanf(" %5[^\n]s", input);
		for(int a=0; a<4; a+=2)
		{
			for(int b=0; b<4-a; b+=2)
			{
				if(input[b]>input[b+2])
				{
					temp=input[b];
					input[b]=input[b+2];
					input[b+2]=temp;
				}
			}
		}
		printf("Case #%d: %s\n", i+1, input);
	}
	
	
	
	return 0;
}
