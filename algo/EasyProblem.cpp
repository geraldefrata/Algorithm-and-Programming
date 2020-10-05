#include<stdio.h>

int main()
{
	int orang, tingkat, max=0;
	int i, j;
	int count=0, count2=0;
	
	scanf("%d", &orang); getchar();
	for(i=0; i<orang; i++)
	{
		scanf("%d", &tingkat);
		if(tingkat==0)
		{
			count++;
		}
		if(tingkat==1)
		{
			count2++;
		}
	}
	max=count;
	if(count2>max)
	{
		max=count2;
	}
	if(max==count)
	{
		printf("easy\n");
	}
	if(max==count2)
	{
	printf("not easy\n");
	}
	
	return 0;
}
