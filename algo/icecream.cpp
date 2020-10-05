#include <stdio.h>
#include<string.h>

int main()
{
	int kasus, jumlahhuruf, rasa;
	int i, j, max;
	char a[100001];
	
	scanf("%d", &kasus); getchar();
	for(i=0; i<kasus; i++)
	{
		scanf("%d", &jumlahhuruf);
		int van = 0;
		int choc = 0;
		int straw = 0;
		for(j=0; j<jumlahhuruf; j++)
		{
			scanf("%s", &a[j]); getchar();
			if(a[j]=='c')
			{
				choc++;
			}
			if(a[j]=='v')
			{
				van++;
			}
			if(a[j]=='s')
			{
				straw++;
			}
		}
		max = choc;
		if(straw>max)
		{
			max=straw;
		}
		if(van>max)
		{
			max=van;
		}
		printf("Case #%d:\n", i+1);
		if(max==choc)
		{
			printf("chocolate\n");
		}
		if(max==straw)
		{
			printf("strawberry\n");
		}
		if(max==van)
		{
			printf("vanilla\n");
		}
	}
	
	return 0;
}
