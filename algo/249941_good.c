#include <stdio.h>
#include <string.h>

int g,o1,o2,d;
char string[81];
char good(char a[])
{
	int i;
	g=0,o1=0,o2=0,d=0;
	for(i = 0; i<=strlen(a)-1; i++)
	{
		if(a[i] == 'g' || a [i] == 'G')
		{
			g = 1;
			if(a[i+1] == 'o' || a[i+1] == 'O')
			{
				o1 = 1;
				if(a[i+2] == 'o' || a[i+2] == 'O')
				{	
					o2 = 1;
					if(a[i+3] == 'd' || a[i+3] == 'D')
					{
					d = 1;
					}
				}
			}
		}
	}
}

int main()
{
	int k,kasus;
	scanf("%d",&kasus);
	for(k=1;k<=kasus;k++)
	{
		getchar();
		scanf("%[^\n]",string);
		printf("Case #%d: ",k);
		good(string);
		if(g == 1 && o1 == 1 && o2 == 1 && d == 1)
		{			
			printf("yes\n");
		}
		else
		{	
			printf("no\n");
		}
	}
	return 0;
}
