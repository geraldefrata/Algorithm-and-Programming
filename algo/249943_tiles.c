#include <stdio.h>

char a[101][101];
int row,column,count;
char check(char x[101][101])
{
	int i,j;
	count = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			if(a[i][j] != '.')
			{
				count++;
			}
			if(a[i][j] == '|' && i != row - 1)
			{
				if(a[i+1][j] !='.')
				{
					count--;
				}
			}
			if(a[i][j] == '\\'&& i != row - 1)
			{
				if(a[i+1][j+1] !='.')
				{
					count--;
				}
			}
			if(a[i][j] == '/'&& i != row - 1)
			{
				if(a[i+1][j-1] !='.')
				{
					count--;
				}
			}
		}
	}
}

int main()
{
	int i,j;
	int k,kasus;
	for(i=0;i<100;i++)
	{
		for(j =0;j<100;j++)
		{
			a[i][j] = 0;
		}
	}
	scanf("%d",&kasus);
	for(k=1;k<=kasus;k++)
	{
		scanf("%d %d",&row,&column);
		getchar();
		for(i=0;i<row;i++)
		{
			for(j=0;j<column;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		check(a);
		printf("Case #%d: %d\n",k,count);
	}
}
