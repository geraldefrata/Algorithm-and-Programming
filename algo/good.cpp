#include<stdio.h>
#include<string.h>

int g=0, o=0, o2=0, d; //'g' 'o' 'o' 'd'
char input[100];
char good(char a[])
{
	g=0;
	o=0;
	o2=0;
	d=0;
	
	for(int i=0; i<=strlen(a)-1; i++)
	{
		if(a[i]=='g' || a[i]=='G')
		{
			g=1;
			if(a[i+1]=='o' || a[i+1]=='O')
			{
				o=1;
				if(a[i+2]=='o' || a[i+2]=='O')
				{
					o2=1;
					if(a[i+3]=='d' || a[i+3]=='D')
					{
						d=1;
					}
				}
			}
		}
	}
}


int main()
{
	int kasus;
	
	scanf("%d", &kasus); getchar();
	for(int j=0; j<kasus; j++)
	{
		scanf("%[^\n]", &input); getchar();
		printf("Case #%d: ", j+1);
		good(input);
		
		if(g==1 && o==1 && o2==1 && d==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}
