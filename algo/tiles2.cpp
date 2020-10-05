#include<stdio.h>

void get(char nama[][101], int baris, int kolom);
void show(char nama[][101], int baris);
void string(char nama[], int kolom);


int main()
{
	int kasus, baris, kolom;
	char nama[101][101];
	
	scanf("%d", &kasus); getchar();
	for(int i=0; i<kasus; i++)
	{
		scanf("%d %d", &baris, &kolom); getchar();
		get(nama, baris, kolom);
		
		int last=0;
		int press=1;
		
		for(int j=0; j<kolom; j++)
		{
			if(nama[0][j]=='.')
			{
				continue;
			}
			else if(nama[0][j]=='|')
			{
				last=i;;
			}
			else if(nama[0][j]=='/')
			{
				last=i-1;
			}
			else
			{
				last=i+1;
			}
		}
		for(int j=1; j<baris; j++)
		{
			for(int k=0; k<kolom; k++)
			{
				if(nama[j][k]=='.')
				{
					continue;
				}
				else if(nama[j][k]=='|')
				{
					if(k!=last)
					press++;
					last=k;
				}
				else if(nama[j][k]=='/')
				{
					if(k!=last)
					press++;
					last=k-1;
				}
				else
				{
					if(k!=last)
					press++;
					last=k+1;
				}
			}
		}
		printf("Case #%d: %d\n",i+1 ,press);
	}
	
	
	return 0;
}
