#include<stdio.h>
#include<string.h>

struct murid
{
	int nomor;
	int tanggal;
	int bulan;
	int tahun;
	char nama[11];
	char x[11];
};

void cari (struct murid top[], int n, int *index, int t)
{
	*index = -1;
	
	for(int i=0; i<t; i++)
	{
		if(top[i].nomor == n)
		{
			*index = i;
			break;
		}
	}
}


int main()
{
	int kasus, kasus2;
	int angka, index = -1;
	struct murid top[101];
	
	scanf("%d", &kasus); 
	
	for(int i=0; i<kasus; i++)
	{
		scanf("%d %d %d %d %s %s", &top[i].nomor, &top[i].tanggal, &top[i].bulan, &top[i].tahun, top[i].nama, top[i].x); getchar();
	}
	
	scanf("%d", &kasus2);
	for(int i=0; i<kasus2; i++)
	{
		scanf("%d", &angka); 
		cari(top,angka,&index,kasus);
		
		if(index == -1)
		{
			printf("No data found!\n");
		}
		else
		{
			printf("%d. %s was born on %d/%d/%d and live at %s\n", top[index].nomor, top[index].nama, top[index].tanggal, top[index].bulan, top[index].tahun, top[index].x);
		}
	}
	
	
	return 0;
}
